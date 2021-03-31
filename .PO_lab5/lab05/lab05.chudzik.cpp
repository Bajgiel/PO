#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct potrawa {
	int kod;
	char nazwa[40];
	int kalorie;
	float cena;
};
struct inf {
	struct potrawa *pointer;
	int size;
}info;
/**
FUNKCJA 1
@brief  funkcja liczy elementy w pliku
@param  plik
@return dlugosc pliku
*/
int row_count(FILE* r)
{
	int row = -1;
	char word[40];
	while (!feof(r))
	{
		for (int i = 0; i < 4; ++i)
		{
			fscanf(r, "%s", word);
			if (i == 3) row++;
		}
	}
	rewind(r);
	return row;
}
/**
FUNKCJA 2
@brief  tworzy tablice dynamiczna i wczytuje do niej zawartosc pliku
@param  nazwa pliku
@return wartosci typu struturalnego o dwoch polach,
	1. przechowuje wskaznik do utworzonej tablicy
	2. rozmiar tablicy
*/
struct inf fill_tab(FILE *r) {
	info.size = row_count(r);
	struct potrawa *a = (struct potrawa*)malloc(info.size * sizeof(struct potrawa));
	for (int i = 0; i < info.size; ++i) {
		a[i].kod = NULL;
		a[i].nazwa, NULL;
		a[i].kalorie = NULL;
		a[i].cena = NULL;
	}
	for (int i = 0; i < info.size; ++i) {
		fscanf(r, "%d", &a[i].kod);
		fscanf(r, "%s", &a[i].nazwa, 40);
		fscanf(r, "%d", &a[i].kalorie);
		fscanf(r, "%f", &a[i].cena);
	}
	struct inf I;
	I.pointer = a;
	I.size = info.size;
	fclose(r);
	return I;
}
/**
FUNKCJA 3
@brief wypisz na ekran zawartosc tablicy o elementach struct, kazda potrawa w osobnej linij
@param tablica, rozmiar tablicy
@return void
*/
void print_tab(struct potrawa a[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d %s %d %.2f\n", a[i].kod, a[i].nazwa, a[i].kalorie, a[i].cena);
	}
}
/**
FUNKCJA 4
@brief  pobiera od uzytkownika kod potrawy
		przenosi  potrawe na koniec tablicy przy pomocy l v
@param  (?)
@return pointer do tablicy dynamicznej
*/
struct potrawa* Ucode(struct potrawa a[], int size) {
	struct potrawa *ptr = a;
	printf("podaj kod potrawy: ");
	int code=0;
	scanf("%d", &code);
	int code_check = 0;
	int pos = 0;
	for (int i = 0; i < size; ++i) {
		if (a[i].kod == code) {
			code_check = 1;
			pos = i;
		}
	}
	if (code_check == 0) {
		printf("bledny kod");
		exit(0);
	}
	struct potrawa tmp;
	int siz_tmp = size - 1;
	tmp = a[pos];
	a[pos] = a[siz_tmp];
	a[siz_tmp] = tmp;
	return ptr;
}
int main() {
	FILE *r;
	if ((r = fopen("file.txt", "r")) == NULL)exit(0);
	/*1. wczytaj dane do tablicy wykorzystujac funkcje 2*/
	struct inf I = fill_tab(r);
	/*2. wypisz zawartosc tablicy wyk funkcje 3*/
	print_tab(I.pointer, I.size);
	/*3. wez funkcje 4 pobierz kod potrawy i zmodyfikuj tablice*/
	Ucode(I.pointer, I.size);
	/*4. wez plik do zapisu otworz i zapisz tablice*/
	char file_write[40];
	printf("podaj nazwe pliku do zapisu: ");
	scanf("%s", file_write,40);
	FILE* w;
	w = fopen(file_write, "w");
	for (int i = 0; i < I.size; i++)
	{
		fprintf(w, "%d %s %d %.2f\n", I.pointer[i].kod, I.pointer[i].nazwa, I.pointer[i].kalorie, I.pointer[i].cena);
	}
	/*5. zamkij plik free tab return 0*/
	fclose(w);
	free(I.pointer);
	return 0;
}
