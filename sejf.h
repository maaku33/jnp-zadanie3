#ifndef __SEJF_H__
#define __SEJF_H__

#include <string>

class Sejf {
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
            return !(this);
        }

        friend std::ostream& operator<< (std::ostream& os, Sejf::Kontroler const& k) {
            return os << k.daj_napis();
        }
        
        
    };

private:
    Kontroler k = Kontroler(*this); // sprawdić tą inicjalizację

public:
    Sejf (const std::string& napis, unsigned liczba);

    Sejf (const std::string& napis);
    
    Sejf (std::string&& napis, unsigned liczba);

    Sejf (std::string&& napis);

    Sejf (Sejf&& s);
        
    Sejf& operator= (const Sejf&) = delete;
    
    Sejf& operator= (Sejf&& s);
    
    Sejf& operator+= (int ile);
    
    Sejf& operator*= (int ile);
    
    Sejf& operator-= (int ile);
    
    short int operator[] (unsigned indeks);
    
    Kontroler& kontroler() {
        return k;
    }
            
};



#endif /* __SEJF_H__ */