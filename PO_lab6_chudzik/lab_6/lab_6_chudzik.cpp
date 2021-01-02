#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar *nast;
};
struct tmp {
	struct pomiar* c1;
	struct pomiar* c2;
	struct pomiar* c3;
	struct pomiar* c4;
};
struct pomiar2w {							// struktura listy 2w
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar2w *nast;
	struct pomiar2w *poprz;
};

struct pomiar* fillList(char *file);			//funkcja 1
void countList(struct pomiar *p);				//funkcja 2
struct tmp* newList(struct pomiar *p);			//funkcja 3
struct pomiar* tempList(struct pomiar *p);		//funkcja 4
struct pomiar2w* twowayList(struct pomiar *p);	//funckja zadanie 2(dla listy 2w)
void countList2w(struct pomiar2w *p);			//funkcja do liczenia listy 2w

int main() {
	char file_name[20]="temp-na-zewn.txt";
	struct pomiar *p = fillList(file_name);	//funkcja 1
	countList(p);							//funckja 2
	struct tmp* tm = newList(p);			//tablica z 4 strukturami //funkcja 3
	free(p);								//zwolnienie tablicy z elementami
	printf("czujnik 1:\n");
	countList(tm->c1);
	struct pomiar* c1 = tempList(tm->c1);
	countList(c1);
	printf("czujnik 2:\n");
	countList(tm->c2);
	struct pomiar* c2 = tempList(tm->c2);
	countList(c1);
	printf("czujnik 3:\n");
	countList(tm->c3);
	struct pomiar* c3 = tempList(tm->c3);
	countList(c3);
	printf("czujnik 4:\n");
	countList(tm->c4);
	struct pomiar* c4 = tempList(tm->c4);
	countList(c4);
	printf("\n\n\n\n");
	struct pomiar2w* tw = twowayList(tm->c4);	//funkcja do zad 2
	countList2w(tw);
	printf("\n\n\n\n");
	free(c1);								//zwolnienie tablic
	free(c2);								//	
	free(c3);								//
	free(c4);								//
	free(tw);

	printf("koniec programu.");
	return 0;
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
void countList(struct pomiar *p) {
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
	printf("liczba elementow: %d\n\n\n", cou);
}
struct tmp* newList(struct pomiar *p) {
	struct pomiar*ptr = p;
	struct pomiar*ptr1 = NULL, *cz1 = NULL;
	struct pomiar*ptr2 = NULL, *cz2 = NULL;
	struct pomiar*ptr3 = NULL, *cz3 = NULL;
	struct pomiar*ptr4 = NULL, *cz4 = NULL;
	struct tmp* tm=(struct tmp*)malloc(sizeof(struct tmp));
	while (ptr) {					//przypisywanie go do glowy
		switch (ptr->nr_czujnika)
		{
		case 1:
			if (cz1 == NULL) {
				cz1 = ptr1 = (struct pomiar*)malloc(sizeof(struct pomiar));
			}
			else {
				ptr1->nast = (struct pomiar*)malloc(sizeof(struct pomiar));
				ptr1 = ptr1->nast;
			}
			ptr1->nr_pomiaru = ptr->nr_pomiaru;
			ptr1->nr_czujnika = ptr->nr_czujnika;
			strcpy(ptr1->data_i_czas, ptr->data_i_czas);
			ptr1->temp = ptr->temp;
			ptr1->nast = NULL;
 			ptr = ptr->nast;
			break;
		case 2:
			if (cz2 == NULL) {
				cz2 = ptr2 = (struct pomiar*)malloc(sizeof(struct pomiar));;
			}
			else {
				ptr2->nast = (struct pomiar*)malloc(sizeof(struct pomiar));;
				ptr2 = ptr2->nast;
			}
			ptr2->nr_pomiaru = ptr->nr_pomiaru;
			ptr2->nr_czujnika = ptr->nr_czujnika;
			strcpy(ptr2->data_i_czas, ptr->data_i_czas);
			ptr2->temp = ptr->temp;
			ptr2->nast = NULL;
			ptr = ptr->nast;
			break;
		case 3:
			if (cz3 == NULL) {
				cz3=ptr3 = (struct pomiar*)malloc(sizeof(struct pomiar));;
			}
			else {
				ptr3->nast = (struct pomiar*)malloc(sizeof(struct pomiar));;
				ptr3 = ptr3->nast;
			}
			ptr3->nr_pomiaru = ptr->nr_pomiaru;
			ptr3->nr_czujnika = ptr->nr_czujnika;
			strcpy(ptr3->data_i_czas, ptr->data_i_czas);
			ptr3->temp = ptr->temp;
			ptr3->nast = NULL;
			ptr = ptr->nast;
			break;
		case 4:
			if (cz4 == NULL) {
				cz4 = ptr4 = (struct pomiar*)malloc(sizeof(struct pomiar));;
			}
			else {
				ptr4->nast = (struct pomiar*)malloc(sizeof(struct pomiar));;
				ptr4 = ptr4->nast;
			}
			ptr4->nr_pomiaru = ptr->nr_pomiaru;
			ptr4->nr_czujnika = ptr->nr_czujnika;
			strcpy(ptr4->data_i_czas, ptr->data_i_czas);
			ptr4->temp = ptr->temp;
			ptr4->nast = NULL;
			ptr = ptr->nast;
			break;
		}
	}
	tm->c1 = cz1;
	tm->c2 = cz2;
	tm->c3 = cz3;
	tm->c4 = cz4;
	return tm;
}
struct pomiar* tempList(struct pomiar *p) {
	struct pomiar *tmp=NULL, *ptr = p;
	struct pomiar* tp = (struct pomiar*)malloc(sizeof(struct pomiar));
	double temp = 0;
	while (ptr) {
		if (temp < ptr->temp) {
			temp = ptr->temp;
			tmp = ptr;
		}
		ptr = ptr->nast;
	}
	printf("Element z najwyzsza temperatura:\n");
	printf("%d %d %s %.2lf\n\n", tmp->nr_pomiaru, tmp->nr_czujnika, tmp->data_i_czas, tmp->temp);
	tp->nr_pomiaru = tmp->nr_pomiaru;
	tp->nr_czujnika = tmp->nr_pomiaru;
	strcpy(tp->data_i_czas, tmp->data_i_czas);
	tp->temp = tmp->temp;
	tp->nast = p;
	return tp;
}
struct pomiar2w* twowayList(struct pomiar *p){
	struct pomiar2w* ptr2 = NULL, *head=NULL, *tmp=NULL;
	struct pomiar* ptr = p;
	while (ptr) {
		if (head == NULL) {
			head = ptr2 = (struct pomiar2w*)malloc(sizeof (struct pomiar2w));
			head->poprz = NULL;
		}
		else {
			tmp = ptr2;
			ptr2->nast = (struct pomiar2w*)malloc(sizeof(struct pomiar2w));
			ptr2 = ptr2->nast;
		}
		ptr2->nr_pomiaru = ptr->nr_pomiaru;
		ptr2->nr_czujnika = ptr->nr_czujnika;
		strcpy(ptr2->data_i_czas, ptr->data_i_czas);
		ptr2->temp = ptr->temp;
		ptr2->poprz = tmp;
		ptr2->nast = NULL;
		ptr = ptr->nast;
	}
	return head;
}
void countList2w(struct pomiar2w *p) {
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
	printf("liczba elementow: %d\n\n\n", cou);
}
