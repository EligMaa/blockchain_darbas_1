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
        cout<<"1 - \"pirmas.txt\""<<endl;
        cout<<"2 - \"antras.txt\""<<endl;
        cout<<"3 - \"trecias.txt\""<<endl;
        cout<<"0 - baigti"<<endl;
        
        cout<<"--------------------------------------------------------"<<endl;
        
            try {
                cout << "Iveskite pasirinkima: " << endl;
                string input;
                cin >> input;

                if (input.find_first_not_of("0123456789") != string::npos) {                                  ///tikrina ar ivestas skaicius naturalusis
                throw invalid_argument("Netinkamas pasirinkimas");
                }

                meniu = stoi(input);

                if (meniu < 0 || meniu > 6) {                                                                ///tikrina ar ivestas skaicius yra nuo 1 iki 3
                    throw invalid_argument("Klaida! Iveskite nuo 1 iki 6 ");
                }
                            
            } 
                        
            catch (const invalid_argument & e) {
                cerr << "Klaida: " << e.what() << endl;
                cout << endl;

                continue;
            }    

            switch (meniu)                                                                                  /// meniu skirtas v0.2
            {
                case 1:

                    // nuu().skaitymas(failai[0]);
                    nuu( );
                        

                    break;

                case 2:

                    break;
                
                case 3:

                    break;
                
                case 0:
                    baigti = true;
                    break;  

            }
    }while (!baigti);
            
}







