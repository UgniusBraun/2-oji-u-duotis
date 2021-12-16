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
| Laikas (s)  | 0.6593 | 6.1724 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0478 | 0.5305 |

Su klase:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.8328 | 5.1269 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0787 | 0.6360 |

### O1 optimizacijos lygis:

Su struktūra:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.7854 | 6.5181 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0519 | 0.6622 |

Su klase:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.6567 | 5.2163 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0773 | 0.7092 |

### O2 optimizacijos lygis:

Su struktūra:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.7030 | 6.3510 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0518 | 0.6718 |

Su klase:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.5614 | 5.2490 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0618 | 0.6537 |

### O3 optimizacijos lygis:

Su struktūra:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.6642 | 6.6098 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0514 | 0.6664 |

Su klase:

Failo nuskaitymo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.5390 | 5.8419 |

Failo grupavimo laikas:
| Studentų sk.       | 100,000   | 1,000,000  |
| :----------    | :------ | :------ |
| Laikas (s)  | 0.0603 | 0.6742 |

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
