#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>


class SilnikSamochodowy {
public:
	SilnikSamochodowy();
	SilnikSamochodowy(int, int);
	SilnikSamochodowy(SilnikSamochodowy&);
	void setPower(int n) { moc = n; }
	int getPower() { return moc; }
	void setSize(int n) { wymiary = n; }
	int getSize() { return wymiary; }
	void printOut();
	SilnikSamochodowy* nast;
	void setNext(SilnikSamochodowy* s) { nast = s; }
	SilnikSamochodowy* getNext() { return nast; }
protected:
	int moc;
	int wymiary;
};

SilnikSamochodowy::SilnikSamochodowy() {
	moc = 1;
	wymiary = 1;
	nast = NULL;
}
SilnikSamochodowy::SilnikSamochodowy(int Pow, int Siz) {
	moc = Pow;
	wymiary = Siz;
	nast = NULL;
}
SilnikSamochodowy::SilnikSamochodowy(SilnikSamochodowy &kss) {
	moc = kss.moc;
	wymiary = kss.wymiary;
	nast = kss.nast;
}

class Samochod {
public:
	Samochod();
	Samochod(int, const char*);
	Samochod(Samochod&);
	void setPrice(int n) { cena = n; }
	int getPrice() { return cena; }
	void setEngineType(const char* type) { strcpy(rodzaj_silnika, type); }
	char* getEngineType() { return rodzaj_silnika; }
	void printOut();
	Samochod* nast;
	void setNext(Samochod* m) { nast = m; }
	Samochod* getNext() { return nast; }
protected:
	int cena;
	char rodzaj_silnika[25];
};

Samochod::Samochod() {
	cena = 1;
	strcpy(rodzaj_silnika, "brak");
	nast = NULL;
}
Samochod::Samochod(int pric, const char* type) {
	cena = pric;
	rodzaj_silnika, type;
	nast = NULL;
}
Samochod::Samochod(Samochod& ks) {
	cena = ks.cena;
	strcpy(rodzaj_silnika, ks.rodzaj_silnika);
	nast = ks.nast;
}

class UrzadzenieOptyczne {
public:
	UrzadzenieOptyczne();
	UrzadzenieOptyczne(int);
	UrzadzenieOptyczne(int, int);
	UrzadzenieOptyczne(UrzadzenieOptyczne&);
	void setZoom(int n) { zoom = n; }
	int getZoom() { return zoom; }
	void setWeight(int n) { waga = n; }
	int getWeight() { return waga; }
	void wypis();
	UrzadzenieOptyczne* nast;
	void setNext(UrzadzenieOptyczne* k) { nast = k; }
	UrzadzenieOptyczne* getNext() { return nast; }
	UrzadzenieOptyczne& operator +=(const UrzadzenieOptyczne& UO) {
		waga += UO.waga;
		zoom += UO.zoom;
		return *this;
	}
protected:
	int zoom;
	int waga;
};

UrzadzenieOptyczne::UrzadzenieOptyczne() {
	zoom = 1;
	waga = 1;
	nast = NULL;
}
UrzadzenieOptyczne::UrzadzenieOptyczne(int n) {
	zoom = 0;
	waga = 0;
	nast = NULL;
}
UrzadzenieOptyczne::UrzadzenieOptyczne(int zo, int we) {
	zoom = zo;
	waga = we;
	nast = NULL;
}
UrzadzenieOptyczne::UrzadzenieOptyczne(UrzadzenieOptyczne &kuo) {
	zoom = kuo.zoom;
	waga = kuo.waga;
	nast = kuo.nast;
}

class OsobaNaUczelni {
public:
	OsobaNaUczelni();
	OsobaNaUczelni(const char*, const char*, const char*);
	OsobaNaUczelni(OsobaNaUczelni&);
	void setName1(char* n) { strcpy(imie, n); }
	char* getName1() { return imie; }
	void setName2(char* n) { strcpy(nazwisko, n); }
	char* getName2() { return nazwisko; }
	void setEmail(char* n) { strcpy(email, n); }
	char* getEmail() { return email; }
	void printOut();
	OsobaNaUczelni* nast;
	void setNext(OsobaNaUczelni* o) { nast = o; }
	OsobaNaUczelni* getNext() { return nast; }

protected:
	char imie[25];
	char nazwisko[30];
	char email[40];
};

