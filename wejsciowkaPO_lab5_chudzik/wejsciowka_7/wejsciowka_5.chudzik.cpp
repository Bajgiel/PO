#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int bin_conv(char **arr, int i);

int main() {
	printf("podaj ilosc kolumn: ");
	int kolumny;// ilosc kolumn
	scanf_s("%d", &kolumny);
	printf("podaj ilosc wierszy: ");
	int wiersze;//ilosc wierszy
	scanf_s("%d", &wiersze);
	char **a = (char**)malloc(wiersze * sizeof(char**));//alokacja tablicy 2d
	for (int i = 0; i < wiersze; ++i) {
		a[i] = (char*)malloc(kolumny * sizeof(char*));
	}
	for (int i = 0; i < wiersze; ++i) {// wypelnieni tablicy NULL
		for (int j = 0; j < kolumny; ++j) {
			a[i][j] = NULL;
		}
	}
	printf("podaj nazwe pliku do odczytu: ");
	char file_name[20];
	scanf_s("%s", file_name, 20);
	FILE *r;
	if ((r = fopen(file_name, "r")) == NULL) {//Otwirzenie pliku i sprawdzenie czy istnieje
		printf("blad pliku.");
	}
	for (int i = 0; !feof(r);++i) {// wypelnienie tablicy danymi z pliku
		for (int j = 0; j<kolumny; ++j) {
			fscanf(r, "%c", &a[i][j]);
			if (a[i][j] == '\n') {
				a[i][j] = '\0';
				break;
			}
		}
	}
	if (NULL != r) {// sprawdzenie czy plik jest pusty
		fseek(r, 0, SEEK_END);
		int size = ftell(r);
		if (0 == size) {
			printf("Plik jest pusty.\nKoniec porgramu.");
			return 0;
		}
	}
	fclose(r);//zamkniecie pliku
	printf("liczby dziesietne:");
	for (int i = 0; a[i][0] != 0; ++i) {// konwersja z binarnego na dziesiatkowy
			int d = bin_conv(a, i);
			printf("\n%d", d);
	}
	for (int i = 0;a[i][0]!=0; ++i) {//sortowanie
		long long max = 0;
		max = atoll(a[i]);
		for (int j = i+1; a[j][0]!=0; ++j) {
			char *tmp = NULL;
			long long check;
			check = atoll(a[j]);
			if (max<check) {
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
				max = check;
			}
		}
	}
	printf("\n\nposortowane liczby dziesietne:");
	for (int i = 0; a[i][0] != 0; ++i) {//wypisanie posortowanych liczb dziesietnych
		int d = bin_conv(a, i);
		printf("\n%d", d);
	}
	for (int i = 0; i < wiersze; ++i) {//dealokacja 2d
		free(a[i]);
	}
	free(a);// dealokacja 1d
}

int bin_conv(char **arr, int i) {
	int dec = 0, x = 0, tmp;
	long long wart = atoll(arr[i]);
	while (wart != 0) {
		tmp = wart % 10;
		dec += tmp * pow(2, x);
		wart /= 10;
		++x;
	}
	return dec;
}
