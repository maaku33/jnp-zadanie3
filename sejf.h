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
    
        public:
            explicit operator bool() const {
                //TODO
                return true;
            }
    
    };
    private:
    Kontroler k;
    
    public:
    Sejf (const std::string& napis, unsigned liczba);
    
    Sejf (std::string&& napis, unsigned liczba);

    Sejf (Sejf&& s);
        
    Sejf& operator= (const Sejf&) = delete;
    
    Sejf& operator= (Sejf&& s);
    
    Sejf& operator+= (int ile);
    
    Sejf& operator*= (int ile);
    
    Sejf& operator-= (int ile);
    
    char operator[] (unsigned indeks) const;
    
    Kontroler& kontroler() {
        k = Kontroler();
        return k;
    }
            
};

#endif /* __SEJF_H__ */