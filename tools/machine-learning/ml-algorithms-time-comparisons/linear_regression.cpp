#include<iostream>
#include<vector>
#include<chrono>
#include<fstream>


int main(){
    std::vector<int> x = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> y = {1,2,3,4,5,6,7,8,9,10};
    int dataset_length = x.size();

    //std::vector<double> error_vector;
    double index_error;
    int input_pred_value;

    //CSV Files
    std::fstream fout;
    fout.open("run_data_cplusplus.csv", std::ios::out | std::ios::out);
    fout << "source" << "," << "epoch" << "," << "run" << "," <<  "time(ms)" << "," << "error_value" << "\n" ;

    //Hyperparameters
    double b0, b1;
    double b0_init=2;
    double b1_init=2;
    double learning_rate = 0.0001;
    int epochs_list[4] = {10000, 20000, 40000, 80000};
    int number_of_runs = 20;

    //Training Phase
    for(uint8_t epochs_index=0;epochs_index < 4; epochs_index++){
        for(uint8_t run_num=0; run_num < number_of_runs; run_num++){
            b0 = b0_init;
            b1 = b1_init;
            auto start = std::chrono::high_resolution_clock::now();
            for(uint32_t i=0; i<epochs_list[epochs_index]; i++){
                for(uint8_t index=0; index<dataset_length; index++){
                    double p = b0 + b1*x[index];
                    index_error = p - y[index];
                    b0 = b0 - learning_rate*index_error;
                    b1 = b1 - learning_rate*index_error*x[index];
                }
            }
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
            //std::cout << "Run " << +run_num << "completed in " << duration.count() << " milliseconds. b0 = " << b0 << " b1 = " << b1 << std::endl;
            fout << "C++" << "," << +epochs_list[epochs_index] << "," << +run_num << "," <<  duration.count() << "," << index_error << "\n" ;
        }
    }
}