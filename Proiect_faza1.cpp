#include <iostream>
using namespace std;

class Liceu {
public:
    const int id;
    static int anulAparitieiLiceului;
    static int mediaAdmitere;
    static int getmediaAdmitere() {
        return mediaAdmitere;
    }
    int nrElevi;
    string adresa;
    float numar;
    int nrProfesori;
    int nrEleviEx;
    string* numeEleviEx;
    int buget;
    int nrClase;
    Liceu():id(1) {
        this->nrElevi = 100;
        this->adresa = "Popescu";
        this->numar = 3;
    }
    void afisareLiceu() {
        cout << "Numarul de elevi este de: " << nrElevi << ", iar adresa este: " << adresa <<" "<< numar << "." << endl;
    };

    Liceu(int nrProfesori, int nrEleviEx, string* numeEleviEx,int id):id(id) {
        this->nrProfesori = nrProfesori;
        this->nrEleviEx = nrEleviEx;
        this->numeEleviEx = new string[nrEleviEx];
        for (int i = 0; i < nrEleviEx; i++) {
            this->numeEleviEx[i] = numeEleviEx[i];
        }
    }
    ~Liceu() {
        if (this->numeEleviEx != NULL)
            delete[]this->numeEleviEx;
    }
    void afisareLiceu1() {
        cout << "Numarul profesorilor este de: " << nrProfesori << " si un numar de elevi exmatriculati cu numele: ";
        if (nrEleviEx != 0) {
            for (int i = 0; i < nrEleviEx; i++) {
                cout << numeEleviEx[i] << " ";
            }
        }
        else {
            cout << "NA" << endl;
        }
    }
    Liceu(float buget, int nrClase,int id):id(id) {
        this->buget = buget;
        this->nrClase = nrClase;
    }
    void afisareLiceu2() {
        cout << "Bugetul liceului este de: " << buget << ", iar numarul de clase este de: " << nrClase << endl;
    }
};
int Liceu::anulAparitieiLiceului = 1960;
int Liceu::mediaAdmitere = 9;



class Materie {
public:
    const int idMan;
    static int nrManuale;
    static string autorMan;
    static void getautorMan() {
      }
    string nume;
    int nrOre;
    float notaMaximaObtinuta;
    int nrProfesori;
    string* numeProfesori;
    Materie():idMan(1) {
        this->nume = "Matematica";
        this->nrOre = 30;
        this->notaMaximaObtinuta = 9,70;


    }
    void afisareMaterie() {
        cout << "Materia este: " << nume << ", si este sustinuta timp de: " << nrOre
            << " minute si nota maxima obtinuta a fost: " << notaMaximaObtinuta << "." << endl;
    }
    Materie(int notaMinimaObtinuta, int idMan):idMan(idMan){
        std::cout << "Nota minima obtinuta a fost: " << notaMinimaObtinuta << "." << std::endl;
    }

    Materie(int nrEleviPr, string numeE,int idMan,int nrProfesori,string* numeProfesori):idMan(idMan) {
        this->nrProfesori = nrProfesori;
        this->numeProfesori = new string[nrProfesori];
        for (int i = 0; i < nrProfesori;i++) {
            this->numeProfesori[i] = numeProfesori[i];
        }
       std:: cout << "Numarul de elevi prezenti la o ora este de: " << nrEleviPr << ",cu numele de" << numeE << "." << std::endl;
    }
    ~Materie() {
        if (this->numeProfesori != NULL)
            delete[]this->numeProfesori;
    }
    void afisareMaterie1() {
        cout << "Numarul de profesori care predau aceasta materie este de " << nrProfesori << ", iar numele lor este ";
       if (nrProfesori != 0) {
           for (int i = 0; i < nrProfesori; i++) {
               cout << numeProfesori[i] << " ";
           }
       }
       else {
           cout << "NA" << endl;
       }
    }
};
int Materie::nrManuale = 1;
string Materie::autorMan = "Dobrescu";



