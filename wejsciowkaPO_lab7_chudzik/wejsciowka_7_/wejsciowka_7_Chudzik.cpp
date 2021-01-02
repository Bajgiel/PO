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
	struct pomiar *poprz;
};
struct czuj {
	struct pomiar *czuj1;
	struct pomiar *czuj2;
	struct pomiar *czuj3;
	struct pomiar *czuj4;
};

int countList(struct pomiar *p);
void tempListL(struct pomiar *p);
void tempListH(struct pomiar *p);


int main() {
	char file_name[20];
	printf("podaj nazwe pliku do odczytu: ");
	scanf("%s", file_name, 20);
	FILE *r;
	if((r = fopen(file_name, "r")) == NULL) exit(0);
	struct pomiar*tmp = NULL;
	struct pomiar*ptr1 = NULL, *cz1 = NULL;
	struct pomiar*ptr2 = NULL, *cz2 = NULL;
	struct pomiar*ptr3 = NULL, *cz3 = NULL;
	struct pomiar*ptr4 = NULL, *cz4 = NULL;
	int tmpPom = 0, tmpCzuj = 0;
	char tmpDat[20];
	double tmpTem = 0;
	fscanf(r, "%d%d%s%lf", &tmpPom, &tmpCzuj, &tmpDat, &tmpTem);
	while (!feof(r)) {	// wypelnienie listy danymi z pliku
		switch (tmpCzuj) {
		case 1:
			if (cz1 == NULL) {
				cz1 = ptr1 = (struct pomiar*)malloc(sizeof(struct pomiar));
				cz1->poprz = NULL;
			}
			else {
				tmp = ptr1;
				ptr1->nast = (struct pomiar*)malloc(sizeof(struct pomiar));
				ptr1 = ptr1->nast;
			}
			ptr1->nr_pomiaru = tmpPom;
			ptr1->nr_czujnika = tmpCzuj;
			strcpy(ptr1->data_i_czas, tmpDat);
			ptr1->temp = tmpTem;
			ptr1->poprz = tmp;
			ptr1->nast = NULL;
			break;
		case 2:
			if (cz2 == NULL) {
				cz2 = ptr2 = (struct pomiar*)malloc(sizeof(struct pomiar));
				cz2->poprz = NULL;
			}
			else {
				tmp = ptr2;
				ptr2->nast = (struct pomiar*)malloc(sizeof(struct pomiar));
				ptr2 = ptr2->nast;
			}
			ptr2->nr_pomiaru = tmpPom;
			ptr2->nr_czujnika = tmpCzuj;
			strcpy(ptr2->data_i_czas, tmpDat);
			ptr2->temp = tmpTem;
			ptr2->poprz = tmp;
			ptr2->nast = NULL;
			break;
		case 3:
			if (cz3 == NULL) {
				cz3 = ptr3 = (struct pomiar*)malloc(sizeof(struct pomiar));
				cz3->poprz = NULL;
			}
			else {
				tmp = ptr3;
				ptr3->nast = (struct pomiar*)malloc(sizeof(struct pomiar));
				ptr3 = ptr3->nast;
			}
			ptr3->nr_pomiaru = tmpPom;
			ptr3->nr_czujnika = tmpCzuj;
			strcpy(ptr3->data_i_czas, tmpDat);
			ptr3->temp = tmpTem;
			ptr3->poprz = tmp;
			ptr3->nast = NULL;
			break;
		case 4:
			if (cz4 == NULL) {
				cz4 = ptr4 = (struct pomiar*)malloc(sizeof(struct pomiar));
				cz4->poprz = NULL;
			}
			else {
				tmp = ptr4;
				ptr4->nast = (struct pomiar*)malloc(sizeof(struct pomiar));
				ptr4 = ptr4->nast;
			}
			ptr4->nr_pomiaru = tmpPom;
			ptr4->nr_czujnika = tmpCzuj;
			strcpy(ptr4->data_i_czas, tmpDat);
			ptr4->temp = tmpTem;
			ptr4->poprz = tmp;
			ptr4->nast = NULL;
			break;
		}
		fscanf(r, "%d%d%s%lf", &tmpPom, &tmpCzuj, &tmpDat, &tmpTem);
	}
	fclose(r);		// zamkniecie pliku
	struct czuj *tm = (struct czuj*)malloc(sizeof(struct czuj));
	tm->czuj1 = cz1;
	tm->czuj2 = cz2;
	tm->czuj3 = cz3;
	tm->czuj4 = cz4;
	printf("ilosc elementow dla czujnika 1: ");
	int s1 = countList(tm->czuj1);
	tempListL(tm->czuj1);
	tempListH(tm->czuj1);
	printf("ilosc elementow dla czujnika 2: ");
	int s2 = countList(tm->czuj2);
	tempListL(tm->czuj2);
	tempListH(tm->czuj2);
	printf("ilosc elementow dla czujnika 3: ");
	int s3 = countList(tm->czuj3);
	tempListL(tm->czuj3);
	tempListH(tm->czuj3);
	printf("ilosc elementow dla czujnika 4: ");
	int s4 = countList(tm->czuj4);
	tempListL(tm->czuj4);
	tempListH(tm->czuj4);
	struct pomiar* head = NULL, *ptr = NULL;
	int sum = s1 + s2 + s3 + s4;
  	int i = 1;
	while (i <= sum) {
		if (tm->czuj1&&tm->czuj1->nr_pomiaru == i) {
			if (head == NULL) {
				head = ptr = tm->czuj1;
				head->poprz = NULL;
			}
			else {
				tmp = ptr;
				ptr->nast = tm->czuj1;
				ptr->poprz = tmp;
				ptr = ptr->nast;
			}
			tm->czuj1 = tm->czuj1->nast;
		}
		else if (tm->czuj2&&tm->czuj2->nr_pomiaru == i) {
			if (head == NULL) {
				head = ptr = tm->czuj2;
				head->poprz = NULL;
			}
			else {
				tmp = ptr;
				ptr->nast = tm->czuj2;
				ptr->poprz = tmp;
				ptr = ptr->nast;
			}
			tm->czuj2 = tm->czuj2->nast;
		}
		else if (tm->czuj3&&tm->czuj3->nr_pomiaru == i) {
			if (head == NULL) {
				head = ptr = tm->czuj3;
				head->poprz = NULL;
			}
			else {
				tmp = ptr;
				ptr->nast = tm->czuj3;
				ptr->poprz = tmp;
				ptr = ptr->nast;
			}
			tm->czuj3 = tm->czuj3->nast;
		}
		else if (tm->czuj4&&tm->czuj4->nr_pomiaru == i) {
			if (head == NULL) {
				head = ptr = tm->czuj4;
				head->poprz = NULL;
			}
			else {
				tmp = ptr;
				ptr->nast = tm->czuj4;
				ptr = ptr->nast;
				ptr->poprz = tmp;
			}
			tm->czuj4 = tm->czuj4->nast;
		}
		++i;
	} 
 //      	while (head) {
	//	printf("%d %d %s %lf\n", head->nr_pomiaru, head->nr_czujnika, head->data_i_czas, head->temp);
	//	head = head->nast;
	//}
	printf("Podaj nazwe pliku do zapisu: ");
	char file_name_write[20];
	scanf("%s", file_name_write, 20);
	FILE* w;
	w = fopen(file_name_write, "w");
	while (head) {
		fprintf(w, "%d %d %s %lf\n", head->nr_pomiaru, head->nr_czujnika, head->data_i_czas, head->temp);
		head = head->nast;
	}
	fclose(w);
	free(ptr);
	free(tmp);
	free(cz1);
	free(cz2);
	free(cz3);
	free(cz4);
	free(ptr2);
	free(ptr4);
}

int countList(struct pomiar *p) {
	int cou = 0;
	while (p) {
		cou++;
		p = p->nast;
	}
	printf("%d\n", cou);
	return cou;
}
void tempListL(struct pomiar *p) {
	struct pomiar *tmp = NULL, *ptr = p;
	struct pomiar* tp = (struct pomiar*)malloc(sizeof(struct pomiar));
	double temp = 100;
	while (ptr) {
		if (temp > ptr->temp) {
			temp = ptr->temp;
			tmp = ptr;
		}
		ptr = ptr->nast;
	}
	printf("Element z najnizsza temperatura:\n");
	printf("%d %d %s %.2lf\n\n", tmp->nr_pomiaru, tmp->nr_czujnika, tmp->data_i_czas, tmp->temp);
}
void tempListH(struct pomiar *p) {
	struct pomiar *tmp = NULL, *ptr = p;
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
}