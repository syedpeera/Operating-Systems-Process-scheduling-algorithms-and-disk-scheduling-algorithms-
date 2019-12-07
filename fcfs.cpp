/* PId  AT  BT  CT  TAT  WT  RT jobdone */

#include<iostream>
using namespace std;
void swap(int *a,int *b);
int totaltime=0;
int count=0;
int main()
{
	int a[10][10],i,n,temp,j,k,sum=0,flag,index;
	cout<<"Enter the number of processes : "<<endl;
	cin>>n;
	cout<<"Enter the process id, arrival time and burst time(for each process) : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Process "<<i+1<<" : ";
		for(j=0;j<3;j++)
		{	
			cin>>a[i][j];
		}
	}	
	for(i=0;i<n-1;i++)
	{
		for(k=0;k<n-i-1;k++)
		{
			if(a[k][1] > a[k+1][1])
			{
				swap(&a[k][0],&a[k+1][0]);
				swap(&a[k][1],&a[k+1][1]);	
				swap(&a[k][2],&a[k+1][2]);
			}
			else if(a[k][1] == a[k+1][1])
			{
				if(a[k][0] > a[k+1][0])
				{
					swap(&a[k][0],&a[k+1][0]);
					swap(&a[k][1],&a[k+1][1]);	
					swap(&a[k][2],&a[k+1][2]);
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		a[i][7] = 0;
	}
/*	cout<<"The data you have entered is : "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	//tat = ct - at;
	//wt = tat - bt;
	
	//tat = wt + bt;
	//ct = tat + at;	
	while(count != n)
	{
		flag = 0;
		for(i=0;i<n;i++)
		{
			if(a[i][1] <= totaltime && !a[i][7]) //is there any process that has arrived and not bursted
			{
				index = i;
				break;
			}
			if(i == n-1)
			{
				flag = 1;
				cout<<"CPU is ideal from "<<totaltime<<" to ";
				totaltime++;
				cout<<totaltime<<endl;
			}
		}		
		if(flag == 0)
		{
			a[i][6] = totaltime;
			totaltime = totaltime + a[index][2];
			a[index][7] = 1;
			a[index][3] = totaltime;
			count++;
		}
	}	
	for(i=0;i<n;i++)
	{
		a[i][4] = a[i][3] - a[i][1];
		a[i][5] = a[i][4] - a[i][2];
		a[i][6] = a[i][6] - a[i][1];
	}	
	cout<<"PId\tAT \tBT \tCT \tTAT\tWT \tRT "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<7;j++)
		{	
			cout<<a[i][j]<<"  \t";
		}
		cout<<endl;
	}
}
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


