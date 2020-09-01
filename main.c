#include <stdio.h>
#include <stdlib.h>

//int swap(int* x, int* y) {
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//int bubbleSort(int dizi[], int size) {
//	
//	for (int i = 0; i < size - 1; i++) {
//		for (int j = 0; j < size - i - 1; j++) {
//			if (dizi[j] > dizi[j + 1]) {
//				swap(&dizi[j], &dizi[j + 1]);
//				}
//		}
//		
//	}
//	}
int kNNAlgoritmasý(int testEdilecekDeger[11]) {
	int egitimVeriSeti[600][12];
	int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
	int yer[3];
	
/*
 1)Eðitim veri seti okunup bir diziye kayýt edilecek
 2)Fonksiyona yollanan veriye en yakýn olan eðitim veri setleri ilk sýralanacak
 3)Sýralanan eðitim veri setinin 11 (Sýnýf bilgisine bakýlacak)
 4)Sýnýf verisine bakýlarak gelen kiþinin hasta mý saðlýklý mý olunduðuna bakýlacak

 OZETLE:Bu fonksiyon bir test veri seti alýp geri dönüþ olarak o veri setinin hasta mý saðlýklý olduðunu
 kontrol ediyor.
 */
	FILE* dosya;
	fopen_s(&dosya, "egitim.txt", "r");
	for (int i = 0; i != 600; i++) {
		fscanf_s(dosya, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11);
		egitimVeriSeti[i][0] = d1;
		egitimVeriSeti[i][1] = d2;
		egitimVeriSeti[i][2] = d3;
		egitimVeriSeti[i][3] = d4;
		egitimVeriSeti[i][4] = d5;
		egitimVeriSeti[i][5] = d6;
		egitimVeriSeti[i][6] = d7;
		egitimVeriSeti[i][7] = d8;
		egitimVeriSeti[i][8] = d9;
		egitimVeriSeti[i][9] = d10;
		egitimVeriSeti[i][10] = d11;
		egitimVeriSeti[i][11] = 0;
		for (int j = 1; j < 10; j++) {

			egitimVeriSeti[i][11]= egitimVeriSeti[i][11] + ((testEdilecekDeger[j] - egitimVeriSeti[i][j]) * (testEdilecekDeger[j] - egitimVeriSeti[i][j]));
		
		}
		
	}
	//for (int i = 0; i < 600; i++)
	//{
	//	printf("%d inci egitim verisetinin uzakligi= %d\n", i,egitimVeriSeti[i][11]);
	//}
	//printf("\n *************************\n");
	//	
	int min1 = 99999999;
	yer[0] = -1;
	
	for (int i = 0; i < 600; i++) {
		if (min1 >= egitimVeriSeti[i][11]) {
			min1 = egitimVeriSeti[i][11];
			yer[0] = i;
		}
	}
	int min2 = 99999999;
	yer[1] = -1;

	for (int i = 0; i < 600; i++) {
		if ((min1 <= egitimVeriSeti[i][11])&&(min2>=egitimVeriSeti[i][11])&&(yer[0]!=i)) {
			min2 = egitimVeriSeti[i][11];
			yer[1] = i;
		}
	}
	int min3 = 99999999;
	yer[2] = -1;

	for (int i = 0; i < 600; i++) {
		if ((min2 <= egitimVeriSeti[i][11]) && (min3 >= egitimVeriSeti[i][11]) && (yer[0] != i) && (yer[1] != i)) {
			min3 = egitimVeriSeti[i][11];
			yer[2] = i;
		}
	}
	/*
			for (int i = 0; i < 3; i++) {
				printf("%d ,", yer[i]);
	}
	*/

	int hasta = 0;
	int saglikli = 0;
	for (int i = 0; i < 3; i++) {
		if (egitimVeriSeti[yer[i]][10] == 2) {
			saglikli++;
		}
		else if (egitimVeriSeti[yer[i]][10] == 4) {
			hasta++;
		}
	}


	if (saglikli > hasta) {
		return 2;
	}
	else if (hasta > saglikli) {
		return 4;
	}
	 
	


	
	return -1;
}

int testVeriOkuma() {
	int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
	int testVeriSeti[83][11];
	int bulunanVeri[83];
	FILE* dosya2;
	fopen_s(&dosya2, "test.txt", "r");
	for (int i = 0; i != 83; i++) {
		fscanf_s(dosya2, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11);
		testVeriSeti[i][0] = d1;
		testVeriSeti[i][1] = d2;
		testVeriSeti[i][2] = d3;
		testVeriSeti[i][3] = d4;
		testVeriSeti[i][4] = d5;
		testVeriSeti[i][5] = d6;
		testVeriSeti[i][6] = d7;
		testVeriSeti[i][7] = d8;
		testVeriSeti[i][8] = d9;
		testVeriSeti[i][9] = d10;
		testVeriSeti[i][10] = d11;
	}
	fclose(dosya2);
	int dogru = 0;
	for (int i = 0; i != 83; i++) {
		//printf("%d test veriseti", i);
		bulunanVeri[i] = kNNAlgoritmasý(testVeriSeti[i]);
		if (bulunanVeri[i] == testVeriSeti[i][10]) {
			dogru++;
		}
	}
float basariOrani = (float) dogru * 100 / 83;
		printf("Basari Orani: %%%f", basariOrani);
}
int main() {HATA:
	printf("\t Yapay Zeka ile Kanser Testi\t");
	printf("\n ---------------------------------------------\n");
	printf("Yapilacak Islemi Seciniz:\n");
	printf("1.Test Dosyasini Hesapla\n");
	printf("2.Parametere Al\n");
	int n;
	
	printf("Girdi:");
	scanf_s("%d", &n);
	if (n == 1) {
		system("cls");
		testVeriOkuma();
	}
	if (n == 2) {
		system("cls");
		int parametre[11];
		parametre[0] = 0;
		parametre[10] = 0;
		printf("9 parametreyi giriniz\n");
		for (int i = 1; i < 10; i++) {
			scanf_s("%d",& parametre[i]);
		}
		system("cls");
		if (kNNAlgoritmasý(parametre) == 2) {
			printf("Birey sagliklidir...");
		}else if(kNNAlgoritmasý(parametre) == 4) {
			printf("Birey hastadir...");
		}
	}
	else if ((n!=1)&&(n!=2))
	{
		system("cls");
		printf("Yanlis girdi alindi! Tekrar deneyiniz...\n");
		goto HATA;
	}
}