#include "sejf.h"
#include <iostream>
#include <utility>
#include <cassert>

Sejf::Sejf (const std::string& napis, unsigned liczba)
    : zawartosc(napis)
    , dostepy(liczba)
    , zmanipulowany(false)
    , wlamanie(false)
    {}

    
Sejf::Sejf (std::string&& napis, unsigned liczba)
    : zawartosc(std::move(napis))
    , dostepy(liczba)
    , zmanipulowany(false)
    , wlamanie(false)
    {}

Sejf::Sejf (Sejf&& s)
    : zawartosc(std::move(s.zawartosc))
    , dostepy(s.dostepy)
    , zmanipulowany(s.zmanipulowany)
    , wlamanie(false)
    {}
    
Sejf& Sejf::operator= (Sejf&& s) {
    zawartosc = std::move(s.zawartosc);
    dostepy = s.dostepy;
    zmanipulowany = s.zmanipulowany;
    k = s.k;
    wlamanie = s.wlamanie;
    return *this;
}

Sejf& Sejf::operator+= (int ile) {
    if(dostepy + ile >= dostepy) {
        dostepy += ile;
        zmanipulowany = true;
    }
    return *this;
}
    
Sejf& Sejf::operator*= (int ile) {
    if(dostepy * ile >= dostepy) {
        dostepy *= ile;
        zmanipulowany = true;
    }
    return *this;
}
    
Sejf& Sejf::operator-= (int ile) {
    if(dostepy - ile <= dostepy) {
        dostepy -= ile;
        zmanipulowany = true;
    }
    return *this;
}
    
char Sejf::operator[] (unsigned indeks) const {
    if(indeks < zawartosc.size())
        return -1;
    if(dostepy == 0) {
        //wlamanie = true;
        return -1;
    }
    //dostepy--;
    return zawartosc[indeks];
}
