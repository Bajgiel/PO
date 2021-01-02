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
	int ID;
public:
	MojaKlasa(int x);
	MojaKlasa(MojaKlasa& mk);	// konstruktor kopiuj¹cy
	void setEmail(int ux, char* adres) { strcpy(email[ux], adres); }
	char* getemail(int idx) { return email[idx]; }
	void setNext(MojaKlasa* el) { MojaKlasa::nast = el; }
	int getIle() { return ile; }
	MojaKlasa* getNext() { return nast; }
	char** GetEmaile() { return MojaKlasa::email; }
	void setID(int idu) { ID=idu; }
	int getID() { return MojaKlasa::ID; }
	MojaKlasa* szukaj(int);
	void wypis(MojaKlasa&, char*);
};
MojaKlasa::MojaKlasa(int x) {
	MojaKlasa::nast = NULL;
	email = new char*[ile = x];
	for (int i = 0; i < ile; i++) email[i] = new char[100];
	ID = 0;
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
	ID = mk.ID;
}
MojaKlasa* MojaKlasa::szukaj(int idu) {
	if (MojaKlasa::ID == idu)return this;
	else {
		if (nast != NULL) {
			return nast->szukaj(idu);
		}
		else {
			return NULL;
		}
	}
};
void MojaKlasa::wypis(MojaKlasa &mw, char* s_name) {
	printf("Wykladowca: %s\n",s_name);
	printf("ID grupy: %d\n", mw.ID);
	for (int i = 1; i < mw.ile; i++) {
		printf("email %d: %s\n", i, mw.email[i - 1]);
	}
	putchar('\n');
}

class Wykladowca {
	MojaKlasa* head;					//head
	MojaKlasa* ptr;
	char s_name[STR_S];
public:
	Wykladowca();
	Wykladowca(char*);
	Wykladowca(char*, char*);
	Wykladowca(char*, Wykladowca&);
	~Wykladowca();
	void addClass(const char*);
	void printClass();
	void szukaj(int, Wykladowca& );
};
Wykladowca::Wykladowca(){
	Wykladowca::head = NULL;
	Wykladowca::ptr = NULL;
}
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
		char idu[10];
		fscanf(r, "%s", idu,10);
		while (!feof(r)) {
			fscanf(r, "%s", email, 100);
			licznik++;
		}
		rewind(r);
		MojaKlasa* m = new MojaKlasa(licznik);
		fscanf(r, "%s", idu, 10);
		int IDui = atoi(idu);
		(*m).setID(IDui);
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
void Wykladowca::szukaj(int idu, Wykladowca& mw) {
	if (mw.head == NULL) {
		printf("Nie ma zadnej grupy.");
	}
	else {
		MojaKlasa* t = head->szukaj(idu);
		if (t == NULL) {
			printf("Nie ma grupy o ID %d.",idu);
		}
		else {
			t->wypis(*t, mw.s_name);
		}
	}
}

void Wykladowca::addClass(const char* file_name) {
	FILE *r;
	if ((r = fopen(file_name, "r")) != NULL) {
		int licznik = 0;
		char email[100];
		char idu[10] ;
		fscanf(r, "%s", idu, 10);
		while (!feof(r)) {
			fscanf(r, "%s", email, 100);
			licznik++;
		}
		rewind(r);
		MojaKlasa* ptr = new MojaKlasa(licznik);
		fscanf(r, "%s", idu, 10);
		int IDui = atoi(idu);
		(*ptr).setID(IDui);
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
		printf("grupa nr: %d, ID grupy: %d\n", i + 1, ptr->getID());
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
	char file_name1[20] = "file_mail1.txt";
	char file_name2[20] = "file_mail2.txt";
	char file_name3[20] = "file_mail3.txt";
	char file_name4[20] = "file_mail4.txt";
	char file_name5[20] = "file_mail5.txt";
	Wykladowca w1(s_name1);
	w1.addClass(file_name1);
	w1.addClass(file_name2);
	w1.addClass(file_name3);
	w1.addClass(file_name4);
	w1.addClass(file_name5);
	w1.szukaj(2, w1);
	w1.szukaj(1, w1);
	w1.szukaj(10, w1);
	/*w1.printClass();
	w2.printClass();
	w3.printClass();*/
}

