#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar *nast;
	struct pomiar *poprz;
};
struct tmp {
	struct pomiar* c1;
	struct pomiar* c2;
	struct pomiar* c3;
	struct pomiar* c4;
};

struct pomiar* fillList(char* file);		//funkcja 1
void countList(struct pomiar* p);			//funkcja 2
struct tmp* newList(struct pomiar* p);		//funkcja 3
int tempList(struct pomiar* t);				//funkcja 4

int main() {
	char file_name[20] = "temp-na-zewn.txt";		// uzycie 
	struct pomiar *p = fillList(file_name);			// 1 funkcji
	countList(p);									// funckja 2
	struct tmp* tm = newList(p);					// stworzenie nowych 4 list (funkcja 3)
	p = NULL;										// i usuniecie glownej listy
	free(p);										//
	printf("\nlista 1:\n\n");							// wypisanie temperatury i ilosci elementow dla 4 list
	countList(tm->c1);
	int dist = tempList(tm->c1);
	printf("odleglosc miedzy punktami to: %d\n", dist);
	printf("\nlista 2:\n\n");
	countList(tm->c2);
	dist = tempList(tm->c2);
	printf("odleglosc miedzy punktami to: %d\n", dist);
	printf("\nlista 3:\n\n");
	countList(tm->c3);
	dist = tempList(tm->c3);
	printf("odleglosc miedzy punktami to: %d\n", dist);
	printf("\nlista 4:\n\n");
	countList(tm->c4);
	dist = tempList(tm->c4);
	printf("odleglosc miedzy punktami to: %d\n", dist);
	free(tm);
	tm = NULL;
	printf("\n\nKoniec programu.\n");
 }

struct pomiar* fillList(char *file) {
	FILE* r;
	if ((r = fopen(file, "r")) == NULL) exit(0);	//sprawdzenie czy plik istnieje
	if (NULL != r) {
		fseek(r, 0, SEEK_END);
		int size = ftell(r);
		if (0 == size) {
			printf("plik jest pusty\n");
			exit(0);
		}
		rewind(r);
	}
	struct pomiar *ptr = NULL, *head = NULL;
	int tmpPom = 0, tmpCzuj = 0;
	char tmpDat[20];
	double tmpTem = 0;
	fscanf(r, "%d%d%s%lf", &tmpPom, &tmpCzuj, &tmpDat, &tmpTem);
	while (!feof(r))	// wypelnienie listy danymi z pliku
	{
		if (head == NULL) {
			head = ptr = (struct pomiar*)malloc(sizeof(struct pomiar));
		}
		else {
			ptr->nast = (struct pomiar*)malloc(sizeof(struct pomiar));
			ptr = ptr->nast;
		}
		ptr->nr_pomiaru = tmpPom;
		ptr->nr_czujnika = tmpCzuj;
		strcpy(ptr->data_i_czas, tmpDat);
		ptr->temp = tmpTem;
		ptr->nast = NULL;
		fscanf(r, "%d%d%s%lf", &tmpPom, &tmpCzuj, &tmpDat, &tmpTem);
	}
	fclose(r);		// zamkniecie pliku
	return head;	// zwrpocenie wartosci struktury
}
void countList(struct pomiar* p) {
	int cou = 0;
	printf("pierwszy pomiar:\n");
	printf("%d %d %s %.2lf\n\n", p->nr_pomiaru, p->nr_czujnika, p->data_i_czas, p->temp);
	while (p) {
		if (p->nast == NULL) {
			printf("ostatni pomiar:\n");
			printf("%d %d %s %.2lf\n\n", p->nr_pomiaru, p->nr_czujnika, p->data_i_czas, p->temp);
		}
		p = p->nast;
		cou++;
	}
	printf("liczba elementow: %d\n\n", cou);
}
struct tmp* newList(struct pomiar* p) {
	struct pomiar*temp1 = NULL, *temp2 = NULL, *temp3 = NULL, *temp4 = NULL;
	struct pomiar*ptr = p;
	struct pomiar*ptr1 = NULL, *cz1 = NULL;
	struct pomiar*ptr2 = NULL, *cz2 = NULL;
	struct pomiar*ptr3 = NULL, *cz3 = NULL;
	struct pomiar*ptr4 = NULL, *cz4 = NULL;
	struct tmp* tm = (struct tmp*)malloc(sizeof(struct tmp));
	while (p) {					//przypisywanie go do glowy
		switch (p->nr_czujnika)
		{

		case 1:
			if (cz1 == NULL) {
				cz1 = ptr1 = p;
				cz1->poprz = NULL;
			}
			else {
				temp1=ptr1;
				ptr1->nast = p;
				ptr1 = ptr1->nast;
				ptr1->poprz = temp1;
			}
			break;
		case 2:
			if (cz2 == NULL) {
				cz2 = ptr2 = p;
				cz2->poprz = NULL;
			}
			else {
				temp2 = ptr2;
				ptr2->nast = p;
				ptr2->nast->poprz=
				ptr2 = ptr2->nast;
				ptr2->poprz = temp2;
			}
			break;
		case 3:
			if (cz3 == NULL) {
				cz3 = ptr3 = p;
				cz3->poprz = NULL;
			}
			else {
				temp3 = ptr3;
				ptr3->nast = p;
				ptr3 = ptr3->nast;
				ptr3->poprz = temp3;
			}
			break;
		case 4:
			if (cz4 == NULL) {
				cz4 = ptr4 = p;
				cz4->poprz = NULL;
			}
			else {
				temp4 = ptr4;
				ptr4->nast = p;
				ptr4 = ptr4->nast;
				ptr4->poprz = temp4;
			}
			break;
		}
		p = p->nast;
	}
	ptr1->nast = NULL;
	ptr2->nast = NULL;
	ptr3->nast = NULL;
	ptr4->nast = NULL;
	tm->c1 = cz1;
	tm->c2 = cz2;
	tm->c3 = cz3;
	tm->c4 = cz4;
	return tm;
}
int tempList(struct pomiar* t) {
	struct pomiar *tmpL = NULL, *ptrL = t;
	struct pomiar *tmpH = NULL, *ptrH = t;
	double temp = 0;
	while (ptrH) {
		if (temp < ptrH->temp) {
			temp = ptrH->temp;
			tmpH = ptrH;
		}
		ptrH = ptrH->nast;
	}	
	while (ptrL) {
		if (temp > ptrL->temp) {
			temp = ptrL->temp;
			tmpL = ptrL;
		}
		ptrL = ptrL->nast;
	}
	printf("Element z najnizsza temperatura:\n");
	printf("%d %d %s %.2lf\n\n", tmpL->nr_pomiaru, tmpL->nr_czujnika, tmpL->data_i_czas, tmpL->temp);
	printf("Element z najwyzsza temperatura:\n");
	printf("%d %d %s %.2lf\n\n", tmpH->nr_pomiaru, tmpH->nr_czujnika, tmpH->data_i_czas, tmpH->temp);
	long long tH = tmpH->nr_pomiaru, tL = tmpL->nr_pomiaru;
	int dist = abs(tH-tL); 
	return dist;
}