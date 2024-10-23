import math

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]

def linear_search(arr, target):
  for index, item in enumerate(arr):
    if item == target:
      return index
  return -1
    
def binary_search(arr, target):
  center = math.floor(len(arr)/2)
  item = arr[center]

  if item == target:
    return center
  elif target < center:
    binary_search(arr, target)




print(linear_search(arr, "D"))
  