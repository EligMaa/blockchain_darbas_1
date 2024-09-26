#include "header.h"
#include "kod.h"

int main() {
    
    ivedimas();
    return 0;
}

void ivedimas ( ){

    int meniu;
    bool baigti = false;


    do {
        cout<<"\nFailu pasirinkimai:"<<endl;
        cout<<"1 - \"testasA.txt\""<<endl;
        cout<<"2 - \"testasB.txt\""<<endl;
        cout<<"3 - \"testasAts1.txt\""<<endl;
        cout<<"4 - \"testasAts2.txt\""<<endl;
        cout<<"5 - \"testas_v_A.txt\""<<endl;
        cout<<"6 - \"testas_v_B.txt\""<<endl;
        cout<<"7 - \"testas_tuscias.txt\""<<endl;
        cout<<"8 - ivesti ranka"<<endl;
        cout<<"9 - generuoti testus"<<endl;
        cout<<"10 - laiko testavimas"<<endl;
        cout<<"11 - kolizijos testaviams"<<endl;
        cout<<"12 - lavinos testavimas"<<endl;
        cout<<"0 - baigti"<<endl;
        
        cout<<"--------------------------------------------------------"<<endl;
        
            try {
                cout << "Iveskite pasirinkima: " << endl;
                string input;
                cin >> input;

                if (input.find_first_not_of("0123456789") != string::npos) {     ///tikrina ar ivestas skaicius naturalusis
                throw invalid_argument("Netinkamas pasirinkimas");
                }

                meniu = stoi(input);

                if (meniu < 0 || meniu > 12) {                                   ///tikrina ar ivestas skaicius yra nuo 0 iki 9
                    throw invalid_argument("Klaida! Iveskite nuo 0 iki 12 ");
                }
                            
            } 
                        
            catch (const invalid_argument & e) {
                cerr << "Klaida: " << e.what() << endl;
                cout << endl;

                continue;
            }    

            switch (meniu)
            {
                case 1:
                    nuu(0);
                    break;
                case 2:
                    nuu(1);
                    break;
                case 3:
                    nuu(2);
                    break;
                case 4:
                    nuu(3);
                    break;
                case 5:
                    nuu(4);
                    break;
                case 6:
                    nuu(5);
                    break;
                case 7:
                    nuu(6);
                    break;
                case 8:
                    nuu(7);
                    break;
                case 9:
                    generuoja_failus_Ats("testasAts1.txt", 1000);   
                    generuoja_failus_Ats("testasAts2.txt", 1000);   
                    generuoja_f_su_viena_skirtinga("testas_v_A.txt", "testas_v_B.txt", 1000);
                    atsitiktiniu_eiluciu_poros();
                    lavinos_failas();
                    break;
                case 10:
                    testavimas("konstitucija.txt");
                    break;
                case 11:
                    nuu().tikrinti_hash_kolizijas();
                case 12:
                    nuu().lavinos_testavimas();
                    break;                
                case 0:
                    baigti = true;
                    break;  

            }
    }while (!baigti);
            
}







