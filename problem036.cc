#include <iostream>
#include <cstdint>
#include <cmath>

// TODO: Redo 035 using 010 to generate primes. Dont use strings

int FindFirstOne(std::uint32_t number);
int GetBit(std::uint32_t number, std::uint16_t index);
bool IsBinaryPalindrome(std::uint32_t number);
int FindHighestPower(std::uint32_t number);
int GetElementAtPower(std::uint32_t number, int power);
bool IsDecimalPalindrome(std::uint32_t number);

int main(int argc, char **argv) {
    auto sum = 0;
    for (auto i = 0; i < 1000000; ++i)
        if (IsDecimalPalindrome(i) && IsBinaryPalindrome(i))
            sum += i;
    std::cout << sum << '\n';
    return 0;
}

bool IsDecimalPalindrome(std::uint32_t number) {
    auto high = FindHighestPower(number);
    auto low = 1;
    while (high > low) {
        if (GetElementAtPower(number, high) != GetElementAtPower(number, low))
            return false;
        high /= 10;
        low *= 10;
    }
    return true;
}

// power must be a non zero multiple of 10, I could use integers, but it may require more evaluations
int GetElementAtPower(std::uint32_t number, int power) {
    auto res = (number % (power * 10));
    return res / power;
}

int FindHighestPower(std::uint32_t number) {
    return number ? static_cast<unsigned>(std::ceil(std::pow(10, static_cast<unsigned>(std::log10(number))))) : -1;
}

int GetBit(std::uint32_t number, std::uint16_t index) {
    return (1 << index) & number ? 1 : 0;
}

bool IsBinaryPalindrome(std::uint32_t number) {
    auto i = FindFirstOne(number);
    auto j = 0;
    while (i > j) {
        if (GetBit(number, i) != GetBit(number, j))
            return false;
        ++j;
        --i;
    }
    return true;
}

int FindFirstOne(std::uint32_t number) {
    if (!number)
        return -1;
    int pos = 0;
    if (number <= 0xFFFF) {
        pos += 16;
        number <<= 16;
    }
    if (number <= 0xFFFFFF) {
        pos += 8;
        number <<= 8;
    }
    if (number <= 0xFFFFFFF) {
        pos += 4;
        number <<= 4;
    }
    if (number <= 0x3FFFFFFF) {
        pos += 2;
        number <<= 2;
    }
    if (number <= 0x7FFFFFFF) {
        pos += 1;
    }
    return 31 - pos;
}
