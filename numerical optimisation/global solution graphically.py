import numpy as np
import matplotlib.pyplot as plt

# Define the function
def f(x):
    return -10 * np.cos(np.pi * x - 2.2) + (x + 1.5) * x

# Generate x values
x_values = np.linspace(-5, 5, 1000)

# Calculate corresponding y values (function values)
y_values = f(x_values)

# Find the x value that corresponds to the minimum y value (global minimum)
optimal_x = x_values[np.argmin(y_values)]
optimal_y = np.min(y_values)

# Plot the function
plt.figure(figsize=(8, 6))
plt.plot(x_values, y_values, label=r'$f(x)=-10\cos(\pi x - 2.2)+(x+1.5)x$')
plt.scatter(optimal_x, optimal_y, color='red', label='Global Optimal Solution')

plt.title('Graph of f(x)')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()
plt.grid(True)
plt.show()

print("Global Optimal Solution (x):", optimal_x)
print("Minimum Value of f(x):", optimal_y)
