// txt_to_obj.c - reads heightgrid from keyboard input and converts it to an .obj file (3D model file)
// max size of terrain is now 64x64, you can change that in the variables "vertexno" and "rowstart" below
// you must end every row with "666"
// and end the whole input with anything higher than or equal to "999"

// kbrecordzz 2022
// license: CC0

#include <stdio.h>

int main()
{
	float c;
	int i = 0;
	int j = 0;
	int vertexno[64][64];	// max size of terrain
	int total = 0;
	int last_total = 0;
	int tmpsecond = 0;
	int rowstart[500];	// this must be same as max size of terrain

	rowstart[0] = 0;

	scanf("%f", &c);
	while (c < 999)
	{
		if (c != 666)
		{
			// v (VERTICES) - '/10' means heightvalues gets divided by 10 as they get into the .obj file. change this value to get a steeper or flatter model
			if (total == 0) printf("v %i %i %f\n", i, j, c);			// only on first face on first row
			if (i >= 1 && j == 0) printf("v %i %i %f\n", i+1, j, c);		// special case for first face on rest of the rows
			else if (i == 0) printf("v %i %i %f\n", i, j+1, c);			// only on rest of the faces on first row
			printf("v %i %i %f\n", i+1, j+1, c);

			// f (FACES)
			if (total == 0) printf("f %i %i %i %i\n", total+4, total+3, total+2, total+1);										// first face on first row
			else if (total == 4) printf("f %i %i %i %i\n", last_total+3, total+2, total+1, last_total+2);								// second face on first row
			else if (i == 1 && j == 0) printf("f 3 4 %i %i\n", last_total+3, last_total+4);										// first face on second row
			else if (i >= 2 && j == 0) printf("f %i %i %i %i\n", rowstart[i-1]+2, rowstart[i-1]+1, last_total+2, last_total+3);					// first face on rest of the rows
			else if (i == 1 && j == 1) { printf("f 3 %i %i 6\n", last_total+2, last_total+3); tmpsecond = 6; }							// second face on second row
			else if (i >= 2 && j == 1) { printf("f %i %i %i %i\n", rowstart[i-1]+2, last_total+2, last_total+3, rowstart[i-1]+3); tmpsecond = rowstart[i-1]+3; }	// second face on rest of the rows
			else if (i == 1 && j >= 2) { printf("f %i %i %i %i\n", tmpsecond, last_total+1, last_total+2, tmpsecond+2); tmpsecond += 2; }				// rest of the faces on second row
			else if (i >= 2 && j >= 2) { printf("f %i %i %i %i\n", tmpsecond, last_total+1, last_total+2, tmpsecond+1); tmpsecond++; }				// rest of the faces on rest of the rows
			else printf("f %i %i %i %i\n", last_total+2, total+2, total+1, last_total+1);										// rest of the faces on first row

			last_total = total;
			vertexno[i][j] = total;
			if (total == 0) total += 4;
			else if (i == 0 || (i >= 1 && j == 0)) total += 2;
			else total++;
			j++;
		}
		if (c == 666)
		{
			printf("\n\n");
			i++;
			j = 0;
			rowstart[i] = total;
		}
		scanf("%f", &c);
	}

	return 0;
}
