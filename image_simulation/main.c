#define num 15

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include<stdio.h>
#include<string.h>
#include "image_processing.h"
#include "global_var.h"

char iname[20];
char oname[20];


void input(void)
{
	int i, j;
	FILE *fpread;
	FILE *fwrite;
	int x;

	fpread = fopen(iname, "r");//matlabœ‘
	for (i = 0; i<320; i++)
	{
		for (j = 0; j<240; j++)
		{
			fscanf(fpread, "%d", &x);
			if (x == 1)
			{
				img_origin[j][i] = 255;
				img_changed[j][i] = 255;
			}

			else
			{
				img_origin[j][i] = 0;
				img_changed[j][i] = 0;
			}

		}
	}
	fclose(fpread);
}

void output(void)
{
	int i, j;
	FILE *fwrite;
	fwrite = fopen(oname, "w");
	for (i = 0; i<240; i++)
	{
		for (j = 0; j<320; j++)
		{
			if (j == 319) fprintf(fwrite, "%d\n", img_origin[i][j]);
			else
				fprintf(fwrite, "%d ", img_origin[i][j]);
		}
	}

	for (i = 0; i<10; i++)
	{
		for (j = 0; j<320; j++)
		{
			if (j == 319) fprintf(fwrite, "%d\n", 127);
			else
				fprintf(fwrite, "%d ", 127);
		}
	}


	for (i = 0; i<240; i++)
	{
		for (j = 0; j<320; j++)
		{
			if (j == 319) fprintf(fwrite, "%d\n", img_changed[i][j]);
			else
				fprintf(fwrite, "%d ", img_changed[i][j]);
		}
	}

	fclose(fwrite);
}
void creat_name(int i)
{
	sprintf(iname, "../../data/m2c/m2c%d.txt", i);
	sprintf(oname, "../../data/c2m/c2m%d.txt", i);
}

int main(int argc, char *argv[]) {

	int i;
	trans();
	for (i = 1; i <= num; i++)
	{
		creat_name(i);
		input();
		image_processing(i);
		output();
		printf("µ⁄%d∏ˆ\n", i);
	}
}