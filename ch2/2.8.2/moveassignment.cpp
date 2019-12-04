#include <initializer_list>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iostream>

class polynomial {
public:
  polynomial() = default;
  explicit polynomial(double pol_degree_) { m_degree = pol_degree_; }

  ~polynomial() = default;

  polynomial(double c1, double c2, double c3) {
    m_coefficients.push_back(c1);
    m_coefficients.push_back(c2);
    m_coefficients.push_back(c3);
  }

  polynomial &operator=(const polynomial &rhs) = default;

  polynomial &operator=(polynomial &&rhs) {
    m_coefficients = std::move(rhs.m_coefficients);
    std::cout << "Moved!!!\n";
    return *this;
  }

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

polynomial f(double c2, double c1, double c0) { return {c0, c1, c2}; }

int main() {
  polynomial p;
  p = f(1, 2, 3);
  std::cout << p;
}
