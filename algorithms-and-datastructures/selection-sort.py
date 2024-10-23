import random

# Create a list from 1 to 30
arr = list(range(1, 30))

# Shuffle the list to scramble the order
random.shuffle(arr)

print("unsorted:", arr)

for i in range(len(arr)):
  min_index = i

  for j in range(i + 1, len(arr)):
    if arr[j] < arr[min_index]:
      new_min = arr[j]
      arr[j] = arr[min_index]
      arr[min_index] = new_min
    
print("sorted:", arr)