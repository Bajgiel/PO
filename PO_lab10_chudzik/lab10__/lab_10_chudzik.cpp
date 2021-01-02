#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <math.h>
using namespace std;

#define PI 3.1415926535897

class Trapez {
	double leng_low;
	double leng_high;
	double h;
	double bok;
	double x;
	double y;
	double positions[4][2];
	double pole;
	Trapez* nast;
public:
	Trapez();
	Trapez(double, double, double, double, double, double, double);
	Trapez(Trapez&);
	void met1();													//inicjalizacja trapezu
	void met2();													//wypis wartosci trapezu
	void met3(double);												//symetria osiowa trapezu
	void setNext(Trapez* el) { Trapez::nast = el; }
	Trapez* setNextPtr(Trapez* el);
};
Trapez::Trapez() {
	leng_low = 1;
	leng_high = 1;
	h = 1;
	bok = 1;
	x = 0;
	y = 0;
	positions[0][0] = { 0 };
	pole = 1;
}
Trapez::Trapez(double l_l, double l_h, double heig, double ram, double ix, double iy, double  p) {
	leng_low = l_l;
	leng_high = l_h;
	h = heig;
	bok = ram;
	x = ix;
	y = iy;
	pole = p;
}
Trapez::Trapez(Trapez& kt) {
	leng_low = kt.leng_low;
	leng_high = kt.leng_high;
	h = kt.h;
	bok = kt.bok;
	x = kt.x;
	y = kt.y;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			positions[i][j] = kt.positions[i][j];
		}
	}
	pole = kt.pole;
}

class Kolo {
	double promien;
	double x;
	double y;
	double positions[5][2];
	double pole;
	Kolo* nast;
public:
	Kolo();
	Kolo(double, double, double, double, double);
	Kolo(Kolo& kk);
	void met1();													//inicjalizacja kola
	void met2();													//wypis wartosci kola
	void met3(double n);											//symetria osiowa kola
	void met4(double px, double py);								//przesuniecie wektora kola
	void setNext(Kolo* el) { Kolo::nast = el; }
	Kolo* setNextPtr(Kolo* el);
};
Kolo::Kolo() {
	promien = 1;
	x = 0;
	y = 0;
	positions[0][0] = { 0 };
	pole = 1;
}
Kolo::Kolo(double r, double ix, double iy, double tab, double p) {
	promien = r;
	x = ix;
	y = iy;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			positions[i][j] = tab;
		}
	}
	pole = p;
}
Kolo::Kolo(Kolo& kk) {
	promien = kk.promien;
	x = kk.x;
	y = kk.y;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			positions[i][j] = kk.positions[i][j];
		}
	}
	pole = kk.pole;
	nast = NULL;
}

class Blejtram{
private:
	Trapez* t_head;
	Trapez* t_ptr;
	Kolo* k_head;
	Kolo* k_ptr;
public:
	Blejtram();
	Trapez* dodajTrapez(Trapez*);
	Kolo* dodajKolo(Kolo*);
	void symetriaOsiowa(double);
	void wypis();
};
Blejtram::Blejtram() {
	t_head = NULL;
	t_ptr = NULL;
	k_head = NULL;
	k_ptr = NULL;
}

