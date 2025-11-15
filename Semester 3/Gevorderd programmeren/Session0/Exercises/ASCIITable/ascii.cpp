#include <iostream>

int main() {
    for (int i = 0; i < 256; i++) {
        std::cout << "int = " << i << ", char = " << char(i) << std::endl;
    }
}
