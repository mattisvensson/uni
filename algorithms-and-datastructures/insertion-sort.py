import random
import timeit

def insertion_sort(arr):
  for i in range(1, len(arr)):
    for j in range(i, 0, -1):
      if arr[j - 1] > arr[j]:
        tmp = arr[j]
        arr[j] = arr[j -1]
        arr[j - 1] = tmp      
  return arr

def measure_time(arr_length):
  arr = list(range(1, arr_length + 1))
  random.shuffle(arr)
  insertion_sort(arr)

array_lengths = [100, 200, 1000, 2000, 4000, 10000, 20000, 40000]

for length in array_lengths:
  execution_time = timeit.timeit(lambda: measure_time(length), number=1)
  print(f"Execution time for array length {length} over 1 run: {execution_time} seconds")
