#ifndef v01_H
#define v01_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <array>
#include <sstream>




using namespace std;
const std::vector<std::string> failai {"pirmas.txt" , "antras.txt" , "trecias.txt" , "ketvirtas.txt" , "penktas.txt" , "sestas.txt"};

class nuu{

    public:
        nuu( );
        inline ~nuu() {}

        void skaitymas (const string &ivestis);

    private:
        string ivestis;
        int ilgis;
        void hash (string &ivestis );
        string konvertavimas(const array<unsigned long long, 4>& hash);
        
};



void ivedimas();


#endif
