
clc;
clear all;
im=imread('fire95.bmp');
imshow(im);

if 1


object=[92,80;
    123,42;
    122,274;
    91,238];%ԭʼͼ���ϵ�����

times=0.5;
x=400;y=300;
%�� ���� ���µ�ͼ���е�����Ϊ(300,800)

source=[0*times+x,0*times+y;
       15*times+x,0*times+y;
       15*times+x,30*times+y;
       0*times+x,30*times+y];%��ʵ�����µ����� ���� ����������ת����������ϵ������
%object=[0,0;15,0;15,30;0,30];



TForm=cp2tform(source,object,'projective');%cp2tform����һ��TForm�ṹ��
                                           %'projective' is a type of
                                           %perspective transform:parallers
                                           %is converge in a point
round(tformfwd(TForm,[100,800]))%�����ص����ȥ�������� roundȡ�� tformfwd����任
%������tdata��

T=TForm.tdata.T;
x0=[298,315,1];
out=x0*T;



T_mat=strcat('../../data/T_mat/1','.txt');
fid=fopen(T_mat,'w');

fprintf(fid,'{');
for i=1:3
    
    fprintf(fid,'{');
    for j=1:3
    if j==3
    fprintf(fid,'%d',T(i,j));
    else
   
    fprintf(fid,'%d,',T(i,j));
    end
    
    end
    
    if i==3
    fprintf(fid,'}');    
    else
    fprintf(fid,'},');      
    end
    
    
end
fprintf(fid,'};');

fclose(fid);

end