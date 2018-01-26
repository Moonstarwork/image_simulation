#include<stdio.h>
#include "global_var.h"
#include<math.h>
#include "Tinv_trans_image.h"
//int x0 = 90, y0 = 160;

int times = 1;//放大的倍数
int img_t[10000][10000];
int distance_x = 200, distance_y = 200;//单位厘米


int right_line(int x0,int y0)
{
	int i,j;

	for (i = y0; i < 320; i++)
	{
	if (img_origin[x0][i] == 0)
		{

		    img_changed[x0][i] = 127;
			return(i);
			//printf("行=%d 列=%d\n", x0, i);
			break;
		}
	}
}

int left_line(int x0, int y0)
{
	int i, j;
	for (i = y0; i >0; i--)
	{


		if (img_origin[x0][i] == 0)
		{
			

			img_changed[x0][i] = 127;
			return(i);
			break;

		}
	}
}





struct point
{
	int x;
	int y;
};

struct point t_point[100000];

long double transfer[3][3]={
	{0.476255294162784	,0.157996159735668	,0.0151961192960659},
{0.00301427401368851	,0.128891603994887,0.000161645461195521},
{-44.0566289840712, - 24.8469750152725 ,- 0.410974612133709}
};

long double Tinv[3][3] = {
	{-0.803735473159934, -5.13298284449364, -0.0317376867736580},
{-0.0965827338129496,	7.77816823464305, -0.000511898173768677},
{	92,	80,	1}
};//matlab 导来的数据

long double t[1000000][4];//0 x 1 y 2 w 3值
long double t_origin[1000000][4];
int img_transfor[1000000][4];

int num = 0;
int point_num = 0;
void trans(void)
{
	int i, j,k,l;


	FILE *poin;
	char poin_name[20];
	
	sprintf(poin_name, "1.txt");
	poin = fopen(poin_name, "w");//matlab显


	for (size_t i = 0; i < 240; i++)
	{
		for (size_t j = 0; j < 320; j++)
		{
			num = i * 320 + j;

			t_origin[num][0] = i;
			t_origin[num][1] = j;
			t_origin[num][2] = 1;


			for (size_t k = 0; k < 3; k++)
			{
				
				for (size_t l = 0; l < 3; l++)
				{
					t[num][k] = t[num][k] + t_origin[num][l] * transfer[l][k];
				}
				
			}//矩阵运算



			for (size_t k = 0; k < 3; k++)
			{
				t[num][k] = t[num][k] / t[num][2];
				t[num][k] *= times;
			}//归一化



			if ((abs(t[num][0]) < distance_x*times) && (abs(t[num][1]) < distance_y*times)&&(t[num][0]<20*times))
			{
				fprintf(poin, "%d,%d,%d,%d\n", (int)(t[num][0]), (int)(t[num][1]), i, j);
				img_transfor[point_num][0] = (int)(t[num][0]);
				img_transfor[point_num][1] = (int)(t[num][1]);
				img_transfor[point_num][2] = i;
				img_transfor[point_num][3] = j;
				point_num++;
			}
			
		}
	}
	fclose(poin);
}




void trans_output(int order)
{
	int i, j;
	FILE *f_write;
	char out_name[100];
	sprintf(out_name, "../../data/trans_txt/%d.txt", order);
	f_write = fopen(out_name, "w");

	for ( i = 0; i < 300*times; i++)
	{
		for (j = 0; j < 400*times; j++)
		{
			if (j == 400*times-1) fprintf(f_write, "%d\n", img_t[i][j]);
			else
				fprintf(f_write, "%d ", img_t[i][j]);
		}
		//printf("%d \n", i);
	}
	fclose(f_write);
}











void image_processing(int order)
{

	int i=0,j=0,k=0,l=0;
	int x, y;
	int x0, y0;
	long double xx, yy,xx0,yy0,ww;
	for (i = 0; i < 240; i++)
	{
		img_changed[i][(right_line(i, 160) + left_line(i, 160)) / 2] = 127;
	}

	printf("sdfaadsfs%d \n",point_num);

#if 0

	for (size_t i = 0; i <point_num ; i++)
	{
		x = img_transfor[i][0]+ distance_x*times;
		y = img_transfor[i][1]+ distance_y*times;
		x0 = img_transfor[i][2];//原来图像上的x0
		y0 = img_transfor[i][3];//原来图像上的y0
		img_t[x][y] = img_origin[x0][y0];
		
	}
	trans_output(order);
#endif

#if 0 //有问题的代码，之后可能尝试修复

	
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < weight; j++)
		{
			x = 0; y = 0;

			xx = i- distance_x*times;//怎么把对应的 原来的x，y求出来；
			yy = j- distance_y*times;
			
			xx = xx/(times*1.0);
			yy = yy/(times*1.0);


			xx0 = xx*Tinv[0][0] + yy*Tinv[1][0] + 1 * Tinv[2][0];
			yy0 = xx*Tinv[0][1] + yy*Tinv[1][1] + 1 * Tinv[2][1];
			ww = xx*Tinv[0][2] + yy*Tinv[1][2] + 1 * Tinv[2][2];

			//printf("%lf \n",ww);
			x =(int)( xx0*1.0 / ww);
			y =(int)(yy0*1.0 / ww);

			
			if ((x >= 0) && (x <240) && (y >= 0) && (y <320))
			{
				//printf("%d %d %d %d\n", x, y,i,j);
				img_t[i][j] = img_origin[x][y];
				Tinv_trans_img[i][j]= img_origin[x][y];

			}
			else
			{
				img_t[i][j] = 127;//无数据的地方
				Tinv_trans_img[i][j]=127;

			}
			//printf("%d %d %d %d %d\n", x, y,i,j,Tinv_trans_img[i][j]);
			
		}
	}
	Tinv_trans_out(order);//输出矫正图片
#endif

	Tinv_trans(order);//与之上的程序不可同时开否则txt文件出现冲突


}