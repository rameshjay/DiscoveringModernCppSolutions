#include <stdexcept>
#include <exception>
#include <cassert>

class odd_iterator {
public:
  odd_iterator() { i = 1; }

  explicit odd_iterator(int val) {
    if (val % 2 == 0) {
      throw "\"Help me...I'm feeling\" - Grinch";
    } else {
      i = val;
    }
  }

  odd_iterator(odd_iterator &other) { i = other.i; }

  odd_iterator &operator=(odd_iterator &other) {
    i = other.i;
    return *this;
  }

  odd_iterator operator++() {
    i += 2;
    return *this;
  }

  odd_iterator operator++(int dummy) {
    odd_iterator tmp = *this;
    ++(*this);
    return tmp;
  }

  int operator*() { return i; }

  bool operator==(const odd_iterator &other) { return i == other.i; }

  bool operator!=(const odd_iterator &other) { return !(*this == other); }

private:
  int i;
};

int main() {
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
