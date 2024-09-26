# blockchain_darbas_1
# versija 0.1

<br> Kaip veikia kodas: 
* randomas, randomas2: sveikasis skaičius, kuris gaunamas pagal įvesties ilgį ir atlikus veiksmus su skaičiumi. Šie du skaičiai veikia kaip savotiški "atsitiktiniai" skaičiai, kuriuos vėliau naudojami maišos funkcijoje.
* Masyvo ***array<unsigned long long, 4> hash***  kiekvienas elementas iš hash masyvo gali laikyti 64 bitus duomenų.
* Maišos funkcija iteruoja per kiekvieną eilutės simbolį. Kiekvienam simboliui atliekamos šios operacijos: 
  * ``` hash[i] ^= (randomas * 999999 + simbolis) ```- XOR operacija: Čia naudojamas XOR (^) operatorius. XOR lygina bitus tarp dviejų operandų, jei jie skiriasi, rezultatas yra 1, jei jie vienodi – 0. Pvz., 1 XOR 0 = 1, 1 XOR 1 = 0. XOR operacija sumaišo pradinę hash[i] reikšmę su dabartinio simbolio reikšme, tam kad rezultatas būtų unikalesnis.
  * ```hash[i] *= (randomas2 ^ hash[i] * hash[i])``` - ši operacija padaugina hash[i] iš reikšmės, gautos atliekant XOR tarp randomas2 ir (hash[i] * hash[i]).
  * ```if(j % 3 == 0)``` ir ```if (j % 3 == 1)``` - pagal šias operacijas atliekamas hash masyvo elementų sukeitimas ```swap(hash[0], hash[3])``` ir tam tikri veiksmai: ```hash[1] += hash[2] * temp * simbolis``` ir ```hash[1] += hash[2] * simbolis```
  * Funkcija ***konvertavimas*** hash konvertuoja į šešioliktainius skaičius. 64 bitai gali būti atvaizduoti kaip 16 šešioliktainių simbolių (nes vienas šešioliktainis simbolis reprezentuoja 4 bitus). Taigi, gaunasi 16 * 4 = 64 simbolių.
  * kiekviena maišos masyvo reikšmė dauginama iš atitinkamos "druskos" vertės, kad būtų pridedama atsitiktinumo, vadinasi, maiša tampa sudėtingesnė ir atspari kolizijoms
  * std::hex: nurodo, kad skaičiai turi būti konvertuoti į šešioliktainį skaičių
  * ss.str(): visos keturių elementų šešioliktainės reikšmės yra sujungiamos į vieną 64 simbolių eilutę, kuri grąžinama kaip maišos rezultatas.
 
# Eksperimentinis tyrimas ir rezultatų analizė

Testams naudojami failai: 
1. du failai sudaryti tik iš vieno, tačiau skirtingo, simbolio
2. du failai sudaryti iš daug (> 1000) atsitiktinai sugeneruotų simbolių
3. du failai sudaryti iš daug (> 1000) simbolių, bet skirtųsi vienas nuo kito tik vienu (pvz. vidurinėje pozicijoje esančiu) simboliu
4. tuščio failo
   
Atlikus hash'avimą su 1. punkte paminėtais failais: 
* 517d357f42b3d3104af6dfb383027e6e6adc2b099645661c99e466085e13707e
* f512e5186a6695bfc575a00d21c0858de4dda3229a71f6a454558538ae7d6251
  
Atlikus hash'avimą su 2. punkte paminėtais failais:
* 6a80079be64ef0a8ae1a5a890667850e5d30421b3378525c8ea912f33e806ab6
* c194a83901088cff5d993301aea921f17587b1000aa266d4c332be617df16491

Atlikus hash'avimą su 3. punkte paminėtais failais:
* be89dcf2bb2435d04ced29b76735c57b21e769e0be47e784726b24ac4e0ba03e
* 296c88f1e88f7a495af054244739f37ec91f1c8eba5e735ca915dfc1f522ddf3

Atlikus hash'avimą su 4. punkte paminėtais failais:
* 4ad9f5ad229b263814622cb8938c63ed65d3730df23f59e4f249eb9c81b23c06

