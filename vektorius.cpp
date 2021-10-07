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

void nuskaitymas(vector<studentas> &vektorius);
void skaiciavimas(vector<studentas> &vektorius);
bool f (const studentas &a, const studentas &b);
void isvedimas(vector<studentas> &vektorius);

int main()
{
    vector<studentas> vektorius;
    nuskaitymas(vektorius);
    skaiciavimas(vektorius);
    isvedimas(vektorius);
}

void nuskaitymas(vector<studentas> &vektorius)
{
    int tikrinimas;
        int tikrinimas2;
        int egzaminas;
        char random;
        int laikinas;
        for (int i=0;;i++)
        {
            studentas stud;
            cout << "Iveskite " << i+1 << " o-jo studento varda bei pavarde:" << endl;
            cin >> stud.Vardas >> stud.Pavarde;
            for (int j=0;;j++)
            {
                cout << "Ar yra dar namu darbu pazymiu? Jei taip, spauskite 1, jei ne, spauskite 2" << endl;
                cin >> tikrinimas2;
                if ((tikrinimas2 == 2 && stud.N == 0) || tikrinimas2 == 1)
                {
                    if (tikrinimas2 == 2)
                    {
                        cout << "Privalote ivesti bent viena namu darbu pazymi!" << endl;
                    }

                    cout << "Ar norite " << i+1 << " -am studentui atsitiktinai sugeneruoti namu darbo pazymi? Jei taip, spauskite 'r' klavisa, jei ne, bet koki kita klavisa" << endl;
                    cin >> random;
                    if (random == 'r' || random == 'R')
                    {
                        stud.NamuDarbai.push_back((rand() % 10) + 1);
                        stud.N++;
                    }
                    else
                    {
                        cout << "Iveskite " << j+1 << " -ojo namu darbo pazymi [1-10]:" << endl;
                        cin >> laikinas;
                        if (laikinas < 1 || laikinas > 10)
                        {
                            cin.clear();
                            cout << "Ivedete netinkama pazymi! Bandykite vesti is naujo" << endl;
                            cin.ignore(256, '\n');
                            j--;
                        }
                        else
                        {
                            stud.NamuDarbai.push_back(laikinas);
                            stud.N++;
                        }
                    }
                }
                else if (tikrinimas2 == 2)
                {
                    break;
                }
                else cout << "Ivesk 1 arba 2!" << endl;
            }
            cout << "Ar norite " << i+1 << " -am studentui atsitiktinai sugeneruoti egzamino pazymi? Jei taip, spauskite 'r' klavisa, jei ne, bet koki kita klavisa" << endl;
            cin >> random;
            if (random == 'r' || random == 'R')
            {
                stud.Egzaminas = (rand() % 10) + 1;
            }
            else
            {
                cout << "Iveskite " << i+1 << " -ojo studento egzamino rezultata [1-10]:" << endl;
                while (egzaminas < 1 || egzaminas > 10)
                {
                    cin >> egzaminas;
                    if (egzaminas >= 1 && egzaminas <= 10)
                    {
                        stud.Egzaminas = egzaminas;
                    }
                    else
                    {
                        cin.clear();
                        cout << "Ivedete netinkama pazymi! Bandykite vesti nauja pazymi [1-10]" << endl;
                        cin.ignore(256, '\n');
                    }
                }
            }
            cout << "Ar yra dar studentu? Jei taip, spauskite 1, jei ne, spauskite 2." << endl;
            cin >> tikrinimas;
            vektorius.push_back(stud);
            if (tikrinimas == 2)
            {
                break;
            }
        }
}


void skaiciavimas(vector<studentas> &vektorius)
{
    for (int i=0; i<vektorius.size(); i++)
    {
        sort(vektorius[i].NamuDarbai.begin(), vektorius[i].NamuDarbai.end());

        if (vektorius[i].N % 2 != 0)
        {
            vektorius[i].Mediana = (vektorius[i].NamuDarbai[(vektorius[i].N/2)]);
        }
        else vektorius[i].Mediana = (vektorius[i].NamuDarbai[(vektorius[i].N/2)-1] + vektorius[i].NamuDarbai[vektorius[i].N/2]) / 2;

        for (int j=0; j<vektorius[i].N; j++)
        {
            vektorius[i].Suma += vektorius[i].NamuDarbai[j];

        }
        vektorius[i].Vidurkis = vektorius[i].Suma / (double)vektorius[i].N;
    }
}

bool f (const studentas &a, const studentas &b)
{
    return a.Vardas < b.Vardas;
}

void isvedimas(vector<studentas> &vektorius)
{
    int tikrinimas;
    cout << "Ar norite, jog programa apskaiciuotu vidurki, ar mediana? Jei norite vidurkio, spauskite 1, jei medianos, spauskite 2." << endl;
    cin >> tikrinimas;

    sort(vektorius.begin(), vektorius.end(), f);
    if (tikrinimas == 1)
    {
        cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(25) << setw(25) << "Galutinis (Vid.)" << endl;
        cout << "-------------------------------------------------------" << endl;
        for (int i=0; i<vektorius.size(); i++)
        {
            cout << setw(15) << vektorius[i].Vardas << setw(15) << vektorius[i].Pavarde;
            cout << setw(25) << fixed << setprecision(2) << vektorius[i].Vidurkis * 0.4 + vektorius[i].Egzaminas * 0.6 << endl;
        }
    }
    else
    {
        cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(25) << setw(25) << "Galutinis (Med.)" << endl;
        cout << "-------------------------------------------------------" << endl;
        for (int i=0; i<vektorius.size(); i++)
        {
            cout << setw(15) << vektorius[i].Vardas << setw(15) << vektorius[i].Pavarde;
            cout << setw(25) << fixed << setprecision(2) << vektorius[i].Mediana * 0.4 + vektorius[i].Egzaminas * 0.6 << endl;
        }
    }

}

