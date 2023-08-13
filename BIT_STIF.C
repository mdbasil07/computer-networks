#include<stdio.h>
#include<conio.h>
int main(){
char data[20],stuffeddata[30];
int i,j,count;
clrscr();
printf("enter the data:");
scanf("%s",data);
i=0;
j=0;
count=0;

while(data[i]!='\0'){
stuffeddata[j]=data[i];

if(data[i]=='1'){
count++;
}else{
  count=0;
}
if(count==5){
  stuffeddata[++j]='0';
  count=0;
}
i++;
j++;
}
stuffeddata[j]='\0';
printf("the data:%s\n",data);
printf(" stuffing data:%s\n",stuffeddata);
getch();
return 0;
}