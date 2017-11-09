#include "sejf.h"
#include <iostream>

int main(){
    Sejf s = Sejf("abcd");
    Sejf::Kontroler k = s.kontroler();
    std::cout << k;
    s += 1;
    std::cout << k;
    for(int i = 0; i < 50; i++){
        s[2];
    }
    std::cout << k;
}