#include <initializer_list>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iostream>

class polynomial {
public:
  polynomial() = default;
  explicit polynomial(double pol_degree_) { m_degree = pol_degree_; }
  polynomial(std::initializer_list<double> il) {
    m_coefficients.assign(il.begin(), il.end());
  }
  ~polynomial() = default;

  // assumption: both polynomial functions are ordered with degress
  // assumption: both have same number of args
  // clang-format off
  polynomial &operator+=(const polynomial &rhs) {
    std::transform(m_coefficients.begin(), m_coefficients.end(),
       rhs.m_coefficients.begin(), m_coefficients.begin(),
                   std::plus<double>());
    return *this;
  }

  polynomial &operator-=(const polynomial &rhs) {
    std::transform(m_coefficients.begin(), m_coefficients.end(),
       rhs.m_coefficients.begin(), m_coefficients.begin(),
                   std::minus<double>());
    return *this;
  }

  // clang-format on
  friend std::ostream &operator<<(std::ostream &os, const polynomial &p);

  std::vector<double> m_coefficients{};
  double m_degree{};
};

std::ostream &operator<<(std::ostream &os, const polynomial &p) {
  if (!p.m_coefficients.empty()) {
    std::for_each(p.m_coefficients.begin(), p.m_coefficients.end(),
                  [&os](const auto coefficient) {
                    if (coefficient != 0) {
                      char sign;
                      coefficient < 0 ? sign = '-' : sign = '+';
                      os << coefficient << 'x' << '^' << 'n' << sign;
                    }
                  });
  }

  return os;
}

int main() {
  polynomial a{1, 2, 3};
  polynomial b{1, 2, 3};
  a += b;
  std::cout << a;
}
