#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


class InstitutieScolara {
    string nume;
public:
    virtual void afiseazaAdresa()= 0;
    InstitutieScolara() {
        this->nume = "Liceu";
    }
    virtual ~InstitutieScolara() {} 
    string getNume() {
        return this->nume;
    }
    void setNume(string nume) {
        if (nume.length() > 3) {
            this->nume = nume;
        }
    }
};

class Liceu:public InstitutieScolara {
private:
    static string adresa;
    static float numar;
    int nrElevi;
    int nrProfesori;
    int buget;
    int nrClase;
    int nrEleviEx;
    string* numeEleviEx;
public:
    const int id;
    static int anulAparitieiLiceului;
    static int mediaAdmitere;
    static int getmediaAdmitere() {
        return mediaAdmitere;
    }

    void afiseazaAdresa() {
        cout << "Adresa liceului este " << this->adresa << endl;
    }
    Liceu() :id(1),InstitutieScolara() {
        this->nrElevi = 100;
        this->nrProfesori = 2;
        this->nrEleviEx = 2;
        this->numeEleviEx = new string[nrEleviEx];
        for (int i = 0; i < nrEleviEx; i++) {
            this->numeEleviEx[i] = numeEleviEx[i];
        }
    }
    void afisareLiceu() {
        cout << "Numarul de elevi este de: " << nrElevi << endl;
    };

