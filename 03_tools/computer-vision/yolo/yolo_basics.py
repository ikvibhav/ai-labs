def calculate_iou(boxA, boxB):
    # box format: [x1, y1, x2, y2]
    # 1. Determine the coordinates of the intersection rectangle
    xA = max(boxA[0], boxB[0])
    yA = max(boxA[1], boxB[1])
    xB = min(boxA[2], boxB[2])
    yB = min(boxA[3], boxB[3])

    # 2. Compute the area of intersection
    interWidth = max(0, xB - xA)
    interHeight = max(0, yB - yA)
    interArea = interWidth * interHeight

    # 3. Compute the area of both bounding boxes
    boxAArea = (boxA[2] - boxA[0]) * (boxA[3] - boxA[1])
    boxBArea = (boxB[2] - boxB[0]) * (boxB[3] - boxB[1])

    # 4. Compute the Union area (A + B - Overlap)
    unionArea = float(boxAArea + boxBArea - interArea)

    # 5. Compute the IoU
    iou = interArea / unionArea
    return iou


# Example:
ground_truth = [50, 50, 150, 150]  # A 100x100 box
prediction = [60, 60, 170, 170]  # A slightly offset box

score = calculate_iou(ground_truth, prediction)
print(f"The IoU Score is: {score:.4f}")
# If Score > 0.5, it's usually considered a 'True Positive'
