# Pažymių vidurkio skaičiuoklė

Programa yra skirta apskaičiuoti pažymių vidurkį arba medianą.

## Veikimo principas

Paleidus programą komandinėje eilutėje yra prašoma atlikti keletą veiksmų:

- Suvesti duomenis (t.y. vardas, pavardė, namu darbu pažymiai, egzamino įvertinimas)
- Po duomenų suvedimo yra apskaičiuojamas galutinis pažymis įvertinimų vidurkiu arba mediana.

Programa suteikia galimybę generuoti atsitiktinius namų darbų rezultatus bei egzamino balą, bei suvesti daugiau nei vieno studento duomenis.

Paleidus programą, prašome sekti komandinėje eilutėje nurodytus instrukcijas.

Vienas iš galimymų programos eigos variantų yra toks:

```shell
-> Iveskite studento varda bei pavarde: Vardenis Pavardenis
-> Įveskite studento namų darbų įvertinimą [0-10], (Jei norite gauti atsitiktinį skaičių, spauskite 'r' klavišą): 
-> Įveskite studento egzamino įvertinimą [0-10], (Jei norite gauti atsitiktinį skaičių, spauskite 'r' klavišą):
-> Ar yra dar studentų? Jei taip spauskite 1, jei ne - 2. 
-> Ar norite vidurkio ar medianos? Jei vidurkio spauskite 1, jei medianos - 2.
```

Po sėkmingo duomenų suvedimo į terminalo langą išvedami rezultatai panašia forma:

```shell
Vardas      Pavarde         Galutinis Vid. Galutinis Med.
----------------------------------------------------------
Vardenis    Pavardenis      5.25
```

Galutinis vidurkis yra apskaičiuojamas pagal formulę `galutinis = 0.4 * vidurkis + 0.6 * egzaminas`.

## Programos diegimas ir paleidimas

- Atsisiųskite programos versiją iš github'o,
- Programą sukompiliuokite.


### Changelog

- [v.01](https://github.com/UgniusBraun/1-oji-uzduotis/releases/tag/V0.1) - Pirmoji programos versija.
