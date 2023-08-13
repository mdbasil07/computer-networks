#include<stdio.h>
#include<string.h>
#include<conio.h>
#define N strlen(genpoly)
char data[28];
char checkvalue[28];
char genpoly[10];
int datalength,i,j;
void XOR()
{
clrscr();

for(j=1;j<N;j++)
  checkvalue[j]=((checkvalue[j]==genpoly[j])?'0':'1');
}
void crc();
void receiver()
{
printf("enter the recieved data:");
scanf("%s",data);
printf("\n----------------------\n");
printf("data recieved:%s",data);
crc();
for(i=0;(i<N-1)&&(checkvalue[i]!='1');i++);
if(i<N-1)
printf("\nerror detected\n\n");
else
printf("\nno error detected\n\n");
}
void crc(){
for(i=0;i<N;i++)
  checkvalue[i]=data[i];
do{
 if(checkvalue[0]=='1')
   XOR();
for(j=0;j<N-1;j++)
 checkvalue[j]=checkvalue[j+1];
 checkvalue[j]=data[i++];
}
while(i<=datalength+N-1);
}
int main()
{
printf("\nenter data to be transmitted:");
scanf("%s",data);
printf("\nenter the generating polynomial:");
scanf("%s",genpoly);
datalength=strlen(data);
for(i=datalength;i<datalength+N-1;i++)
  data[i]='0';
printf("\n---------------------------");
printf("\n data padded with n-1 zeros:%s",data);
printf("\n---------------------------");
crc();
printf("\nCRC or check value is:%s",checkvalue);
for(i=datalength;i<datalength+N-1;i++)
 data[i]=checkvalue[i-datalength];
printf("\n----------------------------");
printf("\nfinal data to be sent:%s",data);
printf("\n----------------------------");
receiver();
getch();
return 0;
}