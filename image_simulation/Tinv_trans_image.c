#include<stdio.h>
#include "global_var.h"
#include<math.h>
#include "Tinv_trans_image.h"

int Tinv_trans_img[height][weight];

void Tinv_trans_out(int order)
{
	int i, j;
	FILE *f_write;
	char out_name[50];
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


#if 0
long double T_mat[3][3] =
{
	{ 0.220209916226684,1.40635042240322,0.00869558900788382 },
	{ 0.0264620343783975,-2.13108644889550,0.000140251435611051 },
	{ -111.811249497827,184.542838976986,-3.06172674518219 }
};//变

#endif // 0

#if 1
long double T_mat[3][3] =
{ { 4.404198e-01,2.812701e+00,1.739118e-02 },{ 5.292407e-02,-4.262173e+00,2.805029e-04 },{ -3.179388e+02,-4.418466e+02,-1.092983e+01 } };


#endif // 0




long double t_ori[3];




void Tinv_trans(int order)
{
	int i, j;
	int x, y;
	static long double point[3];
#if 1 //有问题的代码，之后可能尝试修复



	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < weight; j++)
		{
			t_ori[0] = i;
			t_ori[1] = j;
			t_ori[2] = 1;


			for (size_t k = 0; k < 3; k++)
			{
				for (size_t l = 0; l < 3; l++)
				{
					point[k] = point[k] + t_ori[l] * T_mat[l][k];
				}
			}//矩阵运算

			for (size_t k = 0; k < 3; k++)
			{
				point[k] = point[k] / point[2];
			}//归一化

			x = (int)(point[0]);
			y = (int)(point[1]);

			if ((x >= 0) && (x <240) && (y >= 0) && (y <320))
			{
				//printf("%d %d %d %d\n", x, y,i,j);
				Tinv_trans_img[i][j] = img_origin[x][y];

			}
			else
			{
				Tinv_trans_img[i][j] = 127;
			}
			//printf("%d %d %d %d %d\n", x, y,i,j,Tinv_trans_img[i][j]);

		}
	}
	Tinv_trans_out(order);//输出矫正图片
#endif


}