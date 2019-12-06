#include <cstdint>
#include <algorithm>
#include <cassert>

namespace mine {

template <typename T>
class vector {
public:
  using iterator = T *;
  using const_iterator = const iterator;

  vector(std::initializer_list<T> il) {
    m_size = il.size();
    m_data = new T[m_size];
    std::copy(il.begin(), il.end(), begin());
  }

  ~vector() { delete[] m_data; }

  iterator begin() { return m_data; }
  const_iterator begin() const noexcept { return m_data; }

  iterator end() { return m_data + m_size; }
  const_iterator end() const noexcept { return m_data + m_size; }

private:
  std::size_t m_size{};
  T *m_data{};
};

} // namespace mine

int main() {
  mine::vector<int> iv{2, 0, 1};

  std::sort(iv.begin(), iv.end());

  assert(*iv.begin() == 0);
  assert(*(iv.end() - 1) == 2);
}
