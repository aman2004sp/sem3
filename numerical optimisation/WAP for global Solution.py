from scipy.optimize import fsolve
import numpy as np

# Define the derivative function
def derivative(x):
    return 10 * np.pi * np.sin(np.pi * x - 2.2) + 2 * x + 1.5

# Use fsolve to find the roots (where the derivative is zero)
critical_points = fsolve(derivative, [-2, 2])  # Initial guesses for roots

# Evaluate the function at the critical points
values_at_critical_points = -10 * np.cos(np.pi * critical_points - 2.2) + (critical_points + 1.5) * critical_points

# Find the minimum value among the critical points
global_min_index = np.argmin(values_at_critical_points)
global_optimal_solution = critical_points[global_min_index]
min_function_value = values_at_critical_points[global_min_index]

print("Critical Points:", critical_points)
print("Function Values at Critical Points:", values_at_critical_points)
print("Global Optimal Solution (Minimum):", global_optimal_solution)
print("Minimum Function Value:", min_function_value)
