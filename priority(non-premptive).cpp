/*   considering value with large number to be highest priority   */
/*   PId  priority AT  BT  CT  TAT  WT  RT  */

#include<iostream>
using namespace std;
void swap(int *a,int *b);
int calculate_totaltime(int n);
int totaltime=0;
int max_arrival=-999;
int max_priority=-999;
int a[10][10];
int main()
{
	int i,n,temp,j,k,sum=0,index;
	cout<<"Enter the number of processes : "<<endl;
	cin>>n;
	cout<<"Enter the process id, priority, arrival time and burst time(for each process) : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Process "<<i+1<<" : ";
		for(j=0;j<4;j++)
		{	
			cin>>a[i][j];
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(k=0;k<n-i-1;k++)
		{
			if(a[k][1] < a[k+1][1])
			{
				swap(&a[k][0],&a[k+1][0]);
				swap(&a[k][1],&a[k+1][1]);	
				swap(&a[k][2],&a[k+1][2]);			
				swap(&a[k][3],&a[k+1][3]);
			}
			else if(a[k][1] == a[k+1][1])
			{
				if(a[k][2] > a[k+1][2])
				{
					swap(&a[k][0],&a[k+1][0]);
					swap(&a[k][1],&a[k+1][1]);	
					swap(&a[k][2],&a[k+1][2]);
					swap(&a[k][3],&a[k+1][3]);
				}
				else if(a[k][2] == a[k+1][2])
				{
					if(a[k][0] > a[k+1][0])
					{
						swap(&a[k][0],&a[k+1][0]);
						swap(&a[k][1],&a[k+1][1]);		
						swap(&a[k][2],&a[k+1][2]);
						swap(&a[k][3],&a[k+1][3]);
					}	
				}
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		a[i][8] = 0;
	}
	cout<<"The data you have entered is : "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;	
	for(i=0;i<n;i++)
	{
		if(a[i][2] > max_arrival)
		{
			max_arrival = a[i][2];
		}
		if(a[i][1] > max_priority)
		{
			max_priority = a[i][1];
		}
	}	
	for(i=0;i<max_arrival;)
	{
		if(totaltime > max_arrival)
		{
			break;
		}
		else if(index=calculate_totaltime(n)) //this is assigning not comparision
		{
			if(index == -1)
			{
				index = 0;
			}
			totaltime = totaltime + a[index][3];
			a[index][4] = totaltime;
			a[index][8] = 1;
			i = totaltime;
		}
		else
		{
			totaltime = totaltime + 1;
			i = totaltime;
		}
	}	
	for(i=0;i<n;i++)
	{
		if(!a[i][8])
		{
			totaltime = totaltime + a[i][3];
			a[i][4] = totaltime;
 		}
	}
	//tat = ct - at;
	//wt = tat - bt;
	
	//tat = wt + bt;
	//ct = tat + at;
	for(i=0;i<n;i++)
	{
		a[i][5] = a[i][4] - a[i][2];
		a[i][6] = a[i][5] - a[i][3];
		a[i][7] = a[i][6];
	}	
	cout<<"PId\tPRT\tAT \tBT \tCT \tTAT\tWT \tRT "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<8;j++)
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
	int maxpr = -999;
	for(i=0;i<n;i++)
	{
		if(a[i][2] <= totaltime && !a[i][8])
		{
			array[j] = i;
			j++;
		}
	}
	for(i=0;i<j;i++)
	{
		if(a[array[i]][1] > maxpr)
		{
			maxpr = a[array[i]][1];
		}
	}
	for(i=0;i<n;i++)
	{
		if(maxpr == a[i][1])
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
