#pragma warning( disable : 6031 )
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;


int e, z;
int n;
int licznik=0;
float *x;
float *fx;
float* xfx;
float A, B;
float wynik;

void tablicowanie(int A, int B, int e, int n, float tablicax[], float tablicafx[])
{
	for (int i = 0; i <= e; i++)
	{	
		tablicafx[i] = 0;
		for (int j = 1; j <= n; j++)
		{
			tablicafx[i] = tablicafx[i] + pow((-1), j - 1) * pow(tablicax[i], 2 * j);
		}
		tablicafx[i] = pow(B, A) * tablicafx[i];
	}
}

int main()
{
	FILE* dane1 = fopen("dane.txt", "r");
	fscanf(dane1, "%d", &e);
	x = (float*)malloc(e * sizeof(float));
	fx = (float*)malloc(e * sizeof(float));
	for (int i = 0; i < e; i++)
	{
		fscanf(dane1, "%f\n", &x[i]);
	}
	fclose(dane1);

	printf("Program liczacy sume ciagu\n");
	printf("Podaj liczbe elementow sumy\n");
	scanf("%d", &n);
	printf("Podaj A i B\n");
	scanf("%f,%f", &A,&B);
	printf("%d\n", n);
	printf("%f\n", A);
	printf("%f\n", B);

	tablicowanie(A,B,e,n,x,fx);
	for (int i = 0; i < e; i++)
	{
	printf("Nr %d\t", i+1);
	printf("%f\t", x[i]);
	printf("%f\n", fx[i]);
	}

	FILE* wynik1 = fopen("wynik1.txt", "w");
	for (int i = 0; i < e; i++)
	{
		fprintf(wynik1, "Nr %d\t", i + 1);
		fprintf(wynik1, "%f\t", x[i]);
		fprintf(wynik1, "%f", fx[i]);
		fprintf(wynik1, "\n");
	}
	fclose(wynik1);

	for (int i = 0; i < e; i++)
	{
		if (x[i] * fx[i] > 0)
		{
			licznik++;
		}
	}
	xfx = (float*)malloc(licznik * sizeof(float));

	FILE* wynik2 = fopen("wynik2.txt", "w");	//zapis do pliku na podstawie warunku a nie tablicy
	for (int i = 0; i < e; i++)
	{
		if (x[i] * fx[i] > 0)
		{
			fprintf(wynik2, "Nr %d\t", i + 1);
			fprintf(wynik2, "%f\t", x[i]);
			fprintf(wynik2, "%f\n", fx[i]);
		}
	}
	fclose(wynik2);
	//free(x);
	//free(fx);
	//free(xfx);
	return 0;
}

