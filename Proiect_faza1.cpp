#include <iostream>
using namespace std;

class Liceu {
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
    Liceu() :id(1) {
        this->nrElevi = 100;
    }
    void afisareLiceu() {
        cout << "Numarul de elevi este de: " << nrElevi  << endl;
    };

    Liceu(int nrProfesori, int nrEleviEx, string* numeEleviEx, int id) :id(id) {
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
    Liceu(float buget, int nrClase, int id) :id(id) {
        this->buget = buget;
        this->nrClase = nrClase;
    }
    void afisareLiceu2() {
        cout << "Bugetul liceului este de: " << buget << ", iar numarul de clase este de: " << nrClase << endl;
    }
    Liceu(const Liceu& obiect1) :id(id) {
        this->buget = obiect1.buget;
        this->nrClase =obiect1.nrClase;
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
};
string getSirElevi(const Liceu& obiect2) {
    	string aux = "";
    	for (int i = 0; i < obiect2.nrEleviEx; i++) {
    		aux +=obiect2.numeEleviEx[i]+",";
    	}
    	return aux;
    }
int getElevi(const Liceu& obiect1) {
    return obiect1.nrElevi;
}
int Liceu::anulAparitieiLiceului = 1960;
int Liceu::mediaAdmitere = 9;
string Liceu::adresa="Popescu";
float Liceu::numar=3;

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
        this->nrOre = 30;
        this->notaMaximaObtinuta = 9.70;
    }
    void afisareMaterie() {
        cout << "Materia este: " << nume << ", si este sustinuta timp de: " << nrOre
            << " minute si nota maxima obtinuta a fost: " << notaMaximaObtinuta << "." << endl;
    }
    Materie(int notaMinimaObtinuta, int idMan) :idMan(idMan) {
        std::cout << "Nota minima obtinuta a fost: " << notaMinimaObtinuta << "." << std::endl;
    }

    Materie(int nrEleviPr, string numeE, int idMan, int nrProfesori, string* numeProfesori) :idMan(idMan) {
        this->nrProfesori = nrProfesori;
        this->numeProfesori = new string[nrProfesori];
        for (int i = 0; i < nrProfesori; i++) {
            this->numeProfesori[i] = numeProfesori[i];
        }
        std::cout << "Numarul de elevi prezenti la o ora este de: " << nrEleviPr << ",cu numele de" << numeE << "." << std::endl;
    }

    Materie(const Materie& obiect6) :idMan(idMan) {
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
        if (notaMaximaObtinuta> 0) {
            this->notaMaximaObtinuta = notaMaximaObtinuta;
        }
    }
    friend int getNrOre(const Materie& obiect4);
    friend float getNotaMax(const Materie& obiect4);
};
int getNrOre(const Materie& obiect4) {
    return obiect4.nrOre;
}
float getNotaMax(const Materie& obiect4) {
    return obiect4.notaMaximaObtinuta;
}
int Materie::nrManuale = 1;
string Materie::autorMan = "Dobrescu";
string Materie::zilePractica = "Luni, Miercuri,Joi ";


class Profesori {
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

    Profesori() :nrIn(1) {
        this->nume = "Antonescu";
        this->nrTel = 1234567456;
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
    Profesori(const Profesori& obiect8) :nrIn(nrIn) {
        this->claseDirig = obiect8.claseDirig;
        this->numeSef = new string[obiect8.claseDirig];
        for (int i = 0; i < obiect8.claseDirig; i++) {
            this->numeSef[i] = obiect8.numeSef[i];
        }

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
    Liceu obiect3(100000, 20, 3);
    cout << obiect3.id << endl;
    obiect3.afisareLiceu2();
    Liceu L1(obiect3);
    obiect3.afisareLiceu2();


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
    Materie M1(obiect6);
    obiect6.afisareMaterie1();
    cout << endl;


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
    Profesori obiect9("romana", "ART.", 3);
    cout << obiect9.nrIn << endl;
    obiect9.afisareProfesori2();
    cout << endl;
    cout << getMaterie(obiect9);
};
