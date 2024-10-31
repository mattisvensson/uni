from utils.measure_time import measure

def insertion_sort(arr):
  for i in range(1, len(arr)):
    for j in range(i, 0, -1):
      if arr[j - 1] > arr[j]:
        tmp = arr[j]
        arr[j] = arr[j -1]
        arr[j - 1] = tmp      
  return arr

measure(insertion_sort, 1)