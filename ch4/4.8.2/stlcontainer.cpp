#include <map>
#include <string>
#include <algorithm>
#include <iostream>

int main() {

  // phone number randomly generated from https://fakenumber.org/
  // user names randomly generated https://www.name-generator.org.uk/quick/

  std::map<std::string, unsigned long> phone_book{
      {"Mai Shepard", 202'555'0161},
      {"Harper-Rose Rodrigues", 202'555'0117},
      {"Zoha Ferry", 202'555'0330},
      {"Lacey Moreno", 202'555'0134}};

  std::map<std::string, unsigned long>::iterator result =
      phone_book.find("Mai Shepard");

  if (result != phone_book.end()) {
    // auto [name, phone] = *result; // c++17
    std::cout << result->first << ' ' << phone_book.at("Mai Shepard") << '\n';
  } else {
    std::cout << "Such person not exist in records\n";
  }

  auto result2 = phone_book.find("Asiyah Vega");

  // if (auto result2 = phone_book.find("Asiyah Vega"); result2 !=
  // phone_book.end()) //C++17

  if (result2 != phone_book.end()) {
    std::cout << result2->first << ' ' << result2->second << '\n';
  } else {
    std::cout << "Such person not exist in records\n";
  }

  auto result3 = std::find_if(
      phone_book.begin(), phone_book.end(),
      [](const auto &record) { return record.second == 202'555'0330; });

  if (result3 != phone_book.end()) {
    std::cout << result3->first << ' ' << result3->second << '\n';
  } else {
    std::cout << "Such person not exist in records\n";
  }

  auto result4 = std::find_if(
      phone_book.begin(), phone_book.end(),
      [](const auto &record) { return record.second == 202'555'0113; });

  if (result4 != phone_book.end()) {
    std::cout << result4->first << ' ' << result4->second << '\n';
  } else {
    std::cout << "Such person not exist in records\n";
  }
}
