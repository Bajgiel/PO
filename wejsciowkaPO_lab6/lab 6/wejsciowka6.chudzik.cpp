#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar *nast;
};

FILE* fileOpen();					// funkcja otwiera plik
struct pomiar* fillList(FILE *r);	//funkcja wypelnia liste
void fillCzuj(struct pomiar *p);	// funkcja liczy wielkosc list dla danego czujnika i zapisuje je w pliku

int main() {
	FILE* r = fileOpen();
	struct pomiar *p = fillList(r);
	fillCzuj(p);
	free(p);
}

FILE* fileOpen() {
	char file[20];
	scanf("%s", file, 20);
	FILE* r;
	if ((r = fopen(file, "r")) == NULL) exit(0);	//sprawdzenie czy plik istnieje
	return r;
}
struct pomiar* fillList(FILE *r) {
	struct pomiar *ptr=NULL, *head = NULL;
	int tmpPom=0, tmpCzuj=0;
	char tmpDat[20];
	double tmpTem=0;
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
void fillCzuj(struct pomiar *p) {
	struct pomiar*ptr1 = NULL, *cz1 = NULL;
	struct pomiar*ptr2 = NULL, *cz2 = NULL;
	struct pomiar*ptr3 = NULL, *cz3 = NULL;
	struct pomiar*ptr4 = NULL, *cz4 = NULL;
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	int i = 0;
	while (p) {					//liczenie elementow dla danego czujnika i przypisywanie go do glowy
		switch (p->nr_czujnika)
		{
		case 1:
			if (cz1 == NULL) {
				cz1 = ptr1 = p;
			}
			else {
				ptr1->nast = p;
				ptr1 = ptr1->nast;
			}
			c1++;
			p = p->nast;
			break;
		case 2:
			if (cz2 == NULL) {
				cz2 = ptr2 = p;
			}
			else {
				ptr2->nast = p;
				ptr2 = ptr2->nast;
			}
			c2++;
			p = p->nast;
			break;
		case 3:
			if (cz3 == NULL) {
				cz3 = ptr3 = p;
			}
			else {
				ptr3->nast = p;
				ptr3 = ptr3->nast;
			}
			c3++;
			p = p->nast;
			break;
		case 4:
			if (cz4 == NULL) {
				cz4 = ptr4 = p;
			}
			else {
				ptr4->nast = p;
				ptr4 = ptr4->nast;
			}
			c4++;
			p = p->nast;
			break;
		default:
			break;
		}
		i++;
	}
	printf("ilosc wynikow dla czujnika:\n\n");
	printf("1: %d\n", c1);
	printf("2: %d\n", c2);
	printf("3: %d\n", c3);
	printf("4: %d\n", c4);
													/*zapisanie danych w plikach*/
	printf("podaj nazwe pliku do zapisu: ");
	char file_name[20];
	FILE *w1, *w2, *w3;
	scanf_s("%s", &file_name, 20);
	int len = strlen(file_name);
	char fill[20]="1.txt";
	strncat(file_name, fill, 5);
	printf("%s", file_name);
	w1 = fopen(file_name, "w");
	while (cz1) {
		fprintf(w1, "%d %d %s %.2lf\n", cz1->nr_pomiaru, cz1->nr_czujnika, cz1->data_i_czas, cz1->temp);
		cz1 = cz1->nast;
	}
	fclose(w1);
	free(cz1);
	file_name[len] = '\0';
	char fill2[20] = "2.txt";
	strncat(file_name, fill2, 5);
	printf("%s", file_name);
	w2 = fopen(file_name, "w");
	while (cz2) {
		if (cz2->nr_czujnika != 2) break;
		fprintf(w2, "%d %d %s %.2lf\n", cz2->nr_pomiaru, cz2->nr_czujnika, cz2->data_i_czas, cz2->temp);
		cz2 = cz2->nast;
	}
	fclose(w2);
	free(cz2);
	file_name[len] = '\0';
	char fill3[20] = "3.txt";
	strncat(file_name, fill3, 5);
	printf("%s", file_name);
	w3 = fopen(file_name, "w");
	while (cz3) {
		if (cz3->nr_czujnika != 3) break;
		fprintf(w3, "%d %d %s %.2lf\n", cz3->nr_pomiaru, cz3->nr_czujnika, cz3->data_i_czas, cz3->temp);
		cz3 = cz3->nast;
	}
	fclose(w3);
	free(cz3);
}