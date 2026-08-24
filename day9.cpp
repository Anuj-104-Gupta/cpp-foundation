#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

using namespace std;

// Target 1: Pure Abstract Interface
class Container {
public:
    virtual double& operator[](int i) = 0;
    virtual const double& operator[](int i) const = 0; // Const overload for read-only access
    virtual int size() const = 0;
    virtual ~Container() {} // Virtual destructor ensures proper dynamic cleanup
};

// Target 2: Vector_container (Contiguous Memory Implementation)
class Vector_container : public Container {
private:
    vector<double> v;

public:
    Vector_container(initializer_list<double> il) : v(il) {}

    double& operator[](int i) override {
        return v[i];
    }

    const double& operator[](int i) const override {
        return v[i];
    }

    int size() const override {
        return static_cast<int>(v.size());
    }

    ~Vector_container() override {
        // Automatically cleans up vector<double> v
    }
};

// Target 3: List_container (Node-based Linked List Implementation)
class List_container : public Container {
private:
    list<double> ld;

public:
    List_container(initializer_list<double> il) : ld(il) {}

    // Lists do not have O(1) random access; must traverse nodes
    double& operator[](int i) override {
        for (auto& x : ld) {
            if (i == 0) return x;
            i--;
        }
        throw out_of_range("List_container index out of bounds");
    }

    const double& operator[](int i) const override {
        for (const auto& x : ld) {
            if (i == 0) return x;
            i--;
        }
        throw out_of_range("List_container index out of bounds");
    }

    int size() const override {
        return static_cast<int>(ld.size());
    }

    ~List_container() override {}
};

// Target 4: Decoupled Polymorphic Consumer
void print_elements(const Container& c) {
    int sz = c.size();
    for (int i = 0; i < sz; i++) {
        cout << c[i] << " ";
    }
    cout << '\n';
}

int main() {
    Vector_container vc = {1.1, 2.2, 3.3, 4.4};
    List_container lc = {10.5, 20.5, 30.5};

    cout << "Vector_container: ";
    print_elements(vc); // Dispatches through Container vtable to Vector_container

    cout << "List_container: ";
    print_elements(lc);   // Dispatches through Container vtable to List_container

    // Dynamic allocation & virtual destructor test
    Container* dynamic_ptr = new Vector_container({100.0, 200.0});
    cout << "Dynamic Container: ";
    print_elements(*dynamic_ptr);
    delete dynamic_ptr; // Correctly calls ~Vector_container via vtable

    return 0;
}
