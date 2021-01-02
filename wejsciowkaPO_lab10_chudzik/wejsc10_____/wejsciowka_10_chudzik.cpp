#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <cstring>
using namespace std;

#define STR_S 30

class MojaKlasa {
	MojaKlasa *nast;
	char **email;
	int ile;
public:
	MojaKlasa(int x);
	MojaKlasa(MojaKlasa& mk);	// konstruktor kopiuj¹cy
	void setEmail(int ux, char* adres) { strcpy(email[ux], adres); }
	char* getemail(int idx) { return email[idx]; }
	void setNext(MojaKlasa* el) { MojaKlasa::nast = el; }
	int getIle() { return ile; }
	MojaKlasa* getNext() { return nast; }
	char** GetEmaile() { return MojaKlasa::email; }
};
MojaKlasa::MojaKlasa(int x) {
	MojaKlasa::nast = NULL;
	email = new char*[ile = x];
	for (int i = 0; i < ile; i++) email[i] = new char[100];
}
MojaKlasa::MojaKlasa(MojaKlasa& mk) {
	nast = NULL;
	ile = mk.ile;
	email = new char*[mk.ile];
	if (email != NULL) {
		for (int i = 0; i < ile; i++) {
			email[i] = new char[100];
			if (email[i] != NULL)	strcpy(email[i], mk.getemail(i));
		}
	}
}

class Wykladowca {
	MojaKlasa* head;					//head
	MojaKlasa* ptr;
	char s_name[STR_S];
public:
	Wykladowca(char*);
	Wykladowca(char*, char*);
	Wykladowca(char*, Wykladowca&);
	~Wykladowca();
	void addClass(const char*);
	void printClass();
};
Wykladowca::Wykladowca(char *s_name) {
	Wykladowca::head = NULL;
	Wykladowca::ptr = NULL;
	strcpy_s(Wykladowca::s_name, STR_S, s_name);
}
Wykladowca::Wykladowca(char* file_name, char* s_name) {
	FILE *r;
	r = fopen(file_name, "r");
	if (r != NULL) {
		int licznik = 0;
		char email[100];
		while (!feof(r)) {
			fscanf(r, "%s", email, 100);
			licznik++;
		}
		rewind(r);
		MojaKlasa* m = new MojaKlasa(licznik);
		for (int i = 0; i < licznik; i++) {
			fscanf(r, "%s", email, 100);
			(*m).setEmail(i, email);
		}
		Wykladowca::head = m;
		Wykladowca::ptr = m;
		fclose(r);
	}
	else {
		Wykladowca::head = NULL;
		Wykladowca::ptr = NULL;
	}
	strcpy_s(Wykladowca::s_name, STR_S, s_name);
}
Wykladowca::Wykladowca(char* s_name, Wykladowca& mw) {
	Wykladowca::head = NULL;
	Wykladowca::ptr = NULL;
	if (mw.head != NULL) {
		MojaKlasa* ptr = mw.head;
		while (ptr) {
			if (Wykladowca::head == NULL) {
				Wykladowca::head = new MojaKlasa(*ptr);
				Wykladowca::ptr = Wykladowca::head;
			}
			else {
				MojaKlasa* tmp = new MojaKlasa(*ptr);
				Wykladowca::ptr->setNext(tmp);
				Wykladowca::ptr = tmp;
			}
			ptr = ptr->getNext();
		}
	}
	strcpy_s(Wykladowca::s_name, STR_S, s_name);
}
Wykladowca::~Wykladowca() {
	delete[] ptr;
	delete[] head;
}

void Wykladowca::addClass(const char* file_name) {
	FILE *r;
	if ((r = fopen(file_name, "r")) != NULL) {
		int licznik = 0;
		char email[100];
		while (!feof(r)) {
			fscanf(r, "%s", email, 100);
			licznik++;
		}
		rewind(r);
		MojaKlasa* ptr = new MojaKlasa(licznik);
		for (int i = 0; i < licznik; i++) {
			fscanf_s(r, "%s", email, 100);
			(*ptr).setEmail(i, email);
		}
		if (Wykladowca::head == NULL) {
			Wykladowca::head = ptr;
			Wykladowca::ptr = ptr;
		}
		else {
			Wykladowca::ptr->setNext(ptr);
			Wykladowca::ptr = ptr;
		}
		fclose(r);
	}
	else printf("B³ad.");
}
void Wykladowca::printClass() {
	MojaKlasa* ptr = Wykladowca::head;
	printf("Wykladowca: %s\n", Wykladowca::s_name);
	for (int i = 0; ptr; i++) {
		printf("grupa nr: %d\n", i + 1);
		for (int j = 1; j < ptr->getIle(); j++) {
			printf("email %d: %s\n", j, ptr->getemail(j - 1));
		}
		putchar('\n');
		ptr = ptr->getNext();
	}
	putchar('\n');
}

int main() {
	char s_name1[STR_S] = "Kowalski";
	char s_name2[STR_S] = "Polak";
	char s_name3[STR_S] = "Mazurek";
	char file_name1[20] = "file_mail1.txt";
	char file_name2[20] = "file_mail2.txt";
	char file_name3[20] = "file_mail3.txt";
	char file_name4[20] = "file_mail4.txt";
	Wykladowca w1(s_name1);
	w1.addClass(file_name1);
	w1.addClass(file_name2);
	Wykladowca w2(file_name2, s_name1);
	w2.addClass(file_name3);
	Wykladowca w3(s_name3, w2);
	w3.addClass(file_name4);
	w1.printClass();
	w2.printClass();
	w3.printClass();
}
/*
konstruktory zostaly wywolane lacznie 10 razy,
3 razy konstruktory dla klasy wykladowca oraz
7 razy konstruktory dla klasy MojaKlasa.

destruktor zostal wywolany 3 razy przy klamerce zamykajacej funkcje main
dla kazdego utworzonego obiektu klasy Wykladowca.
*/