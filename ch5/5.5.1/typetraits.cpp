#include <type_traits>
#include <iostream>

namespace mine {

template <typename T>
struct remove_reference final {
  using type = T;
};

template <typename T>
struct remove_reference<T &> final {
  using type = T;
};

template <typename T>
using remove_reference_t = typename remove_reference<T>::type;

template <typename T>
struct add_reference final {
  using type = T &;
};

template <typename T>
using add_reference_t = typename add_reference<T>::type;

template <typename T, typename U>
bool is_same_v = std::is_same<T, U>::value;

} // namespace mine

int main() {
  using namespace mine;

  std::cout << is_same_v<remove_reference_t<const int &>, const int>;
  std::cout << is_same_v<add_reference_t<int>, int &>;
}
