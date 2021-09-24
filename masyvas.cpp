#include <bits/stdc++.h>
using namespace std;

struct studentas
{
    string Vardas, Pavarde;
    double NamuDarbai[100];
    int Egzaminas, Suma=0;
    double Vidurkis, Mediana;
    int N;
};

void nuskaitymas(int &m, studentas masyvas[]);
void skaiciavimas(int m, studentas masyvas[]);
void isvedimas(int m, studentas masyvas[]);

int main()
{
    int m=1;
    studentas masyvas[100];
    nuskaitymas(m, masyvas);
    skaiciavimas(m, masyvas);
    isvedimas(m, masyvas);
}

void nuskaitymas(int &m, studentas masyvas[])
{
    int tikrinimas;
    int tikrinimas2;
    int egzaminas;
    char random;
        for (int i=0; i<100; i++)
        {
            cout << "Iveskite " << i+1 << " o-jo studento varda bei pavarde:" << endl;
            cin >> masyvas[i].Vardas >> masyvas[i].Pavarde;
            for (int j=0; j<100; j++)
            {
                cout << "Ar yra dar namu darbu pazymiu? Jei taip, spauskite 1, jei ne, spauskite 2" << endl;
                cin >> tikrinimas2;
                if ((tikrinimas2 == 2 && masyvas[i].N == 0) || tikrinimas2 == 1)
                {
                    if (tikrinimas2 == 2)
                    {
                        cout << "Privalote ivesti bent viena namu darbu pazymi!" << endl;
                    }

                    cout << "Ar norite " << i+1 << " -am studentui atsitiktinai sugeneruoti namu darbo pazymi? Jei taip, spauskite 'r' klavisa, jei ne, bet koki kita klavisa" << endl;
                    cin >> random;
                    if (random == 'r' || random == 'R')
                    {
                        masyvas[i].NamuDarbai[j] = (rand() % 10) + 1;
                        masyvas[i].N++;
                        cout << masyvas[i].NamuDarbai[j] << endl;
                    }
                    else
                    {
                        cout << "Iveskite " << j+1 << " -ojo namu darbo pazymi [1-10]:" << endl;
                        cin >> masyvas[i].NamuDarbai[j];
                        if (masyvas[i].NamuDarbai[j] < 1 || masyvas[i].NamuDarbai[j] > 10)
                        {
                            cin.clear();
                            cout << "Ivedete netinkama pazymi! Bandykite vesti is naujo" << endl;
                            cin.ignore(256, '\n');
                            j--;
                        }
                        else
                        {
                            masyvas[i].N++;
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
                    masyvas[i].Egzaminas = (rand() % 10) + 1;
                }
                else
                {
                            cout << "Iveskite " << i+1 << " -ojo studento egzamino rezultata [1-10]:" << endl;
                    while (egzaminas < 1 || egzaminas > 10)
                    {
                        cin >> egzaminas;
                        if (egzaminas >= 1 && egzaminas <= 10)
                        {
                            masyvas[i].Egzaminas = egzaminas;
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
            if (tikrinimas == 2)
            {
                break;
            }
            else m++;
        }
}

void skaiciavimas(int m, studentas masyvas[])
{
    for (int i=0; i<m; i++)
    {
        sort(masyvas[i].NamuDarbai, masyvas[i].NamuDarbai + masyvas[i].N);

        if (masyvas[i].N % 2 != 0)
        {
            masyvas[i].Mediana = (masyvas[i].NamuDarbai[(masyvas[i].N/2)]);
        }
        else masyvas[i].Mediana = (masyvas[i].NamuDarbai[(masyvas[i].N/2)-1] + masyvas[i].NamuDarbai[masyvas[i].N/2]) / 2;

        for (int j=0; j<masyvas[i].N; j++)
        {
            masyvas[i].Suma += masyvas[i].NamuDarbai[j];

        }
        masyvas[i].Vidurkis = masyvas[i].Suma / masyvas[i].N;
    }
}

void isvedimas(int m, studentas masyvas[])
{
    int tikrinimas;
    cout << "Ar norite, jog programa apskaiciuotu vidurki, ar mediana? Jei norite vidurkio, spauskite 1, jei medianos, spauskite 2." << endl;
    cin >> tikrinimas;

    if (tikrinimas == 1)
        {
            cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(25) << setw(25) << "Galutinis (Vid.)" << endl;
            cout << "-------------------------------------------------------" << endl;
            for (int i=0; i<m; i++)
            {
                cout << setw(15) << masyvas[i].Vardas << setw(15) << masyvas[i].Pavarde;
                cout << setw(25) << fixed << setprecision(2) << masyvas[i].Vidurkis * 0.4 + masyvas[i].Egzaminas * 0.6 << endl;
            }
        }
    else
    {
        cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(25) << setw(25) << "Galutinis (Med.)" << endl;
        cout << "-------------------------------------------------------" << endl;
        for (int i=0; i<m; i++)
        {
            cout << setw(15) << masyvas[i].Vardas << setw(15) << masyvas[i].Pavarde;
            cout << setw(25) << fixed << setprecision(2) << masyvas[i].Mediana * 0.4 + masyvas[i].Egzaminas * 0.6 << endl;
        }
    }

}
