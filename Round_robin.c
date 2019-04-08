#include<stdio.h>

int main()
{
      int i,no,CT=0,x,counter= 0,quantum; 
      int WT=0,TAT=0,AT[10],BT[10],temp[10]; 
      float AWT,ATAT;
      printf("\nEnter Number of Processes:\t"); 
      scanf("%d",&no); 
      x = no; 
      for(i=0;i<no;i++) 
      {
            printf("\nData for process [%d]\n", i + 1);
            printf("Enter Arrival Time:\t");
            scanf("%d", &AT[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &BT[i]); 
            temp[i] = BT[i];
      } 
      printf("\nEnter Quantum:\t"); 
      scanf("%d",&quantum); 
      printf("Process ID   Burst Time   Turnaround Time  Waiting Time\n");
      for(CT=0,i=0;x!=0;) 
      { 
            if(temp[i]<=quantum && temp[i]>0) 
            { 
              CT=CT+temp[i]; 
              temp[i]=0; 
              counter=1; 
            } 
            else if(temp[i]>0) 
            { 
              temp[i]=temp[i]-quantum; 
              CT=CT+quantum; 
            } 
            if(temp[i]==0&&counter==1) 
            { 
              x--; 
              printf("\nProcess[%d]         %d            %d               %d",i+1,BT[i],CT-AT[i],CT-AT[i]-BT[i]);
              WT=WT+CT-AT[i]-BT[i]; 
              TAT=TAT+CT-AT[i]; 
              counter=0; 
            } 
            if(i==no-1) 
               i=0; 
            else if(AT[i+1]<=CT) 
               i++;
            else 
               i=0;
      } 
      AWT=WT*1.0/no;
      ATAT=TAT*1.0/no;
      printf("\nAverage Waiting Time:  %f", AWT); 
      printf("\nAvg Turnaround Time:  %f\n", ATAT); 
      return 0; 
}
