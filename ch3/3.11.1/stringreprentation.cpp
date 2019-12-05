#include <string>
#include <cassert>
#include <sstream>

namespace mine {

template <typename T>
std::string to_string(const T &t) {
  std::stringstream ss;

  ss << t;
  return ss.str();
}

// C++11, need to make recursive call
template <typename T, typename... Args>
std::string to_string(const T &t, const Args &... args) {
  std::stringstream ss;

  ss << t << to_string(args...);
  return ss.str();
}

// C++17
template <typename... Args>
std::string to_string2(const Args &... args) {
  std::stringstream ss;

  (ss << ... << args);
  return ss.str();
}

} // namespace mine

int main() {
  assert("c1111.11.1something" ==
         mine::to_string('c', 1, 1l, 1ul, 1.1, 1.1f, "something"));

  assert("c1111.11.1something" ==
         mine::to_string2('c', 1, 1l, 1ul, 1.1, 1.1f, "something"));
}

