#include "Studentai.h"
#include "Funkcijos.h"

using namespace std;

int main()
{

    vector<string> Vardai_v = { "Petras", "Jonas", "Paulius", "Saulius", "Martynas", "Kornelijus", "Adomas", "Lukas", "Marius", "Kazimieras", "Dovydas", "Mantas", "Arnas", "Dziugas" };
    vector<string> Vardai_m = { "Eva", "Paulina", "Sofija", "Gintare", "Skaiste", "Marija", "Lukrecija", "Kornelija", "Egle", "Kamile", "Auguste", "Meda", "Ruta" };
    vector<string> Pavardes_v = { "Kazlauskas", "Vasiliauskas", "Petrauskas", "Paulauskas", "Urbonas", "Adomaitis", "Sadauskas", "Vaitkus", "Jankauskas", "Rimkus" };
    vector<string> Pavardes_m = { "Kazlauskaite", "Vasiliauskiene", "Paulauskyte", "Vaitkute", "Jankauskaite", "Rimkute", "Adomaitiene", "Petrauskyte" };
    vector<Studentas> studentai;

    int budas = 0;
    int pasirinkimas = 0;
    int rusiavimas = 0;
    int sk;
    Studentas S;
    //

    cout << "*****************************************************" << endl;
    cout << "Duomenu uzpildymo budas" << endl;
    cout << "1. Uzpildyti ranka" << endl;
    cout << "2. Uzpildyti pazymius automatiskai" << endl;
    cout << "3. Uzpildyti varda, pavarde bei pazymius automatiskai" << endl;
    cout << "4. Nuskaityti duomenis is failo" << endl;
    cout << "5. Generuoti failus" << endl;
    cout << "*****************************************************" << endl;

    while (true) {
        cout << "Jusu pasirinkimas: ";
        budas = IntInput();

        if (budas < 1 || budas > 5) {
            cout << "Netinkamas pasirinkimas!" << endl;
        }
        else break;
    }


    cout << "**************************************" << endl;
    cout << "Kaip norite surusiuoti rezultatus?" << endl;
    cout << "1. Pagal galutini pazymi (mazejanciai)" << endl;
    cout << "2. Pagal galutini pazymi (didejanciai)" << endl;
    cout << "3. Pagal varda (A -> Z)" << endl;
    cout << "4. Pagal varda (Z -> A)" << endl;
    cout << "5. Pagal pavarde (A -> Z)" << endl;
    cout << "6. Pagal pavarde (Z -> A)" << endl;
    cout << "7. Nerusiuoti" << endl;
    while (true) {

        rusiavimas = IntInput();
        if (rusiavimas < 1 || rusiavimas > 7) {
            cout << "Netinkamas pasirinkimas!" << endl;
        }
        else break;
    }

    cout << "----------------------------------" << endl;
    cout << "Pasirinktie galutinio balo skaiciavimo metoda: " << endl;
    cout << "1. Skaiciuoti naudojant vidurki" << endl;
    cout << "2. Skaiciuoti naudojant mediana" << endl;
    while (true) {

        cout << "Jusu pasirinkimas: ";
        S.pasirinkimas = IntInput();

        if (S.pasirinkimas != 1 && S.pasirinkimas != 2) {
            cout << "Netinkamas pasirinkimas!" << endl;
        }
        else break;
    }

    // Pildymas ranka

    if (budas == 1) {
        while (true) {
            bool loop = false;
            cout << "Iveskite savo varda: ";

            S.vardas = StringInput();

            cout << "Iveskite savo pavarde: ";

            S.pavarde = StringInput();

            cout << "Iveskite egzamino bala [1 - 10]: " << endl;
            while (true) {
                cout << "Pazymys: ";
                S.egz = IntInput();

                if (S.egz < 1 || S.egz>10) {
                    cout << "Iveskite pazymi nuo 1 iki 10" << endl;
                }
                else break;
            }


            cout << "Iveskite atliktu namu darbu skaiciu: " << endl;
            while (true) {
                S.n = IntInput();
                if (S.n) break;
            }

            cout << "----------------------------------" << endl;
            S.nd.resize(S.n);
            cout << "Iveskite pazymi nuo [1 - 10] " << endl;
            for (int j = 0; j < S.n; j++) {
                while (true) {
                    cout << "Pazymys: ";
                    S.nd[j] = IntInput();

                    if (S.nd[j] < 1 || S.nd[j] > 10) {
                        cout << "Iveskite skaiciu nuo 1 iki 10" << endl;
                    }
                    else break;

                }
            }
            if (S.pasirinkimas == 1) {
                S.vid = Vidurkis(S.nd, S.n);
                S.galut = 0.4 * S.vid + 0.6 * S.egz;
            }
            else {
                S.medi = Mediana(S.nd);
                S.galut = 0.4 * S.medi + 0.6 * S.egz;
            }
            cout << "*******************************" << endl;
            studentai.push_back(S);

            cout << "0. Baigti" << endl;
            cout << "1. Testi" << endl;
            while (true) {
                sk = IntInput();
                if (sk < 0 || sk > 1) {
                    cout << "Iveskite skaiciu 0 arba 1" << endl;
                }
                else break;
            }

            if (sk == 0) {
                break;
            }
            else loop = true;
        }
    }

    // *************************************
    // Pazymiu automatinis pildymas

    if (budas == 2) {
        while (true) {
            bool loop = false;

            cout << "Iveskite savo varda: ";

            S.vardas = StringInput();

            cout << "Iveskite savo pavarde: ";

            S.pavarde = StringInput();

            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> distribution(1, 10);
            S.egz = distribution(gen);

            cout << "Iveskite atliktu namu darbu skaiciu: " << endl;
            while (true) {
                S.n = IntInput();
                if (S.n) break;
            }
            S.nd.resize(S.n);
            for (int j = 0; j < S.n; j++) {

                S.nd[j] = distribution(gen);
            }
            if (S.pasirinkimas == 1) {
                S.vid = Vidurkis(S.nd, S.n);
                S.galut = 0.4 * S.vid + 0.6 * S.egz;
            }
            else {
                S.medi = Mediana(S.nd);
                S.galut = 0.4 * S.medi + 0.6 * S.egz;
            }
            cout << "*******************************" << endl;
            studentai.push_back(S);

            cout << "0. Baigti" << endl;
            cout << "1. Testi" << endl;
            while (true) {
                sk = IntInput();
                if (sk < 0 || sk > 1) {
                    cout << "Iveskite skaiciu 0 arba 1" << endl;
                }
                else break;
            }

            if (sk == 0) {
                break;
            }
            else loop = true;
        }
    }

    //***************************************
    //Automatinis vardo bei pazymiu pildymas

    if (budas == 3) {
        while (true) {
            bool loop = false;

            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> distribution(1, 10);
            uniform_int_distribution<int> lyties_num(0, 1); // 0 - vyras, 1 - moteris

            int lytis = lyties_num(gen);

            if (lytis == 0) {
                S.vardas = Vardai_v[uniform_int_distribution<int>(0, Vardai_v.size() - 1)(gen)];
                S.pavarde = Pavardes_v[uniform_int_distribution<int>(0, Pavardes_v.size() - 1)(gen)];
            }
            else {
                S.vardas = Vardai_m[uniform_int_distribution<int>(0, Vardai_m.size() - 1)(gen)];
                S.pavarde = Pavardes_m[uniform_int_distribution<int>(0, Pavardes_m.size() - 1)(gen)];
            }
            S.egz = distribution(gen);

            cout << "Iveskite atliktu namu darbu skaiciu: " << endl;
            while (true) {
                S.n = IntInput();
                if (S.n) break;
            }
            S.nd.resize(S.n);
            for (int j = 0; j < S.n; j++) {

                S.nd[j] = distribution(gen);
            }
            if (S.pasirinkimas == 1) {
                S.vid = Vidurkis(S.nd, S.n);
                S.galut = 0.4 * S.vid + 0.6 * S.egz;
            }
            else {
                S.medi = Mediana(S.nd);
                S.galut = 0.4 * S.medi + 0.6 * S.egz;
            }
            cout << "*******************************" << endl;
            studentai.push_back(S);

            cout << "0. Baigti" << endl;
            cout << "1. Testi" << endl;
            while (true) {
                sk = IntInput();
                if (sk < 0 || sk > 1) {
                    cout << "Iveskite skaiciu 0 arba 1" << endl;
                }
                else break;
            }

            if (sk == 0) {
                break;
            }
            else loop = true;
        }
    }

    // Nuskaitymas is failo

    if (budas == 4) {
        string filename = FailoPatikrinimas();
        readFile(filename, studentai);
    }

    // Failu generavimas

    if (budas == 5) {
        generateFile("1000.txt", 1000);
        readFile("1000.txt", studentai);
    }

    sortStudents(studentai, rusiavimas);

    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)  /" << setw(20) << "Galutinis (Med.)" << endl;
    cout << setfill('-') << setw(68) << "" << setfill(' ') << endl;
    for (const auto& S : studentai) {
        if (S.pasirinkimas == 1) {
            cout << left << setw(15) << S.pavarde << setw(15) << S.vardas << setw(20) << fixed << setprecision(2) << S.galut << endl;
        }
        else {
            cout << left << setw(15) << S.pavarde << setw(15) << S.vardas << setw(20) << " " << setw(20) << fixed << setprecision(2) << S.galut << endl;
        }
    }

}
