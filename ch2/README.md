# 2.8 Exercises

## 2.8.1 Polynomial

Write a class for polynomials that should at least contain:

• A constructor giving the degree of the polynomial;
• A dynamic array/vector/list of double to store the coefficients;
• A destructor; and
• A output function for ostream.

Further members like arithmetic operations are optional.

## 2.8.2 Move Assignment

Write a move assignment operator for the polynomial in Exercise 2.8.1.
Define the copy constructor as default. To test whether your assignment is 
used write a function `polynomial f(double c2, double c1, double c0)` that 
takes three coefficients and returns a polynomial. Print out a message 
in your move assignment or use a debugger to make sure your assignment is used.

## 2.8.3 Initializer List

Expand the program from Exercise 2.8.1 with a constructor and an assignment operator
for a initializer list. The degree of the polynomial should be the length of the initializer list
minus one afterward.

## 2.8.4 Resource Rescue

Refactor the implementation from Section 2.4.2.5. Implement a deleter for Statement and use
managed statements in a managed ResultSet .
