#include <iostream>
#include <tuple>
#include <set>
#include <unordered_map>

int gcd(int a, int b);
std::set<std::tuple<int, int, int>> GeneratePrimitiveTuple(int limit);

int main(int argc, char **argv) {
    auto tuples = GeneratePrimitiveTuple(100);
    std::unordered_map<unsigned, unsigned> solutions;
    for (const auto &tuple : tuples) {
        auto sum = std::get<0>(tuple) + std::get<1>(tuple) + std::get<2>(tuple);
        auto k = 1;
        while (k * sum < 1000) {
            if (solutions.find(k * sum) == solutions.end())
                solutions.insert(std::make_pair(k * sum, 0));
            solutions[k * sum] += 1;
            ++k;
        }
    }
    unsigned p = 0;
    unsigned max_sum = 0;
    for (auto sol : solutions) {
        if (sol.second > max_sum) {
            max_sum = sol.second;
            p = sol.first;
        }
    }
    std::cout << p << '\n';
    return 0;
}

std::set<std::tuple<int, int, int>> GeneratePrimitiveTuple(int limit) {
    std::set<std::tuple<int, int, int>> res;
    for (int m = 2; m < limit; ++m) {
        for (int n = 1; n < m; ++n) {
            if (gcd(m, n) == 1 && (m - n) % 2) {
                auto a = m*m - n*n;
                auto b = 2 * m * n;
                if (b < a)
                    std::swap(a, b);
                res.insert(std::make_tuple(a, b, m * m + n * n));
            }
        }
    }
    return res;
}

int gcd(int a, int b) {
    while (b) {
        auto tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
