#include<iostream>
using namespace std;
int main()
{
	int n;
	printf("enter the number of process\n");
	scanf("%d",&n);
	int q[n],q1[n],q2[n],b[n],b1[n],b2[n],k,a=0,a1=0,a2=0,p[n],p1[n],p2[n],at[n],rt[n];
	printf("\nEnter priority between:\n0 to 10 for high priority\n11 to 20 for medium priority\n21 to 30 for lowest priority for every process\n");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter priority of process %d:",(i+1));
		scanf("%d",&k);
		if(k>0&&k<=10){
		p[a]=k;
		printf("\nEnter burst time of process %d:",(i+1));
		scanf("%d",&b[a]);rt[a]=b[a];
		printf("\nEnter arival time of process %d:",(i+1));
		scanf("%d",&at[a]);
		q[a++]=(i+1);}
		else if(k>10&&k<=20){
		p1[a1]=k;
		printf("\nEnter burst time of process %d:",(i+1));
		scanf("%d",&b[a1]);
		q1[a1++]=(i+1);}
		else if(k>20&&k<=30){
		p2[a2]=k;
		printf("\nEnter burst time of process %d:",(i+1));
		scanf("%d",&b[a2]);
		q2[a2++]=(i+1);}
	}
	printf("\nHighest priority queue:");
	printf("\nProcess ID\tArrival Time\tPriority\tBurst Time\n");
	for(int i=0;i<a;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n",q[i],at[i],p[i],b[i]);
	}
	//-------------------------ROUND-ROBIN-------------------------------------------------------
	  int count,time,remain=a,flag=0,time_quantum=4; 
   int wait_time=0,turnaround_time=0;
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
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
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-b[count]); 
      wait_time+=time-at[count]-b[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==a-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/a); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/a); 
  //---------------------PRIORITY-----------------------------------------------------
	printf("\nmedium priority queue:");
	printf("\nProcess ID\tPriority\tBurst Time\n");
	for(int i=0;i<a1;i++)
	{
		printf("%d\t\t%d\t\t%d\n",q1[i],p1[i],b1[i]);
	}
	
	
	    //sorting burst time, priority and process number in ascending order using selection sort
	int wt[20],tat[20],i,j,total=0,pos,temp,avg_wt,avg_tat;
    for(i=0;i<a1;i++)
    {
        pos=i;
        for(j=i+1;j<a1;j++)
        {
            if(p1[j]<p1[pos])
                pos=j;
        }
 
        temp=p1[i];
        p1[i]=p1[pos];
        p1[pos]=temp;
 
        temp=b1[i];
        b1[i]=b1[pos];
        b1[pos]=temp;
 
        temp=q1[i];
        q1[i]=q1[pos];
        q1[pos]=temp;
    }
 
    wt[0]=0;    //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<a1;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=b1[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/a1;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<a1;i++)
    {
        tat[i]=b1[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",q1[i],b1[i],wt[i],tat[i]);
    }
 
    avg_tat=total/a1;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
    //--------------------------------------FCFS--------------------------------------------------
    printf("\nlowest priority queue:");
	printf("\nProcess ID\tPriority\tBurst Time\n");
	for(int i=0;i<a2;i++)
	{
		printf("%d\t\t%d\t\t%d\n",q2[i],p2[i],b2[i]);
	}
	int wt1[20],tat1[20],avwt=0,avtat=0;
        wt1[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<a2;i++)
    {
        wt1[i]=0;
        for(j=0;j<i;j++)
            wt1[i]+=b2[j];
    }
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    //calculating turnaround time
    for(i=0;i<a2;i++)
    {
        tat1[i]=b2[i]+wt1[i];
        avwt+=wt1[i];
        avtat+=tat1[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,b2[i],wt1[i],tat1[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);
 return 0;
}

