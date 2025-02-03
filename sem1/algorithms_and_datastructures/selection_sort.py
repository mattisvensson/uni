import random
import timeit

def selection_sort(arr):
  for i in range(len(arr)):
    min_index = i

    for j in range(i + 1, len(arr)):
      if arr[j] < arr[min_index]:
        new_min = arr[j]
        arr[j] = arr[min_index]
        arr[min_index] = new_min
  return arr

def measure_time(arr_length):
    arr = list(range(1, arr_length + 1))
    random.shuffle(arr)
    selection_sort(arr)

array_lengths = [100, 200, 1000, 2000, 4000, 10000, 20000, 40000]

for length in array_lengths:
    execution_time = timeit.timeit(lambda: measure_time(length), number=1)
    print(f"Execution time for array length {length} over 1 run: {execution_time} seconds")
