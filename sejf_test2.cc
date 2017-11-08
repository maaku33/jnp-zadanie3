#include "sejf.h"
#include <iostream>
#include <cassert>

int main() {
    Sejf s1("Hello", 3);
    assert(s1[1] == 'e');
    
    Sejf s2 = std::move(s1);
    auto k2 = s2.kontroler();

    int i = 2;
    while (k2) {
        assert(s2[0] == 'H');
        assert(i > 0);

        i--;
    }
}