#include "../3.11.5/odditerator.h"
#include <iostream>

namespace mine {

class odd_range {
public:
  odd_range(int b, int e) {
    mb = b;
    me = e;
  }

  odd_iterator begin() {
    odd_iterator b(mb);
    return b;
  }

  odd_iterator end() {
    odd_iterator e(me);
    return e;
  }

private:
  int mb, me;
};

} // namespace mine

int main() {
  using namespace mine;

  for (int i : odd_range(7, 27))
    std ::cout << i << '\n';
}

