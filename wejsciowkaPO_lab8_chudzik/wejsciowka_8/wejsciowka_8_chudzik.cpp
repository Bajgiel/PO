#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

char* timeCu();
int fileCheck(char* nick);

int main(int argc, char *argv[]) {
	FILE *log;
	srand((unsigned int)time(NULL));
	if ((log = fopen("log.txt", "a")) == NULL) {
		printf("Error while trying to open file %s: %s\n\n", "log.txt", strerror(errno));
		exit(0);
	}
	printf("podaj swoj nick: ");
	char nick[20];
	scanf_s("%s", &nick, 20);
	fprintf(log, "%s\tuzytkownik wprowadzil nick '%s'\n", timeCu(), nick);					//nick
	printf("\npodaj niewielka liczbe naturalna: ");
	float nat_num;
	scanf_s("%f", &nat_num);
	fprintf(log, "%s\tuzytkownik podal liczbe: %.2f\n", timeCu(), nat_num);					//liczba uzytkownika
	if (nat_num <= 0 || (int)nat_num - nat_num != 0) {
		printf("blad. liczba nie jest naturalna");
		fprintf(log, "%s\tuzytkownik podal liczbe nie naturalna\n", timeCu());				//zla liczba
		exit(0);
	}
	int wynik = 0;
	time_t start_t, end_t;
	system("cls");
	printf("Uwaga, zaraz zacznie sie rozgrywka, ilosc liter to: %.0f", nat_num);
	Sleep(5000);
	system("cls");
	for (int i = 3; i > 0; i--) {
		printf("%d", i);
		Sleep(1000);
		system("cls");
	}
	time(&start_t);
	for (int i = 0; i < nat_num; i++) {
		int lit = rand() % 26 + 97;
		fprintf(log, "%s\tzostala wylosowana litera: %c\n", timeCu(), lit);				//litera wylosowana
		printf("%c\n", lit);
		char key = _getch();
		fprintf(log, "%s\tuzytkownik podal litere: %c\n", timeCu(), key);				//litara podana
		if (lit == key) {
			wynik++;
			fprintf(log, "%s\tlitera podana przez uzytkownika jest prawidlowa\n", timeCu());			//litera podana prawidlowa
		}
		else {
			fprintf(log, "%s\tlitera podana przez uzytkownika jest nieprawidlowa\n", timeCu());			//litera podana bledna
		}
	}
	time(&end_t);
	double diff_t = difftime(end_t, start_t);
	fprintf(log, "%s\tczas proby: %f\n", timeCu(), diff_t);					// czas proby
	printf("czas to: %f sekund\n", diff_t);
	printf("twoj wynik to: %d\n", wynik);
	strcat(nick, ".txt");
	int file_check = fileCheck(nick);
	FILE *nickf;
	if (file_check == 0) {
		printf("twoj wynik zostanie zapisany w pliku z nazwa twojego nicku pod adresem:\n%s\n\n", argv[0]);
	}
	nickf = fopen(nick, "a");
	fprintf(log, "%s\totwarcie pliku: %s\n", timeCu(), nick);					//plik nick
	fprintf(nickf, "\n%.2fsec\t%dpts", diff_t, wynik);
	fprintf(log, "%s\twynik zostal zapisany do pliku o nazwie: %s\n", timeCu(), nick);					//zapis wynniku w pliku
	printf("Koniec programu.\n\n");
	fclose(nickf);
	return 0;
}

char* timeCu() {
	time_t current_time;
	char* string_time;
	current_time = time(NULL);
	string_time = ctime(&current_time);
	int lenght = strlen(string_time);
	string_time[lenght - 1] = NULL;
	return string_time;
}
int fileCheck(char* nick) {
	FILE *r;
	if ((r = fopen(nick, "r")) == NULL) {
		return 0;
	}
	else {
		fclose(r);
		return 1;
	}
}