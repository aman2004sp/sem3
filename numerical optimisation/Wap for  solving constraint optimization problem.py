from scipy.optimize import minimize

# Define the objective function to minimize
def objective_function(variables):
    x, y = variables
    return x**2 + y**2

# Define the inequality constraints
def inequality_constraints(variables):
    x, y = variables
    return [
        1 - 2*x - y,  # 2x + y >= 1 becomes 2x + y - 1 >= 0
        2 - x - 3*y   # x + 3y >= 2 becomes x + 3y - 2 >= 0
    ]

# Define initial guess for variables
initial_guess = [0.5, 0.5]  # Initial guess for x and y

# Set up bounds for x and y (non-negative)
bounds = [(0, None), (0, None)]  # x and y should be non-negative

# Define constraints using dictionary format
constraints = {'type': 'ineq', 'fun': inequality_constraints}

# Use minimize function to solve the optimization problem
result = minimize(objective_function, initial_guess, bounds=bounds, constraints=constraints)

# Print the optimal solution and minimum value of the objective function
print("Optimal Solution (x, y):", result.x)
print("Minimum Value of f(x, y):", result.fun)
