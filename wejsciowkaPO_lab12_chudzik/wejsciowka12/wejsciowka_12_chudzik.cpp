#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class SilnikSamochodowy{
public:
	SilnikSamochodowy();
	SilnikSamochodowy(int, int);
	SilnikSamochodowy(SilnikSamochodowy& );
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

SilnikSamochodowy::SilnikSamochodowy(){
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
	Samochod(int,const char*);
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

Samochod::Samochod(){
	cena = 1;
	strcpy(rodzaj_silnika, "brak");
	nast = NULL;
}
Samochod::Samochod(int pric,const char* type){
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
	UrzadzenieOptyczne(int, int);
	UrzadzenieOptyczne(UrzadzenieOptyczne&);
	void setZoom(int n) { zoom = n; }
	int getZoom() { return zoom; }
	void setWeight(int n) { waga = n; }
	int getWeight() { return waga; }
	void printOut();
	UrzadzenieOptyczne* nast;
	void setNext(UrzadzenieOptyczne* k) { nast = k; }
	UrzadzenieOptyczne* getNext() { return nast; }
protected:
	int zoom;
	int waga;
};

UrzadzenieOptyczne::UrzadzenieOptyczne(){
	zoom = 1;
	waga = 1;
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
	OsobaNaUczelni(OsobaNaUczelni& );
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

OsobaNaUczelni::OsobaNaUczelni(){
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

int main() {
	SilnikSamochodowy* si = NULL, *ptrsi = NULL;
	Samochod* sa = NULL, *ptrsa = NULL;
	UrzadzenieOptyczne* uo = NULL, *ptruo=NULL;
	OsobaNaUczelni* on = NULL, *ptron=NULL;

	for (int i = 0; i < 4; i++){
		ptrsi->setNext(new SilnikSamochodowy);
		ptrsi = ptrsi->getNext();
		ptrsa->setNext(new Samochod);
		ptrsa = ptrsa->getNext();
		ptruo->setNext(new UrzadzenieOptyczne);
		ptruo = ptruo->getNext();
		ptron->setNext(new OsobaNaUczelni);
		ptron = ptron->getNext();
	}
	while (si) {
		si->printOut();
		si = si->getNext();
	}
	while (sa) {
		sa->printOut();
		sa = sa->getNext();
	}
	while (uo) {
		uo->printOut();
		uo = uo->getNext();
	}
	while (on) {
		on->printOut();
		on = on->getNext();
	}
	delete on;
	delete ptron;
	delete si;
	delete ptrsi;
	delete sa;
	delete ptrsa;
	delete uo;
	delete ptruo;
}

void SilnikSamochodowy::printOut(){
	printf("Moc: %d\n", SilnikSamochodowy::moc);
	printf("Wymiary: %d\n", SilnikSamochodowy::wymiary);
}

void Samochod::printOut(){
	printf("Cena: %d\n", Samochod::cena);
	printf("Rodzaj silnika: %s\n", Samochod::rodzaj_silnika);
}

void UrzadzenieOptyczne::printOut(){
	printf("Zoom: %d\n", UrzadzenieOptyczne::zoom);
	printf("Waga: %d\n", UrzadzenieOptyczne::waga);
}

void OsobaNaUczelni::printOut() {
	printf("%s\n", OsobaNaUczelni::imie);
	printf("%s\n", OsobaNaUczelni::nazwisko);
	printf("%s\n", OsobaNaUczelni::email);
}