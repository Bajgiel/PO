#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int numberRan();
int convOtD(int oct);
char* timeCu();

int main() {
	FILE *nickf, *log;
	if ((log = freopen("log.txt", "a+", stderr)) == NULL) {
		printf("Error while trying to open file %s: %s\n\n", "log.txt", strerror(errno));
		exit(0);
	}
	fprintf(stderr, "%s Poczatek programu\n", timeCu());		//poczatek programu
	srand((unsigned int)time(NULL));
	int end = 1;
	do {
		printf("podaj swoj nick: ");
		char nick[20];
		scanf_s("%s", &nick, 20);
		char file_name[25] = "gra-";
		strcat(file_name, nick);
		strcat(file_name, ".txt");
		if ((nickf = fopen(file_name, "a")) == NULL) {
			fprintf(stderr, "%s error: %s\n", timeCu(), strerror(errno));
			fprintf(stderr, "%s koniec programu\n", timeCu());		//koniec programu
			exit(EXIT_FAILURE);
		}
		printf("\npodaj niewielka liczbe naturalna: ");
		float nat_num;
		while (scanf_s("%f", &nat_num) != 1 || nat_num <= 0 || (int)nat_num - nat_num != 0 || getchar() != '\n') {
			printf("blad, popraw\n liczba: ");
			while (getchar() != '\n') {
				;
			}
		}
		int uans;
		int wynik = 0;
		fprintf(stderr, "%s poczatek gry, gracz: %s\n", timeCu(), nick);		//poczatek gry
		time_t czas;
		double srczas = 0;
		for (int i = 0; i < nat_num; i++) {
			czas = clock();
			int ran = numberRan();
			printf("%d\n", ran);
			scanf("%d", &uans);
			fprintf(nickf, "wylosowana: %d, podana: %d\t", ran, uans);
			if (uans == convOtD(ran)) {
				wynik++;
				fprintf(nickf, "1\n");
			}
			else {
				fprintf(nickf, "0\n");
			}
			czas = clock() - czas;
			double how_long = ((double)czas) / CLOCKS_PER_SEC;
			srczas += how_long;
		}
		srczas /= nat_num;
		fprintf(stderr, "%s koniec gry, sredni czas to: %.4lf\n", timeCu(), srczas);		//koniec gry
		printf("twoj wynik to: %d\n", wynik);
		printf("Jesli chcesz zagrac jeszcze raz wpisz '1', jesli chcesz zakonczyc prace programu wpisz '0': ");
		while (scanf_s("%d", &end) != 1 || end != 0 && end != 1 || getchar() != '\n') {
			printf("blad, popraw\n liczba: ");
			while (getchar() != '\n') {
				;
			}
		}
	} while (end == 1);
	printf("\n\nKoniec programu, Dziekuje za gre :)\n");
	fprintf(stderr, "%s koniec programu\n", timeCu());		//koniec programu
}

int numberRan() {
	int num1, num2;
	int fnum;
	num1 = rand() % 8;
	num2 = rand() % 8;
	fnum = (num1 * 10) + num2;
	return fnum;
}
int convOtD(int oct) {
	int dec = 0;
	int i = 0;
	while (oct != 0)
	{
		dec = dec + (oct % 10)* pow(8, i++);
		oct = oct / 10;
	}
	return dec;
}
char* timeCu() {
	time_t current_time;
	char* string_time;
	current_time = time(NULL);
	string_time = ctime(&current_time);
	int lenght = strlen(string_time);
	string_time[lenght - 6] = NULL;
	return string_time;
}