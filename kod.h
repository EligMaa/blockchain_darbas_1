#include "header.h"

nuu::nuu(){
    ivestis = "Labas 2 rytas";
    hash(ivestis);


}

void nuu::hash(std::string &ivestis){

    int randomas = abs(ilgis / 2 + 1);
    int randomas2 = abs(ilgis / 3 - 1);
    int randomas3 = abs(randomas + randomas2 - 4);
    int randomas4 = abs(randomas + randomas3 - 1);

    array<unsigned long long, 4> hash = {0, 0, 0, 0};

    for (char simbolis : ivestis) { 
        for (int i = 0; i < 4; ++i) {
            hash[i] = hash[i] + randomas * 256 + simbolis;
            hash[i] = hash[i] + randomas2 * 256 + simbolis;
        }
        
    }
    std::cout << konvertavimas(hash) <<std::endl;
    
    
}
string nuu::konvertavimas(const array<unsigned long long, 4>& hash){

    std::stringstream ss;
    for (const auto& part : hash) {
        ss << std::setw(16) << std::setfill('0') << std::hex << part; // 64 bits -> 16 hex digits
    }
    return ss.str();

}