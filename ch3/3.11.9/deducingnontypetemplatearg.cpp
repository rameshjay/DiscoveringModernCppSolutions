#include <cstdint>
#include <cassert>

template <typename T, std::size_t N>
std::size_t array_size(const T (&arg)[N]) {
  return N;
}

int main() {
  int ia[16];
  assert(16 == array_size(ia));

  double da[32];
  assert(32 == array_size(da));

  struct complex {
    int re, im;
  };

  complex coor[2];

  assert(2 == array_size(coor));
}