OsobaNaUczelni::OsobaNaUczelni() {
	strcpy(imie, "brak");
	strcpy(nazwisko, "brak");
	strcpy(email, "brak");
	nast = NULL;
}
OsobaNaUczelni::OsobaNaUczelni(const char* name, const char* name2, const char* mail) {
	strcpy(imie, name);
	strcpy(nazwisko, name2);
	strcpy(email, mail);
	nast = NULL;
}
OsobaNaUczelni::OsobaNaUczelni(OsobaNaUczelni &ko) {
	strcpy(imie, ko.imie);
	strcpy(nazwisko, ko.nazwisko);
	strcpy(email, ko.email);
	nast = ko.nast;
}

class Kamera :public UrzadzenieOptyczne {
public:
	Kamera();
	Kamera(int, int, int, char*);
	Kamera(Kamera&);
	int getMax() { return max_czas; }
	void setMax(int m) { max_czas = m; }
	char* getStandard() { return standard; }
	void setStandard(char*);
	void wypis(FILE*);
protected:
	int max_czas;
	char standard[7]; //MPEG-2 MPEG-4 AVCHD HDV
};

Kamera::Kamera() : UrzadzenieOptyczne() {
	max_czas = 120;
	strcpy(standard, "MPEG-2");
}
Kamera::Kamera(int zo, int wag, int m, char *st)
	: UrzadzenieOptyczne(zo, wag), max_czas(m) {
	strcpy(standard, st);
}
Kamera::Kamera(Kamera& kk)
	: UrzadzenieOptyczne(kk), max_czas(kk.max_czas) {
	strcpy(standard, kk.standard);
}

class Lornetka :public UrzadzenieOptyczne {
public:
	Lornetka();
	Lornetka(int );
	Lornetka(int, int, int, int);
	Lornetka(Lornetka&);
	int getPowiekszenie() { return powiekszenie; }
	void setPowiekszenie(int);
	int getSrednica() { return srednica_obi; }
	void setSrednica(int);
	Lornetka* getNext() { return nast; }
	void wypis();
	Lornetka* nast;
	Lornetka& operator+=(const Lornetka& kl) {
		zoom += kl.zoom;
		waga += kl.waga;
		powiekszenie += kl.powiekszenie;
		srednica_obi += kl.srednica_obi;
		return *this;
	}
protected:
	int powiekszenie;
	int srednica_obi; //21,25,28,32,36,42,50
};

Lornetka::Lornetka() :UrzadzenieOptyczne() {
	powiekszenie = 20;
	srednica_obi = 21;
}
Lornetka::Lornetka(int n) {
	powiekszenie = 0;
	srednica_obi = 0;
}
Lornetka::Lornetka(int zo, int wag, int pow, int sre)
	: UrzadzenieOptyczne(zo, wag) {
	setPowiekszenie(pow);
	setSrednica(sre);
}
Lornetka::Lornetka(Lornetka &kl)
	: UrzadzenieOptyczne(kl), powiekszenie(kl.powiekszenie), srednica_obi(kl.srednica_obi) {
}

template<class T>
T sumuj(T *kt) {
	int n = 0;
	T tmp(n);
	while (kt){
		tmp += (*kt); 
		kt = kt->getNext();
	}
	return tmp;
} 

