#include<stdio.h>
#include<conio.h>
int main()
{
int w,i,f,frames[50];
clrscr();
printf("enter window size:");
scanf("%d",&w);
printf("\nenter number of frames to transmit:");
scanf("%d",&f);
printf("\nenter %d frames:",f);
for(i=1;i<=f;i++);
scanf("%d",&frames[i]);
printf("\nWith sliding window protocol the frames will be sent in the following manner(assuming no corruption of frames)\n\n");
printf("after sending %d frames at ech stage sender waits for acknoledgement sent by the receiver\n\n",w);
for(i=1;i<=f;i++)
{
 if(i%w==0)
 {
  printf("%d\n",frames[i]);
  printf("acknologement of above frames sent is recieved by the sender\n\n");
}
else{
printf("%d",frames[i]);
}
}
if(f%w!=0)
printf("\nAcknowledegment of above frames sent is recieved by sender\n");
getch();
return 0;
}