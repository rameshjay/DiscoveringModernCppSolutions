#include "odditerator.h"
#include <cassert>

int main() {
  using namespace mine;

  odd_iterator a;
  assert(*(a) == 1);

  // odd_iterator b(4); // throws
  odd_iterator b(3);
  assert(*b == 3);

  odd_iterator c(b);
  assert(c == b);

  odd_iterator d;
  d = c;
  assert(d == c);

  odd_iterator e;
  assert(*(e) == 1);
  assert(*(++e) == 3);
  assert(*(e++) == 3);
  assert(*e == 5);

  d = e;
  ++d;
  assert(e != d);
}
