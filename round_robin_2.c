#include<stdio.h>
void deleting_process(int);
void push_process(int);
void processing_process();
int main_function();
void swap_function();
void delete_from_queue();

int at[20],bt[20],id[20],status[20]={0};
int qu=0,qat[20],qbt[20],qid[20],qstatus[20];
int i,j,m,n,time=0,start=0,last,quantum=2,execution[20],ex=0;

void get_data()
{
 printf("Number of Process: ");
 scanf("%d",&n);  m=n; last=n-1;

for(i=0;i<n;i++)
 {
  id[i]=i+1;
  arrival_time:
  printf("Arrival Time for process %d: ",i+1);
  scanf("%d",&at[i]);
  if(at[i]
   burst_time:
  printf("Burst Time: ");
  scanf("%d",&bt[i]);
  if(bt[i]<0)
   { printf("Not valid Burst Time: \n"); goto burst_time;}
 }
}

int main()
{
get_data();

int z;
again:
 z=main_function();
if(n>0)
 {
    if(z==0)time++;
    goto again; }
int i=-1,k=0,found=-1,total=0,wt=0,tat=0;
while(k<qu)
{
 i++;
 if(i>qu-1) i=0;
int temp=qbt[i];
if(qu==1) break;
 if(qbt[i]>quantum && qbt[i]>0)
  { qbt[i]-=quantum; total=total+quantum; }
 else if(qbt[i]>0)
  {
    k++; execution[ex++]=qid[i]; total=total+qbt[i];  qbt[i]=-1;
    int instant_tat=total-qat[i];
    wt=wt+instant_tat-temp;
    tat=tat+instant_tat;
 }
}
printf("Order of Execution\n");
for(i=0;i<ex;i++)
 printf("p%d ",execution[i]);
printf("\nTat: %f     WT: %f",(float)tat/m,(float)wt/m);
}

int main_function()
{
int k=0;
for(int i=0;i<n;i++)
{
 if(at[i]<=time)
  { k++; push_process(i); i=0; }
}
if(k==0) return 0;
else return 1;
}

void deleting_process(int i)
{
while(i<n-1)
 {
  at[i]=at[i+1];
  bt[i]=bt[i+1];
  id[i]=id[i+1];
  status[i]=status[i+1];
  i++;
 }
 n--;
}

void push_process(int i)
{
 qid[qu]=id[i];
 qbt[qu]=bt[i];
 qat[qu]=at[i];
 qstatus[qu]=status[i];
 qu++;
deleting_process(i);
}
