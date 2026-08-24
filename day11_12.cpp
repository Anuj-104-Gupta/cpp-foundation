#include <iostream>
#include <utility>
using namespace std;
class DynamicArray {
private:
    int* data;
    size_t sz;
public:
    DynamicArray(size_t size, int init_val = 0)
        : data(new int[size]), sz(size) {
        for (size_t i = 0; i < sz; i++) {
            data[i] = init_val;
        }
        cout << "[Constructor] Allocated array of size " << sz << " at " << data << "\n";
    }
    ~DynamicArray() {
        cout << "[Destructor] Freeing memory at " << data << "\n";
        delete[] data;
    }
    DynamicArray(const DynamicArray& other)
        : data(new int[other.sz]), sz(other.sz) {
        for (size_t i = 0; i < sz; i++) {
            data[i] = other.data[i];
        }
        cout << "[Copy Constructor] Deep copied from " << other.data << " to " << data << "\n";
    }
    DynamicArray& operator=(const DynamicArray& other) {
        cout << "[Copy Assignment] Called\n";
        if (this == &other) {
            return *this;
        }
        delete[] data;
        sz = other.sz;
        data = new int[sz];
        for (size_t i = 0; i < sz; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }
    DynamicArray(DynamicArray&& other) noexcept
        : data(other.data), sz(other.sz) {
        cout << "[Move Constructor] Stole buffer " << data << " from source\n";
        other.data = nullptr;
        other.sz = 0;
    }
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        cout << "[Move Assignment] Called\n";
        if (this == &other) {
            return *this;
        }
        delete[] data;
        data = other.data;
        sz = other.sz;
        other.data = nullptr;
        other.sz = 0;
        return *this;
    }
    size_t size() const { return sz; }
    int& operator[](size_t index) { return data[index]; }
    const int* get_data() const { return data; }
};

int main() {
    cout << "--- 1. Base Construction ---\n";
    DynamicArray a(3, 10);
    cout << "\n--- 2. Copy Construction ---\n";
    DynamicArray b = a;
    b[0] = 999;
    cout << "a[0]: " << a[0] << " (expected 10), b[0]: " << b[0] << " (expected 999)\n";

    cout << "\n--- 3. Copy Assignment ---\n";
    DynamicArray c(2, 5);
    c = a;
    cout << "\n--- 4. Move Construction ---\n";
    DynamicArray d = std::move(a);
    cout << "d.size(): " << d.size() << ", a.data pointer: " << a.get_data() << " (nullified)\n";
    cout << "\n--- 5. Move Assignment ---\n";
    c = move(b);
    cout << "c.size(): " << c.size() << ", b.data pointer: " << b.get_data() << " (nullified)\n";

    cout << "\n--- Destruction Phase ---\n";
    return 0;
}
