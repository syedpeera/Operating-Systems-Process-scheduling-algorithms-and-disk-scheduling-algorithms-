/*   PId  AT  BT  CT  TAT  WT  RT    -    remaining bursttime  */

#include<iostream>
using namespace std;
void swap(int *a,int *b);
int calculate_totaltime(int n);
int totaltime=0;
int max_arrival=-999;
int a[10][10];
int main()
{
	int i,n,temp,j,k,sum=0,index;
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
			if(a[k][2] > a[k+1][2])
			{
				swap(&a[k][0],&a[k+1][0]);
				swap(&a[k][1],&a[k+1][1]);	
				swap(&a[k][2],&a[k+1][2]);
			}
			else if(a[k][2] == a[k+1][2])
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
	}
	for(i=0;i<n;i++)
	{
		a[i][7] = 0;
		a[i][8] = a[i][2];
	}
	cout<<"The data you have entered is : "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		if(a[i][1] > max_arrival)
		{
			max_arrival = a[i][1];
		}
	}
	for(i=0;i<=max_arrival;i++)
	{
		if(index=calculate_totaltime(n)) //this is assigning not comparision
		{
			if(index == -1)
			{
				index=0;
			}
			if(totaltime > max_arrival)
			{
				break;
			}
			else
			{
				a[index][2]--;
				totaltime = totaltime + 1;
				if(a[index][2] == 0)
				{
					a[index][3] = totaltime;	
					a[index][7] = 1;		
				}
				if((a[index][8] - a[index][2]) == 1)
				{
					a[index][6] = totaltime - 1;
				}
			}
		}
		else
		{
			totaltime = totaltime + 1;
		}
	}
	for(i=0;i<n;i++)
	{
		if(!a[i][7])
		{
			if((a[i][8] - a[i][2]) == 0)
			{
				a[i][6] = totaltime;
			}
			totaltime = totaltime + a[i][2];
			a[i][3] = totaltime;
 		}
	}
	//tat = ct - at;
	//wt = tat - bt;
	
	//tat = wt + bt;
	//ct = tat + at;
	for(i=0;i<n;i++)
	{
		a[i][4] = a[i][3] - a[i][1];
		a[i][6] = a[i][6] - a[i][1];
		a[i][2] = a[i][8];
		a[i][5] = a[i][4] - a[i][2];
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
int calculate_totaltime(int n)
{	
	int i,array[n];
	int j=0;
	int minbt = 999;
	for(i=0;i<n;i++)
	{
		if(a[i][1] <= totaltime && !a[i][7])
		{
			array[j] = i;
			j++;
		}
	}
	for(i=0;i<j;i++)
	{
		if(a[array[i]][2] < minbt)
		{
			minbt = a[array[i]][2];
		}
	}
	for(i=0;i<n;i++)
	{
		if(minbt == a[i][2])
		{
			if(i==0)
			{
				return -1;
			}
			return i;
		}
	}
	return 0;
}
