#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"

void generate_array(int **, int, int, int);


int main(){
	
	//Check NSnipers

	//Check CountPairs Sample Code 

	//Check Steps Sample Code
	printf("steps:  %d\t ", get_steps(12));

	//Check Spiral Sample Code

	int rows = 10, columns = 1;
	int **input_array = (int **)malloc(rows * sizeof(int *));
	for (int i = 0; i < rows; i++)
		input_array[i] = (int *)malloc(columns * sizeof(int));

	generate_array((int**)input_array, rows, columns, 2);

	int *output_array = spiral(rows, columns, (int**)input_array);

	printf("\n output is : \n");
	for (int i = 0; i < 10; i++)
		printf("\t %d is %d \t \n",i, output_array[i]);


	//Check Maze Sample Code

	int maze[3][5] = {
		{ 1, 0, 0, 0, 1 },
		{ 1, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0 }
	};

	int m = 3, n = 5;
	int x1 = 0, y1 = 0, x2 = 2, y2 = 2, res;
	res = path_exists((int*)maze, m, n, x1, y1, x2, y2);


	//int pairs = count_pairs_wrapper("abababababxxxyyy", 16);
	printf("no of pairs : %d", res);

	
	

	
	return 0;
}



void generate_array(int **input_array, int rows, int columns, int seq)
{
	int k = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			input_array[i][j] = (k++)*seq;
}