int main() {
	//UrzadzenieOptyczne* uo = NULL, *ptruo = NULL;
	//uo = ptruo = new UrzadzenieOptyczne();
	//int n = 0;
	//UrzadzenieOptyczne* suma = new UrzadzenieOptyczne(n);
	//UrzadzenieOptyczne tmp(n);
	//for (int i = 0; i < 4; i++) {
	//	ptruo->setNext(new UrzadzenieOptyczne);
	//	ptruo = ptruo->getNext();
 //	}
	//tmp = sumuj<UrzadzenieOptyczne>(uo);
	//tmp.wypis();
	//delete uo;
	//delete ptruo;
	//delete suma;
	Lornetka* kl, *ptrkl = NULL;
	Kamera* kk, *ptrkk = NULL;
	kk = new Kamera;
	kl = new Lornetka;
	Lornetka A1;
	Kamera* B1 = new Kamera;
	kk = NULL;
	kl = NULL;
	A1.setPowiekszenie(0);
	A1.setSrednica(0);
	for (int i = 0; i < 5; i++) {
		if (kl == NULL) {
			kl = ptrkl = new Lornetka;
		}
		else {
			ptrkl->nast = new Lornetka;
			ptrkl = ptrkl->nast;
		}
	}
	A1 = sumuj<Lornetka>(kl);
	A1.wypis();

}
/*
				program dziala zgodnie z zalozeniami
				program dziala zgodnie z zalozeniami
				program dziala zgodnie z zalozeniami
				program dziala zgodnie z zalozeniami
*/


void SilnikSamochodowy::printOut() {
	printf("Moc: %d\n", SilnikSamochodowy::moc);
	printf("Wymiary: %d\n", SilnikSamochodowy::wymiary);
}

void Samochod::printOut() {
	printf("Cena: %d\n", Samochod::cena);
	printf("Rodzaj silnika: %s\n", Samochod::rodzaj_silnika);
}

void UrzadzenieOptyczne::wypis() {
	printf("Zoom: %d\n", UrzadzenieOptyczne::zoom);
	printf("Waga: %d\n", UrzadzenieOptyczne::waga);
}

void OsobaNaUczelni::printOut() {
	printf("%s\n", OsobaNaUczelni::imie);
	printf("%s\n", OsobaNaUczelni::nazwisko);
	printf("%s\n", OsobaNaUczelni::email);
}

void Kamera::setStandard(char* typ) {
	char mp2[7];
	char mp4[7];
	char avc[7];
	char hdv[7];
	strcpy(mp2, "MPEG-2");
	strcpy(mp4, "MPEG-4");
	strcpy(avc, "AVCHD");
	strcpy(hdv, "HDV");
	if (typ == mp2 || typ == mp4 || typ == avc || typ == hdv) {
		strcpy(standard, typ);
	}
	else {
		printf("Bledny podany format, zostanie uzyty predefiniowany format");
		strcpy(standard, "MPEG-2");
	}
}
void Kamera::wypis(FILE* w) {
	fprintf(w, "%s", "Kamera:\n");
	fprintf(w, "Zoom: %d\n", Kamera::getZoom());
	fprintf(w, "Waga: %d\n", Kamera::getWeight());
	fprintf(w, "Czas pracy: %d\n", Kamera::getMax());
	fprintf(w, "Standard: %s\n\n", Kamera::getStandard());
}

void Lornetka::setPowiekszenie(int p) {
	if (p % 2 != 0) {
		printf("Podana liczba nie jest parzysta. Liczba zostanie zmieniona na domyslna.");
		powiekszenie = 2;
	}
	else {
		powiekszenie = p;
	}
}
void Lornetka::setSrednica(int s) {
	if (s == 21 || s == 25 || s == 28 || s == 32 || s == 36 || s == 42 || s == 50) {
		srednica_obi = s;
	}
	else {
		printf("\nbledna liczba, liczba zostanie zastapiona wartoscia domyslna");
		srednica_obi = 21;
	}
}
void Lornetka::wypis() {
	printf("%s", "Lornetka: \n");
	std::cout << "Zoom: " << zoom << std::endl;
	std::cout << "Waga: " << waga << std::endl;
	printf("Powiekszenie: %d\n", Lornetka::getPowiekszenie());
	printf("Srednica: %d\n\n", Lornetka::getSrednica());
}