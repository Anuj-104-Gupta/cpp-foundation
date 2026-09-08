#include <iostream>
#include <string>
#include <vector>

// ==========================================
// Target 1: Variadic Print with Fold Expressions (§5.5)
// ==========================================
template<typename... Args>
void printSeparated(const std::string& separator, const Args&... args) {
    bool first = true;
    // Comma fold expression expanding across every argument in the pack
    ((std::cout << (first ? "" : separator) << args, first = false), ...);
    std::cout << '\n';
}

// ==========================================
// Target 2: Fold-Expression Math Aggregator (§5.5)
// ==========================================

// Logical AND fold: checks if all arguments satisfy (arg > 0)
template<typename... Args>
bool allPositive(const Args&... args) {
    return (... && (args > 0));
}

// Binary multiplication fold: computes (a * b * c * ...)
template<typename... Args>
auto product(const Args&... args) {
    return (... * args);
}

// ==========================================
// Target 3: CTAD and Deduction Guides (§5.7)
// ==========================================
template<typename Iter>
struct Range {
    Iter first;
    Iter last;

    Range(Iter f, Iter l) : first{f}, last{l} {}

    // Iterator interface to support range-based for loops
    Iter begin() const { return first; }
    Iter end() const { return last; }
};

// Deduction guide: map a standard container reference directly to Range<Iterator>
template<typename Container>
Range(Container& c) -> Range<typename Container::iterator>;

// ==========================================
// Main Verification Suite
// ==========================================
int main() {
    std::cout << boolalpha;

    std::cout << "--- Target 1: Fold Expression Formatter ---\n";
    printSeparated(" | ", 42, "C++20", 3.14159, 'Z', true);

    std::cout << "\n--- Target 2: Fold Math Operations ---\n";
    std::cout << "allPositive(1, 4, 10.5, 0.2): " 
              << allPositive(1, 4, 10.5, 0.2) << '\n'; // true
    std::cout << "allPositive(5, -2, 8): " 
              << allPositive(5, -2, 8) << '\n';        // false

    std::cout << "product(2, 3, 4, 0.5): " 
              << product(2, 3, 4, 0.5) << '\n';        // 12

    std::cout << "\n--- Target 3: CTAD Range Wrapper ---\n";
    std::vector<int> nums = {10, 20, 30, 40, 50};

    // CTAD automatically deduces Range<std::vector<int>::iterator>
    Range r{nums};

    std::cout << "Range contents: ";
    for (int x : r) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    return 0;
}
