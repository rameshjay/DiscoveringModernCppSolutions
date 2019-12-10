namespace mine {

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

  odd_iterator(const odd_iterator &other) { i = other.i; }

  odd_iterator &operator=(const odd_iterator &other) {
    i = other.i;
    return *this;
  }

  odd_iterator &operator++() {
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

} // namespace mine
