/*   PId  Period Deadline TimeSlot remainingtimeslot AT deadline_fixed */
/* Considering low number to be highest priority */
/* Dynamic Priority */

#include<iostream>
using namespace std;
void swap(int *a,int *b);
void sort(int n);
int totaltime = 0;
int max_ganttchart_length=0;
int a[15][15];
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void sort(int n)
{
	int i,k;
	for(i=0;i<n;i++)
	{
		for(k=0;k<n-i-1;k++)
		{
			if(a[k][2] > a[k+1][2])
			{
				swap(&a[k][0],&a[k+1][0]);
				swap(&a[k][1],&a[k+1][1]);	
				swap(&a[k][2],&a[k+1][2]);
				swap(&a[k][3],&a[k+1][3]);
				swap(&a[k][4],&a[k+1][4]);
				swap(&a[k][5],&a[k+1][5]);
				swap(&a[k][6],&a[k+1][6]);
			}
			if(a[k][2] == a[k+1][2])
			{
				if(a[k][5] > a[k+1][5])
				{
					swap(&a[k][0],&a[k+1][0]);
					swap(&a[k][1],&a[k+1][1]);	
					swap(&a[k][2],&a[k+1][2]);
					swap(&a[k][3],&a[k+1][3]);
					swap(&a[k][4],&a[k+1][4]);
					swap(&a[k][5],&a[k+1][5]);
					swap(&a[k][6],&a[k+1][6]);
				}
			}
		}
	}
}
int main()
{
	int i,temp,j,k,index,flag=0;
	int n;
	cout<<"Enter the number of processes : "<<endl;
	cin>>n;
	cout<<"Enter the Process id, Period , Deadline, Processing time (for each process) : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Process "<<i+1<<" : ";
		for(j=0;j<4;j++)
		{	
			cin>>a[i][j];
		}
	}
	cout<<"Enter the Gantt chart length : ";
	cin>>max_ganttchart_length;
	for(i=0;i<n;i++)
	{
		a[i][4] = a[i][3];
		a[i][5] = 0;
		a[i][6] = a[i][5] + a[i][2]; // copying deadlines to another column
 	}
	for(i=0;i<n;i++)
	{
		if(!(a[i][1] >= a[i][2] && a[i][2] >= a[i][3]))
		{
			cout<<"Invalid Inputs (plz give proper inputs for period, processingtime and deadline) "<<endl;
			return 1;
		}
	}
	double result1 = (double)0.0;
	for(i=0;i<n;i++)
	{
		result1 = (double) (result1 + (a[i][3]/(a[i][1])));
	}
	if(result1 > 1)
	{
		cout<<"The process cannot be scheduled for the given input values in EDF "<<endl;
		return 1;
	}
	sort(n);
	cout<<"The data you have entered is : "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<7;j++)
		
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
/*   PId  Period Deadline TimeSlot remainingtimeslot AT deadline_fixed */	
	while(totaltime < max_ganttchart_length)
	{
		flag = 0;
		for(i=0;i<n;i++)
		{
				if(a[i][5] <= totaltime)
				{
					index = i; //getting the index of the process that is having high priority and started the period
					break;
				}
				else if(i == n-1)
				{
					flag = 1;
					cout<<"CPU is idle from "<<totaltime<<" to ";
					totaltime = totaltime + 1;
					cout<<totaltime<<endl;
				}	
		}
		if(flag == 0)
		{
			cout<<"Process P"<<a[index][0]<<" is executing from "<<totaltime<<" to ";
			totaltime = totaltime + 1;
			cout<<totaltime<<endl;
			a[index][4]--;
			if(a[index][4] == 0)
			{
				a[index][4] = a[index][3];
				a[index][5] = a[index][5] + a[index][1];
				a[index][2] = a[index][5] + a[index][6];
				sort(n);
			}
		}
	}
	return 0;
}
