#include <bits/stdc++.h>

using namespace std;

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(1, 10);

/**
 * Klasė Zmogus, kuri yra abstrakti klasė
 */
class Zmogus
{
protected:
    string Vardas, Pavarde;
public:
    Zmogus(){};
    ~Zmogus() = default;
    virtual string getVardas() const { return Vardas; }
    virtual string getPavarde() const { return Pavarde; }
};

/**
 * Klasė studentas, išvesta iš abstrakčios klasės Zmogus
 */
class studentas : public Zmogus
{
    /**
     * Kintamieji, priklausantys klasei studentas
     * \param Vardas Vardas, kuris identifikuoja studentą
     * \param Pavarde Pavarde, kuri identifikuoja studentą
     * \param Galutinis Galutinis pažymys, suskaičiuotas pagal studento namų darbų bei egzamino įvertinimus
     */
private:
    string Vardas, Pavarde;
    double Galutinis;

public:
    /**
     * Konstruktorius
     */
    studentas() : Galutinis(0), Zmogus() {};
    /**
     * Destruktorius
     */
    ~studentas() = default;
    studentas(const studentas &laikinas)
    {
        Vardas = laikinas.Vardas;
        Pavarde = laikinas.Pavarde;
        Galutinis = laikinas.Galutinis;
    }
    studentas(ifstream& in, int pazymiu_kiekis);
    double getGalutinis() {return Galutinis;}
    /**
     * Funkcija, skirta studento duomenų nuskaitymui iš failo
     */
    void readStudentas(ifstream&);
};

studentas::studentas(ifstream& in, int pazymiu_kiekis)
{
    readStudentas(in);
}

/**
 * Nuskaito studento vardą, pavardę bei galutinį įvertinimą
 * @param in ifstream kintamasis
 */
void studentas::readStudentas(ifstream &in)
{

    in >> this->Vardas >> this->Pavarde >> this->Galutinis;
}

/**
 * Funkcija, kuri faile esančius duomenis nuskaito į vector tipo konteinerį
 * @param stud Vector tipo konteineris, skirtas laikyti studentų duomenis
 * @param studentu_kiekis Kintamasis saugantis studentų kiekį
 */
void SkaitymasIFaila (vector<studentas> &stud, int studentu_kiekis)
{
    stud.reserve(studentu_kiekis);
    string failo_pav = "Studentai_" + to_string(studentu_kiekis) + ".txt";
    studentas laikinas;
    ifstream in;
    in.open(failo_pav);
    auto pradzia = chrono::high_resolution_clock::now();
    for (int i=0; i < studentu_kiekis; i++)
    {
        laikinas.readStudentas(in);
        stud.push_back(laikinas);
    }
    in.close();
    auto pabaiga = chrono::high_resolution_clock::now();
    chrono::duration<double> trukme = pabaiga - pradzia;
    cout << "Failo su " + to_string(studentu_kiekis) + " studentu nuskaitymas uztruko: " << trukme.count() << " sek." << endl;
}

/**
 * Funkcija, kuri skirsto studentus į dvi grupes, atsižvelgiant į jų galutinį pažymį
 * @param studentu_kiekis Kintamas saugantis studentų kiekį
 * @param vektorius Vector tipo konteineris, skirtas laikyti visų studentų duomenis
 * @param kietekai Vector tipo konteineris, skirtas laikyti pažangesniųjų studentų duomenis
 * @param nenaudeliai Vector tipo konteineris, skirtas laikyti silpnesniųjų studentų duomenis
 */
void Grupavimas (int studentu_kiekis, vector<studentas> &vektorius, vector<studentas> &kietekai, vector<studentas> &nenaudeliai)
{
    auto pradzia = chrono::high_resolution_clock::now();

    for (int i=0; i < studentu_kiekis; i++)
    {
        if (vektorius.at(i).getGalutinis() < 5)
        {
            nenaudeliai.push_back(vektorius.at(i));
        }
        else kietekai.push_back(vektorius.at(i));
    }

    auto pabaiga = chrono::high_resolution_clock::now();
    chrono::duration<double> trukme = pabaiga - pradzia;
    cout << "Failo grupavimas su " + to_string(studentu_kiekis)+ " studentu i dvi grupes uztruko : " << trukme.count() << " sek." << endl;
}

/**
 * Funkcija, skirta sugrupuotus studentus išvesti į atitinkamus failus, pagal jų pažangumo lygį
 * @param studentu_kiekis Kintamasis saugantis studentų kiekį
 * @param kietekai Vector tipo konteineris, saugantis pažangesniųjų studentų duomenis
 * @param nenaudeliai Vector tipo konteineris, saugantis silpnesniųjų studentų duomenis
 */
void Isvedimas (int studentu_kiekis, vector<studentas> &kietekai, vector<studentas> &nenaudeliai)
{
    string failo_pav;
    failo_pav = "Kietekai_" + to_string(studentu_kiekis) + ".txt";

    auto pradzia_kiet = chrono::high_resolution_clock::now();

    ofstream out_kiet(failo_pav);
    for (studentas s : kietekai)
    {
        out_kiet << s.getVardas() << setw(20) << s.getPavarde() << setw(18) << fixed << setprecision(2) << s.getGalutinis() << endl;
    }
    out_kiet.close();
    auto pabaiga_kiet = chrono::high_resolution_clock::now();
    chrono::duration<double> trukme_kiet = pabaiga_kiet - pradzia_kiet;
    cout << "Kieteku isvedimas su " + to_string(studentu_kiekis) + " studentu uztruko : " << trukme_kiet.count() << " sek." << endl;


    failo_pav = "Nenaudeliai_" + to_string(studentu_kiekis) + ".txt";

    auto pradzia_nen = chrono::high_resolution_clock::now();

    ofstream out_nen(failo_pav);
    for (studentas s : nenaudeliai)
    {
        out_nen << s.getVardas() << setw(20) << s.getPavarde() << setw(18) << fixed << setprecision(2) << s.getGalutinis() << endl;
    }
    out_nen.close();
    auto pabaiga_nen = chrono::high_resolution_clock::now();
    chrono::duration<double> trukme_nen = pabaiga_nen - pradzia_nen;
    cout << "Nenaudeliu isvedimas su " + to_string(studentu_kiekis) + " studentu uztruko : " << trukme_nen.count() << " sek." << endl;
    cout << endl;
}

int main()
{
    /**
     * Pagrindinis ciklas sukamas c kartų, po kiekvienos iteracijos studentų kiekį dauginant iš 10
     * \param studentu_kiekis Kintamasis saugantis studentų kiekį
     */
    int studentu_kiekis = 100000;
    vector<studentas> stud;
    vector<studentas> kietekai;
    vector<studentas> nenaudeliai;

    for (int c=0; c<2; c++)
    {
        SkaitymasIFaila(stud, studentu_kiekis);

        Grupavimas(studentu_kiekis, stud, kietekai, nenaudeliai);
        Isvedimas(studentu_kiekis, kietekai, nenaudeliai);

        stud.clear();
        nenaudeliai.clear();
        kietekai.clear();
        studentu_kiekis *= 10;
    }
    return 0;
}
