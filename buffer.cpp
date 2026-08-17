#include <iostream>
#include "buffer.h"
#include <stdexcept>

namespace CoreSystems {

void append(Buffer& buf, int val) {
    if (buf.capacity > buf.length) {
        buf.data[buf.length] = val;
        buf.length++;
    }
    else {
        throw std::out_of_range("Buffer is Full");
    }
}

int get(const Buffer& buf, size_t index) {
    if (index < buf.length) {
        return buf.data[index];
    }
    else {
        throw std::out_of_range("Given Index is not within range");
    }
}

}
