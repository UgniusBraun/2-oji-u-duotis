#include <bits/stdc++.h>

using namespace std;

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 10);

struct studentas
{
    string Vardas, Pavarde;
    double Galutinis;
};

vector<int> generuoti_pazymius (int pazymiu_kiekis)
{
    vector<int> skaiciai;
    for (int i=0; i<pazymiu_kiekis; i++)
    {
        skaiciai.push_back(dist(mt));
    }
    return skaiciai;
}

double galutinis_pazymys (vector<int> skaiciai)
{
    studentas stud;
    stud.Galutinis = (accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size()) * 0.4 + dist(mt) * 0.6;
    return stud.Galutinis;
}

void generuoti_faila (int studentu_kiekis)
{
    vector<int> skaiciai;
    studentas stud;
    string failo_pav = "Studentai_" + to_string(studentu_kiekis) + ".txt";

    auto pradzia = chrono::high_resolution_clock::now();

    ofstream out(failo_pav);
    out << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;

    for (int i=1; i <= studentu_kiekis; i++)
    {
        skaiciai = generuoti_pazymius(5);
        out << setw(20) << "Vardas" + to_string(i) << setw(20) << "Pavarde" + to_string(i) << setw(18) << galutinis_pazymys(skaiciai) << endl;
        skaiciai.clear();
    }
    out.close();

    auto pabaiga = chrono::high_resolution_clock::now();
    chrono::duration<double> trukme = pabaiga - pradzia;
    cout << "Failo su " + to_string(studentu_kiekis) + " studentu generavimas uztruko: " << trukme.count() << " sek." << endl;
}

void skaitymas_i_faila (vector<studentas> &stud, int studentu_kiekis)
{
    string failo_pav = "Studentai_" + to_string(studentu_kiekis) + ".txt";
    string laikinas;
    ifstream in;
    in.open(failo_pav);
    if (in.is_open())
    {
        stud.resize(studentu_kiekis + 1);
        auto pradzia = chrono::high_resolution_clock::now();
        in.ignore(256, '\n');
        for (int i=1 ;i <= studentu_kiekis; i++)
        {
            in >> stud.at(i).Vardas >> stud.at(i).Pavarde >> stud.at(i).Galutinis;
        }
        auto pabaiga = chrono::high_resolution_clock::now();
        chrono::duration<double> trukme = pabaiga - pradzia;
        cout << "Failo su " + to_string(studentu_kiekis) + " studentu nuskaitymas uztruko: " << trukme.count() << " sek." << endl;
    }
}

bool Lyginimas (studentas stud)
{
    return stud.Galutinis < 5;
}

int main()
{
    long int studentu_kiekis = 1000;
    vector<int> skaiciai;
    vector<studentas> vektorius;
    vector<studentas> kietekai;
    vector<studentas> nenaudeliai;
    for (int c=0; c<5; c++)
    {
        generuoti_faila(studentu_kiekis);
        skaitymas_i_faila(vektorius, studentu_kiekis);
        auto pradzia = chrono::high_resolution_clock::now();

        for (auto iteratorius = vektorius.begin(); iteratorius != vektorius.end(); ++iteratorius)
        {
            if (iteratorius->Galutinis < 5)
            {
                nenaudeliai.push_back(*iteratorius);
            }
        }
        remove_if(vektorius.begin(), vektorius.end(), Lyginimas);

        auto pabaiga = chrono::high_resolution_clock::now();
        chrono::duration<double> trukme = pabaiga - pradzia;
        cout << "Failo grupavimas su " + to_string(studentu_kiekis)+ " studentu i dvi grupes uztruko : " << trukme.count() << " sek." << endl;

        string failo_pav;
        failo_pav = "Kietekai_" + to_string(studentu_kiekis) + ".txt";

        auto pradzia_kiet = chrono::high_resolution_clock::now();

        ofstream out_kiet(failo_pav);
        for (int i=0; i < vektorius.size(); i++)
        {
            out_kiet << vektorius.at(i).Vardas << setw(20) << vektorius.at(i).Pavarde << setw(18) << vektorius.at(i).Galutinis << endl;
        }
        out_kiet.close();
        auto pabaiga_kiet = chrono::high_resolution_clock::now();
        chrono::duration<double> trukme_kiet = pabaiga_kiet - pradzia_kiet;
        cout << "Kieteku isvedimas su " + to_string(studentu_kiekis) + " studentu uztruko : " << trukme_kiet.count() << " sek." << endl;


        failo_pav = "Nenaudeliai_" + to_string(studentu_kiekis) + ".txt";

        auto pradzia_nen = chrono::high_resolution_clock::now();

        ofstream out_nen(failo_pav);
        for (int i=0; i < nenaudeliai.size(); i++)
        {
            out_nen << nenaudeliai.at(i).Vardas << setw(20) << nenaudeliai.at(i).Pavarde << setw(18) << nenaudeliai.at(i).Galutinis << endl;
        }
        out_nen.close();
        auto pabaiga_nen = chrono::high_resolution_clock::now();
        chrono::duration<double> trukme_nen = pabaiga_nen - pradzia_nen;
        cout << "Nenaudeliu isvedimas su " + to_string(studentu_kiekis) + " studentu uztruko : " << trukme_nen.count() << " sek." << endl;
        cout << endl;
        studentu_kiekis *= 10;
    }
    return 0;
}
