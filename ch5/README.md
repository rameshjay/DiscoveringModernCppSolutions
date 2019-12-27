# 5.5 Exercises

## 5.5.1 Type Traits
Write type traits for removing and adding references. Add a domain-specific type trait for the
meta-predicate is_vector and assume that the only known vectors are so far `my_vector<Value>`
and `vector_sum<E1, E2>`.

## 5.5.2 Fibonacci Sequence
Write a meta-template that generates the Fibonacci sequence at compile-time. The
Fibonacci sequence is defined by the following recursion:



x<sub>0</sub> = 0

x<sub>1</sub> = 1

x<sub>n</sub> = x<sub>n−1</sub> + x<sub>n−2</sub> for n >= 2 .

## 5.5.3 Meta-Program for Greatest Common Divisor

Write a meta-program for the GCD (greatest common divisor) of two integers. The algorithm
is as follows: Write a generic function for an integer type I that computes the GCD.
```c++
1 function gcd(a, b):
2 if b = 0 return a
3 else return gcd(b, a mod b)
```

```c++
template <typename I>
I gcd (I a, I b) { ... }
```

Then write an integral meta-function that executes the same algorithm but at compile time. Your meta-function should be of the following form:

```c++
template <int A, int B>
struct gcd_meta {
   static int const value = ... ;
};
```
i.e., `gcd_meta<a,b>::value` is the GCD of a and b. Verify whether the results correspond to
your C ++ function `gcd()`.

## 5.5.4 Vector Expression Template

Implement a vector class (you can use `std::vector<double>` internally) that contains at least the following members:

```c++
class my_vector {
public:
  typedef double value_type;

  my_vector(int n);

  // Copy Constructor from type itself
  my_vector(my_vector &);

  // Constructor from generic vector
  template <typename Vector>
  my_vector(Vector &);

  // Assignment operator
  my_vector &operator=(my_vector const &v);

  // Assignment for generic Vector
  template <typename Vector>
  my_vector &operator=(Vector const &v);

  value_type &operator()(int i);
  int size() const;
  value_type operator()(int i) const;
};

```

Make an expression for a scalar multiplied with a vector:

```c++
template <typename Scalar, typename Vector>
class scalar_times_vector_expression {};

template <typename Scalar, typename Vector>
scalar_times_vector_expressions<Scalar, Vector> operator*(Scalar const &s,
                                                          Vector const &v) {
  return scalar_times_vector_expressions<Scalar, Vector>(s, v);
}

```

Put all classes and functions in the namespace math . You can also create an expression
template for the addition of two vectors. Write a small program, e.g.:

```c++
int main() {
  math::my_vector v(5);
  //  ... Fill in some values of v...
  math::my_vector w(5);
  w = 5.0 * v;
  w = 5.0 * (7.0 * v);
  w = v + 7.0 * v; // ( If you have added the operator +)
}

```
Use the debugger to see what happens.

## 5.5.5 Meta-List

Create a list of types. Implement the meta-functions `insert`, `append`, `erase`, and `size`.
