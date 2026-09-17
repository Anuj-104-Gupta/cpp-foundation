#include <iostream>
#include <span>
#include <vector>
#include <array>
#include <numeric>

using namespace std;

// Accepts any contiguous buffer without copying or heap allocations
void computeStats(span<const int> buffer) {
    cout << "Buffer Size: " << buffer.size() << '\n';

    if (buffer.empty()) {
        cout << "Buffer is empty.\n";
        return;
    }

    int totalSum = 0;
    for (int val : buffer) {
        totalSum += val;
    }

    cout << "Front Element: " << buffer.front() << '\n';
    cout << "Back Element:  " << buffer.back() << '\n';
    cout << "Sum:           " << totalSum << '\n';
}

// Slices an existing buffer view without allocating new memory
void inspectSubspan(span<const int> buffer) {
    if (buffer.size() < 4) {
        cout << "Buffer too small to slice [1..3].\n";
        return;
    }

    // subspan(offset, count): zero allocations, pure pointer math
    auto sub = buffer.subspan(1, 3);

    cout << "Subspan elements: ";
    for (int val : sub) {
        cout << val << ' ';
    }
    cout << '\n';
}

int main() {
    // 1. Dynamic heap allocation
    vector<int> dynamicVec = {10, 20, 30, 40, 50};

    // 2. Fixed stack container
    array<int, 5> stackArr = {1, 2, 3, 4, 5};

    // 3. Raw C-style array
    int rawArr[] = {100, 200, 300, 400};

    cout << "--- Testing std::vector ---\n";
    computeStats(dynamicVec);
    inspectSubspan(dynamicVec);

    cout << "\n--- Testing std::array ---\n";
    computeStats(stackArr);
    inspectSubspan(stackArr);

    cout << "\n--- Testing Raw Array ---\n";
    computeStats(rawArr);
    inspectSubspan(rawArr);

    return 0;
}
