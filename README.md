# Pažymių vidurkio skaičiuoklė

Programa atsitiktinai generuoja pažymius dideliam kiekiui studentų, suskaičiuoja jų galutinį pažymį, ir pagal jį skirsto studentus į geriau besimokančius "kietekus" bei prasčiau besimokančius "nenaudėlius".

## Veikimo principas

Paleidus programą ji atlieka šiuos veiksmus:

- Sukuria studentų failą, kiekvienam studentui atsitiktinai sugeneravusi tam tikrą skaičių namų darbų pažymių, bei egzamino pažymį.
- Apskaičiuoja kiekvieno studento galutinį pažymį.
- Pagal tai, ar galutinis pažymys yra didesnis už praeinamą penketą, ar ne, skirsto studentus į dvi grupes.
- Sukuria du failus, į kuriuos išvedami atitinkamai į grupes suskirstyti studentai.
- Skaičiuoja kiek laiko buvo vykdomas kiekvienas iš šių žingsnių, ir šį vykdymo laiką išveda į terminalo langą.

Po sėkmingo programos įvykdymo į terminalo langą išvedami rezultatai panašia forma:

```shell
Vardas      Pavarde         Galutinis Vid. Galutinis Med.
----------------------------------------------------------
Vardenis    Pavardenis      5.25
```

Galutinis vidurkis yra apskaičiuojamas pagal formulę `galutinis = 0.4 * vidurkis + 0.6 * egzaminas`.


### Programos veikimo greičio analizė:

Su struktūra:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 1.4638 | 9.9845 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0803 | 1.1004 |

Su klase:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.8621 | 8.4884 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0937 | 1.0271 |

### O1 optimizacijos lygis:

Su struktūra:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 1.4210 | 9.9926 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0101 | 0.1221 |

Su klase:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.8375 | 8.1694 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0506 | 0.4686 |

### O2 optimizacijos lygis:

Su struktūra:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.7291 | 5.8921 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0 | 0.0918 |

Su klase:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.6841 | 4.8750 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0296 | 0.2955 |

### O3 optimizacijos lygis:

Su struktūra:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.9405 | 5.9865 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0071 | 0.0908 |

Su klase:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.6013 | 4.9144 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0312 | 0.2734 |

## Programos diegimas ir paleidimas

- Atsisiųskite programos versiją iš github'o,
- Programą sukompiliuokite.


### Changelog

- [v.01](https://github.com/UgniusBraun/1-oji-uzduotis/releases/tag/V0.1) - Pirmoji programos versija.
- [v.02](https://github.com/UgniusBraun/1-oji-uzduotis/releases/tag/V0.2) - Antroji programos versija. Pridėta galimybė duomenis nuskaityti iš failų.
- [v.03](https://github.com/UgniusBraun/1-oji-uzduotis/releases/tag/V.03) - Trečioji programos versija. Kodas išskirstytas į (.cpp) bei (.h) header failus. Taip pat implementuotas išimčių valdymas.
- [v.04](https://github.com/UgniusBraun/1-oji-uzduotis/releases/tag/V.04) - Ketvirtoji programos versija. Pridėta galimybė generuoti failą, su daug studentų, bei atliekama programos veikimo greičio analizė.
- [v.05](https://github.com/UgniusBraun/1-oji-uzduotis/releases/tag/V.05) - Penktoji programos versija. Pakeistas naudojamas konteineris iš vector į list. Taip pat patobulintos programos veikimo sparta palyginta su praeitos realizacijos veikimo sparta.
- [v.10](https://github.com/UgniusBraun/1-oji-uzduotis/releases/tag/V.10) - Šeštoji programos versija. Grupavimo dalis tiek vector tiek list konteineriams padaryta naudojantis pora skirtingų strategijų. Visų bandytų variantų veikimo sparta palyginama.
- [v1.1](https://github.com/UgniusBraun/2-oji-uzduotis/releases/tag/V.10) - Septintoji programos versija. Iš struktūros tipo pakeista į klasės tipą. Taip pat panaudoti skirtingi kompiliatoriaus optimizavimo lygiai, ir palyginta veikimo sparta visais variantais.
