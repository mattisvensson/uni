from utils.measure_time import measure

def setup(arr):
    quick_sort(arr, 0, len(arr))

def quick_sort(arr, low, high):
  print(low)
  print(high)
  if low < high:
    pivot = partition(arr, low, high)
    
    quick_sort(arr, low, pivot)
    
    quick_sort(arr, pivot + 1, high)
    
def partition(arr, low, high):
    pivot = arr[(low + high) // 2]
    i = low - 1
    j = high + 1
    
    while True:
        i += 1
        while arr[i] < pivot:
            i += 1
        
        j -= 1
        while arr[j] > pivot:
            j -= 1
        
        if i >= j:
            return j
        
        arr[i], arr[j] = arr[j], arr[i]
  
  
  
  
  
# arr = list(range(1, arr_length + 1))
# random.shuffle(arr)
measure(setup, 1)