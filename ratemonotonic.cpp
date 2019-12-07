/*   PId  Period Deadline TimeSlot Priority remainingtimeslot AT*//*Syed Peera Saheb*/
/* Considering low number to be highest priority */
/* Static Priority */

#include<iostream>
#include<math.h>
using namespace std;
void swap(int *a,int *b);
int totaltime = 0;
int max_ganttchart_length=0;
int max_arrival=-999;
double a[10][10];
void swap(double *a,double *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int i,temp,j,k,sum=0,index,flag=0;
	double n;
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
	for(i=0;i<n-1;i++)
	{
		for(k=0;k<n-i-1;k++)
		{
			if(a[k][1] > a[k+1][1])
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
	for(i=0;i<n;i++)
	{
		a[i][4] = i+1;
		a[i][5] = a[i][3];
		a[i][6] = 0;
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
	double result2 = (double) (n * ( pow( 2,(1.0/n) ) -1)  );
	cout<<"result 1 : "<<result1<<endl;
	cout<<"result 2 : "<<result2<<endl;
	if(result1 > result2)
	{
		cout<<"The processes cannot be scheduled for the given input values in RMS "<<endl;
		return 1;		
	}
	cout<<"The data you have entered is : "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<5;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	while(totaltime < max_ganttchart_length)
	{
		flag = 0;
		for(i=0;i<n;i++)
		{
			if(totaltime > max_ganttchart_length)
			{
				break;
			}
			else
			{
				if(a[i][6] <= totaltime)
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
		}
		if(flag == 0)
		{
			cout<<"Process P"<<index+1<<" is executing from "<<totaltime<<" to ";
			totaltime = totaltime + 1;
			cout<<totaltime<<endl;
			a[index][5]--;
			if(a[index][5] == 0)
			{
				a[index][5] = a[index][3];
				a[index][6] = a[index][6] + a[index][1];
			}
		}
	}
	return 0;
}