int main() {
	Trapez t1;
	Trapez t2(4,2,2,2,0,0,1);
	Trapez t3(t1);
	Kolo k1;
	Kolo k2(4,0,0,0,3);
	Kolo k3(k1);
	Blejtram* b = new Blejtram();
	(*b).dodajKolo(&k1);
	(*b).dodajKolo(&k2);
	(*b).dodajKolo(&k3);
	(*b).dodajTrapez(&t1);
	(*b).dodajTrapez(&t2);
	(*b).dodajTrapez(&t3);
	printf("\t\twypis\n\n");
	(*b).wypis();
	printf("\t\tsymetria\n\n");
	(*b).symetriaOsiowa(2);
	printf("\t\twypis\n\n");
	(*b).wypis();
	printf("\t\tsymetria\n\n");
	(*b).symetriaOsiowa(2);
	printf("\t\twypis\n\n");
	(*b).wypis();
	delete b;
}
/*
Konstruktory zostaly wywolane 13 razy
przy konstruktorach figur w liniach 138-143
w wywolaniu klasy Blejtram
oraz w wywolaniu metod dodania trapezu oraz dodania kola 
*/
Trapez* Blejtram::dodajTrapez(Trapez* t) {
	Trapez* ptr = new Trapez();
	ptr = t;
	if (Blejtram::t_head == NULL) {
		Blejtram::t_head = ptr;
		Blejtram::t_ptr = ptr;
	}
	else {
		Blejtram::t_ptr->setNext(ptr);
		Blejtram::t_ptr = ptr;
	}
	return ptr;
}
Kolo* Blejtram::dodajKolo(Kolo* t) {
	Kolo* ptr = new Kolo();
	ptr = t;
	if (Blejtram::k_head == NULL) {
		Blejtram::k_head = ptr;
		Blejtram::k_ptr = ptr;
	}
	else {
		Blejtram::k_ptr->setNext(ptr);
		Blejtram::k_ptr = ptr;
	}
	return ptr;
}
void Blejtram::symetriaOsiowa(double n) {
	Trapez* t_head0 = Blejtram::t_head;
	Kolo* k_head0 = Blejtram::k_head;
	while (t_head0){
		t_head0->met3(n);
		t_head0 = t_head0->setNextPtr(t_head0);
	}
	while (k_head0) {
		k_head0->met3(n);
		k_head0 = k_head0->setNextPtr(k_head0);
	}
}
void Blejtram::wypis() {
	Trapez* t_head0 = Blejtram::t_head;
	Kolo* k_head0 = Blejtram::k_head;
	while (t_head0) {
		t_head0->met2();
		t_head0 = t_head0->setNextPtr(t_head0);
	}
	while (k_head0) {
		k_head0->met2();
		k_head0 = k_head0->setNextPtr(k_head0);
	}
}

void Trapez::met1() {
	printf("Trapez:\n");
	printf("Podaj dlugosc dolnej podstawy: ");
	double len_low;
	scanf_s("%lf", &len_low);
	printf("\nPodaj dlugosc gornej podstawy: ");
	double len_high;
	scanf_s("%lf", &len_high);
	double hei;
	printf("\nPodaj wysokosc: ");
	scanf_s("%lf", &hei);
	printf("\nPodaj wartosc x lewego dolnego wierzolka: ");
	double xu;
	while (scanf_s("%lf", &xu) != 1 || getchar() != '\n') {
		printf("blad. popraw");
		while (getchar() != '\n') {
			;
		}
	}
	printf("\nPodaj wartosc y lewego dolnego wierzolka: ");
	double yu;
	while (scanf_s("%lf", &yu) != 1 || getchar() != '\n') {
		printf("blad. popraw");
		while (getchar() != '\n') {
			;
		}
	}
	if (len_low > 0) leng_low = len_low;
	if (len_high > 0) leng_high = len_high;
	if (hei > 0) h = hei;
	x = xu;
	y = yu;
	bok = sqrt(pow((fabs(leng_low - leng_high) / 2), 2) + pow(h, 2));
	positions[0][0] = x;												//Left Low x
	positions[0][1] = y;												//Left Low y
	positions[1][0] = x + ((leng_low - leng_high) / 2);					//Left High x
	positions[1][1] = h + y;											//Left High y
	positions[2][0] = leng_low + x;										//Right Low x
	positions[2][1] = y;												//Right Low y
	positions[3][0] = x + ((leng_low - leng_high) / 2) + leng_high;		//Right High x
	positions[3][1] = h + y;											//Right High y
	pole = ((leng_low + leng_high) / 2) * h;
}
void Trapez::met2() {
	printf("\n\n\t\ttrapez:\n\n");
	printf("\n\nwspolrzedne: \n");
	printf("lewy dolny rog: (%.2lf,%.2lf)\n", positions[0][0], positions[0][1]);
	printf("lewy gorny rog: (%.2lf,%.2lf)\n", positions[1][0], positions[1][1]);
	printf("prawy dolny rog: (%.2lf,%.2lf)\n", positions[2][0], positions[2][1]);
	printf("prawy gorny rog: (%.2lf,%.2lf)\n", positions[3][0], positions[3][1]);
	printf("\ndlugosci: \n");
	printf("dolna podstawa: %.2lf\n", leng_low);
	printf("gorna podstawa: %.2lf\n", leng_high);
	printf("ramie: %.2lf\n", bok);
	printf("wysokosc: %.2lf\n", h);
	printf("pole: %.2lf", pole);
}
void Trapez::met3(double n) {
	for (int i = 0; i < 4; i++) {
		double tmp = 0;
		if (n > positions[i][0]) {
			tmp = fabs(positions[i][0] - n);
			tmp *= 2;
			positions[i][0] += tmp;
		}
		else {
			tmp = fabs(positions[i][0] - n);
			tmp *= 2;
			positions[i][0] -= tmp;
		}
	}
}
Trapez* Trapez::setNextPtr(Trapez* el) {
	el = el->nast;
	return el;
}

