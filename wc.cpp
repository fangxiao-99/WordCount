#include <stdio.h>
#include <stdlib.h>

int flag;  //�ж��ļ��Ƿ�Ϊ�� 
void x1(char address[]);
void x2(char address[]);
void x3(char address[]);

int main()
{
	char address[100];  //�ļ���ַ
	while(1)
      {
	  	    printf("��������Ҫ���ҵ��ļ��ĵ�ַ��\n");
	  		scanf("%s",address);
		    x1(address);  //ͳ���ַ��� 
			x2(address);  //ͳ�Ƶ����� 
			x3(address);  //ͳ������ 
	  }   
}

 void x1(char address[])  //�����ַ�������
 {
 	int Charnum = 0;
    FILE *fp = NULL;
    if((fp = fopen(address,"r")) == NULL)  //�п� 
    {
        printf("���ļ�ʧ��\n");
		exit(-1);
    }
    char x = NULL;
    x = fgetc(fp);
    while(x != EOF)
    {
    	x = fgetc(fp);
    	Charnum++;
	}
	
	if(Charnum == 0)  //������ļ��ַ���Ϊ0������flagΪ0����ʾ���ļ�Ϊ���ļ�
	  {
		flag = 0;
	  } 
    else 
	  {
		flag = 1;
	  }
	printf("���ļ����ַ���Ϊ%d\n", Charnum);
 }
 
 
 
 void x2(char address[])  //���㵥�������� 
 {
 	int Wordnum = 0;
    FILE *fp = NULL;
    if((fp = fopen(address,"r")) == NULL)  //�п� 
    {
    	printf("���ļ�ʧ��\n");
        exit(-1);
    }
    char x = NULL;
    x = fgetc(fp);
    int word = 0;  //ͳ�Ƶ������ı�־ 
        while(x != EOF)
        {
    	    if(!(x >= 'A' && x <= 'Z'|| x >= 'a' && x <= 'z'))  //���ַ�Ϊ����ĸʱ 
                {
                     word = 0;  //�õ��ʱ�־Ϊ0 
                }
            else if((word == 0) && (x >= 'A' && x <= 'Z'|| x >= 'a' && x <= 'z'))  //���ַ�Ϊ��ĸʱ 
                {
                     word = 1;  //�õ��ʱ�־Ϊ1����ʾ�ַ���Ϊһ������ 
                     Wordnum++;
                }
        x = fgetc(fp);    
	    } 
	printf("���ļ��ĵ�����Ϊ%d\n", Wordnum);
 }
 
 
 
 void x3(char address[])  //������������ 
 {
 	int Linenum = 0;
 	FILE *fp = NULL;
    if((fp = fopen(address,"r")) == NULL)
    {
    	printf("���ļ�ʧ��\n");
        exit(-1);
    }
    char x = NULL;
    x = fgetc(fp);
    while(x != EOF)
 	{
        if(x == '\n')  //xΪת�з���ʱ 
        {
            Linenum++;
        }
        x = fgetc(fp);    
    }
    Linenum++;  //����+1 
	if(flag == 0)  //���ļ�Ϊ�գ�����Ϊ0
	 {
		Linenum = 0;
	 } 
    printf("���ļ�������Ϊ%d\n", Linenum);
 }
 
 
 
 
 
 
 
