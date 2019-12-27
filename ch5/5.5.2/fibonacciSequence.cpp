#include <type_traits>

namespace mine {

template <typename T>
struct is_integer : std::false_type {};

template <>
struct is_integer<int> : std::true_type {};

template <typename T>
const bool is_integer_v = is_integer<T>::value;

template <typename T, typename = std::enable_if_t<is_integer_v<T>>>
constexpr T fibonacci(T n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

} // namespace mine

int main() {
  static_assert(mine::fibonacci<int>(0) == 0, "");
  static_assert(mine::fibonacci<int>(1) == 1, "");
  static_assert(mine::fibonacci<int>(2) == 1, "");
}

