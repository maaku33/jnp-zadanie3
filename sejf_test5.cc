#include "sejf.h"
#include <iostream>
#include <cassert>

int main() {
    Sejf s1("zawartosc", 1);
    Sejf s2("zawartosc", 0);

    auto k = s1.kontroler();
    std::swap(s1, s2);
    assert(!k);
}