void Kolo::met1() {
	printf("Kolo:\n");
	printf("Podaj wartsoc x srodka kola: ");
	double xk;
	while (scanf_s("%lf", &xk) != 1 || getchar() != '\n') {
		printf("blad. popraw");
		while (getchar() != '\n') {
			;
		}
	}
	x = xk;
	printf("\nPodaj wartosc y srodka kola: ");
	double yk;
	while (scanf_s("%lf", &yk) != 1 || getchar() != '\n') {
		printf("blad. popraw");
		while (getchar() != '\n') {
			;
		}
	}
	y = yk;
	printf("\nPodaj dlugosc promienia: ");
	double r;
	scanf_s("%lf", &r);
	if (r > 0) {
		promien = r;
	}
	positions[0][0] = x;						//middle of circle x
	positions[0][1] = y;						//middle of circle y
	positions[1][0] = x + promien;				//right x
	positions[1][1] = y;						//right y
	positions[2][0] = x;						//down x
	positions[2][1] = y - promien;				//down y
	positions[3][0] = x - promien;				//left x
	positions[3][1] = y;						//left y
	positions[4][0] = x;						//up x
	positions[4][1] = y + promien;				//up y
	pole = promien * promien * PI;
}
void Kolo::met2() {
	printf("\n\n\t\tKolo:\n\n");
	printf("\n\nwspolrzedne:\n");
	printf("srodek okregu: (%.2lf,%.2lf)\n", positions[0][0], positions[0][1]);
	printf("prawy punkt: (%.2lf,%.2lf)\n", positions[1][0], positions[1][1]);
	printf("dolny punkt: (%.2lf,%.2lf)\n", positions[2][0], positions[2][1]);
	printf("lewy punkt: (%.2lf,%.2lf)\n", positions[3][0], positions[3][1]);
	printf("gorny punkt: (%.2lf,%.2lf)\n", positions[4][0], positions[4][1]);
	printf("dlugosci:\n");
	printf("promien: %.2lf\n", promien);
	printf("pole: %.2lf", pole);
}
void Kolo::met3(double n) {
	for (int i = 0; i < 5; i++) {
		double tmp = 0;
		if (n > positions[i][0]) {
			tmp = fabs(positions[i][0] - n);
			tmp *= 2;
			positions[i][0] += tmp;
		}
		else {
			tmp = fabs(positions[i][0] - n);
			tmp *= 2;
			positions[i][0] -= tmp;
		}
	}
}
void Kolo::met4(double px, double py) {
	for (int i = 0; i < 5; i++) {
		positions[i][0] += px;
		positions[i][1] += py;
	}
}
Kolo* Kolo::setNextPtr(Kolo* el) {
	el = el->nast;
	return el;
}

