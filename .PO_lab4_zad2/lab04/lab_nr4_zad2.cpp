#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

#define N 20
#define P 2//przesuniecie w kodzie cezara

int sizar(int t, int n) {
	if (isupper(t)) {
		t = t + n;/*65-90*/
		if (t > 90) {
			int liczba = t - 90;
			t = 64 + liczba;
		}
	}
	else if (islower(t)) {
		t = t + n;/*97-122*/
		if (t > 122) {
			int liczba = t - 122;
			t = 96 + liczba;
		}
	}
	return t;
}
int decode(int t, int n){
	if (isupper(t)) {
		t = t - n;/*65-90*/
		if (t < 65) {
			int liczba = 64-t;
			t = 90 - liczba;
		}
	}
	else if (islower(t)) {
		t = t - n;/*97-122*/
		if (t < 97) {
			int liczba = 97-t;
			t = 123 - liczba;
		}
	}
	return t;
}

int main() {
	int t = '0';
	printf("podaj nazwe pliku do odczytu: ");
	char file_name_read[N];
	scanf_s("%s", file_name_read, N);
	FILE *r, *w;
	if ((r = fopen(file_name_read, "r")) == NULL) {
		printf("blad.");
		return 0;
	}
	printf("podaj nazwe pliku do zapisu: ");
	char file_name_write[N];
	scanf_s("%s", file_name_write,N);
	if ((w = fopen(file_name_write, "w")) == NULL) {
		printf("blad.");
	}
	int i = 0;
	while (!feof(r)) {
		fscanf(r, "%c", &t);
		t = sizar(t,P);
		fprintf(w, "%c", t);
	}
	fclose(r);
	fclose(w);
	r = fopen(file_name_write, "r");
	while (!feof(r)) {
		fscanf(r, "%c", &t);
		t = decode(t, P);
		printf("%c", t);
	}
	fclose(r);
}