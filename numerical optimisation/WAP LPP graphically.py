import matplotlib.pyplot as plt
import numpy as np

# Define the objective function coefficients (Z = cx + dy)
c = 3
d = 4

# Define the constraints (in the form ax + by <= c)
constraint1 = {'a': 2, 'b': 1, 'c': 20}  # 2x + y <= 20
constraint2 = {'a': -4, 'b': 5, 'c': 10}  # -4x + 5y <= 10

# Calculate the feasible region
x = np.linspace(0, 10, 400)  # Range of x values

# Constraint 1: 2x + y <= 20
y1 = (constraint1['c'] - constraint1['a']*x) / constraint1['b']

# Constraint 2: -4x + 5y <= 10
y2 = (constraint2['c'] - constraint2['a']*x) / constraint2['b']

# Plotting the constraints and feasible region
plt.figure(figsize=(8, 6))

plt.plot(x, y1, label=r'$2x + y \leq 20$')
plt.plot(x, y2, label=r'$-4x + 5y \leq 10$')
plt.fill_between(x, 0, np.minimum(y1, y2), where=(y1 > 0) & (y2 > 0), color='gray', alpha=0.3, label='Feasible Region')
plt.xlim((0, 10))
plt.ylim((0, 10))
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.title('Graphical Representation of Linear Programming Problem')

# Plot the objective function Z = cx + dy for some values of x and corresponding y in the feasible region
Z = c*x + d*y1  # Using y1 as it represents the upper bound of feasible y values
plt.plot(x, Z, label=r'$Z = 3x + 4y$')
optimal_x = 2
optimal_y = 16
plt.scatter(optimal_x, optimal_y, color='red', marker='*', s=100, label='Optimal Solution (2, 16)')

plt.legend()
plt.show()
            
