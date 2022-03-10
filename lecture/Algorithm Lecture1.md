# Algorithm Lecture1

## intro by insertion sort

```python
def insertion_sort(Array : list) - >list:
	for j in range(2, len(array)):
		i = j-1
		key = Array[i]
		while i > 0 and Array[i] > key:
			Array[i-1] = Array[i]
			i -= 1
		Array[i] = key
	return Array
```

## Some Issue

### 1. Running Time

1. input itself (assum the array is sorted)
2. input size
3. Upper bound of the program

### 2. Kind of Analysis

1. worst case
2. Average case
3. best case (meaning less)

## how do we measure algorithm? ->asymptotic analysis

### 1.big idea

1. Ignore machine dependents constants

2. look at the growth of running time

### 2. Big O 

## Better algorithm of sort 

#### merge sort -> O(nlogn)

