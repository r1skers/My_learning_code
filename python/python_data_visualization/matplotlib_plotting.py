
import numpy as np
import matplotlib.pyplot as plt

# --- 1. Generate Data ---
# Create an array for the x-axis (time) from 0 to 4*pi with 1000 points.
x = np.linspace(0, 4 * np.pi, 1000)

# Create a clean sine wave.
y_clean = np.sin(x)

# --- 2. Add Noise ---
# Generate some random noise.
# The noise will be random numbers from a normal (Gaussian) distribution.
# 'loc=0' means the average of the noise is 0.
# 'scale=0.2' controls the amplitude of the noise.
noise = np.random.normal(loc=0, scale=0.2, size=x.shape)

# Add the noise to the clean sine wave to create a noisy signal.
y_noisy = y_clean + noise

# --- 3. Filter the Data ---
# We'll use a simple moving average filter.
# This filter averages a small window of points to smooth out the signal.
window_size = 20
# The convolve function is great for this kind of operation.
# 'valid' mode means we only get output where the window fully overlaps the data.
y_filtered = np.convolve(y_noisy, np.ones(window_size)/window_size, mode='valid')

# Because of the 'valid' mode, the filtered data is shorter than the original.
# We need to adjust the x-axis data to match its length for plotting.
x_filtered = x[window_size-1:]


# --- 4. Plot the Comparison ---
# Create a figure and axes for our plot.
plt.figure(figsize=(12, 6)) # Set the figure size for better readability.

# Plot the three datasets.
plt.plot(x, y_clean, label='Original Sine Wave', color='blue', linewidth=2)
plt.plot(x, y_noisy, label='Noisy Data', color='orange', alpha=0.5) # alpha makes it semi-transparent
plt.plot(x_filtered, y_filtered, label='Filtered Data', color='green', linewidth=2)

# Add titles and labels for clarity.
plt.title('Filtering Noisy Data')
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.legend() # Display the labels for each line.
plt.grid(True) # Add a grid to the background.

# Show the first plot.
print("Displaying the plot of the sine wave, noisy data, and filtered data.")
plt.show()


# --- 5. Create a Histogram of the Noise ---
# Create a new figure for the histogram.
plt.figure(figsize=(8, 5))

# Create the histogram. 'bins=50' means the noise values are grouped into 50 bars.
plt.hist(noise, bins=50, density=True, alpha=0.7, label='Noise Distribution')

# Add titles and labels.
plt.title('Histogram of the Random Noise')
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.legend()
plt.grid(True)

# Show the second plot.
print("Displaying the histogram of the noise.")
plt.show()

print("\nScript finished. Run this file to see the plots.")
