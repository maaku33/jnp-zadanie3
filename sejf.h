#ifndef __SEJF_H__
#define __SEJF_H__

#include <string>
#include <cstdint>
#include <cstddef>

class Sejf {
    static const unsigned DOMYSLNE_DOSTEPY = 42;

    std::string zawartosc;
    unsigned dostepy;
    bool zmanipulowany;
    bool wlamanie;

public:
    class Kontroler {
        friend class Sejf;

        const Sejf& sejf;

        const std::string OK = "OK\n";
        const std::string WLAMANIE = "ALARM: WLAMANIE\n";
        const std::string MANIPULACJA = "ALARM: ZMANIPULOWANY\n";

        Kontroler(const Sejf& s) : sejf(s) {}

        std::string daj_napis() const;

        public:
        explicit operator bool() const {
            return sejf.dostepy > 0;
        }

        bool operator! () const {
            return sejf.dostepy <= 0;
        }

        friend std::ostream& operator<< (std::ostream& os, Kontroler const& k) {
            return os << k.daj_napis();
        }
    };

    Sejf (const std::string& napis, unsigned liczba = DOMYSLNE_DOSTEPY);
    Sejf (std::string&& napis, unsigned liczba = DOMYSLNE_DOSTEPY);
    Sejf (const Sejf&) = delete;
    Sejf (Sejf&& s);

    Sejf& operator= (const Sejf&) = delete;
    Sejf& operator= (Sejf&& s);
    Sejf& operator+= (unsigned ile);
    Sejf& operator*= (unsigned ile);
    Sejf& operator-= (unsigned ile);

    int16_t operator[] (size_t indeks);

    const Kontroler kontroler() const {
        return Kontroler(*this);
    }

};

#endif /* __SEJF_H__ */
