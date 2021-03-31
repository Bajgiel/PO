//#include<stdio.h>
//#include<string.h>
//
//#define N 5
//
//struct str {//struktura char i int
//	char napis[16];
//	int liczba;
//};
//
//int fun_str(struct str ar[N]) {
//	int skrocenie=0;
//	for (int i = 0; i < N; ++i) {
//		int lenght = strlen(ar[i].napis);
//		if (ar[i].liczba >= 0 && ar[i].liczba < lenght) {// sprawdza i skraca char
//			ar[i].napis[ar[i].liczba] = '\0';
//			skrocenie++;
//		}
//	}
//	return skrocenie;
//}
//
//int main() {
//	struct str ar[5];//seed struktury
//	for (int i = 0; i < N; ++i) {// wypelnienie struktury
//		char string[20];
//		int num;
//		printf("podaj napis(bez spacji, do %d znakow): ", 16);
//		scanf_s("%s", string, 16);
//		printf("podaj liczbe: ");
//		scanf_s("%d", &num);
//		strcpy_s(ar[i].napis, string);
//		ar[i].liczba = num;
//	}
//	int skr=fun_str(ar);
//	printf("napisy:\t\twartosci:\n");
//	for (int i = 0; i < N; ++i) {// wypis skroconej struktury
//		printf("%-16s%d\n", ar[i].napis, ar[i].liczba);
//	}
//	printf("\nilosc skrocen: %d", skr);
//}
//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>

#define N 20

void fun(int x) {
	if (isupper(x)) {
		x = tolower(x);
	}
	else if (islower(x)) {
		x = toupper(x);
	}
}

int main() {
	char file_name_read[N] = "read.txt";
	FILE *r, *w;
	r = fopen(file_name_read, "r");
	char file_name_write[N] = "write.txt";
	if ((w = fopen(file_name_write, "w")) == NULL) {
		printf("blad.");
	}
	int x = '0';
	for (int i = 0; i < N;++i) {
		fscanf(r, "%c", &x);
		fun(x);
		fprintf(w, "%c", x);
	}
	fclose(r);
	fclose(w);
}