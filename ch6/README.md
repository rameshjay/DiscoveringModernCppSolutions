# 6.7 Exercises

##  6.7.1 Non-redundant Diamond Shape

Implement the diamond shape from Section 6.3.2 such that the name is only printed once.
Distinguish in derived classes between `all_info()` and `my_infos()` and call the two functions
appropriately.

## 6.7.2 Inheritance Vector Class

Revise the vector example from Chapter 2. Introduce the base class vector_expression for
size and operator(). Make vector inherit from this base class. Then make a class ones that
is a vector of all ones and also inherits from vector_expression.

## 6.7.3 Clone Function

Write a CRTP class for a member function named `clone()` that copies the current object-like the Java function clone (http://en.wikipedia.org/wiki/Clone_%28Java_method%29).
Consider that the return type of the function must be the one of the cloned object.

