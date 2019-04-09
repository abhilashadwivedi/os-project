#include<stdio.h>
#include<unistd.h>
#include<stdlib.h> 
 
int main() 
{ 
 
  int count,n,time,time_quantum,left,flag=0; 
  int waiting_time=0,turnaround_t=0,wt[10],xt[10],rt[10]; 
  printf("Enter the Total Process:\t "); 
  scanf("%d",&n); 
  left=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&wt[count]); 
    scanf("%d",&xt[count]); 
    rt[count]=xt[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround time|Waiting Time\n\n"); 
