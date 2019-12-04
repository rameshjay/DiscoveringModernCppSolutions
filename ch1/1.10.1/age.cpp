#include <fstream>
#include <iostream>
#include <ostream>

void write_message(std::ostream &os, int i) { os << i << '\n'; }

int main() {
  std::cout << "What is your age?";

  int age;
  std::cin >> age;

  write_message(std::cout, age);

  std::ofstream filestream("outputfile.txt");

  if (filestream.good())
    write_message(filestream, age);

  filestream.close();

  return 0;
}

