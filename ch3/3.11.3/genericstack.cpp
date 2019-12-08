#include <cstdint>
#include <vector>
#include <stdexcept>
#include <cassert>

namespace mine {
template <typename T>
class stack {
public:
  stack() { m_data.reserve(m_capacity); }

  T top() { return m_data.at(m_data.size() - 1); }

  void pop() {
    if (empty()) {
      throw std::underflow_error("Stack under flowed");
    } else {
      m_data.pop_back();
    }
  }

  void push(const T &element) {
    if (full()) {
      throw std::overflow_error("Stack over flowed");
    } else {
      m_data.push_back(element);
    }
  }

  void clear() { m_data.clear(); }
  void size() { return m_data.size(); }

  bool full() const noexcept { return m_capacity == m_data.size(); }
  bool empty() const noexcept { return 0 == m_data.size(); }

private:
  std::size_t m_capacity = 10; // hard wired capacity
  std::vector<T> m_data;
};
} // namespace mine

int main() {
  mine::stack<int> is;

  for (int i = 0; i < 10; ++i) {
    is.push(i);
  }
  // is.push(10); // overflow

  assert(is.full() == true);
  assert(is.top() == 9);

  for (int i = 0; i < 10; ++i) {
    is.pop();
  }
  assert(is.empty() == true);
  // is.pop(); // undeflow

  is.push(10);
  is.clear();
  assert(is.empty() == true);
}
