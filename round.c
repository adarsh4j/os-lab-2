#include <stdio.h>
#include <stdbool.h>
int turnarroundtime(int processes[], int n,int bt[], int wt[], int tat[])
{
   
   for (int i = 0; i < n ; i++)
   tat[i] = bt[i] + wt[i];
   return 1;
}

int waitingtime(int processes[], int n,int bt[], int wt[], int quantum) 
{
   
   int rem_bt[n];
   for (int i = 0 ; i < n ; i++)
   rem_bt[i] = bt[i];
   int t = 0; 
   
   while (1) 
   {
      bool done = true;
      
      for (int i = 0 ; i < n; i++) {
        
         if (rem_bt[i] > 0) {
            done = false; 
            if (rem_bt[i] > quantum) {
               
               t += quantum;
               
               rem_bt[i] -= quantum;
            }
            
            else {
               
               t = t + rem_bt[i];
               
               wt[i] = t - bt[i];
               
               rem_bt[i] = 0;
            }
         }
      }
     
      if (done == true)
         break;
   }
   return 1;
}

int findavgTime(int processes[], int n, int bt[],int quantum) 
{
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
  
   waitingtime(processes, n, bt, wt, quantum);
   
   turnarroundtime(processes, n, bt, wt, tat);
   
   printf("Processes Burst Time Waiting Time turnaround time\n");
  
   for (int i=0; i<n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      printf("\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1, bt[i], wt[i], tat[i]);
   }
   printf("Average waiting time = %f", (float)total_wt / (float)n);
   printf("\nAverage turnaround time = %f\n", (float)total_tat / (float)n);
   return 1;
}

int main() 
{
  
   int processes[10],burst_time[10],n,quantum;
   printf("enter the number of process");
   scanf("%d",&n);
   printf("enter the process one by one");
   for(int i=0;i<n;i++)
      scanf("%d",&processes[i]);
   printf("enter the burst time one by one");  
   for(int i=0;i<n;i++)
      scanf("%d",&burst_time[i]); 
   printf("enter the quantum");
   scanf("%d",&quantum);
       
   findavgTime(processes, n, burst_time, quantum);
   return 0;
}
