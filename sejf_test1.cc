#include "sejf.h"
#include <iostream>

int main() {
    Sejf s("aaa", 3);
    char x = s[0];
    std::cout << x << std::endl;
    //std::cout << s[0] << std::endl;
    //assert(s[0] == 'a');
    //assert(s[5] == -1);
    return 0;
}