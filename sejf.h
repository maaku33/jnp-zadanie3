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

        Kontroler(const Sejf& s) : sejf(s) {}

        public:
        explicit operator bool() const {
            return sejf.dostepy > 0;
        }
        
        bool operator! () const {
            return !(this);
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