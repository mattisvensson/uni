import random
import timeit

def measure_time(arr_length, fn):
  arr = list(range(1, arr_length + 1))
  random.shuffle(arr)
  fn(arr)

array_lengths = [100, 200, 1000, 2000, 4000, 10000, 20000, 40000]

def measure(fn, runs = 1):
  for length in array_lengths:
    execution_time = timeit.timeit(lambda: measure_time(length, fn), number=runs)
    print(f"Execution time for array length {length} over {runs} run: {execution_time} seconds")
