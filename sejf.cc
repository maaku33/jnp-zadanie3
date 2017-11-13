#include "sejf.h"
#include <iostream>
#include <utility>
#include <cassert>

const unsigned DOMYSLNE_DOSTEPY = 42;

Sejf::Sejf (const std::string& napis, unsigned liczba)
    : zawartosc(napis)
    , dostepy(liczba)
    , zmanipulowany(false)
    , wlamanie(false)
    {}

Sejf::Sejf (const std::string& napis)
    : zawartosc(napis)
    , dostepy(DOMYSLNE_DOSTEPY)
    , zmanipulowany(false)
    , wlamanie(false)
    {}


Sejf::Sejf (std::string&& napis, unsigned liczba)
    : zawartosc(std::move(napis))
    , dostepy(liczba)
    , zmanipulowany(false)
    , wlamanie(false)
    {}

Sejf::Sejf (std::string&& napis)
    : zawartosc(std::move(napis))
    , dostepy(DOMYSLNE_DOSTEPY)
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
    wlamanie = s.wlamanie;
    return *this;
}

Sejf& Sejf::operator+= (int ile) {
    if (dostepy + ile >= dostepy) {
        dostepy += ile;
        zmanipulowany = true;
    }
    return *this;
}

Sejf& Sejf::operator*= (int ile) {
    if (dostepy * ile >= dostepy) {
        dostepy *= ile;
        zmanipulowany = true;
    }
    return *this;
}

Sejf& Sejf::operator-= (int ile) {
    if (dostepy - ile <= dostepy) {
        dostepy -= ile;
        zmanipulowany = true;
    }
    return *this;
}

short int Sejf::operator[] (unsigned indeks) {
    if (indeks >= zawartosc.size())
        return -1;
    if (dostepy == 0) {
        wlamanie = true;
        return -1;
    }
    dostepy--;
    return (short int) zawartosc[indeks];
}

std::string Sejf::Kontroler::daj_napis() const {
    if (sejf.wlamanie && sejf.zmanipulowany)
        return WLAMANIE + MANIPULACJA; //nie wiem co dokładnie wypisać w tej sytuacji
    if (sejf.wlamanie)
        return WLAMANIE;
    if (sejf.zmanipulowany)
        return MANIPULACJA;
    return OK;
}
