#include <memory>
#include <utility>
#include <cassert>

namespace mine {

/*
template <class... Ts>
std::unique_ptr<T> make_unique2(Ts &&... t) {
return new Ts(std::forward<Ts>(t)...);
}
*/

// Confession: lookup to std::forward in cppreference and
// come across the answer itself, my not working version is commented.

template <class T, class... U>
std::unique_ptr<T> make_unique(U &&... u) {
  return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}

} // namespace mine

int main() {
  auto up = mine::make_unique<int>(3);
  assert(*up == 3);

  int *p = up.get();
  assert(*p == 3);
}
