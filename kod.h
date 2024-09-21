#include "header.h"

nuu::nuu( int nr ) {
    ivestis = skaitymas(failai[nr]);
    hash(ivestis);


}

void nuu::hash(std::string &ivestis){

    unsigned long long randomas = ivestis.length() / 2 + 1;
    unsigned long long randomas2 = ivestis.length() / 3 - 9;

    array<unsigned long long, 4> hash = {0, 0, 0, 0};

    for (char simbolis : ivestis) { 
        for (int i = 0; i < 4; ++i) {
            hash[i] ^= (randomas * 256 + simbolis);
            hash[i] *= randomas2 ^ hash[i-1] - simbolis;
        }
        
    }
    std::cout << konvertavimas(hash) <<std::endl;
    
    
}
string nuu::konvertavimas(const array<unsigned long long, 4>& hash){

    std::stringstream ss;
    for (const auto& n : hash) {
        // 64 bits -> 16 hex 
        ss << std::setw(16) << std::setfill('0') << std::hex << n; 
    }
    return ss.str();

}

string nuu::skaitymas(const string &ivestis){

    ifstream failas(ivestis);
    
    if (!failas) {
        throw invalid_argument("Nepavyko atidaryti failo: " + ivestis);
    }
    string eilute;
    while (getline(failas, eilute)) {
        ilgis = eilute.length();
        return eilute;
    }
    failas.close();
    return eilute;
}

