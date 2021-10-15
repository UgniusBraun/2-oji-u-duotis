#include <bits/stdc++.h>
using namespace std;

struct studentas
{
    string Vardas, Pavarde;
    vector <double> NamuDarbai;
    int Egzaminas;
    double Galutinis;
};

vector<int> generuoti_pazymius (int pazymiu_kiekis);
double galutinis_pazymys (vector<int> skaiciai);
int generuoti_faila (vector<int> pazymiai);
void skaitymas_i_faila (vector<studentas> &stud, int studentu_kiekis);

vector<int> generuoti_pazymius (int pazymiu_kiekis)
{
    vector<int> skaiciai;
    for (int i=0; i<pazymiu_kiekis; i++)
    {
        skaiciai.push_back((rand() % 10) + 1);
    }
    return skaiciai;
}

double galutinis_pazymys (vector<int> skaiciai)
{
    studentas stud;
    stud.Galutinis = (accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size()) * 0.4 + (rand() % 10 + 1) * 0.6;
    return stud.Galutinis;
}

int generuoti_faila (vector<int> pazymiai)
{
    vector<int> skaiciai;
    studentas stud;
    int studentu_kiekis;
    cout << "Keletui studentu norite atsitiktinai sugeneruoti pazymius?" << endl;
    cin >> studentu_kiekis;
    string failo_pav = "Studentai_" + to_string(studentu_kiekis) + ".txt";

    auto pradzia = chrono::high_resolution_clock::now();

    ofstream out(failo_pav);
    out << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)";

    for (int i=1; i<studentu_kiekis + 1; i++)
    {
        skaiciai = generuoti_pazymius(5);
        out << setw(20) << "Vardas" + to_string(i) << setw(20) << "Pavarde" + to_string(i) << setw(18) << galutinis_pazymys(skaiciai) << endl;
        skaiciai.clear();
    }

    auto pabaiga = chrono::high_resolution_clock::now();
    chrono::duration<double> trukme = pabaiga - pradzia;
    cout << "Failo su " + to_string(studentu_kiekis) + " studentu generavimas uztruko: " << trukme.count() << " sekundziu" << endl;

    return studentu_kiekis;
}

void skaitymas_i_faila (vector<studentas> &stud, int studentu_kiekis)
{
    int studentu_skaicius = 0;
    string failo_pav = "Studentai_" + to_string(studentu_kiekis) + ".txt";
    string laikinas;
    ifstream in;
    in.open(failo_pav);
    if (in.is_open())
    {
        auto pradzia = chrono::high_resolution_clock::now();
		auto p = pradzia;
		getline(in >> ws, laikinas);
		while (studentu_skaicius < studentu_kiekis)
        {
            stud.resize(stud.size() + 1);
            in >> stud.at(studentu_skaicius).Vardas >> stud.at(studentu_skaicius).Pavarde >> stud.at(studentu_skaicius).Galutinis;
            studentu_skaicius++;
        }
        auto pabaiga = chrono::high_resolution_clock::now();
        chrono::duration<double> trukme = pabaiga - pradzia;
        cout << "Failo su " + to_string(studentu_kiekis) + " studentu generavimas uztruko: " << trukme.count() << " sek." << endl;
    }
}

int main()
{
    vector<int> skaiciai;
    int studentu_kiekis = generuoti_faila(skaiciai);
    vector<studentas> vektorius;
    skaitymas_i_faila(vektorius, studentu_kiekis);
    vector<studentas> kietekai;
    vector<studentas> nenaudeliai;
    int kiet = 0, nenaud = 0;

    auto pradzia = chrono::high_resolution_clock::now();

	for (int i=0; i<studentu_kiekis; i++)
    {
        if (vektorius.at(i).Galutinis >= 5.00)
        {
            kietekai.push_back(vektorius.at(i));
            kiet++;
        }
    }
    for (int i=0; i<studentu_kiekis; i++)
    {
        if (vektorius.at(i).Galutinis <= 5.00)
        {
            nenaudeliai.push_back(vektorius.at(i));
            nenaud++;
        }
    }
    auto pabaiga = chrono::high_resolution_clock::now();
	chrono::duration<double> trukme = pabaiga - pradzia;
	cout << "Failo grupavimas su " + to_string(studentu_kiekis)+ " studentu i dvi grupes uztruko : " << trukme.count() << " sek." << endl;

	string failo_pav;
	failo_pav = "Kietekai_" + to_string(studentu_kiekis) + ".txt";

	auto pradzia_kiet = chrono::high_resolution_clock::now();

	ofstream out_kiet(failo_pav);
	for (int i=0; i<studentu_kiekis; i++)
    {
        if (vektorius.at(i).Galutinis >= 5.00)
        {
            out_kiet << vektorius.at(i).Vardas << setw(20) << vektorius.at(i).Pavarde << setw(18) << vektorius.at(i).Galutinis << endl;
        }
    }
    auto pabaiga_kiet = chrono::high_resolution_clock::now();
	chrono::duration<double> trukme_kiet = pabaiga_kiet - pradzia_kiet;
	cout << "Kieteku isvedimas su " + to_string(studentu_kiekis) + " studentu uztruko : " << trukme_kiet.count() << " sek." << endl;


    failo_pav = "Nenaudeliai_" + to_string(studentu_kiekis) + ".txt";

	auto pradzia_nen = chrono::high_resolution_clock::now();

	ofstream out_nen(failo_pav);
	for (int i=0; i<studentu_kiekis; i++)
    {
        if (vektorius.at(i).Galutinis <= 5.00)
        {
            out_nen << vektorius.at(i).Vardas << setw(20) << vektorius.at(i).Pavarde << setw(18) << vektorius.at(i).Galutinis << endl;
        }
    }
    auto pabaiga_nen = chrono::high_resolution_clock::now();
	chrono::duration<double> trukme_nen = pabaiga_nen - pradzia_nen;
	cout << "Nenaudeliu isvedimas su " + to_string(studentu_kiekis) + " studentu uztruko : " << trukme_nen.count() << " sek." << endl;
}
