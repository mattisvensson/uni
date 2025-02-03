from utils.measure_time import measure
from insertion_sort import insertion_sort

def merge_sort(arr):
  if len(arr) <= 10:
    return insertion_sort(arr)
  
  mid = len(arr) // 2
  
  left_arr = arr[:mid]
  right_arr = arr[mid:]
  
  sorted_left = merge_sort(left_arr)
  sorted_right = merge_sort(right_arr)

  return merge(sorted_left, sorted_right)

def merge(left, right):
  result = []
  left_idx, right_idx = 0, 0

  while left_idx < len(left) and right_idx < len(right):
    if left[left_idx] <= right[right_idx]:
      result.append(left[left_idx])
      left_idx += 1
    else:
      result.append(right[right_idx])
      right_idx += 1
  
  while left_idx < len(left):
    result.append(left[left_idx])
    left_idx += 1
    
  while right_idx < len(right):
    result.append(right[right_idx])
    right_idx += 1
    
  return result

measure(merge_sort, 5)