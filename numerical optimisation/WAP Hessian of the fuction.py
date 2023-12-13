import sympy as sp

# Define the variables
x1, x2 = sp.symbols('x1 x2')

# Define the function
f = 100 * (x2 - x1**2)**2 + (1 - x1)**2

# Compute the gradient
gradient = [sp.diff(f, var) for var in (x1, x2)]

# Compute the Hessian matrix
hessian = sp.hessian(f, (x1, x2))

# Print the gradient and Hessian matrix
print("Gradient of f(x):", gradient)
print("\nHessian of f(x):")
print(hessian)
