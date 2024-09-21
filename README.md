# blockchain_darbas_1
# versija 0.1

<br> Kaip veikia kodas: 
* randomas, randomas2: sveikasis skaičius, kuris gaunamas pagal įvesties ilgį ir atlikus veiksmus su skaičiumi. Šie du skaičiai veikia kaip savotiški "atsitiktiniai" skaičiai, kuriuos vėliau naudojami maišos funkcijoje.
* Mastvo ***array<unsigned long long, 4> hash***  kiekvienas elementas iš hash masyvo gali laikyti 64 bitus duomenų.
* Maišos funkcija iteruoja per kiekvieną eilutės simbolį. Kiekvienam simboliui atliekamos šios operacijos: 
  * kiekvienas hash masyvo elementas atnaujinamas naudojant daugybos ir sudėties operacijų derinį.
  * hash masyvo elementai sąlyginai sukeičia vietomis pagal j reikšmę
* Funkcija ***konvertavimas*** hash konvertuoja į šešioliktainius skaičius. 64 bitai gali būti atvaizduoti kaip 16 šešioliktainių simbolių (nes vienas šešioliktainis simbolis reprezentuoja 4 bitus). Taigi, gaunasi 16 * 4 = 64 simbolių.
  * kiekviena maišos masyvo reikšmė dauginama iš atitinkamos "druskos" vertės, kad būtų pridedama atsitiktinumo, vadinasi, maiša tampa sudėtingesnė ir atspari kolizijoms
  * std::hex: nurodo, kad skaičiai turi būti konvertuoti į šešioliktainį skaičių
  * ss.str(): visos keturių elementų šešioliktainės reikšmės yra sujungiamos į vieną 64 simbolių eilutę, kuri grąžinama kaip maišos rezultatas.
  
