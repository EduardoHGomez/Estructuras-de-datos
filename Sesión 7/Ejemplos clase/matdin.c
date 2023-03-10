/*
 * matdin.c
 *
 *  Created on: 15 feb 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4

void printmat(int **m,int rows,int cols);

int main()
{
	srand(time(NULL));
	int **mat;
	int ren,col;

	mat = malloc(ROWS * sizeof(int *));

	// Pedir memoria para cada renglón
	for(ren=0;ren<ROWS;ren++)
		mat[ren] = malloc(COLS * sizeof(int));

	// Inicializar los valores de la matriz
	for(ren=0;ren<ROWS;ren++)
		for(col=0;col<COLS;col++)
			mat[ren][col] = (rand() % 10); // 10*(ren+1)+col+1

	//LIBERAR LA MEMORIA UTIILIZADA POR MAT
	for (int i = 0; i < ROWS; i++)
		free(mat[i]);
	free(mat);

	printmat(mat,ROWS,COLS);
}

void printmat(int **m,int rows,int cols)
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		printf("\n");
		for(j=0;j<cols;j++)
			printf("\t%d",m[i][j]);
	}
	printf("\n");
}