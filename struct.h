#pragma once
#include <bits/stdc++.h>

using namespace std;

struct studentas
{
    string Vardas, Pavarde;
    vector <double> NamuDarbai;
    int Egzaminas, Suma=0;
    double Vidurkis, Mediana;
    int N = 0;
};

void nuskaitymas(vector<studentas> &vektorius, int &arivesti, bool &failasneegz);
void skaiciavimas(vector<studentas> &vektorius);
void isvedimas(vector<studentas> &vektorius);
void isvedimas2(vector<studentas> &vektorius);
