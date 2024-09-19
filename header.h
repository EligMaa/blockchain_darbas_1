#ifndef v01_H
#define v01_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>



using namespace std;
const std::vector<std::string> failai {"pirmas.txt" , "antras.txt" , "trecias.txt" , "ketvirtas.txt" , "penktas.txt" , "sestas.txt"};

class nuu{

    public:
        nuu( );
        ~nuu();

        void skaitymas (const string &ivestis);

    private:
        string ivestis;
        void hash ( );
        
};

nuu::nuu( )
{
}

nuu::~nuu()
{
}

void ivedimas();


#endif
