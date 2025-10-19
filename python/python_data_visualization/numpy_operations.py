
import numpy as np

# To use numpy, you first need to import it.
# The 'as np' part is a standard convention to give it a shorter name.

# --- Creating a numpy array ---
# We can create an array from a regular Python list.
my_list = [1, 2, 3, 4, 5]
my_array = np.array(my_list)

print(f"This is a Python list: {my_list}")
print(f"This is a numpy array: {my_array}")

# --- Basic Array Operations ---
# A major advantage of numpy arrays is that you can apply operations to the entire array at once.

# Add 5 to every element
added_array = my_array + 5
print(f"Array after adding 5: {added_array}")

# Multiply every element by 2
multiplied_array = my_array * 2
print(f"Array after multiplying by 2: {multiplied_array}")

# --- Universal Functions ---
# Numpy also provides many fast mathematical functions called 'universal functions'.

# Calculate the square root of each element
squareroot_array = np.sqrt(my_array)
print(f"Square root of the array: {squareroot_array}")

print("\nScript finished. You can now run this file to see the output.")
