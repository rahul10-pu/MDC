// this is decompression of 5 byte
#include"header.h"
#include"prototype.h"
int decompression7(char *open_encr,char *open_key,char *str)
{

//	printf("in function----->%s\n",__func__);
	
	unsigned char *buff=NULL,ch,d,c,e,f,m;
	unsigned int efd,efd2,fd2,fd3,i=0,count,count1,length,j,n,r;	
	
char decr1[]=".decompressed";
	
	char *decr;
	
	decr=malloc(strlen(str) + strlen(decr1) + 1);
	

    strcpy(decr, str);
    strcat(decr, decr1);
    printf("decompressed file name is---> %s\n",decr);

	
	efd=open(open_key,O_RDONLY);
	efd2=open(str,O_RDONLY);
	fd2=open(open_encr,O_RDONLY);
	fd3=open(decr,O_RDWR | O_CREAT);
	

	count=lseek(efd2,0,SEEK_END); 
	count1=lseek(efd,0,SEEK_END); //master array
	length=lseek(fd2,0,SEEK_END); //encrypted file
	lseek(efd2,0,SEEK_SET);
	lseek(efd,0,SEEK_SET);
	lseek(fd2,0,SEEK_SET);
	printf("no. of characters in actual file && encrypted file is : %d && %d\n",count,length);
	buff=(char*)malloc(sizeof(char)*(count1));

	count1=read(efd,buff,(count1));
	printf("master array is : %s\n and no. of characters-----: %d\n",buff,count1);
	j=1,f=0; 
	while(i<length)
	{

		r =read(fd2,&ch,1);
		if(f==0)
		{
			printf("in ---->f(0)\n");	
			printf("character is read......yeah!----->%c && %d\n",ch,ch);
			c = ch;
			d = ch;
			c = c >> 1;
			if(j<count)
			{
				write(fd3,(buff+c),1);
				printf("the written charracter is %c\n",*(buff+c));
				j++;
			}

		
		}
		if(f==1)
		{	
			printf("in ---->f(1)\n");	
			printf("character is read......yeah!----->%c && %d\n",ch,ch);
			c = ch;
			e = ch;
			d = d << 7;
			d = d >> 1;
			c = c >> 2;
			d = d | c;

			if(j<count)
			{
				write(fd3,(buff+d),1);
				printf("the written charracter is %c\n",*(buff+d));
				j++;
			}

		
		}
		if(f==2)
		{	

			printf("in ---->f(2)\n");	
			c = ch;
			d = ch;
			e = e << 6;
			e = e >> 1;
			c = c >> 3;
			c = c | e;
			if(j<count)
			{
				write(fd3,(buff+c),1);
				printf("the written charracter is %c\n",*(buff+c));
				j++;
			}

		}
		if(f==3)
		{	
			printf("in ---->f(3)\n");	
			printf("character is read......yeah!----->%c && %d\n",ch,ch);
			c = ch;
			e = ch;
			d = d << 5;
			d = d >> 1;
			c = c >> 4;
			d = d | c;
		
			
			if(j<count)
			{
				write(fd3,(buff+d),1);
				printf("the written charracter is %c\n",*(buff+d));
				j++;
			}

		}
		if(f==4)
		{	
			printf("in ---->f(4)\n");	
			printf("character is read......yeah!----->%c && %d\n",ch,ch);
			c = ch;
			d = ch;
			e = e << 4;
			e = e >> 1;
			c = c >> 5;
			c = c | e; 
			if(j<count)
			{
				write(fd3,(buff+c),1);
				printf("the written charracter is %c\n",*(buff+c));
				j++;
			}

		}
		if(f==5)
		{	
			printf("in ---->f(5)\n");	
			c = ch;
			e = ch;
			d = d << 3;
			d = d >> 1;
			c = c >> 6;
			d = d | c;
			if(j<count)
			{
				write(fd3,(buff+d),1);
				printf("the written charracter is %c\n",*(buff+d));
				j++;
			}

		}
		if(f==6)
		{	
			printf("in ---->f(6)\n");	
			printf("character is read......yeah!----->%c && %d\n",ch,ch);
			c = ch;
			m = ch;
			e = e << 2;
			e = e >> 1;
			c = c >> 7;
			c = c | e;
			m = m << 1;
			m = m >> 1;
			if(j<count)
			{
				write(fd3,(buff+c),1);
				printf("the written charracter is %c\n",*(buff+c));
				j++;
			}
			if(j<count)
			{
				write(fd3,(buff+m),1);
				printf("the written charracter is %c\n",*(buff+m));
				j++;
			}


		}
		i++;
		f++;
		if(f==7)
		f=0;
	}
	close(fd2);
	close(fd3);
	close(efd);
	return 0;
	
}

