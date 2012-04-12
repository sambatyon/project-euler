#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <set>
#include <string>

typedef std::set<std::pair<unsigned, unsigned> > factors;

std::vector<factors> create_factor_lookup(const unsigned &limit);
inline
factors multiply_exp(const factors &fact, const unsigned &alpha);
inline
std::string hash(const factors &fact);

int main(int argc, char **argv) {
  std::vector<factors> lookup = create_factor_lookup(101u);
  std::set<std::string> counter;
  for (unsigned a = 2u; a <= 100u; ++a)
    for (unsigned b = 2u; b <= 100u; ++b)
      counter.insert(hash(multiply_exp(lookup[a], b)));
  std::cout << counter.size() << '\n';

  return 0;
}


inline
std::string hash(const factors &fact) {
  std::stringstream str;
  for (auto f : fact)
    str << f.first << "^" << f.second << " ";
  return str.str();
}

inline
factors multiply_exp(const factors &fact, const unsigned &alpha) {
  factors res;
  for (auto p : fact)
    res.insert(std::make_pair(p.first, alpha * p.second));
  return res;
}

/**
 * Uses the primes generator algorithm from TAOCP vol. 1
 */
std::vector<unsigned> gen_primes(const unsigned &max) {
  unsigned n = 3;
  std::vector<unsigned> primes;
  primes.push_back(2);
  primes.push_back(n);
  while (n <= max) {
    n += 2;
    for (unsigned k = 1; k < primes.size(); ++k) {
      if (n % primes[k] == 0)
        break;
      if (n / primes[k] <= primes[k]) {
        primes.push_back(n);
        break;
      }
    }
  }
  return primes;
}

factors factorize(unsigned number) {
  static std::vector<unsigned> primes = gen_primes(100u);
  int i = 0;
  factors res;
  while (number != 1) {
    unsigned exponent = 0;
    while (number % primes[i] == 0) {
      number /= primes[i];
      ++exponent;
    }
    if (exponent)
      res.insert(std::make_pair(primes[i], exponent));
    ++i;
  }
  return res;
}

std::vector<factors> create_factor_lookup(const unsigned &limit) {
  std::vector<factors> factor_lookup;
  factors tmp;
  // zero and one are not used, but this simplifies computations
  factor_lookup.push_back(tmp);
  factor_lookup.push_back(tmp);
  for (unsigned i = 2u; i < limit; ++i)
    factor_lookup.push_back(factorize(i));
  return factor_lookup;
}

