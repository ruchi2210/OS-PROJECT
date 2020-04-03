// Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple
// requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time.
// He will log into the system from 10am to 12am only.  He wants to have separate requests queues for students and faculty.
// Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries
// and average query time.

#include<stdio.h>
#include<stdlib.h>
int handleQueries();
int main() 
{ 
 while(1){
	int detail;
  printf("\nEnter your Occupation : \n1.Faculty \t2.Student \t3.Exit\n");
  scanf("%d",&detail);
  switch(detail){
  	case 1:
  		printf("\n\t\tFaculty Queries : ");
  		handleQueries();
  		break;
  	case 2:
  		printf("\n\t\tStudent Queries");
  		handleQueries();
  		break;
  	case 3:
  		printf("\nProgram terminated ");
  		exit(0);
		break;
  	default:
  		printf("\n OOPs!...Wrong key pressed");
  		break;
  }
}
}
int handleQueries(){
  	int i,j,n,time,remain,flag=0,quantum_time,detail; 
  	int waitingTime=0,turnaroundTime=0; 
  	int at[10],bt[10],rt[10];
	printf("\nEnter Number of Process: \t "); 
  	scanf("%d",&n); 
  	remain=n; 
  	for(i=0;i<n;i++) 
  	{ 
  		printf("\n Number of Request: %d",i+1);
    	printf("\nEnter Arrival Time:"); 
    	scanf("%d",&at[i]); 
    	printf("Enter Burst Time:");
    	scanf("%d",&bt[i]); 
    	rt[i]=bt[i]; 
  	} 
  	printf("\nHow much time each request take ? :\t");
  	scanf("%d",&quantum_time); 
  	printf("\n\nRequest\t|Turnaround Time|Waiting Time :\n\n"); 
  	for(time=0,i=0;remain!=0;) 
  	{ 
    	if(rt[i]<=quantum_time && rt[i]>0) 
    	{ 
      	time+=rt[i]; 
      	rt[i]=0; 
      	flag=1; 
    	} 
    	else if(rt[i]>0) 
    	{ 
      	rt[i]-=quantum_time; 
      	time+=quantum_time; 
    	} 
    	if(rt[i]==0 && flag==1) 
    	{ 
      	remain--; 
      	printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]); 
      	waitingTime+=time-at[i]-bt[i]; 
      	turnaroundTime+=time-at[i]; 
      	flag=0; 
    	} 
    	if(i==n-1) 
      	i=0; 
    	else if(at[i+1]<=time) 
      	i++; 
    	else 
      	i=0; 
  	} 
  	printf("\nAverage Waiting Time= %f\n",waitingTime*1.0/n); 
  	printf("Avgerage Turnaround Time = %f",turnaroundTime*1.0/n); 
  
  	return 0;
}