<br> Nepriklausomai nuo input'o, output'ai visada yra vienodo dydžio, o to paties failo hash'as yra tas pats (deterministiškumas)

Kolizijos testui naudojamas failas iš atsitiktinių simbolių eilučių (string'ų) porų, pvz.: (asdfg, hijkl):
* 25 000 porų, kurių ilgis - 10 simbolių
* 25 000 porų, kurių ilgis - 100 simbolių
* 25 000 poras kurių ilgis - 500 simbolių 
* 25 000 poras kurių ilgis - 1000 simbolių

Naudojant faile sugeneruotas poras, visais atvejais gautieji porų hash'ai nesutampa. Tokiu būdu įrodoma, kad hash funkcija atspari kolizijai.

Lavinos efekto testui naudojamas failas iš 100 000 atsitiktinių simbolių eilučių (string'ų) porų, apsiribojant iki 1000 simbolių eilučių ilgiu, taip, kad jos skirtųsi tik vienu simboliu pvz.: (asdfg, bsdfg). Hash'ų procentinis "skirtingumas" įvertinamas taip:
* bitų lygmenyje
  * vidurkis - 50% skirtingumas
  * minimalus - 37% skirtingumas
  * maksimalus - 65% skirtingumas
* hex'ų lygmenyje
  * vidurkis - 93% skirtingumas
  * minimalus - 75% skirtingumas
  * maksimalus - 100% skirtingumas


## Laiko testavimai su "konstitucija.txt"
                                                             Testavimas
|     | 1     |  2         | 4          | 8          | 16         | 32         | 64         | 128        | 256        | 512        | 789        |
| --- | ----- | ---------- | ---------- | ---------- | ---------- | ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| 1   | 0s.   | 0.000996s. | 0s.        | 0s.        | 0s.        | 0.000135s. | 0s.        | 0.000996s. | 0.003294s. | 0.004009s. | 0.006975s. |
| 2   | 0s.   | 0s.        | 0.000264s. | 0s.        | 0.000293s. | 0s.        | 0.000998s. | 0.001998s. | 0.004045s. | 0.007025s. | 0.007025s. |
| 3   | 0s.   | 0s.        | 0s.        | 0s.        | 0.000305s. | 0.001002s. | 0.000998s. | 0.003078s. | 0.004076s. | 0.006847s. | 0.006847s. |
| 4   | 0s.   | 0s.        | 0s.        | 0.000996s. | 0.000173s. | 0s.        | 0.000995s. | 0.001994s. | 0.006155s. | 0.006021s. | 0.006847s. |
| 5   | 0s.   | 0s.        | 0s.        | 0s.        | 0s.        | 0s.        | 0.000998s. | 0.001996s. | 0.004627s. | 0.00803s.  | 0.00803s.  | 

<img src="https://github.com/user-attachments/assets/b629bed6-e2dd-4896-b762-80c295c75a3b" width="500">

# Apibendrinimas

Šiame eksperimente buvo atliktas hash funkcijos testavimas pagal deterministiškumą, kolizijų atsparumą, lavinos efektą ir veikimo laiką. Testai parodė, kad hash funkcija yra deterministinė – nepriklausomai nuo to, kiek kartų tas pats failas yra hash'uojamas, rezultatas visada yra vienodas. Eksperimentai su 25 000 porų, kurių ilgiai svyravo nuo 10 iki 1000 simbolių, nerado nė vienos kolizijos. Tai rodo, kad funkcija turi atsparumą kolizijoms. Lavinos efekto testai, atliekant su 100 000 atsitiktinių simbolių eilučių porų, kurių eilutės skyrėsi tik vienu simboliu, rezultatai rodo, kad hash funkcija generuoja pakankamai stiprų lavinos efektą, nes minimalūs ir maksimalūs procentiniai skirtingumai tiek bitų, tiek hex lygiu yra arti idealios lavinos savybės. Laiko testai su „konstitucija.txt“ parodė, kad hash funkcija yra efektyvi apdorojant tiek mažus, tiek didelius failus.
