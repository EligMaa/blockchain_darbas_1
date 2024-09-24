#include "header.h"

nuu::nuu( int nr ) {

    if(nr == 3)   {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear leftover newline
    std::getline(std::cin, ivestis);
    }
    else
    ivestis = skaitymas(failai[nr]);

    hash(ivestis);

}

void nuu::hash(std::string &ivestis){

    unsigned long long randomas = ivestis.length() / 2 + 1;
    unsigned long long randomas2 = ivestis.length() / 3 - 9;

    array<unsigned long long, 4> hash = {0, 0, 0, 0};
    int j = 0;
    char temp = 'n';

    for (char simbolis : ivestis) { 

        for (int i = 0; i < 4; ++i) {
            hash[i] ^= (randomas * 298 + simbolis );
            hash[i] *= (randomas2 ^ hash[i] - i * hash[i] );
        }
        
        if (j % 3 == 0) {
            swap(hash[0], hash[3]);
            hash[1] += hash[2] * temp * simbolis;
        }
        else if (j % 3 == 1) {
            hash[1] += hash[2] * simbolis;
            swap(hash[1], hash[2]);
        }
        temp = simbolis;
        ++j;
        
    }
    std::cout << konvertavimas(hash) <<std::endl;
    
    
}
string nuu::konvertavimas(const array<unsigned long long, 4>& hash){

    vector <unsigned long long> druska = {192837645ULL, 1098765432ULL, 123456789ULL, 987654321ULL};
    std::stringstream ss;
    int i = 0;

    for (const auto& n : hash) {
        
        unsigned long long druskintas = n * druska[3 - i];
        // 64 bits -> 16 hex 
        ss << std::setw(16) << std::setfill('0') << std::hex << druskintas; 
        ++i;
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

