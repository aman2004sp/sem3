import numpy as np

# Define the objective function
def f(x):
    return x**2 + 5 * x + 6  # Example function: f(x) = x^2 + 5x + 6

# Define the derivative of the objective function
def f_prime(x):
    return 2 * x + 5  # Derivative of f(x)

# Line search method to find the optimal solution
def line_search_method(x_start, direction, step_size, epsilon=1e-5, max_iterations=1000):
    x = x_start
    iteration = 0

    while iteration < max_iterations:
        gradient = f_prime(x)
        new_x = x + step_size * direction

        # If the change is negligible or the gradient is close to zero, stop
        if np.abs(new_x - x) < epsilon or np.abs(gradient) < epsilon:
            break

        x = new_x
        iteration += 1

    return x, f(x)

# Set initial values
x_start = 0  # Initial value of x
search_direction = -1  # Direction of search (-1 for minimizing the function)
step = 0.1  # Step size for the line search

# Perform line search
optimal_solution, minimum_value = line_search_method(x_start, search_direction, step)

print("Optimal Solution (x):", optimal_solution)
print("Minimum Value of f(x):", minimum_value)
