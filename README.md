# blockchain_darbas_1
# versija 0.1

<br> Kaip veikia kodas: 
* randomas, randomas2: sveikasis skaičius, kuris gaunamas pagal įvesties ilgį ir atlikus veiksmus su skaičiumi. Šie du skaičiai veikia kaip savotiški "atsitiktiniai" skaičiai, kuriuos vėliau naudojami maišos funkcijoje.
* Masyvo ***array<unsigned long long, 4> hash***  kiekvienas elementas iš hash masyvo gali laikyti 64 bitus duomenų.
* Maišos funkcija iteruoja per kiekvieną eilutės simbolį. Kiekvienam simboliui atliekamos šios operacijos: 
  * ``` hash[i] ^= (randomas * 300 + simbolis) ```- XOR operacija: Čia naudojamas XOR (^) operatorius. XOR lygina bitus tarp dviejų operandų, jei jie skiriasi, rezultatas yra 1, jei jie vienodi – 0. Pvz., 1 XOR 0 = 1, 1 XOR 1 = 0. XOR operacija sumaišo pradinę hash[i] reikšmę su dabartinio simbolio reikšme, tam kad rezultatas būtų unikalesnis.
  * ```hash[i] *= (randomas2 ^ hash[i] * hash[i])``` - ši operacija padaugina hash[i] iš reikšmės, gautos atliekant XOR tarp randomas2 ir (hash[i] * hash[i]).
  * ```if(j % 3 == 0)``` ir ```if (j % 3 == 1)``` - pagal šias operacijas atliekamas hash masyvo elementų sukeitimas ```swap(hash[0], hash[3])``` ir tam tikri veiksmai: ```hash[1] += hash[2] * temp * simbolis``` ir ```hash[1] += hash[2] * simbolis```
  * Funkcija ***konvertavimas*** hash konvertuoja į šešioliktainius skaičius. 64 bitai gali būti atvaizduoti kaip 16 šešioliktainių simbolių (nes vienas šešioliktainis simbolis reprezentuoja 4 bitus). Taigi, gaunasi 16 * 4 = 64 simbolių.
  * kiekviena maišos masyvo reikšmė dauginama iš atitinkamos "druskos" vertės, kad būtų pridedama atsitiktinumo, vadinasi, maiša tampa sudėtingesnė ir atspari kolizijoms
  * std::hex: nurodo, kad skaičiai turi būti konvertuoti į šešioliktainį skaičių
  * ss.str(): visos keturių elementų šešioliktainės reikšmės yra sujungiamos į vieną 64 simbolių eilutę, kuri grąžinama kaip maišos rezultatas.
  