    Liceu(int nrProfesori, int nrEleviEx, string* numeEleviEx, int id) :id(id),InstitutieScolara() {
        this->nrProfesori = nrProfesori;
        this->nrEleviEx = nrEleviEx;
        this->numeEleviEx = new string[nrEleviEx];
        for (int i = 0; i < nrEleviEx; i++) {
            this->numeEleviEx[i] = numeEleviEx[i];
        }
    }
    Liceu(const Liceu& obiect2) :id(id),InstitutieScolara(obiect2) {
        this->nrProfesori = obiect2.nrProfesori;
        this->nrEleviEx = obiect2.nrEleviEx;
        this->numeEleviEx = new string[obiect2.nrEleviEx];
        for (int i = 0; i < obiect2.nrEleviEx; i++) {
            this->numeEleviEx[i] = obiect2.numeEleviEx[i];
        }

    }
    ~Liceu() {
        if (this->numeEleviEx != NULL)
            delete[]this->numeEleviEx;
    }
    Liceu operator=(const Liceu& obiect2) {
        if (this != &obiect2) {
            InstitutieScolara::operator=(obiect2);
            this->nrProfesori = obiect2.nrProfesori;
            this->nrEleviEx = obiect2.nrEleviEx;
            if (this->numeEleviEx != NULL) {
                delete[]this->numeEleviEx;
            }
            this->numeEleviEx = new string[obiect2.nrEleviEx];
            for (int i = 0; i < obiect2.nrEleviEx; i++) {
                this->numeEleviEx[i] = obiect2.numeEleviEx[i];
            }
        }
        return *this;
    }
    Liceu operator+=(const Liceu& obiect2) {
        this->nrProfesori += obiect2.nrProfesori;
        int aux = this->nrEleviEx;
        this->nrEleviEx += obiect2.nrEleviEx;
        string* vector = new string[this->nrEleviEx];
        for (int i = 0; i < aux; i++) {
            vector[i] = this->numeEleviEx[i];
        }
        for (int i = aux; i < this->nrEleviEx; i++)
        {
            vector[i] = obiect2.numeEleviEx[i - aux];
        }
        if (this->numeEleviEx != NULL) {
            delete[]this->numeEleviEx;
        }
        this->numeEleviEx = vector;
        return*this;
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
    Liceu(float buget, int nrClase, int id) :id(id) {
        this->buget = buget;
        this->nrClase = nrClase;
    }
    void afisareLiceu2() {
        cout << "Bugetul liceului este de: " << buget << ", iar numarul de clase este de: " << nrClase << endl;
    }
    static string getAdresa() {
        return adresa;
    }
    static  float getNumar() {
        return numar;
    }
    static void setAdresa(string adresa) {
        Liceu::adresa = adresa;
    }
    static void setNumar(float numar) {
        Liceu::numar = numar;
    }
    void setElv(int nrEleviEx, string* numeEleviEx) {
        if (nrEleviEx > 0) {
            this->nrEleviEx = nrEleviEx;
            if (this->numeEleviEx != NULL) {
                delete[]this->numeEleviEx;
            }
            this->numeEleviEx = new string[nrEleviEx];
            for (int i = 0; i < nrEleviEx; i++) {
                this->numeEleviEx[i] = numeEleviEx[i];
            }
        }
    }
    int getNrElevi() {
        return nrElevi;
    }

    void setNrElevi(int nrElevi) {
        if (nrElevi > 0) {
            this->nrElevi = nrElevi;
        }

    }
    int getNrProfesori() {
        return nrProfesori;
    }

    void setNrProfesori(int nrProfesori) {
        if (nrProfesori > 0) {
            this->nrProfesori = nrProfesori;
        }

    }
    int getNrEleviEx() {
        return nrEleviEx;
    }

    void setNrEleviEx(int nrEleviEx) {
        if (nrEleviEx > 0) {
            this->nrEleviEx = nrEleviEx;
        }
    }
    string* getNumeEleviEx() {
        return numeEleviEx;
    }

    string setNumeEleviEx(int i) {
        if (i >= 0 && i < nrEleviEx)
        {
            return numeEleviEx[i];
        }
    }

    int getNrClase() {
        return nrClase;
    }

    void setNrClase(int nrClase) {
        if (nrClase > 0) {
            this->nrClase = nrClase;
        }
    }
    int getBuget() {
        return buget;
    }

    void setBuget(int buget) {
        if (buget > 0) {
            this->buget = buget;
        }
    }
    friend string getSirElevi(const Liceu& obiect2);
    friend int getElevi(const Liceu& obiect1);
    friend int getElevi1(Liceu& obiect1);
    friend ostream& operator<<(ostream& scoala, const Liceu& obiect3);
    friend istream& operator>>(istream& colegiu, Liceu& obiect2) {
        cout << "Introduceti numarul profesorilor: ";
        colegiu >> obiect2.nrProfesori;
        cout << "Numarul elevilor exmatriculati: ";
        colegiu >> obiect2.nrEleviEx;
        cout << "Numele elevilor ematriculati: ";
        if (obiect2.numeEleviEx != NULL) {
            delete[]obiect2.numeEleviEx;

            obiect2.numeEleviEx = new string[obiect2.nrEleviEx];
            for (int i = 0; i < obiect2.nrEleviEx; i++) {
                colegiu >> obiect2.numeEleviEx[i];
            }
            return colegiu;
        }
    }
    friend ifstream& operator>>(ifstream& colegiu, Liceu& obiect3) {
        cout << "Introduceti numarul profesorilor: ";
        colegiu >> obiect3.nrProfesori;
        cout << "Numarul elevilor exmatriculati: ";
        colegiu >> obiect3.nrEleviEx;
        cout << "Numele elevilor ematriculati: ";
        obiect3.numeEleviEx = new string[obiect3.nrEleviEx];
        for (int i = 0; i < obiect3.nrEleviEx; i++) {
            colegiu >> obiect3.numeEleviEx[i];
        }

        return colegiu;
    }
    friend ofstream& operator<<(ofstream& scoala, const Liceu& obiect3) {
        //scoala << "Liceul are un buget de:" << obiect3.buget << " si un numar de clase de: " << obiect3.nrClase;
        scoala << "Numarul de profesori este: " << obiect3.nrProfesori << " ";
        scoala << "Numarul de elevi exmatriculati: " << obiect3.nrEleviEx << " ";
        scoala << "Numele acestora este: ";
        for (int i = 0; i < obiect3.nrEleviEx; i++) {
            scoala << obiect3.numeEleviEx[i] << ", ";
        }
        return scoala;
    }
    void citeste() {
        std::cout << "Introduceti adresa liceului: ";
        std::cin >> adresa;
    }
    void afiseaza() const {
        std::cout << "Numele liceului: " << adresa << std::endl;
    }
};

string getSirElevi(const Liceu& obiect2) {
    string aux = "";
    for (int i = 0; i < obiect2.nrEleviEx; i++) {
        aux += obiect2.numeEleviEx[i] + ",";
    }
    return aux;
}
int getElevi(const Liceu& obiect1) {
    return obiect1.nrElevi;
}
int getElevi1(Liceu& obiect1) {
    obiect1.nrElevi = obiect1.nrElevi - 20;
    return obiect1.nrElevi;
}
int Liceu::anulAparitieiLiceului = 1960;
int Liceu::mediaAdmitere = 9;
string Liceu::adresa = "Popescu";
float Liceu::numar = 3;

ostream& operator<<(ostream& scoala, const Liceu& obiect3) {
    //scoala << "Liceul are un buget de:" << obiect3.buget << " si un numar de clase de: " << obiect3.nrClase;
    scoala << "Numarul de profesori este: " << obiect3.nrProfesori << " ";
    scoala << "Numarul de elevi exmatriculati: " << obiect3.nrEleviEx << " ";
    scoala << "Numele acestora este: ";
    for (int i = 0; i < obiect3.nrEleviEx; i++) {
        scoala << obiect3.numeEleviEx[i] << ", ";
    }
    return scoala;
}

class Materie {
private:
    static string zilePractica;
    string alteMaterii;
    int nrMaterii;
    string nume;
    int nrOre;
    float notaMaximaObtinuta;
    int nrProfesori;
    string* numeProfesori;
public:
    const int idMan;
    static int nrManuale;
    static string autorMan;
    static void getautorMan() {
    }
    Materie() :idMan(1) {
        this->nume = "Matematica";
        this->nrOre = 40;
        this->notaMaximaObtinuta = 9.70;
        this->nrProfesori = 2;
        this->numeProfesori = new string[nrProfesori];
        for (int i = 0; i < nrProfesori; i++) {
            this->numeProfesori[i] = numeProfesori[i];
        }
    }

