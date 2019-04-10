#include<stdio.h>
int p[20],a[20],a1[20],q1[20],q2[20],bt[20],at[20],pri[20],b[20],b1[20],i,j,n,c1=0,c2=0;
int atwt,attat,aswt,astat;
void process(int n){
	for(i=0;i<n;i++){
		printf("Enter Process number : ");
		scanf("%d",&p[i]);
		printf("Enter Arrival Time : ");
		scanf("%d",&at[i]);
		printf("Enter Burst Time : ");
		scanf("%d",&bt[i]);
		printf("Enter Priority 0 or 1 : ");
		scanf("%d",&pri[i]);
	}
}
void process_allocation(int n){
	int k=0,l=0;
	for(i=0;i<n;i++){
		if(pri[i]==0){
			q1[k]=p[i];
			b[k]=bt[i];
			a[k]=at[i];
			k=k+1;
			c1=c1+1;
		}
		else if(pri[i]==1){
			q2[l]=p[i];
			b1[l]=bt[i];
			a1[l]=at[i];
			l=l+1;
			c2=c2+1;
		}
	}
}
void queue(){
	printf("\nProcess in Teacher Queue : ");
	for(i=0;i<c1;i++){
		printf("%d ",q1[i]);
	}
	printf("\nProcess in Student Queue : ");
	for(i=0;i<c2;i++){
		printf("%d ",q2[i]);
	}
}
void fcfs(){
	int wt[20],tat[20],s=0,twt=0,ttat=0;
	printf("\n\nFood Serving to Teacher : ");
	printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time");
	for(i=0;i<c1;i++){
		if(i==0)
			wt[i]=0;
		else{
			s=s+b[i-1];
			wt[i]=s-a[i]+a[0];
		}
		tat[i]=(wt[i]+b[i]);
		twt=twt+wt[i];
		ttat=ttat+tat[i];
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",q1[i],a[i],b[i],wt[i],tat[i]);
	}
	atwt=twt/i;
	attat=ttat/i;
	printf("\nThe average waiting time is = %d",atwt);
	printf("\nThe average turn around time is = %d",attat);
}
void sjf(){
	int temp,min,b=0,wt[20],tat[20],swt=0,stat=0,k=1,w=0,ta=0;
	wt[0]=0;
	for(i=0;i<c2;i++){
		for(j=i;j<c2;j++){
			if(b1[i]>b1[j]){
				temp=q2[i];
				q2[i]=q2[j];
				q2[j]=temp;
				temp=a1[i];
				a1[i]=a1[j];
				a1[j]=a1[i];
				temp=b1[i];
				b1[i]=b1[j];
				temp=b1[j];
			}
		}
	}
	for(i=0;i<c2;i++){
		b=b+b1[i];
		min=b1[k];
		for(j=k;j<c2;j++){
			if(b>=a1[j] && min<b1[j]){
				temp=p[k];
				p[k]=p[j];
				p[j]=temp;
				temp=a1[k];
				a1[k]=a1[j];
				a1[j]=temp;
				temp=b1[k];
				b1[k]=b1[j];
				b1[j]=temp;
			}
		}	
		k++;
	}
	//wt[0]=0;
	k=0;
	for(i=0;i<c2;i++){
		if(i==0)
			wt[i]=0;
		else{
			k=k+b1[i-1];
			wt[i]=k-a1[i]+a1[0];
		}
		tat[i]=(wt[i]+b1[i]);
		swt=swt+wt[i];
		stat=stat+tat[i];
	}
	printf("\n\nFood Serveing to Student : ");
	printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time");
	for(i=0;i<c2;i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",q2[i],a1[i],b1[i],wt[i],tat[i]);
	}
	aswt=swt/c2;
	astat=stat/c2;
	printf("\nThe average waiting time is = %d",aswt);
	printf("\nThe average turn around time is = %d",astat);
}
int main(){
	printf("Enter no of processes :");
	scanf("%d",&n);
	process(n);
	process_allocation(n);
	queue();
	fcfs();
	sjf();
}
