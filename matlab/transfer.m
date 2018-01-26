clc;
clear all;

im=imread('fire1.bmp');
imshow(im);

if 1
    
source=[92,80;
    123,42;
    122,274;
    91,238];%原始图像上的坐标

times=0.5;
x=400;y=300;
%点 （） 在新的图像中的坐标为(300,800)

object=[0*times+x,0*times+y;
       15*times+x,0*times+y;
       15*times+x,30*times+y;
       0*times+x,30*times+y];%真实场景下的坐标 或者 其他作者想转换到的坐标系的坐标
%object=[0,0;15,0;15,30;0,30];




TForm=cp2tform(source,object,'projective');%cp2tform创建一个TForm结构体
                                           %'projective' is a type of
                                           %perspective transform:parallers
                                           %is converge in a point
round(tformfwd(TForm,[51,165]))%将像素点带进去进行验真 round取整 tformfwd仿射变换
%数据在tdata中

T=TForm.tdata.T;
x0=[89,159,1];
out=x0*T;
%out=out/out[1][3]




end