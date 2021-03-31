#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

//int bin_conv(char *arr[]);
int bin_conv(char *arr, int i) {
	int dec = 0,x=0, tmp;
	//int j = 0;
	int wart = arr[i];
	printf(" wartosc arr[%d]= %d\n\n", i, wart);
	while(wart!=0){
		tmp = wart % 10;
		printf("linia:%d wartosc: %d obrot:%d \n\n", 11, tmp, x);
		printf("tmp:%d wart:%d dec:%d \n\n", tmp, wart, dec);
		
		dec += tmp * pow(2, x);
		printf("linia:%d wartosc:%d obrot:%d \n\n", 15, dec, x);
		printf("tmp:%d wart:%d dec:%d \n\n", tmp, wart, dec);
		wart /= 10;
		printf("linia:%d wartosc:%d obrot:%d \n\n", 13, wart, x);
		printf("tmp:%d wart:%d dec:%d \n\n", tmp, wart, dec);
		++x;
	}
	return dec;
}

int main() {
	int wiersz;//w zadaniu /*m*/
	int kolumna;//w zadaniu /*n*/
	printf("podaj ilosc wierszy: ");
	//scanf_s("%d\n", &m);
	wiersz = 10;// do wyjebania
	printf("\npodaj ilosc kolumn:\n ");
	//scanf_s("%d", &n);
	kolumna = 20;// do wyjebania
	//char **arr;// pointer to array
	char **arr = (char**)calloc(wiersz, sizeof(char*));// alokacja tablicy 1d
	for (int i = 0; i < wiersz; ++i) {
		arr[i] = (char*)malloc(kolumna*sizeof(char));//alokacja tablicy 2d
	}
	printf("\nLINIA: %d", 23);
	int tab[10][20];
	for (int i = 0; i < wiersz; ++i) {//array fill with 0
		for (int j = 0; j < kolumna; ++j) {
			arr[i][j] = NULL;
		}
	}
	printf("\nLINIA: %d", 31);
	char file_name_read[20] = "text.txt";
	FILE *r;
	r = fopen (file_name_read, "r");
	//if ((r = fopen(file_name_read, "r")) == NULL) {// otwarcie pliku do odczytu
	//	printf("blad pliku.");
	//}
	printf("\nLINIA: %d\n", 38);
	for (int i = 0; i < wiersz; ++i) {
		for (int j = 0; j < kolumna; ++j) {
			if (feof(r)) {
				break;
			}
			fscanf(r, "%c", &arr[i][j]);
			if (arr[i][j] == '\n') {
				arr[i][j] = '\0';
				break;
			}
		}
	}
	printf("tu wyswietla %s", arr[0]);
	printf("tu wyswietla %s", arr[1]);
	printf("tu wyswietla %s\n\n", arr[2]);
	for (int i = 0; i < wiersz; ++i) {
			arr[i] -= '0';
	}
	for (int i = 0; i < wiersz; ++i) {
		for (int j = 0; j<kolumna; ++j) {
			if (arr[i][j] == '\0') {
				continue;
			}
			printf("%d", arr[i]);
		}
		putchar('\n');
	}
	for (int i = 0; i < wiersz; ++i) {
		printf("wartosc w main przed przekazaniem ar[%d]= %d", i, arr[i]);
			int dec = bin_conv(arr[i], i);
			printf("%d\n", dec);
			printf("wartosc po wyjsciu ar[%d]= %d\n\n", i, arr[i]);
	}
	printf("\nLINIA: %d", 48);
	fclose(r);
	printf("\nLINIA: %d", 50);
	for (int i = 0; i < kolumna; ++i) {
		free(arr[i]);
		printf("\nLINIA: %d", 53);
	}
	printf("\nLINIA: %d", 56);
	free(arr);// dealokacja pamieci

}

