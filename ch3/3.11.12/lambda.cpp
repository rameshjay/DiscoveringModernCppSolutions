#include <cmath>
#include <iostream>

template <typename F, typename T>
class derivative {
public:
  derivative(const F &f, const T &h) : f(f), h(h) {}

  T operator()(T x) { return (f(x + h) - f(x)) / h; }

private:
  const F &f;
  T h;
};

template <typename F, typename T, unsigned N>
class nth_derivative {
public:
  using prev_derivative = nth_derivative<F, T, N - 1>;

  nth_derivative(const F &f, const T &h) : h(h), fp(f, h){};

  T operator()(T x) {
    return N & 1 ? (fp(x + h) - fp(x)) / h : (fp(x) - fp(x - h)) / h;
  }

private:
  T h;
  prev_derivative fp;
};

template <typename F, typename T>
class nth_derivative<F, T, 1> : public derivative<F, T> {
  using derivative<F, T>::derivative;
};

template <unsigned N, typename F, typename T>
nth_derivative<F, T, N> make_nth_derivative(const F &f, const T &h) {
  return nth_derivative<F, T, N>(f, h);
}

int main() {
  auto f = [](double x) { return (2 * std::cos(x)) + std::pow(x, 2); };

  // auto f_prime = make_nth_derivative<1>(
  //   [](double x) { return (2 * std::cos(x)) + std::pow(x, 2); }, 0.0001);

  auto f_prime = make_nth_derivative<1>(f, 0.0001);
  std::cout << f_prime(10) << '\n'; // x=10 for −2(sin(x) − x)

  auto f_prime2 = make_nth_derivative<2>(f, 0.0001);
  std::cout << f_prime2(10) << '\n'; //  x=10 for  −2(cos(x) − 1)
}
