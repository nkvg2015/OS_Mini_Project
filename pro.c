#include<stdio.h>

int execution[20];
int n,i,j;
int at[20],bt[20],queue[5],id[20],status[20],pack[20]={1};

void round_robin(int i,int quantum)
{ bt[i]=bt[i]-quantum; }

void fcfs(int i)
{ bt[i]=0; }

int main()
{
printf("Enter number of Processes:\n");
scanf("%d",&n);
//n=4;
for(i=0;i<n;i++)
{
id[i]=i+1;  //generatint id number
printf("Enter arrival time ");
scanf("%d",&at[i]);
//at[0]=0; at[1]=0; at[2]=0; at[3]=10;
printf("Enter Burst time ");
scanf("%d",&bt[i]);
bt[0]=4; bt[1]=3; bt[2]=20; bt[3]=5;

status[i]=0;
}
int time=0,ex=0,k=1000;
for(i=0;i<n;i++)
{
 if(bt[i]>8)
   { time=time+8; round_robin(i,8); }
 else
   { time=time+bt[i]; round_robin(i,bt[i]);  execution[ex]=i;  ex++; }
}

for(i=0;i<n;i++)
{
if(bt[i]!=0)
 {
  if(bt[i]>16)
    { time=time+16; round_robin(i,16); }
  else if(bt[i]<16 && bt[i]>0)
    { time=time+bt[i]; round_robin(i,bt[i]);  execution[ex]=i; ex++; }
 }
}

for(i=0;i<n;i++)
{
if(bt[i]!=0)
 {
   fcfs(i);  execution[ex]=i;  ex++;
 }
}

printf("Order of process Execution: \n");
for(j=0;j<ex;j++)
  printf("p%d\n",execution[j]);

return 0;
}
