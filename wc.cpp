#include <stdio.h>
#include <stdlib.h>

int flag;  //判断文件是否为空 
void x1(char address[]);
void x2(char address[]);
void x3(char address[]);

int main()
{
	char address[100];  //文件地址
	while(1)
      {
	  	    printf("请输入你要查找的文件的地址：\n");
	  		scanf("%s",address);
		    x1(address);  //统计字符数 
			x2(address);  //统计单词数 
			x3(address);  //统计行数 
	  }   
}

 void x1(char address[])  //计算字符数函数
 {
 	int Charnum = 0;
    FILE *fp = NULL;
    if((fp = fopen(address,"r")) == NULL)  //判空 
    {
        printf("打开文件失败\n");
		exit(-1);
    }
    char x = NULL;
    x = fgetc(fp);
    while(x != EOF)
    {
    	x = fgetc(fp);
    	Charnum++;
	}
	
	if(Charnum == 0)  //如果该文件字符数为0，则置flag为0，表示该文件为空文件
	  {
		flag = 0;
	  } 
    else 
	  {
		flag = 1;
	  }
	printf("该文件的字符数为%d\n", Charnum);
 }
 
 
 
 void x2(char address[])  //计算单词数函数 
 {
 	int Wordnum = 0;
    FILE *fp = NULL;
    if((fp = fopen(address,"r")) == NULL)  //判空 
    {
    	printf("打开文件失败\n");
        exit(-1);
    }
    char x = NULL;
    x = fgetc(fp);
    int word = 0;  //统计单词数的标志 
        while(x != EOF)
        {
    	    if(!(x >= 'A' && x <= 'Z'|| x >= 'a' && x <= 'z'))  //当字符为非字母时 
                {
                     word = 0;  //置单词标志为0 
                }
            else if((word == 0) && (x >= 'A' && x <= 'Z'|| x >= 'a' && x <= 'z'))  //当字符为字母时 
                {
                     word = 1;  //置单词标志为1，表示字符串为一个单词 
                     Wordnum++;
                }
        x = fgetc(fp);    
	    } 
	printf("该文件的单词数为%d\n", Wordnum);
 }
 
 
 
 void x3(char address[])  //计算行数函数 
 {
 	int Linenum = 0;
 	FILE *fp = NULL;
    if((fp = fopen(address,"r")) == NULL)
    {
    	printf("打开文件失败\n");
        exit(-1);
    }
    char x = NULL;
    x = fgetc(fp);
    while(x != EOF)
 	{
        if(x == '\n')  //x为转行符号时 
        {
            Linenum++;
        }
        x = fgetc(fp);    
    }
    Linenum++;  //行数+1 
	if(flag == 0)  //当文件为空，行数为0
	 {
		Linenum = 0;
	 } 
    printf("该文件的行数为%d\n", Linenum);
 }
 
 
 
 
 
 
 
