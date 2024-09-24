#include "header.h"

nuu::nuu( int nr ) {

    if(nr == 7)   {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear leftover newline
    std::getline(std::cin, ivestis);
    }
    else
    ivestis = skaitymas(failai[nr]);

    laiko_matavimas(ivestis);
    // hash(ivestis);

}

void nuu::hash(string &ivestis){

    unsigned long long randomas = ivestis.length() / 2 + 1;
    unsigned long long randomas2 = ivestis.length() / 3 - 9;

    array<unsigned long long, 4> hash = {0, 0, 0, 0};
    int j = 0;
    char temp = 'n';


    for (char simbolis : ivestis) { 

        for (int i = 0; i < 4; ++i) {
            hash[i] ^= (randomas * 999999 + simbolis );
            hash[i] *= (randomas2 ^ hash[i] * hash[i] );
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
    uzhashuotas = konvertavimas(hash);
    std::cout << uzhashuotas <<std::endl;
    
    
}
string nuu::konvertavimas(const array<unsigned long long, 4>& hash){

    vector <unsigned long long> druska = {192837645ULL, 1098765432ULL, 123456789ULL, 987654321ULL};
    vector<char> druska1 = {'-','$','#','@'};
    vector<char> druska2 = {'&','/','*',','};
    stringstream ss;
    int i = 0;

    for (const auto& n : hash) {
        
        unsigned long long druskintas = n * druska[3 - i] + druska1[3 - i] * druska2[3 - i];
        // 64 bits -> 16 hex 
        ss << std::setw(16) << std::setfill('5') << std::hex << druskintas; 
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

    if(failas.peek() == std::ifstream::traits_type::eof()) eilute = "da39a3ee5e6b4b0d3255bfef95601890afd80709";  // tikrina ar failas tuscias

    while (getline(failas, eilute)) {
        ilgis = eilute.length();
        return eilute;
    }
    failas.close();
    return eilute;
}

void generuoja_failus_Ats(const std::string& pav, int ilgis) {
    std::ofstream failas(pav);

    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> intervalas('A', 'Z'); // intervalas tarp A ir Z

    for (int i = 0; i < ilgis; ++i) {
        char random = static_cast<char>(intervalas(gen)); // generuoja atsitiktine raide
        int sk = rand() % 100 + 1;
        failas << random << sk;
    }

    failas.close();
}

void generuoja_f_su_viena_skirtinga(const std::string& pav,const std::string& pav2, int ilgis) {
    std::ofstream failas(pav);
    std::ofstream failas2(pav2);

    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> intervalas('A', 'Z'); // intervalas tarp A ir Z

    for (int i = 0; i < ilgis; ++i) {
        char random = static_cast<char>(intervalas(gen)); // generuoja atsitiktine raide
        int sk = rand() % 10 ;
        failas << random << sk;
        failas2 << random << sk;
        if(i == ilgis / 2 ){
            failas << 'A';
            failas2 << 'B';
        }
    }

    failas.close();
    failas2.close();

}

double nuu::laiko_matavimas( string& ivestis) {
    auto pradzia = std::chrono::high_resolution_clock::now();
    
    hash(ivestis); 

    auto pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas = pabaiga - pradzia;
    cout<<laikas.count()<<endl;
    return laikas.count();  // grazina sekundes
}