    void afisareMaterie() {
        cout << "Materia este: " << nume << ", si este sustinuta timp de: " << nrOre
            << " minute si nota maxima obtinuta a fost: " << notaMaximaObtinuta << "." << endl;
    }
    Materie operator+(int nrOre) const {
        Materie aux = *this;
        aux.nrOre = this->nrOre + nrOre;
        return aux;
    }
    Materie(int notaMinimaObtinuta, int idMan) :idMan(idMan) {
        std::cout << "Nota minima obtinuta a fost: " << notaMinimaObtinuta << "." << std::endl;
    }

    Materie operator++() {
        this->nrOre++;
        return *this;
    }

    Materie operator++(int) {
        Materie initial = *this;
        this->nrOre++;
        return initial;
    }
    Materie(int nrEleviPr, string numeE, int idMan, int nrProfesori, string* numeProfesori) :idMan(idMan){
        this->nrProfesori = nrProfesori;
        this->numeProfesori = new string[nrProfesori];
        for (int i = 0; i < nrProfesori; i++) {
            this->numeProfesori[i] = numeProfesori[i];
        }
        std::cout << "Numarul de elevi prezenti la o ora este de: " << nrEleviPr << ",cu numele de" << numeE << "." << std::endl;
    }

    Materie(const Materie& obiect6) :idMan(idMan) {
        this->notaMaximaObtinuta = obiect6.notaMaximaObtinuta;
        this->nrOre = obiect6.nrOre;
        this->nrProfesori = obiect6.nrProfesori;
        this->numeProfesori = new string[obiect6.nrProfesori];
        for (int i = 0; i < obiect6.nrProfesori; i++) {
            this->numeProfesori[i] = obiect6.numeProfesori[i];
        }

    }

    ~Materie() {
        if (this->numeProfesori != NULL)
            delete[]this->numeProfesori;
    }
    Materie operator=(const Materie& obiect6) {
        if (this != &obiect6) {
            this->nrOre = obiect6.nrOre;
            if (this != &obiect6) {
                this->nrProfesori = obiect6.nrProfesori;
                if (this->numeProfesori != NULL) {
                    delete[]this->numeProfesori;
                }
                this->numeProfesori = new string[obiect6.nrProfesori];
                for (int i = 0; i < obiect6.nrProfesori; i++) {
                    this->numeProfesori[i] = obiect6.numeProfesori[i];
                }
            }
        }
        return *this;
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
    static  string getZilePractica() {
        return zilePractica;
    }
    static void setZilePractica(string zilePractica) {
        Materie::zilePractica = zilePractica;
    }
    string getNume() {
        return nume;
    }
    string setNume(int i) {
        return nume;
    }
    int getNrOre() {
        return nrOre;
    }
    void setNrOre(int nrClase) {
        if (nrClase > 0) {
            this->nrOre = nrOre;
        }
    }
    float getNotaMaximaObtinuta() {
        return notaMaximaObtinuta;
    }

    void setNotaMaximaObtinuta(float notaMaximaObtinuta) {
        if (notaMaximaObtinuta > 0) {
            this->notaMaximaObtinuta = notaMaximaObtinuta;
        }
    }
    bool operator>(Materie obiect10) {
        return this->nrOre > obiect10.nrOre;
    }
    friend int getNrOre(const Materie& obiect4);
    friend float getNotaMax(const Materie& obiect4);
    friend  Materie operator+(int nrOre, const Materie& obiect4) {
        Materie aux = obiect4;
        aux.nrOre = obiect4.nrOre + nrOre;
        return aux;
    }
    friend ostream& operator<<(ostream& ore, const Materie& obiect10);
    friend istream& operator>>(istream& materie, Materie& obiect6) {
        cout << "Introduceti numarul de clase: ";
        materie >> obiect6.nrProfesori;
        if (obiect6.numeProfesori != NULL) {
            delete[]obiect6.numeProfesori;

            obiect6.numeProfesori = new string[obiect6.nrProfesori];
            for (int i = 0; i < obiect6.nrProfesori; i++) {
                materie >> obiect6.numeProfesori[i];
            }
            return materie;
        }
    }
    void citeste() {
        std::cout << "Introduceti numele materiei: ";
        std::cin >> nume;
    }


    void afiseaza() const {
        std::cout << "Numele materiei: " << nume << std::endl;
    }
    friend ofstream& operator<<(ofstream& ora, const Materie& obiect4) {
        ora << "Materia se desfasoara intr-un numar de ore pe saptamana de:" << obiect4.nrOre;
        ora << "Numarul de profesori este: " << obiect4.nrProfesori << " ";
        ora << "Numele acestora este: ";
        for (int i = 0; i < obiect4.nrProfesori; i++) {
            ora << obiect4.numeProfesori[i] << ", ";
        }
        return ora;
    }
    friend ifstream& operator>>(ifstream& m, Materie& obiect4) {
        m >> obiect4.nrOre;
        m >> obiect4.nrProfesori;
        if (obiect4.numeProfesori != NULL) {
            delete[]obiect4.numeProfesori;

            obiect4.numeProfesori = new string[obiect4.nrProfesori];
            for (int i = 0; i < obiect4.nrProfesori; i++) {
                m >> obiect4.numeProfesori[i];
            }
            return m;
        }
    }

};
ostream& operator<<(ostream& ore, const Materie& obiect4) {
    ore << "Materia se desfasoara intr-un numar de ore pe saptamana de:" << obiect4.nrOre;
    ore << "Numarul de profesori este: " << obiect4.nrProfesori << " ";
    ore << "Numele acestora este: ";
    for (int i = 0; i < obiect4.nrProfesori; i++) {
        ore << obiect4.numeProfesori[i] << ", ";
    }
    return ore;
}

int getNrOre(const Materie& obiect4) {
    return obiect4.nrOre;
}
float getNotaMax(const Materie& obiect4) {
    return obiect4.notaMaximaObtinuta;

}
int Materie::nrManuale = 1;
string Materie::autorMan = "Dobrescu";
string Materie::zilePractica = "Luni, Miercuri,Joi ";

class Profesori{
private:
    static float salariul;
    string nume;
    string manual;
    string materie;
    long long int nrTel;
    int claseDirig;
    string* numeSef;
public:
    const int nrIn;
    static int nrClase;
    static string prenume;
    static void getprenume() {

    }

