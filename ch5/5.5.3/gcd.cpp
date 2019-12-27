#include <iostream>

template <typename I>
constexpr I gcd(I a, I b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

template <int A, int B>
struct gcd_meta {
  static int const value = gcd(A, B);
};

int main() {
  static_assert(gcd_meta<10, 0>::value == 10, "");
  static_assert(gcd_meta<10, 11>::value == 1, "");
  static_assert(gcd_meta<10, 100>::value == 10, "");
}
