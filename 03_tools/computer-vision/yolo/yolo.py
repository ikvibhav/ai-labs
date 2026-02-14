# Code with some OOPS
from abc import ABC, abstractmethod
import os
import time
from ultralytics import YOLO
from onnxruntime.quantization import quantize_dynamic, QuantType

IMAGE_URL = "https://ultralytics.com/images/bus.jpg"


class Yolo(ABC):

    @abstractmethod
    def get_onnx_model(self):
        pass

    @abstractmethod
    def get_object_detection(self, image_url: str):
        """Returns tuple of (results, execution_time_ms)"""
        pass

    @abstractmethod
    def get_model_file_size(self):
        pass

    @abstractmethod
    def quantize(self):
        pass


class Yolov8(Yolo):

    def __init__(self):
        super().__init__()
        self.model_name = "yolov8n.pt"
        self.model_name_onnx = "yolov8n.onnx"
        self.model = YOLO(self.model_name)
        self.model_onnx = self.get_onnx_model()

    def get_onnx_model(self):
        return self.model.export(format="onnx")

    def get_object_detection(self, image_url: str):
        print(f"Performing object detection on {image_url} using YOLOv8")
        start_time = time.time()
        results = self.model.predict(image_url)
        end_time = time.time()
        execution_time_ms = (end_time - start_time) * 1000
        return results, execution_time_ms

    def get_model_file_size(self):
        return os.path.getsize(self.model_onnx)

    def quantize(self, output_path: str):
        return quantize_dynamic(
            model_input=self.model_name_onnx,
            model_output=output_path,
            op_types_to_quantize=["MatMul", "Conv"],
            weight_type=QuantType.QInt8,
        )


class Yolov11(Yolo):

    def __init__(self):
        super().__init__()
        self.model_name = "yolo11n.pt"  # YOLOv11 nano model
        self.model_name_onnx = "yolo11n.onnx"
        self.model = YOLO(self.model_name)
        self.model_onnx = self.get_onnx_model()

    def get_onnx_model(self):
        return self.model.export(format="onnx")

    def get_object_detection(self, image_url: str):
        print(f"Performing object detection on {image_url} using YOLOv11")
        start_time = time.time()
        results = self.model.predict(image_url)
        end_time = time.time()
        execution_time_ms = (end_time - start_time) * 1000
        return results, execution_time_ms

    def get_model_file_size(self):
        return os.path.getsize(self.model_onnx)

    def quantize(self, output_path: str):
        return quantize_dynamic(
            model_input=self.model_name_onnx,
            model_output=output_path,
            op_types_to_quantize=["MatMul", "Conv"],
            weight_type=QuantType.QInt8,
        )


def compare_models(models, image_url, num_runs=3):
    """Compare multiple YOLO models for size and speed"""
    print("\n" + "=" * 80)
    print("YOLO MODEL COMPARISON")
    print("=" * 80)

    results = {}

    for model_name, model_instance in models.items():
        print(f"\n--- Testing {model_name} ---")

        # Get model size
        model_size = model_instance.get_model_file_size()
        model_size_mb = model_size / (1024 * 1024)

        # Run multiple times for average timing
        times = []
        detection_results = None

        for run in range(num_runs):
            print(f"Run {run + 1}/{num_runs}...")
            detection_results, exec_time = model_instance.get_object_detection(
                image_url
            )
            times.append(exec_time)

        avg_time = sum(times) / len(times)
        min_time = min(times)
        max_time = max(times)

        # Count detections
        num_detections = (
            len(detection_results[0].boxes)
            if detection_results and len(detection_results) > 0
            else 0
        )

        results[model_name] = {
            "model_size_bytes": model_size,
            "model_size_mb": model_size_mb,
            "avg_time_ms": avg_time,
            "min_time_ms": min_time,
            "max_time_ms": max_time,
            "num_detections": num_detections,
            "all_times": times,
        }

        print(f"Model Size: {model_size_mb:.2f} MB")
        print(f"Average Time: {avg_time:.2f} ms")
        print(f"Detections: {num_detections}")

    # Print comparison summary
    print("\n" + "=" * 80)
    print("COMPARISON SUMMARY")
    print("=" * 80)
    print(
        f"{'Model':<15} {'Size (MB)':<12} {'Avg Time (ms)':<15} {'Detections':<12} {'Speed Factor':<12}"
    )
    print("-" * 80)

    # Find fastest model for speed factor calculation
    fastest_time = min(results[model]["avg_time_ms"] for model in results)

    for model_name, data in results.items():
        speed_factor = data["avg_time_ms"] / fastest_time
        print(
            f"{model_name:<15} {data['model_size_mb']:<12.2f} {data['avg_time_ms']:<15.2f} {data['num_detections']:<12} {speed_factor:<12.2f}x"
        )

    # Determine winner
    print("\n" + "-" * 80)
    fastest_model = min(results.keys(), key=lambda x: results[x]["avg_time_ms"])
    smallest_model = min(results.keys(), key=lambda x: results[x]["model_size_mb"])

    print(
        f"🏆 Fastest Model: {fastest_model} ({results[fastest_model]['avg_time_ms']:.2f} ms)"
    )
    print(
        f"📦 Smallest Model: {smallest_model} ({results[smallest_model]['model_size_mb']:.2f} MB)"
    )

    return results


if __name__ == "__main__":
    print("Initializing YOLO models...")

    # Create model instances
    yolov8 = Yolov8()
    yolov11 = Yolov11()

    # Store models for comparison
    models = {"YOLOv8n": yolov8, "YOLOv11n": yolov11}

    # Run comprehensive comparison
    comparison_results = compare_models(models, IMAGE_URL, num_runs=5)

    # Test quantization for both models
    print("\n" + "=" * 80)
    print("QUANTIZATION TESTING")
    print("=" * 80)

    # Quantize YOLOv8
    print("\nQuantizing YOLOv8...")
    yolov8_quantized_path = "yolov8n_quantized.onnx"
    yolov8.quantize(yolov8_quantized_path)
    yolov8_quantized_size = os.path.getsize(yolov8_quantized_path) / (1024 * 1024)
    print(
        f"YOLOv8 Quantized model saved at: {yolov8_quantized_path} ({yolov8_quantized_size:.2f} MB)"
    )

    # Quantize YOLOv11
    print("\nQuantizing YOLOv11...")
    yolov11_quantized_path = "yolo11n_quantized.onnx"
    yolov11.quantize(yolov11_quantized_path)
    yolov11_quantized_size = os.path.getsize(yolov11_quantized_path) / (1024 * 1024)
    print(
        f"YOLOv11 Quantized model saved at: {yolov11_quantized_path} ({yolov11_quantized_size:.2f} MB)"
    )

    # Show quantization benefits
    print("\nQuantization Size Reduction:")
    yolov8_original_size = comparison_results["YOLOv8n"]["model_size_mb"]
    yolov11_original_size = comparison_results["YOLOv11n"]["model_size_mb"]

    yolov8_reduction = (
        (yolov8_original_size - yolov8_quantized_size) / yolov8_original_size
    ) * 100
    yolov11_reduction = (
        (yolov11_original_size - yolov11_quantized_size) / yolov11_original_size
    ) * 100

    print(
        f"YOLOv8:  {yolov8_original_size:.2f} MB → {yolov8_quantized_size:.2f} MB ({yolov8_reduction:.1f}% reduction)"
    )
    print(
        f"YOLOv11: {yolov11_original_size:.2f} MB → {yolov11_quantized_size:.2f} MB ({yolov11_reduction:.1f}% reduction)"
    )

    print("\n🎯 Analysis complete! Check the comparison results above.")
