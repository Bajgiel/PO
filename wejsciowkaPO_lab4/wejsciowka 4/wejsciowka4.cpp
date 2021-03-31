#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define N 5

struct para {//struktura 2 elementow
	char napis[15];
	int liczba;
};

int wiersz(FILE *f, struct para *p){// funkcja przypisujace wiersze
	char cos[15];
	int cosi;
	for (int i = 0; i < 3; ++i) {
		if (feof(f)) {
			return 1;
		}
		else {
			if (i % 3 == 0) {
				fscanf(f, "%s", &cos);
			}
			else if (i % 3 == 1) {
				fscanf(f, "%s", &cos);
				strcpy(p->napis, cos);
			}
			else if (i % 3 == 2) {
				fscanf(f, "%d", &cosi);
				p->liczba = cosi;
			}
		}
	}
	return 0;
}

int main() {
	struct para t[N];//seed
	printf("podaj nazwe pliku z danymi: ");
	char file_name_read[20];
	scanf_s("%s", file_name_read, 20);
	printf("\npodaj nazwe pliku wyjsciowego: ");
	char file_name_write[20];
	scanf_s("%s", file_name_write, 20);
	FILE *f, *q;
	f=fopen(file_name_read, "r");
	q=fopen(file_name_write, "w");
	for (int i = 0; i < N; i++) {
		int n = wiersz(f, t);
		switch (n) {
		case 0: 
			t[i].liczba = t->liczba;
			strcpy(t[i].napis, t->napis);
			for (int j = 0; j < 20; ++j) {
				if (t[i].napis[j] == 'a' || t[i].napis[j] == 'e' || t[i].napis[j] == 'i' || t[i].napis[j] == 'o' || t[i].napis[j] == 'u' || t[i].napis[j] == 'y') {
					t[i].napis[j] = '*';
				}
			}
			break;
		case 1:
			continue;
		}
		printf("%s, %d\n", t[i].napis, t[i].liczba);
		fprintf(q, "%s\t%d\n", t[i].napis, t[i].liczba);
	}
	fclose(f);
	fclose(q);
}
