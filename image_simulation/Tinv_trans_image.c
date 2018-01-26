#include<stdio.h>
#include "global_var.h"
#include<math.h>
#include "Tinv_trans_image.h"

int Tinv_trans_img[height][weight];

void Tinv_trans_out(int order)
{
	int i, j;
	FILE *f_write;
	char out_name[30];
	sprintf(out_name, "../../data/trans_txt/%d.txt", order);
	f_write = fopen(out_name, "w");

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < weight; j++)
		{
			if (j == weight-1) fprintf(f_write, "%d\n", Tinv_trans_img[i][j]);
			else
				fprintf(f_write, "%d ", Tinv_trans_img[i][j]);
		}
		//printf("%d \n", i);
	}
	fclose(f_write);
}

void Tinv_trans(int order)
{
	int i, j;
	int x, y;

	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < weight; j++)
		{
			x =1 ;//怎么把对应的 原来的x，y求出来；
			y = 1;
			if ((x>=0)&&(x<= height)&&(y>=0)&&(y<=weight))
			{
				Tinv_trans_img[i][j] = img_origin[x][y];
			}
			else
			{
				Tinv_trans_img[i][j] = 127;//无数据的地方
			}
		}
		Tinv_trans_out(order);
	}
}