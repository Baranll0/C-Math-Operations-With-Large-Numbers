#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10000
#define true 1
#define false 0
int sayi1[MAX], sayi2[MAX], topla[MAX];
char s1[MAX], s2[MAX];
int l1, l2;
void sayiTopla(int sayi1[], int sayi2[], char s1[], char s2[], int l1, int l2)
{
	for (l1 = 0; s1[l1] != '\0'; l1++) // Alinan sayiyi integer e çevirme islemi diziyle yapiliyor.
	{
		sayi1[l1] = s1[l1] - '0';
	}
	for (l2 = 0; s2[l2] != '\0'; l2++)
	{
		sayi2[l2] = s2[l2] - '0';
	}
	int tasi = 0; // Toplama islemi yapiliyor elde bir sonraki sayiya aktarilir.
	int k = 0;
	int i = l1 - 1;
	int j = l2 - 1;
	for (; i >= 0 && j >= 0; i--, j--, k++)
	{
		topla[k] = (sayi1[i] + sayi2[j] + tasi) % 10;
		tasi = (sayi1[1] + sayi2[j] + tasi) / 10;
	}
	if (l1 > l2)
	{
		while (i >= 0)
		{
			topla[k++] = (sayi1[i] + tasi) % 10;
			tasi = (sayi1[i--] + tasi) / 10;
		}
	}
	else if (l1 < l2)
	{
		while (j >= 0)
		{
			topla[k++] = (sayi2[j] + tasi) % 10;
			tasi = (sayi2[j--] + tasi) / 10;
		}
	}
	else
	{
		if (tasi > 0)
		{
			topla[k++] = tasi;
		}
	}
	while (true) // Burada hangi sayinşin buyuk olduguna karar vererek while içinde toplam sonucu yazdirir.
	{
		if (strlen(s2) > strlen(s1))
		{
			printf("%s\n", s2);
			for (i = 0; i < strlen(s2) - strlen(s1); i++)
			{
				printf(" ");
			}
			printf("%s\n+\n", s1);
			for(i=0;i<strlen(s2);i++)
				printf("_");
			printf("\n");
			for (k--; k >= 0; k--)
			{
				printf("%d ", topla[k]);
			}
			break;
		}
		else
		{
			printf(" %s\n", s1);
			for (i = 0; i < strlen(s1) - strlen(s2); i++)
			{
				printf(" ");
			}
			printf(" %s\n+\n", s2);
			for(i=0;i<strlen(s1);i++)
				printf("_");
			printf("\n");
			for (k--; k >= 0; k--)
			{
				printf("%d ", topla[k]);
			}
			break;
		}
	}
}
void sayiCikar(char number1[], char number2[], int num1[], int num2[])
{
	int n = strlen(number1), m = strlen(number2);
	int i;
	for (i = 0; i < n; i++) // Alinan sayiyi integere dönüstürme islemi yapilir.
	{
		num1[i] = number1[n - i - 1] - '0';
	}
	for (i = 0; i < m; i++)
	{
		num2[i] = number2[m - i - 1] - '0';
	}
	int k;
	if (n > m)
	{
		k = n;
	}
	else
	{
		k = m;
	}
	printf("\n");
	if (strlen(number1) > strlen(number2)) // Burada hangi sayinin basamak sayisi buyukse diye kontrol edilir.Büyük olandan küçük sayiyi çikarma islemi yapildiktan sonra yazdirma islemi yapilir.
	{									   // 1.Sayi daha büyükse Sayi 2 dekini azaltip sayi 1 e ekler.Ek durumda da 10 ekler(4-6 gibi islemde 4 e 10 ekler )
		printf("%s\n", number1);
		for (i = 0; i < strlen(number1) - strlen(number2); i++)
		{
			printf(" ");
		}
		printf("%s\n-\n", number2);
		for(i=0;i<strlen(number1);i++)
			printf("_");
		printf("\n");
		for (i = 0; i < k; i++)
		{						
			num1[i] -= num2[i]; 
			if (num1[i] < 0)
			{				   
				num1[i + 1]--; 
				num1[i] += 10; 
			}
		}
		i = k;
		while (num1[i] == 0)
			i--;
		if (i < 0)
			printf("0");
		for (; i >= 0; i--)
		{
			printf("%d ", num1[i]);
		}
	}
	else if (strlen(number1) < strlen(number2)) // Burada ise sayi2 nin sayi1 den basamak sayisi olarak büyük oldugu durumu kontrol eder.Ve ayni iþlemi burada da yapar
	{
		printf("%s\n", number2);
		for (i = 0; i < strlen(number2) - strlen(number1); i++)
		{
			printf(" ");
		}
		printf("%s\n-\n", number1);
		for(i=0;i<strlen(number2);i++)
			printf("_");
		printf("\n");
		for (i = 0; i < k; i++)
		{
			num2[i] -= num1[i];
			if (num2[i] < 0)
			{
				num2[i + 1]--;
				num2[i] += 10;
			}
		}
		i = k;
		while (num2[i] == 0)
			i--;
		if (i < 0)
			printf("0");
		for (; i >= 0; i--)
		{
			printf("%d ", num2[i]);
		}
	}
	else if (strlen(number1) == strlen(number2)) // Geriye tek durum kaliyor: iki sayinin basamak sayisinin esit olmasi durumu.
	{
		i = 1;
		int j;
		while (i <= k) // Buradan sonraki islemlerde sayinin teker teker basamak degerlerini kontrol eder.Ve büyük olani küçük olandan çikardiktan sonra
		{			   // Return ile sonlandirir ki asagida while den sonra tekrar bi islem yapmasin diye.
			if (num1[k - i] > num2[k - i])
			{
				printf("%s\n", number1);
				printf("%s\n-\n", number2);
				for(i=0;i<strlen(number1);i++)
					printf("_");
				printf("\n");
				for (j = 0; j < k; j++)
				{
					num1[j] -= num2[j];
					if (num1[j] < 0)
					{
						num1[j + 1]--;
						num1[j] += 10;
					}
				}
				j = k;
				while (num1[j] == 0)
					j--;
				if (j < 0)
					printf("0");
				for (; j >= 0; j--)
				{
					printf("%d", num1[j]);
				}
				return 0;
			}
			else if (num2[k - i] > num1[k - i])
			{
				printf("%s\n", number2);
				printf("%s\n-\n", number1);
				for(i=0;i<strlen(number2);i++)
					printf("_");
				printf("\n");
				for (j = 0; j < k; j++)
				{
					num2[j] -= num1[j];
					if (num2[j] < 0)
					{
						num2[j + 1]--;
						num2[j] += 10;
					}
				}
				j = k;
				while (num2[j] == 0)
					j--;
				if (j < 0)
					printf("0");
				for (; j >= 0; j--)
				{
					printf("%d", num2[j]);
				}
				return 0;
			}
			i++;
		}
		printf("%s\n", number2);
		printf("%s\n-\n", number1);
		for(i=0;i<strlen(number2);i++)
			printf("_");
		printf("\n");
		for (j = 0; j < k; j++)
		{
			num2[j] -= num1[j];
			if (num2[j] < 0)
			{
				num2[j + 1]--;
				num2[j] += 10;
			}
		}
		j = k;
		while (num2[j] == 0)
			j--;
		if (j < 0)
			printf("0");
		for (; j >= 0; j--)
		{
			printf("%d", num2[j]);
		}
	}
}
void sayiCarp(char number1[], char number2[], int num1[], int num2[]) // Burada çarpma islemi kontrol edilir.
{	// Sonuç [i+j] = num1[i] * num2[j]; bu, esasen sýrasiyla num1[i] 10^i ve num2[j] 10^j'nin çarpimidir.
	// Sonuç num1[i]*num2[j]*10^(i+j) olur. O zaman sonuç tam olarak i+j konumunda, yani sözde yasa ortaya çikiyor.
	//  Özü hesaplama yöntemi ile sinirlidir
	int result[1000] = {0};
	int n = strlen(number1), m = strlen(number2);
	int i, j;
	for (i = 0; i < n; i++)
	{
		num1[i] = number1[n - i - 1] - '0';
	}
	for (i = 0; i < m; i++)
	{
		num2[i] = number2[m - i - 1] - '0';
	}
	int k = n + m; //Çarpma kuralina göre çarpma sonucunun basamak sayisi m+n i gecmeyecektir.
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			result[i + j] += num1[i] * num2[j]; // result[i+j]=num1[i]*num2[j] islemi yapilir.
		}					// num1[i] 10^i, num2[j] 10^j ile çarpilir ve sonuç num1[i]*num2[j]*10^(i+j) olur
	}						// Sonuç i+j konumunda olur.Böylece sözde kural ortaya çikar ve özü hesaplama yoluyla sinirlandirilir.
	for (i = 0; i < k; i++)
	{
		if (result[i] >= 10)
		{
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	if (strlen(number1) > strlen(number2)) // Burada da sayilarýn basamak sayilarini karsilastirip ekrana yazdirilir.
	{
		printf("%s\n", number1);
		for (i = 0; i < strlen(number1) - strlen(number2); i++)
		{
			printf(" ");
		}
		printf("%s\n*\n", number2);
		for(i=0;i<strlen(number1);i++)
			printf("_");
	}
	else
	{
		printf("%s\n", number2);
		for (i = 0; i < strlen(number2) - strlen(number1); i++)
		{
			printf(" ");
		}
		printf("%s\n*\n", number1);
		for(i=0;i<strlen(number2);i++)
			printf("_");
	}
	printf("\n");
	i = k;
	while (result[i] == 0)
		i--;
	if (i < 0)
		printf("0");
	else
		for (; i >= 0; i--)
		{
			printf("%d ", result[i]);
		}
}
int main()
{
	printf("Kac basamakli ? (En fazla %d): \n", MAX); // Burada basamak sayisi alinir. Yukaridaki MAX degerini yonetici istedigi sekilde degistirebilir.
	int max, secim;									  // Ve kullaniciyi biraz da olsa sinirlar.
	char *c;
	scanf("%d", &max);
	if (max > MAX) // Burada siniri gecmemesi için kontrol edilir.
	{
		printf("Siniri gectiniz. ");
		return;
	}
	printf("1.TOPLA\n");
	printf("2.CIKAR\n");
	printf("3.CARP \n");
	scanf("%d", &secim); // Kullanicinin yapacagi islem secilir.
	int i;
	switch (secim)
	{
		case 1:
			printf("1.Sayi: ");
			scanf("%s", &s1);
			for (i = 0; i < strlen(s1); i++) // Sayiyi string olarak aldigimiz icin gercek bir string deðeri girerse diye ASCII kodlari ile kontrol edilir.
			{								 // Kullanicinin sayi disinda baska karakter girilmesine izin verilmez.
				if (47 < s1[i] && s1[i] > 58)
				{
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			printf("2.Sayi: ");
			scanf("%s", &s2);
			for (i = 0; i < strlen(s2); i++) // Sayiyi string olarak aldigimiz icin gercek bir string deðeri girerse diye ASCII kodlari ile kontrol edilir.
			{								 // Kullanicinin sayi disinda baska karakter girilmesine izin verilmez.
				if (47 < s2[i] && s2[i] > 58)
				{
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			sayiTopla(sayi1, sayi2, s1, s2, l1, l2);
			break;
		case 2:
			printf("1.Sayi: ");
			scanf("%s", &s1);
			for (i = 0; i < strlen(s1); i++) // Sayiyi string olarak aldigimiz icin gercek bir string deðeri girerse diye ASCII kodlari ile kontrol edilir.
			{								 // Kullanicinin sayi disinda baska karakter girilmesine izin verilmez.
				if (47 < s1[i] && s1[i] > 58)
				{
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			printf("2.Sayi: ");
			scanf("%s", &s2);
			for (i = 0; i < strlen(s2); i++)
			{
				if (47 < s2[i] && s2[i] > 58) // Sayiyi string olarak aldigimiz icin gercek bir string deðeri girerse diye ASCII kodlari ile kontrol edilir.
				{							  // Kullanýcýnýn sayý dýþýnda baþka karakter girilmesine izin verilmez.
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			sayiCikar(s1, s2, sayi1, sayi2);
			break;
		case 3:
			printf("1.Sayi: ");
			scanf("%s", &s1);
			for (i = 0; i < strlen(s1); i++) // Sayiyi string olarak aldigimiz icin gercek bir string deðeri girerse diye ASCII kodlari ile kontrol edilir.
			{								 // Kullanicinin sayi disinda baska karakter girilmesine izin verilmez.
				if (47 < s1[i] && s1[i] > 58)
				{
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			printf("2.Sayi: ");
			scanf("%s", &s2);
			for (i = 0; i < strlen(s2); i++) // Sayiyi string olarak aldigimiz icin gercek bir string deðeri girerse diye ASCII kodlari ile kontrol edilir.
			{								 // Kullanicinin sayi disinda baska karakter girilmesine izin verilmez.
				if (47 < s2[i] && s2[i] > 58)
				{
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			sayiCarp(s1, s2, sayi1, sayi2);
			break;
		default: // Burada ise uc islem disinda baska secim yapilmamasi icin kontrol edilir.
			printf("Hatali secim yaptiniz.");
			break;
	}
	return 0;
}