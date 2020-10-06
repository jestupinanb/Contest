import numpy as np

a = [1, 2, 3]
b = [5, 6, 7]

arr = np.array([a])
for i in range(2):
    arr = np.concatenate((arr, [b]))

for i in range(1, 3):
    print(i)

print(arr)
