#include<stdio.h>
#include<stdlib.h>

int time;

struct node  // setting process data
{
 int execution;
 int at,bt,id,status;
 struct node *link;
};
struct node *start=NULL,*ptr=NULL;

struct compiled // struct conatin executed process id
{
int id;
struct compiled *link;
};
struct compiled *first=NULL,*pt=NULL;

void push_compiled(int num)  // push id of executed process
{
 struct compiled *temp=(struct compiled*)malloc(sizeof(struct compiled));
 temp->id=num;
 temp->link=NULL;
 if(first==NULL)
  first=temp;
 else
  {
    pt=first;
     while(pt->link!=NULL)
      pt=pt->link;
     pt->link=temp;
  }
}
void push(int id,int at,int bt)  // push process data
{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
 temp->id=id;
 temp->at=at;
 temp->bt=bt;
 temp->status=0;
 temp->execution=0;
 temp->link=NULL;
 if(start==NULL)
  start=temp;
 else
  {
    ptr=start;
     while(ptr->link!=NULL)
      ptr=ptr->link;
     ptr->link=temp;
  }
}

void display()  /* printing id after execution */
{
 pt=first;
  while(pt!=NULL)
  { printf("p[%d] ",pt->id); pt=pt->link; }
  printf("\n");
}

void pop(int id)  // pop process id
{
 struct node *par;
 ptr=start;
 if(start->id==id)
  start=start->link;
 else
  {
   while(ptr!=NULL && id!=ptr->id)
    { par=ptr; ptr=ptr->link; }
   if(ptr!=NULL && id==ptr->id)
    par->link=ptr->link;
  }
}

int set_status() // setting status
{
int found=0;
 ptr=start;
  while(ptr!=NULL)
   {
     if(ptr->at<=time)
      { ptr->status=1; found=1; }
     ptr=ptr->link;
   }
return found;
}

/* * * * * * * * *     M A I N    B O D Y     * * * * * * * * * * */

int main()
{
int i,n,at,bt;
printf("Enter number of Process: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
 printf("Process id: %d\n",i+1);
 printf("Enter arrival Time: ");
 again_at:
 scanf("%d",&at);
  if(at<0)         // arrival time can't be less than 0
    {
      printf("\nInvalid arrival time\nPlease enter it again\n\n");
      goto again_at;
    }
 printf("Enter Burst Time: ");
 again_bt:
 scanf("%d",&bt);
  if(bt<0)         // Waiting time can't be less than 0
    {
      printf("\nInvalid Burst time\nPlease enter it again\n\n");
      goto again_bt;
    }
 push(i+1,at,bt);
}

int found,wait=0,k;
ptr=start;
while(ptr!=NULL)  // for loop for round_robin_8
{
again:
k=set_status();
 if(k==0)
  {
    time++;
    wait++;
    goto again;
  }

 struct node *p=start;
  while(p!=NULL)    /* execution starts*/
  {
    if(p->status==1)
     {
       if(p->bt>8 && p->execution==0) /* execution is variable to determine whether process has run atleast once or not*/
        {
          p->bt=p->bt-8;
          time+=8;
          p->execution=1;
        }
       else if(p->bt<=8 && p->bt>0 && p->execution==0)
        {
          time=p->bt+time;
          p->bt=0;
          push_compiled(p->id);
          p->execution=1;
          pop(p->id);
        }
      }
   p=p->link;
  }
}

ptr=start;
while(ptr!=NULL)
 {
  ptr->execution=0;
  ptr->status=0;
  ptr=ptr->link;
 } //Reset all status and execution

ptr=start;
while(ptr!=NULL)     // for loop for round_robin_16
{
again_:
k=set_status();
 if(k==0)
  {
   time++;
   wait++;
   goto again_;
  }

 struct node *p=start;  // execution round_robin_16 //
  while(p!=NULL)
  {
    if(p->status==1)
     {
       if(p->bt>16 && p->execution==0)
        {
          p->bt-=16;
          time+=16;
          p->execution=1;
        }
       else if(p->bt<=16 && p->bt>0 && p->execution==0)
        {
          time+=p->bt;
          p->bt=0;
          push_compiled(p->id);
          p->execution=1;
        }
     }
   p=p->link;
  }
}

ptr=start;
while(ptr!=NULL)
 {
  ptr->execution=0;
  ptr->status=0;
  ptr=ptr->link;
 }

   /* first come first serve  */
 struct node *p=start;  /* execution starts */
 while(p!=NULL)
  {
    if(p->bt>0 && p->execution==0)
      {
       time+=p->bt;
       p->bt=0;
       push_compiled(p->id);
       p->execution=1;
      }
    p=p->link;
  }

printf("Order of Execution: \n");
display();

return 0;
}