class Profesori {
public:
    const int nrIn;
    string nume;
    string manual;
    string materie;
    int nrTel;
    float salariu;
    static int nrClase;
    static string prenume;
    int claseDirig;
    static void getprenume() {

    }
    string* numeSef;

    Profesori():nrIn(1) {
        this->nume = "Antonescu";
        this->nrTel = 0740366456;
        this->salariu= 3452.7;

    }
    void afisareProfesori() {
        cout << "Numele profesorului este " << nume << " si are numarul de telefon " << nrTel
            << " si salariul " << salariu << "."<< endl;
    }

    Profesori(int claseDirig,string* numeSef,int nrIn):nrIn(nrIn) {
        this->claseDirig = claseDirig;
        this->numeSef = new string[claseDirig];
        for (int i = 0; i < claseDirig; i++) {
            this->numeSef[i] = numeSef[i];
        }
        std::cout << "Profesorul este diriginte la: " << claseDirig<<" clase." << std::endl;
    }
    ~Profesori() {
        if (this->numeSef != NULL)
            delete[]this->numeSef;
    }
    void afisareProfesori1() {
        cout << "Numarul sefilor de clasa este " << claseDirig<< ", iar numele lor sunt ";
        if (claseDirig != 0) {
            for (int i = 0; i < claseDirig; i++) {
                cout << numeSef[i] << " ";
            }
        }
        else {
            cout << "NA" << endl;
        }
    }

    Profesori(string materie, string manual,int nrIn):nrIn(nrIn) {
        this->materie = materie;
        this->manual = manual;
    }
    void afisareProfesori2() {
        cout << "Cei mai multi dintre profesori predau materia: " << materie << ", si lucreaza de pe manualul: " << manual << endl;
    }
};
int Profesori::nrClase = 3;
string Profesori::prenume = "Ionut";

void main() {
    cout << "LICEU" << endl;
    Liceu obiect1;
    cout << obiect1.id << endl;
    obiect1.afisareLiceu();
    cout << "Anul aparitiei liceului este: " << Liceu::anulAparitieiLiceului << endl;
    cout << "Media de admitere este :" << Liceu::getmediaAdmitere() << endl;
    string* numeEleviEx = new string[3];
    numeEleviEx[0] = "Popescu,";
    numeEleviEx[1] = "Ionescu,";
    numeEleviEx[2] = "Georgescu.";
    Liceu obiect2(42, 3, numeEleviEx,2);
    cout << obiect2.id << endl;
    obiect2.afisareLiceu1();
    cout << endl;
    Liceu obiect3(100000, 20,3);
    cout << obiect3.id << endl;
    obiect3.afisareLiceu2();

    cout << "MATERIE"<<endl;
    Materie obiect4;
    cout << obiect4.idMan << endl;
    obiect4.afisareMaterie();
    cout << "Numarul de manuale este de: " << Materie::nrManuale
        << ", iar autorul este: " << Materie::autorMan << "." << endl;
    Materie obiect5(5,2);
    cout << obiect5.idMan << endl;
    string* numeProfesori = new string[2];
    numeProfesori[0] = "Popescu,";
    numeProfesori[1] = "Ionescu.";
    Materie obiect6(1, " Ion",3, 2, numeProfesori);
    cout << obiect6.idMan << endl;
    obiect6.afisareMaterie1();
    cout << endl;

    cout << "PROFESORI"<<endl;
    Profesori obiect7;
    cout << obiect7.nrIn << endl;
    obiect7.afisareProfesori();
    cout << "Un profesor preda la " <<Profesori::nrClase << " clase, iar prenumele profesorului este " << Profesori::prenume << "." << endl;

    string* numeSef = new string[2];
    numeSef[0] = "Voiculescu,";
    numeSef[1] = "Paunescu.";
    Profesori obiect8(2,numeSef,2);
    cout << obiect8.nrIn << endl;
    obiect8.afisareProfesori1();
    cout << endl;
   
    Profesori obiect9("romana", "ART.",3);
    cout << obiect9.nrIn << endl;
    obiect9.afisareProfesori2();
    cout << endl;


}
