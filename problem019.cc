#include <iostream>
#include <vector>
#include <cstdint>

bool is_leap(const std::uint16_t &year);
std::uint16_t next_cal_id(const std::uint16_t &cal_id, const bool &next_leap);
std::vector<std::uint16_t> &&lookup();

int main(int argc, char **argv) {
  std::vector<std::uint16_t> year_count = lookup();
  std::uint16_t cal_id = 2;
  std::uint16_t res = 0;
  for (int i = 1901; i < 2001; ++i) {
    res += year_count[cal_id];
    cal_id = next_cal_id(cal_id, is_leap(i + 1));
  }
  std::cout << res << '\n';
  return 0;
}

/**
 * Returns true if the year is a leap year.
 *
 * @param year The year for which one wants to know if it is a leap year.
 * @return true if the given year is a leap year
 */
bool is_leap(const std::uint16_t &year) {
  if (!(year % 100) && (year % 400))
    return false;
  return !(year % 4);
}

/**
 * Computes the next calendar id based on the following rule:
 * the id mod 7 indicates the first day of the year, so if
 * cal_id mod 7 == 0, the first day of this calendar id is sunday.
 * if cal_id > 6, then it is a leap year.
 *
 * It uses the fact that there are only 14 different calendars. Two
 * for each day of the year, leap and not leap.
 *
 * @param cal_id The calendar id of the current year.
 * @param next_leap True if the next year is a leap year.
 * @return The calendar id of the year that comes after cal_id.
 */
std::uint16_t next_cal_id(const std::uint16_t &cal_id, const bool &next_leap) {
  std::uint16_t days_count = cal_id < 7u ? 365u : 366u; // How many days this
                                                        // year had
  std::uint16_t next = (cal_id + days_count) % 7; // Whis is the first day of
                                                  // the next year?
  if (next_leap) // compute the final calendar id
    next += 7;
  return next;
}

/**
 * Returns how many sunday are the first of their month.
 */
std::uint16_t count_sundays_begin_month(std::uint16_t cal_id) {
  std::vector<std::uint16_t> days_per_month =
      {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  std::uint16_t first_day_of_year = cal_id % 7u;
  days_per_month[1] = cal_id < 7u ? 28u : 29u;
  cal_id %= 7;
  std::uint16_t res = 0;
  for (auto it = days_per_month.begin(); it != days_per_month.end(); ++it) {
    if (cal_id == 0)
      ++res;
    cal_id = (cal_id + *it) % 7;
  }
  return res;
}

std::vector<std::uint16_t> &&lookup() {
  std::vector<std::uint16_t> res;
  for (int i = 0; i < 14; ++i)
    res.push_back(count_sundays_begin_month(i));
  return res;
}