    Profesori() :nrIn(1){
        this->nume = "Antonescu";
        this->nrTel = 1234567456;
        this->claseDirig = 2;
        this->numeSef = new string[claseDirig];
        for (int i = 0; i < claseDirig; i++) {
            this->numeSef[i] = numeSef[i];
        }
    }
    void afisareProfesori() {
        cout << "Numele profesorului este " << nume << " si are numarul de telefon " << nrTel << "." << endl;
    }
  
    Profesori(int claseDirig, string* numeSef, int nrIn) :nrIn(nrIn) {
        this->claseDirig = claseDirig;
        this->numeSef = new string[claseDirig];
        for (int i = 0; i < claseDirig; i++) {
            this->numeSef[i] = numeSef[i];
        }
        std::cout << "Profesorul este diriginte la: " << claseDirig << " clase." << std::endl;
    }
    ~Profesori() {
        if (this->numeSef != NULL)
            delete[]this->numeSef;
    }
    void afisareProfesori1() {
        cout << "Numarul sefilor de clasa este " << claseDirig << ", iar numele lor sunt ";
        if (claseDirig != 0) {
            for (int i = 0; i < claseDirig; i++) {
                cout << numeSef[i] << " ";
            }
        }
        else {
            cout << "NA" << endl;
        }
    }
    Profesori operator+=(const Profesori& obiect8) {
        int aux = this->claseDirig;
        this->claseDirig += obiect8.claseDirig;
        string* vector = new string[this->claseDirig];
        for (int i = 0; i < aux; i++) {
            vector[i] = this->numeSef[i];
        }
        for (int i = aux; i < this->claseDirig; i++)
        {
            vector[i] = obiect8.numeSef[i - aux];
        }
        if (this->numeSef != NULL) {
            delete[]this->numeSef;
        }
        this->numeSef = vector;
        return*this;
    }
    Profesori(const Profesori& obiect8) :nrIn(nrIn){
        this->claseDirig = obiect8.claseDirig;
        this->numeSef = new string[obiect8.claseDirig];
        for (int i = 0; i < obiect8.claseDirig; i++) {
            this->numeSef[i] = obiect8.numeSef[i];
        }

    }
    Profesori operator=(const Profesori& obiect8) {
        if (this != &obiect8) {
            this->claseDirig = obiect8.claseDirig;
            if (this->numeSef != NULL) {
                delete[]this->numeSef;
            }
            this->numeSef = new string[obiect8.claseDirig];
            for (int i = 0; i < obiect8.claseDirig; i++) {
                this->numeSef[i] = obiect8.numeSef[i];
            }
        }
        return *this;
    }
    bool operator==(const Profesori& o) const {
        return this->manual == o.manual;
    }
    Profesori(string materie, string manual, int nrIn) :nrIn(nrIn) {
        this->materie = materie;
        this->manual = manual;
    }
    void afisareProfesori2() {
        cout << "Cei mai multi dintre profesori predau materia: " << materie << ", si lucreaza de pe manualul: " << manual << endl;
    }
    static  float getSalariul() {
        return salariul;
    }
    static void setSalariul(float salariul) {
        Profesori::salariul = salariul;
    }
    string getManual() {
        return manual;
    }
    string setManual() {
        return manual;
    }
    string getNume() {
        return nume;
    }
    string setNume() {
        return nume;
    }
    string getMaterie() {
        return materie;
    }

    string setMaterie() {
        return materie;
    }
    long long int getNrTel() {
        return nrTel;
    }
    void setNrTel(int nrTel) {
        if (nrTel != NULL) {
            this->nrTel = nrTel;
        }

    }
    int getNrClaseDirig() {
        return claseDirig;
    }

