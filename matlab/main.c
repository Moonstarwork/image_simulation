#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



#include<stdio.h>
#include<string.h>
#include "image.h" 
int img_origin[240][320],img_changed[240][320];
char iname[20];
char oname[20]; 

void input(void)
{
	int i,j;
	FILE *fpread;
	FILE *fwrite;
	int x;
	
	fpread=fopen(iname,"r");//matlabœ‘
	for(i=0;i<320;i++)
	{
		for(j=0;j<240;j++)
		{
		   fscanf(fpread,"%d",&x);
		   if(x==1) 
		   { 
		   	  img_origin[j][i]=255;
		      img_changed[j][i]=255;
	       }    

		   else
		   {
		   	  img_origin[j][i]=0;
		      img_changed[j][i]=0;
		   }
		   	
		}
	}
	fclose(fpread);
}

void output(void)
{
	int i,j;
	FILE *fwrite;
	fwrite=fopen(oname,"w"); 	
	for(i=0;i<240;i++)
	{
		for(j=0;j<320;j++)
		{
		   if(j==319) fprintf(fwrite,"%d\n",img_origin[i][j]);
		   else 
		   fprintf(fwrite,"%d ",img_origin[i][j]);
		}
	}
	
    for(i=0;i<10;i++)
	{
		for(j=0;j<320;j++)
		{
		   if(j==319) fprintf(fwrite,"%d\n",127);
		   else 
		   fprintf(fwrite,"%d ",127);
		}
	}
	
	
	for(i=0;i<240;i++)
	{
		for(j=0;j<320;j++)
		{
		   if(j==319) fprintf(fwrite,"%d\n",img_changed[i][j]);
		   else 
		   fprintf(fwrite,"%d ",img_changed[i][j]);
		}
	}
	
	
	
	
	
	fclose(fwrite);
}
void creat_name(int i)
{
	sprintf(iname,"../data/m2c/m2c%d.txt",i);
	sprintf(oname,"../data/c2m/c2m%d.txt",i);
}


int point[30][2];
void init(void)
{

/*	
	point[0][0]=39 ; point[0][1]=40;	
	point[1][0]=27; point[1][1]=40;	
	point[2][0]=22; point[2][1]=40;	
	point[3][0]=19; point[3][1]=40;	
	point[4][0]=17; point[4][1]=40;
	
	point[5][0]=38; point[5][1]=13;		
	point[6][0]=28; point[6][1]=21;	
	
*/	
	
	
} 

void image_processing(void)
{
	int i,j;
	for(i=0;i<=6;i++)
	{
		img_changed[point[i][0]][point[i][1]]=0;
	}
}
 
int main(int argc, char *argv[]) {
    
	int i;
	init();
	for(i=1;i<=30;i++)
	{
		creat_name(i);
		input();
		
        image_processing();	
		
	    output();
	    printf("µ⁄%d∏ˆ\n",i); 
	    print_test();
	}

} 
