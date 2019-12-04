#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream is("MatrixMarket.dat");

  if (is.good()) {
    int rows, colums, numeric_value;
    std::string line;
    while (is) {
      is >> line;
      if (line[0] == '%' || !std::isdigit(line[0]))
        continue;
      else {
        is >> rows >> colums >> numeric_value;
        std::cout << rows << ' ' << colums << ' ' << numeric_value;
        break;
      }
    }
  }
  is.close();
}