    void setNrClaseDirig(int nrClaseDirig) {
        if (nrClaseDirig > 0) {
            this->claseDirig = nrClaseDirig;
        }
    }
    string* getNumeSef() {
        return numeSef;
    }
    string setNumeSef(int i) {
        if (i >= 0 && i < claseDirig)
        {
            return numeSef[i];
        }
    }
    friend string getSirSefClasa(const Profesori& obiect8);
    friend string getMaterie(const Profesori& obiect9);
    friend istream& operator>>(istream& prof, Profesori& obiect11) {
        cout << "Introduceti numarul de clase: ";
        prof >> obiect11.claseDirig;
        if (obiect11.numeSef != NULL) {
            delete[]obiect11.numeSef;

            obiect11.numeSef = new string[obiect11.claseDirig];
            for (int i = 0; i < obiect11.claseDirig; i++) {
                prof >> obiect11.numeSef[i];
            }
            return prof;
        }
    }
    bool operator!=(const Profesori& obiect8) {
        return this->claseDirig != obiect8.claseDirig;
    }
    void citeste() {
        std::cout << "Introduceti numele manualului: ";
        std::cin >> nume;
    }
    void afiseaza() const {
        std::cout << "Numele manualului: " << nume << std::endl;

    }
    friend ostream& operator<<(ostream& clase, const Profesori& obiect9);
};
string getSirSefClasa(const Profesori& obiect8) {
    string aux = "";
    for (int i = 0; i < obiect8.claseDirig; i++) {
        aux += obiect8.numeSef[i] + ",";
    }
    return aux;
}
string getMaterie(const Profesori& obiect9) {
    return obiect9.materie;
}

int Profesori::nrClase = 3;
string Profesori::prenume = "Ionut";
float Profesori::salariul = 3457.8;
ostream& operator<<(ostream& clase, const Profesori& obiect9) {
    clase << "Numarul de clase este: " << obiect9.claseDirig << " ";
    clase << "Numele acestora este: ";
    for (int i = 0; i < obiect9.claseDirig; i++) {
        clase << obiect9.numeSef[i] << ", ";
    }
    return clase;
};

class Cladire {
    string nume;
public:
    virtual void afiseazaCladire() = 0;
    Cladire() {
        this->nume = "Scoala";
    }
    virtual ~Cladire() {}
    string getNume() {
        return this->nume;
    }
    void setNume(string nume) {
        if (nume.length() > 3) {
            this->nume = nume;
        }
    }
};
class Scoala:public Cladire {
private:
    string numeScoala;
    Profesori manual; // Atribut de tip Profesori
    int nr;
    int numar;
public:
    Scoala():Cladire() {
        this->numeScoala = "Colegiu";
        this->nr = 12;
    }
    void afiseazaCladire() {
        cout << "Numele scolii este " << this->numeScoala <<endl;
    }
    Scoala(string numeScoala, int nr, Profesori manual):Cladire() {
        this->numeScoala = numeScoala;
        this->nr = nr;
    }
    Scoala(const Scoala& p):Cladire(p) {
        this->numeScoala = p.numeScoala;
        this->nr = p.nr;
        this->numar = p.numar;
    }
    Scoala(string numeScoala) :Cladire() {
        this->numeScoala= numeScoala;
    }

    void setManual(const Profesori& prof) {
        manual = prof;
    }

    Profesori getManual() const {
        return manual;
    }
    void setNumeScoala(const string& nume) {
        numeScoala = nume;
    }

    string getNumeScoala() const {
        return numeScoala;
    }
    int getNr() const {
        return nr;
    }
    void setNr(int nr) {
        if (nr > 0) {
            this->nr = nr;
        }
    }
    int getNumar() const {
        return numar;
    }
    void setNumar(int numar) {
        if (nr > 0) {
            this->numar = numar;
        }
    }

    bool operator==(const Scoala& o) const {
        return this->numeScoala == o.numeScoala &&
            this->manual == o.manual
            && this->nr == o.nr;
    }

    bool operator!=(const Scoala& s) const {
        return !(*this == s);
    }

    Scoala& operator=(const Scoala& m) {
        if (this != &m) {
            this->numeScoala = m.numeScoala;
            this->manual = m.manual;
            this->nr = m.nr;
            this->numar = m.numar;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& scl, const Scoala& obiect20);
    friend istream& operator>>(istream& s, Scoala& obiect20) {
        cout << "Introduceti nume: ";
        s >> obiect20.numeScoala;
        cout << "Introduceti numarul: ";
        s >> obiect20.nr;
        return s;
    }
    friend ifstream& operator>>(ifstream& s, Scoala& obiect21) {
        s >> obiect21.nr;
        s >> obiect21.numeScoala;
        return s;
    }
    friend ofstream& operator<<(ofstream& scl, const Scoala& obiect21) {
        scl << "Numarul de manuale este: " << obiect21.nr << " ";
        scl << "Numele scolii: " << obiect21.numeScoala << " ";
        return scl;
    }

};

class ProfesorDeMatematica :public Profesori {
private:
    string* ProblemeRezolvate;
    int n;
    string cartePublicata;
public:
    ProfesorDeMatematica():Profesori(){
        this->n = 2;
        this->ProblemeRezolvate = new string[n];
        for (int i = 0; i < n; i++) {
            this->ProblemeRezolvate[i] = ProblemeRezolvate[i];
        }
        this->cartePublicata = "Gazeta";
    }
    ProfesorDeMatematica(int claseDririg,string*numeSef,int nrIn, int nrProblemeRezolvate, string cartePublicata):Profesori()  {
        this->n=n;
        this->ProblemeRezolvate = new string[n];
        for (int i = 0; i < n; i++) {
            this->ProblemeRezolvate[i] = nrProblemeRezolvate;
        }
        this->cartePublicata = cartePublicata;
    }
  

