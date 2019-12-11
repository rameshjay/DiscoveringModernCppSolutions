#include <cmath>
#include <iostream>

template <typename F, typename T>
double trapezoid(F f, T a, T b) {
  int n = 10000;
  double h = (b - a) / n;

  double subsum{};
  for (int j = 1; j <= n - 1; ++j) {
    subsum += f(a + (j * h));
  }

  // clang-format off
  return (h/2)*f(a) + (h/2)*f(b) + (h*subsum);
  // clang-format on
}

double exp3f(double x) { return std::exp(3.0 * x); }

struct exp3t {
  double operator()(double x) const { return std::exp(3.0 * x); }
};

struct conditional_func {
  double operator()(double x) {
    if (x < 1)
      return std::sin(x);
    else
      return std::cos(x);
  }
};

int main() {
  std::cout << trapezoid(exp3f, 0.0, 4.0) << '\n';

  exp3t t;
  std::cout << trapezoid(t, 0.0, 4.0) << '\n';

  conditional_func f;
  std::cout << trapezoid(f, 0.0, 4.0) << '\n';

  //  std::cout << trapezoid(std::sin, 0.0, 2.0) << '\n'; // fails
}
