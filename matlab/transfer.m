clc;
clear all;

im=imread('fire1.bmp');
imshow(im);

if 1
    
source=[92,80;
    123,42;
    122,274;
    91,238];%ԭʼͼ���ϵ�����

times=0.5;
x=400;y=300;
%�� ���� ���µ�ͼ���е�����Ϊ(300,800)

object=[0*times+x,0*times+y;
       15*times+x,0*times+y;
       15*times+x,30*times+y;
       0*times+x,30*times+y];%��ʵ�����µ����� ���� ����������ת����������ϵ������
%object=[0,0;15,0;15,30;0,30];




TForm=cp2tform(source,object,'projective');%cp2tform����һ��TForm�ṹ��
                                           %'projective' is a type of
                                           %perspective transform:parallers
                                           %is converge in a point
round(tformfwd(TForm,[51,165]))%�����ص����ȥ�������� roundȡ�� tformfwd����任
%������tdata��

T=TForm.tdata.T;
x0=[89,159,1];
out=x0*T;
%out=out/out[1][3]




end