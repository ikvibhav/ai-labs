import time
import csv

x = [1,2,3,4,5,6,7,8,9,10]
y = [1,2,3,4,5,6,7,8,9,10]
dataset_length = len(x)

csvfile_python = 'run_data_python.csv'
with open(csvfile_python, 'w') as f:
    writer = csv.writer(f)
    writer.writerow(['source','epoch', 'run', 'time(ms)', 'error_value'])

b0_init = 2
b1_init = 2
learning_rate = 0.0001
epochslist = [10000, 20000, 40000, 80000]
number_of_runs = 20

for epochs in epochslist:
    for run_index in range(number_of_runs):
        b0 = b0_init
        b1 = b1_init
        start = time.time()
        for i in range(epochs):
            for index in range(dataset_length):
                p = b0 + b1*x[index]
                index_error = p - y[index]
                b0 = b0 - learning_rate*index_error
                b1 = b1 - learning_rate*index_error*x[index]
        duration = time.time() - start
        #print(f'Run {run_index} Completed in {duration*1000} milliseconds. b0 = {b0} b1 = {b1}')
        
        row_to_write = ['Python',epochs, run_index, int(duration*1000), index_error]

        with open(csvfile_python, 'a') as f:
            writer = csv.writer(f)
            writer.writerow(row_to_write)