    ProfesorDeMatematica(const ProfesorDeMatematica& p):Profesori(p){
        this->n=p.n;
        this->ProblemeRezolvate = new string[p.n];
        for (int i = 0; i <p.n; i++) {
            this->ProblemeRezolvate[i] = p.ProblemeRezolvate[i];
        }
        this->cartePublicata = p.cartePublicata;
    }
    ProfesorDeMatematica operator=(const ProfesorDeMatematica& s) {
        if (this != &s) {
            if (this->ProblemeRezolvate) {
                delete[]this->ProblemeRezolvate;
            }
            this->n=s.n;
            this->ProblemeRezolvate = new string[s.n];
            for (int i = 0; i < s.n; i++) {
                this->ProblemeRezolvate[i] = s.ProblemeRezolvate[i];
            }
            this->cartePublicata = s.cartePublicata;
        }
        return *this;
    }
    ~ProfesorDeMatematica() {
        if (this->ProblemeRezolvate) {
            delete[]this->ProblemeRezolvate;
        }
    }
    friend ostream& operator<<(ostream& prof, const ProfesorDeMatematica& s) {
        prof << "Nume probleme rezolvate pentru revista: ";
        for (int i = 0; i < s.n; i++) {
            prof<< s.ProblemeRezolvate[i] << ", "<<endl;
        }
        prof << "Numele cartii publicate:";
        prof<< s.cartePublicata << endl;
        return prof;
    }

     int getN() {
        return n;
    }
    void setN(int n) {
        if (n != NULL) {
            this->n = n;
        }

    }
    string getCartePublicata() {
        return cartePublicata;
    }

    void setCartePublicata (string cartePublicata){
        this->cartePublicata = cartePublicata;
    }
    string* getProblemeRezolvate() {
        return ProblemeRezolvate;
    }
    string setProblemeRezolvate(int i) {
        if (i >= 0 && i < n)
        {
            return ProblemeRezolvate[i];
        }
    }
};

class Matematica :public Materie{
private:
    int minuteOra;
    string numeProf;
public:
    Matematica() :Materie(){
        this->minuteOra= 50; 
        this->numeProf= "Popescu";
    }
    Matematica(int notaMinimabtinuta, int idMna,int minuteOra, string numeProf) :Materie() {
        this->minuteOra= minuteOra;
        this->numeProf = numeProf;
    }


