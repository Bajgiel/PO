#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define PI 3.1415926535897

class Trapez{
	double leng_low;
	double leng_high;
	double h;
	double bok;
	double x;
	double y;
	double positions[4][2];
	double pole;
public:
	Trapez(double l_l = 10, double l_h = 5, double heig = 3, double ram = 0, double ix = 0, double iy = 0, double  p = 0) {
		leng_low = l_l;
		leng_high = l_h;
		h = heig;
		bok = ram;
		x = ix;
		y = iy;
		pole = p;
	}
	/*fun1*/
	void met1();
	/*fun2*/
	void met2();
	/*fun3*/
	void met3(double);
}trapezm[3];

class Kolo{
	double promien;
	double x;
	double y;
	double positions[5][2];
	double pole;
public:
	Kolo(double r = 6, double ix = 0, double iy = 0, double tab = 0, double p = 0) {
		promien = r;
		x = ix;
		y = iy;
		positions[5][2] = { tab };
		pole = p;
	}
	void met1();
	void met2();
	void met3(double n);
	void met4(double px, double py);
}kolom[3];



int main() {
	printf("witaj, ");
	while (1) {
		printf("ktora figure chesz zainicjalizowac?(wpisz 1 jesli trapez, wpisz 2 jesli kolo, wpisz 0 jesli chcesz wyjsc): ");
		int figura = 0;
		scanf_s("%d", &figura);
		if (figura == 0) {
			printf("\nKoniec programu.");
			exit(0);
		}
		printf("Podaj, indeks figury na ktorej chcesz pracowac(od 1 do 3): ");
		int indeks = -1;
		scanf_s("%d", &indeks);
		int wybor_trapez = 0;
		int wybor_kolo = 0;
		switch (figura) {
		case 1:
			trapezm[indeks - 1].met1();
			printf("Co chcesz zrobic z trapezem?:\n");
			printf("Jesli chcesz zmienic dane wybierz 1\n");
			printf("Jesli chcesz dokonac przekrztalcenia liniowego wybierz 2");
			scanf_s("%d", &wybor_trapez);
			switch (wybor_trapez) {
			case 1:
				trapezm[indeks - 1].met1();
				trapezm[indeks - 1].met2();
				break;
			case 2:
				printf("Podaj n (dla prostej x=n) do przeksztalcenia liniowego: ");
				double n;
				scanf_s("%lf", &n);
				trapezm[indeks - 1].met3(n);
				trapezm[indeks - 1].met2();
				break;
			default:
				printf("blad\n\n");
				break;
			}
			break;
		case 2:
			kolom[indeks - 1].met1();
			printf("Co chcesz zrobic z kolem?:\n");
			printf("Jesli chcesz zmienic dane wybierz 1\n");
			printf("Jesli chcesz dokonac przekrztalcenia liniowego wybierz 2\n");
			printf("Jesli chcesz przesunac kolo o wskazany wektor wybierz 3\n");
			scanf_s("%d", &wybor_kolo);
			switch (wybor_kolo) {
			case 1:
				kolom[indeks - 1].met1();
				kolom[indeks - 1].met2();
				break;
			case 2:
				printf("Podaj n (dla prostej x=n) do przeksztalcenia liniowego: ");
				double n;
				scanf_s("%lf", &n);
				kolom[indeks - 1].met3(n);
				kolom[indeks - 1].met2();
				break;
			case 3:
				printf("\nPodaj wektor o ktory ma sie przesunac kolo");
				printf("\nx: ");
				double px;
				scanf_s("%lf", &px);
				printf("\ny: ");
				double py;
				scanf_s("%lf", &py);
				kolom[indeks - 1].met4(px, py);
				kolom[indeks - 1].met2();
				break;
			default:
				printf("blad\n\n");
				break;
			}
			break;
		default:
			printf("blad\n\n");
			break;
		}
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
	positions[1][0] = x+promien;				//right x
	positions[1][1] = y;						//right y
	positions[2][0] = x;						//down x
	positions[2][1] = y-promien;				//down y
	positions[3][0] = x-promien;				//left x
	positions[3][1] = y;						//left y
	positions[4][0] = x;						//up x
	positions[4][1] = y+promien;				//up y
	pole = promien * promien * PI;
}
void Kolo::met2() {
	printf("\nwspolrzedne:\n");
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
	for (int i = 0; i < 5; i++){
		positions[i][0] += px;
		positions[i][1] += py;
	}
}