
clc;
clear all;
num=1;

%����Ϊͼ������任��ĳ���
if 1
    
    vedio = VideoWriter('../../data/videos/demo.avi'); %��ʼ��һ��avi�ļ�
    vedio.FrameRate = 50;
    open(vedio);
    
    
    for i=1:num
        image=load(strcat('../../data/trans_txt/',int2str(i),'.txt'));
        
        image=uint8(image);
        imshow(image);
        imwrite(image,strcat('../../data/trans_png/',int2str(i),'.png'));
        writeVideo(vedio,image);
        disp(strcat('fire',int2str(i),'д����Ƶ.'));
    end
    close(vedio);
    
end




if 0
    for i=1:num
        
        image=imread(strcat('../../data/fire6/fire',int2str(i),'.bmp'));
        image=~image;
        
        image_txt=strcat('../../data/m2c/m2c',int2str(i),'.txt');%Ϊ txt �ļ�ȥ����
        fid=fopen(image_txt,'w');
        fprintf(fid,'%d ',image);
        fclose(fid);
        
        %imwrite(image,strcat('fire',int2str(i),'.jpg'));
        disp(strcat('fire',int2str(i),'ת������.'));
        
        
    end
    disp('����ת������.');
    
    
    
    
    
    
    %����Ϊת������Ƶ�Ĵ���
    
    
    if 0
        vedio = VideoWriter('demo3.avi'); %��ʼ��һ��avi�ļ�
        vedio.FrameRate = 50;
        open(vedio);
        for i=1:num %ͼ�����и���
            fname=strcat('fire',num2str(i,'%d'),'.jpg');
            frame = imread(fname);
            
            writeVideo(vedio,frame);
            disp(strcat('fire',int2str(i),'д����Ƶ.'));
            
        end
        close(vedio);
    end
end



%һ��Ϊͼ��������Ƶ�ϳ�
if 0
    vedio = VideoWriter('../../data/videos/demo.avi'); %��ʼ��һ��avi�ļ�
    vedio.FrameRate = 50;
    open(vedio);
    
    for i=1:num
        image=load(strcat('../../data/c2m/c2m',int2str(i),'.txt'));
        image=uint8(image);
        imshow(image);
        imwrite(image,strcat('../../data/jpg/',int2str(i),'.png'));
        %     fname=strcat('../../data/jpg/',num2str(i,'%d'),'.png');
        %     frame = imread(fname);
        writeVideo(vedio,image);
        disp(strcat('fire',int2str(i),'д����Ƶ.'));
    end
    close(vedio);
end

