
import numpy as np

# --- Creating a 2D array (matrix) ---
# We can create a 2D array by passing a list of lists.
my_matrix = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print("A 2x3 matrix (2D array):")
print(my_matrix)

# --- Special Array Creation Functions ---
# Numpy provides functions to create arrays with initial placeholder content.

# Create an array of all zeros
zeros_array = np.zeros((3, 4))  # A 3x4 array of zeros
print("\nA 3x4 array of zeros:")
print(zeros_array)

# Create an array of all ones
ones_array = np.ones((2, 5))   # A 2x5 array of ones
print("\nA 2x5 array of ones:")
print(ones_array)

# Create an array with a range of elements
range_array = np.arange(10, 20, 2) # From 10 up to (but not including) 20, in steps of 2
print(f"\nAn array from 10 to 18 with a step of 2: {range_array}")

# Create an array of random values
# This creates an array with random numbers between 0 and 1.
random_array = np.random.rand(3, 3)
print("\nA 3x3 array of random values:")
print(random_array)

# --- Reshaping Arrays ---
# We can change the shape of an array.
original_array = np.arange(12) # An array from 0 to 11
print(f"\nOriginal array: {original_array}")

# Reshape it into a 3x4 matrix
reshaped_array = original_array.reshape(3, 4)
print("\nReshaped into a 3x4 matrix:")
print(reshaped_array)

print("\nScript finished. You can now run this file to see the output.")
