#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename Range>
void print_interval(const Range &r, std::ostream &os = std::cout) {
  using std::begin;
  using std::end;

  os << '[';

  for (const auto &item : r) {
    os << item << ' ';
  }

  os << ']' << '\n';
}

struct cmp_fn {
  bool operator()(const double x, const double y) {
    return std::fabs(x) < std::fabs(y);
  }
};

int main() {
  std::vector<double> dv{-9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2};

  std::sort(dv.begin(), dv.end(), [](const double x, const double y) {
    return std::fabs(x) < std::fabs(y);
  });

  print_interval(dv);

  dv = {-9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2};

  cmp_fn f;
  std::sort(dv.begin(), dv.end(), f);

  print_interval(dv);
}