    Matematica(const Matematica& m) :Materie(m){
        this->minuteOra = m.minuteOra;
        this->numeProf = m.numeProf;
    }
    Matematica operator=(const Matematica& k) {
        if (this != &k) {
            this->minuteOra = k.minuteOra;
            this->numeProf = k.numeProf;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& mate, const Matematica& s) {
        mate<< "Nume profesor de matematica: ";
        mate << s.numeProf<<endl;
        mate<< "O ora de curs dureaza:";
        mate << s.minuteOra;
        cout<< " minute."<<endl;
        return mate;
    }

    int getMinuteOra() {
        return minuteOra;
    }
    void setMinuteOra(int minuteOra) {
        if (minuteOra != NULL) {
            this->minuteOra = minuteOra;
        }

    }
    string getNumeProf() {
        return numeProf;
    }

    void setNumeProf(string numeProf) {
        this->numeProf = numeProf;
    }
    void descriere() {
        cout << "O ora dureaza" << this->minuteOra << " ore si numele profesorului este " << this->numeProf << endl;
    }
};
class Sc {
    int nr;
    Cladire** scoli;
public:
    Sc() {
        this->nr = 10;
        this->scoli = new Cladire * [10];
        for (int i = 0; i < 10; i++) {
            this->scoli[i] = new Scoala();
        }

    }
    Cladire*& operator[](int i) {
        if (i >= 0 && i < this->nr)
            return this->scoli[i];
    }
    ~Sc() {
        if (this->scoli != NULL) {
            delete[]this->scoli;
        }
    }

};


void main() {
    cout << "LICEU" << endl;
    Liceu obiect1;
    cout << obiect1.id << endl;
    obiect1.afisareLiceu();
    cout << "Adresa este: " << Liceu::getAdresa() << " " << Liceu::getNumar() << "." << endl;
    obiect1.setAdresa("Popescu");
    obiect1.setNumar(3);
    cout << getElevi(obiect1);
    cout << endl;
    cout << getElevi1(obiect1);
    cout << endl;
    cout << "Anul aparitiei liceului este: " << Liceu::anulAparitieiLiceului << endl;
    cout << "Media de admitere este :" << Liceu::getmediaAdmitere() << endl;
    string* numeEleviEx = new string[3];
    numeEleviEx[0] = "Popescu,";
    numeEleviEx[1] = "Ionescu,";
    numeEleviEx[2] = "Georgescu.";
    Liceu obiect2(42, 3, numeEleviEx, 2);
    cout << obiect2.id << endl;
    obiect2.afisareLiceu1();
    cout << endl;
    cout << getSirElevi(obiect2);
    cout << endl;
    Liceu obiect12;
    obiect12 = obiect2;
    obiect12.afisareLiceu1();
    cout << endl;
    obiect1 += obiect2;
    obiect1.afisareLiceu1();
    cout << endl;
    Liceu obiect3(100000, 20, 3);
    cout << obiect3.id << endl;
    obiect3.afisareLiceu2();
    Liceu L1(obiect3);
    obiect3.afisareLiceu2();
    //cout << obiect3 << endl;
    cin >> obiect2;

    cout << "MATERIE" << endl;
    Materie obiect4;
    cout << obiect4.idMan << endl;
    obiect4.afisareMaterie();
    cout << "Numarul de manuale este de: " << Materie::nrManuale
        << ", iar autorul este: " << Materie::autorMan << "." << endl;
    cout << "Zilele in care se practica aceasta materie sunt: " << Materie::getZilePractica() << endl;
    obiect4.setZilePractica("Luni, Miercuri, Joi");
    cout << endl;
    cout << getNrOre(obiect4);
    cout << endl;
    cout << getNotaMax(obiect4);
    cout << endl;
    Materie obiect5(5, 2);
    cout << obiect5.idMan << endl;
    string* numeProfesori = new string[2];
    numeProfesori[0] = "Popescu,";
    numeProfesori[1] = "Ionescu.";
    Materie obiect6(1, " Ion", 3, 2, numeProfesori);
    cout << obiect6.idMan << endl;
    obiect6.afisareMaterie1();
    cout << endl;
    Materie obiect13;
    obiect13 = obiect6;
    obiect13.afisareMaterie1();
    cout << endl;
    Materie M1(obiect6);
    obiect6.afisareMaterie1();
    cout << endl;
    Materie obiect10 = obiect4 + 5;
    cout << obiect10 << endl;
    if (obiect10 > obiect4) {
        cout << "Este mai mare" << endl;
    }
    else
        cout << "Este mai mic" << endl;
    Materie obiect18 = obiect4++;
    obiect18 = ++obiect4;
    cout << obiect18 << endl;


    cout << "PROFESORI" << endl;
    Profesori obiect7;
    cout << obiect7.nrIn << endl;
    obiect7.afisareProfesori();
    cout << "Un profesor preda la " << Profesori::nrClase << " clase, iar prenumele profesorului este " << Profesori::prenume << "." << endl;
    cout << "Salariul profesorului este de: " << Profesori::getSalariul() << endl;
    obiect7.setSalariul(3457.8);
    string* numeSef = new string[2];
    numeSef[0] = "Voiculescu,";
    numeSef[1] = "Paunescu.";
    Profesori obiect8(2, numeSef, 2);
    cout << obiect8.nrIn << endl;
    obiect8.afisareProfesori1();
    cout << endl;
    Profesori P1(obiect8);
    obiect8.afisareProfesori1();
    cout << endl;
    cout << getSirSefClasa(obiect8);
    cout << endl;
    Profesori obiect14;
    obiect14 = obiect8;
    obiect14.afisareProfesori1();
    cout << endl;
    Profesori obiect16;
    obiect16 = obiect8;
    obiect16.afisareProfesori1();
    cout << endl;
    Profesori obiect9("romana", "ART.", 3);
    cout << obiect9.nrIn << endl;
    obiect9.afisareProfesori2();
    cout << endl;
    cout << getMaterie(obiect9) << endl;
    Profesori obiect11;
    cin >> obiect11;
    if (obiect8 != obiect11) {
        cout << "Clasele sunt diferite";
    }
    else
        cout << "Nu sunt diferite" << endl;

    cout << "Liceu" << endl;
    int nrEleviEx = 0;
    cout << "Numarul de elevi este ";
    cin >> nrEleviEx;
    Liceu* vector = new Liceu[nrEleviEx];
    for (int i = 0; i < nrEleviEx; i++) {
        cin >> vector[i];
    }
    for (int i = 0; i < nrEleviEx; i++) {
        cout << vector[i] << endl;
    }
    const int nrLinii = 2;
    const int nrColoane = 2;
    Liceu liceu[nrLinii][nrColoane];
    for (int i = 0; i << nrLinii; i++) {
        for (int j = 0; j < nrColoane; j++) {
            cout << "Elevul de pe locul: " << i + 1 << " " << j + 1 << endl;
        }
        for (int i = 0; i << nrLinii; i++) {
            for (int j = 0; j < nrColoane; j++) {
                cout << liceu[i][j] << " ";
            }
        }cout << endl;
    }


    cout << "Materie" << endl;
    int nrProfesori = 0;
    cout << "Numarul de profesori este ";
    cin >> nrProfesori;
    Materie* vector1 = new Materie[nrProfesori];
    for (int i = 0; i < nrProfesori; i++) {
        cin >> vector1[i];
    }
    for (int i = 0; i < nrProfesori; i++) {
        cout << vector1[i] << endl;
    }

    cout << "Profesori" << endl;
    int claseDirig = 0;
    cout << "Numarul de clase este ";
    cin >> claseDirig;
    Profesori* vector2 = new Profesori[claseDirig];
    for (int i = 0; i < claseDirig; i++) {
        cin >> vector2[i];
    }
    for (int i = 0; i < claseDirig; i++) {
        cout << vector2[i] << endl;
    }

    cout << endl << endl << endl << endl;
    Scoala scoala;
    scoala.setNumeScoala("Colegiul National");
    Profesori prof;
    prof.citeste();
    scoala.setManual(prof);
    cout << "Numele scolii: " << scoala.getNumeScoala() << endl;
    Scoala altaScoala;
    Scoala scoala1;
    altaScoala != scoala;
    scoala1 = scoala;
    Scoala scoala2;
    scoala2 == altaScoala;
    Scoala obiect21;


    if (scoala == scoala1) {
        cout << "Cele doua scoli sunt identice." << endl;
    }
    else {
        cout << "Cele doua scoli sunt diferite." << endl;
    }

    if (scoala != altaScoala) {
        cout << "Cele doua scoli sunt diferite." << endl;
    }
    else {
        cout << "Cele doua scoli sunt identice." << endl;
    }


    cin >> obiect4;
    ofstream afisare("materie.txt", ios::out);
    afisare << obiect4;
    afisare.close();
    ifstream citire("materie.txt", ios::in);
    citire >> obiect4;
    citire.close();
    cout << endl;

    cin >> obiect21;
    ofstream afisare1("scoala.txt", ios::out);
    afisare1 << obiect21;
    afisare1.close();
    ifstream citire1("scoala.txt", ios::in);
    citire1 >> obiect21;
    citire1.close();


    char sir[100] = "text salvat in fisier binar";
    fstream f("profesori.bin", ios::out | ios::binary);
    f.write((char*)&claseDirig, sizeof(int));
    int lungime = strlen(sir) + 1;
    f.write((char*)&lungime, sizeof(int));
    f.write((char*)sir, strlen(sir) + 1);
    f.close();

    char sir1[100] = "text salvat in fisier binar";
    fstream g("liceu.bin", ios::out | ios::binary);
    g.write((char*)&nrProfesori, sizeof(int));
    int lungime1 = strlen(sir1) + 1;
    g.write((char*)&lungime1, sizeof(int));
    g.write((char*)sir1, strlen(sir1) + 1);
    g.close();

    fstream h("profesori.bin", ios::binary | ios::in);
    char* sir2;
    int lungime2;
    h.read((char*)&claseDirig, sizeof(float));
    h.read((char*)&lungime2, sizeof(int));
    sir2 = new char[lungime2];
    h.read((char*)sir2, lungime2);
    h.close();
    cout << claseDirig << " " << sir2;
    delete[]sir2;
    cout << endl;
    fstream j("liceu.bin", ios::binary | ios::in);
    char* sir3;
    int lungime3;
    j.read((char*)&nrProfesori, sizeof(float));
    j.read((char*)&lungime3, sizeof(int));
    sir3 = new char[lungime3];
    j.read((char*)sir3, lungime3);
    j.close();
    cout << nrProfesori << " " << sir3;
    delete[]sir3;
    cout << endl;


    ProfesorDeMatematica pm(2, numeSef, 1, 20, "Gazeta");
    ProfesorDeMatematica pm2 = pm;
    ProfesorDeMatematica pm3;
    pm3 = pm;
    // cout << pm3<<endl;
    Profesori p;
    ProfesorDeMatematica pm1;
    cout << pm1.getNrClaseDirig() << endl;
    cout << p.getNrClaseDirig() << endl;

    Materie* m;
    m = new Matematica();
    m->afiseaza();
    Matematica mt(2, 1, 50, "Vasilescu");
    Materie m1;
    mt.descriere();
    Matematica mt1;

    cout << mt1.getNotaMaximaObtinuta() << endl;
    cout << m1.getNotaMaximaObtinuta() << endl;
    Matematica mt2 = mt;
    Matematica mt4;
    mt4 = mt2;
    cout << mt4<<endl;

    InstitutieScolara* i;
    i = new Liceu();
    i->afiseazaAdresa();


    Cladire* c;
    c = new Scoala();
    c->afiseazaCladire();


    Sc c1;
    c1[0] = new Scoala("Nr1");
    c1[1] = new Scoala("Nr2");
    c1[2] = new Scoala("Nr3");
    c1[3] = new Scoala("Nr4");
    c1[4] = new Scoala("Nr5");
    c1[5] = new Scoala("Nr6");
    c1[6] = new Scoala("Nr7");
    c1[7] = new Scoala("Nr8");
    c1[8] = new Scoala("Nr9");
    c1[9] = new Scoala("Nr10");

    for (int i = 0; i <10; i++) {
 	   c1[i]->afiseazaCladire();
    }
    
}
