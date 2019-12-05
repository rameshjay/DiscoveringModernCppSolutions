# 3.11 Exercises

## 3.11.1 String Representation

Write a generic function `to_string` that takes an argument of an arbitrary type (as `const&` )
and generates a string by piping it to a `std::stringstream` and returning the resulting string.

## 3.11.2 String Representation of Tuples

Write a variadic template function that represents an arbitrary number of arguments as a
tuple in a string. That is, the function call `to_tuple_string(x, y, z)` returns a string of the
form (x, y, z) by printing each element to a string stream.
Hint: Use a helper function `to_tuple_string_aux` that is overloaded for different arities.

## 3.11.3 Generic Stack

Write a stack implementation for a generic value type. The maximal size of the stack is
defined in the class (hard-wired). Provide the following functions:

- Constructor;
- Destructor if necessary;
- top : show last element;
- pop : remove last element (without returning);
- push : insert new element;
- clear : delete all entries;
- size : number of elements;
- full : whether stack is full;
- empty : whether stack is empty.

Stack over- or underflow must throw an exception.

## 3.11.4 Iterator of a Vector

Add the methods `begin()` and `end()` for returning a begin and end iterator to class vector.
Add the types iterator and `const_iterator` to the class as well. Note that pointers are models
of the concept of random-access iterators.
Use the **STL** function sort for ordering vector entries to demonstrate that your iterators
work as they should.

## 3.11.5 Odd Iterator

Write an iterator class for odd numbers named odd_iterator. The class must model (realize)
the ForwardIterator concept [http://www.sgi.com/tech/stl/ForwardIterator.html](http://www.sgi.com/tech/stl/ForwardIterator.html). That
means it must provide the following members:

- Default and copy constructor
- `operator++` to the next odd element, as pre-increment and post-increment
- `operator*` as dereference which returns an (odd) int 
- `operator==` and `operator!=` and `operator=`.

with the obvious semantics. In addition, the class should contain a constructor that accepts
an int value. This value will be returned in the dereference operator (as long as the iterator
is not incremented). This constructor should throw an exception if the value is even. Likewise
the default constructor should initialize the internal value with 1 to provide a legal state.

## 3.11.6 Odd Range

Write a class for a range of odd numbers. The member or free functions begin and end should
return an odd_iterator as defined in Exercise 3.11.5.
The following code should print the odd numbers {7, 9, . . . , 25}:

```c++
for ( int i : odd_range (7 , 27))
    std :: cout << i << '\n';
```

## 3.11.7 Stack of bool

Specialize your stack implementation from Exercise 3.11.3 for bool . Use an unsigned char for
8 bool as in Section 3.6.1.

## 3.11.8 Stack with Custom Size

Revise your stack implementation from Exercise 3.11.3 (and optionally that of Exercise 3.11.7)
with a user-defined size. The size is passed as the second template argument. The default should
be 4096.

## 3.11.9 Deducing Non-type Template Arguments

We have seen that the type of a template argument can be deduced in a function call.
Non-type template arguments are in most cases declared explicitly, but they can be deduced
as well when they are part of the argument type. As illustration: write a function array_size
that accepts a C array of arbitrary type and size as a reference and returns the size of that
array. The actual function argument can be omitted since we are only interested in its type.
Do you remember? We threatened this exercise in Section 1.8.7.1. On the other hand, we
revealed the trickiest part of it in the meantime.

## 3.11.10 Trapezoid Rule

A simple method for computing the integral of a function is the trapezoid rule. Suppose
we want to integrate the function f over the interval [a, b]. We split the interval in n small
intervals [x i , x i+1 ] of the same length h = (b − a)/n and approximate f by a piecewise linear
function. The integral is then approximated by the sum of the integrals of that function.
This leads to the following formula: 

~~(unformatted math formula)~~

For comparison, implement this using inheritance and generic programming. As a test case,
integrate:

- f = exp(−3x) for x ∈ [0, 4].

 Try trapezoid with the following arguments:

```c++

double exp3f (double x) {
   return std::exp (3.0 * x);
}

struct exp3t {
   double operator() (double x) const {
      return std::exp (3.0 * x);
   }
};
```
- f = sin(x) if x < 1 and f = cos(x) if x 1 for x ∈ [0, 4].
- Can we call trapezoid(std::sin, 0.0, 2.0); ?

As a second exercise, develop a functor for computing the finite difference. Then integrate
the finite difference to verify that you get the function value back.

## 3.11.11 Functor

Write a functor for 2 cos x + x 2 and compute the first and second derivatives with the functor
from Section 3.8.1.

## 3.11.12 Lambda

Compute the same derivatives as in Exercise 3.11.11 but this time with a lambda expression.

## 3.11.13 Implement make_unique

Implement your own `make_unique`. Use `std::forward` to pass parameter packs to the new.

