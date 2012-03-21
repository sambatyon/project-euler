#include <iostream>
#include <utility>
#include <string>
#include <map>

std::string string_of_number(const unsigned &x);
unsigned number_of_characters(const unsigned &x);

int main(int argc, char **argv) {
  unsigned acc = 0;
  for (unsigned i = 1; i <= 1000; ++i)
    acc += number_of_characters(i);
  std::cout << acc << '\n';
  return 0;
}

std::map<unsigned, unsigned> generate_count_map();

unsigned number_of_characters(const unsigned &x) {
  static std::map<unsigned, unsigned> lookup = generate_count_map();
  if (lookup.find(x) != lookup.end())
    return lookup[x];

  unsigned char_count = 0;

  if (x >= 0 && x < 20) {
    return lookup[x];
  } else if (x >= 20U && x < 100U) {
    if (x % 10U == 0) {
      return lookup[x];
    } else {
      char_count = lookup[x - x % 10U] + number_of_characters(x % 10U);
      lookup.insert(std::make_pair(x, char_count));
      return char_count;
    }
  } else if (x >= 100U && x < 1000U) {
    if (x % 100U == 0) {
      char_count = lookup[x / 100U] + 7U;
      lookup.insert(std::make_pair(x, char_count));
      return char_count;
    } else {
      char_count = lookup[x / 100U] + 10U + number_of_characters(x % 100U);
      lookup.insert(std::make_pair(x, char_count));
      return char_count;
    }
  } else if (x == 1000) {
    return 11U;
  } else {
    return 0;
  }
}

std::map<unsigned, unsigned> generate_count_map() {
  std::map<unsigned, unsigned> res;
  using namespace std;
  res.insert(make_pair(   0U, 4U)); // zero
  res.insert(make_pair(   1U, 3U)); // one
  res.insert(make_pair(   2U, 3U)); // two
  res.insert(make_pair(   3U, 5U)); // three
  res.insert(make_pair(   4U, 4U)); // four
  res.insert(make_pair(   5U, 4U)); // five
  res.insert(make_pair(   6U, 3U)); // six
  res.insert(make_pair(   7U, 5U)); // seven
  res.insert(make_pair(   8U, 5U)); // eight
  res.insert(make_pair(   9U, 4U)); // nine
  res.insert(make_pair(  10U, 3U)); // ten
  res.insert(make_pair(  11U, 6U)); // eleven
  res.insert(make_pair(  12U, 6U)); // twelve
  res.insert(make_pair(  13U, 8U)); // thirteen
  res.insert(make_pair(  14U, 8U)); // fourteen
  res.insert(make_pair(  15U, 7U)); // fifteen
  res.insert(make_pair(  16U, 7U)); // sixteen
  res.insert(make_pair(  17U, 9U)); // seventeen
  res.insert(make_pair(  18U, 8U)); // eighteen
  res.insert(make_pair(  19U, 8U)); // nineteen
  res.insert(make_pair(  20U, 6U)); // twenty
  res.insert(make_pair(  30U, 6U)); // thirty
  res.insert(make_pair(  40U, 5U)); // forty
  res.insert(make_pair(  50U, 5U)); // fifty
  res.insert(make_pair(  60U, 5U)); // sixty
  res.insert(make_pair(  70U, 7U)); // seventy
  res.insert(make_pair(  80U, 6U)); // eighty
  res.insert(make_pair(  90U, 6U)); // ninety
  res.insert(make_pair(1000U, 11U)); // one thousand
  return res;
}

std::map<unsigned, std::string> generate_map();

std::string string_of_number(const unsigned &x) {
  static std::map<unsigned, std::string> lookup = generate_map();
  if (x >= 0 && x < 20) {
    return lookup[x];
  } else if (x >= 20 && x < 100) {
    if (x % 10 == 0)
      return lookup[x];
    else
      return lookup[x - x % 10] + "-" + string_of_number(x % 10);
  } else if (x >= 100 && x < 1000) {
    if (x % 100 == 0)
      return lookup[x / 100] + " hundred";
    else
      return lookup[x / 100] + " hundred and " + string_of_number(x % 100);
  } else if (x == 1000) {
    return "one thousand";
  } else {
    return "unsuported number";
  }
}

std::map<unsigned, std::string> generate_map() {
  std::map<unsigned, std::string> res;
  using namespace std;
  res.insert(make_pair(   0U, string("zero")));
  res.insert(make_pair(   1U, string("one")));
  res.insert(make_pair(   2U, string("two")));
  res.insert(make_pair(   3U, string("three")));
  res.insert(make_pair(   4U, string("four")));
  res.insert(make_pair(   5U, string("five")));
  res.insert(make_pair(   6U, string("six")));
  res.insert(make_pair(   7U, string("seven")));
  res.insert(make_pair(   8U, string("eight")));
  res.insert(make_pair(   9U, string("nine")));
  res.insert(make_pair(  10U, string("ten")));
  res.insert(make_pair(  11U, string("eleven")));
  res.insert(make_pair(  12U, string("twelve")));
  res.insert(make_pair(  13U, string("thirteen")));
  res.insert(make_pair(  14U, string("fourteen")));
  res.insert(make_pair(  15U, string("fifteen")));
  res.insert(make_pair(  16U, string("sixteen")));
  res.insert(make_pair(  17U, string("seventeen")));
  res.insert(make_pair(  18U, string("eighteen")));
  res.insert(make_pair(  19U, string("nineteen")));
  res.insert(make_pair(  20U, string("twenty")));
  res.insert(make_pair(  30U, string("thirty")));
  res.insert(make_pair(  40U, string("forty")));
  res.insert(make_pair(  50U, string("fifty")));
  res.insert(make_pair(  60U, string("sixty")));
  res.insert(make_pair(  70U, string("seventy")));
  res.insert(make_pair(  80U, string("eighty")));
  res.insert(make_pair(  90U, string("ninety")));
  res.insert(make_pair(1000U, string("thousand")));
  return res;
}
