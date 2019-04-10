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
  
  for(time=0,count=0;left!=0) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
          left--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-wt[count],time-wt[count]-xt[count]); 
      waiting_time+=time-wt[count]-xt[count]; 
      turnaround_t+=time-wt[count]; 
      flag=0; 
    } 

    if(count==n-1) 
      count=0; 
    else if(wt[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
    printf("\nAverage Waiting Time= %f\n",waiting_time*1.0/n); 
    printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
    return 0; 
}
  
