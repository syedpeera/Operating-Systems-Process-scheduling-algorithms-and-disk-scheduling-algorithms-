/*   PId  AT  BT  CT  TAT  WT  RT  */
/* column 7 is for getting the completion time of the process */
/* column 8 contains all the burst time values of the process */
/* column 9 contains 1 or 0 which tells whether a process is scheduled atleast once then it is 1 or it is 0 */
/* column 10 gives info about the process which is having less burst time(total burst time for entire process) less then tq  */
/* The queue that iam using only holds the indexes of the process */

#include<iostream>
#include<queue>
using namespace std;
void swap(int *a,int *b);
int calculate_totaltime(int key_at,int n);
void update_the_queue(int n);
int totaltime=0;
int tq=0;
int max_arrival=-999;
int a[10][11],flag=0,flag1=0;
queue <int> q;
int main()
{
	int i,n,temp,j,k,sum=0,index,temp1;
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
	cout<<"Enter the time quantum value : "<<endl;
	cin>>tq;
	/*
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
		}
	}
	*/
	for(i=0;i<n;i++)
	{
		a[i][7] = 0;
		a[i][9] = 0;
		a[i][10] = 0;
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
		if(totaltime > max_arrival)
		{
			break;
		}	
		if(index=calculate_totaltime(i,n)) //this is assigning not comparision
		{
			if(index == -1)
			{
				index = 0;
			}	
			if(a[index][2] >= tq)
			{
				q.pop();
				totaltime = totaltime + tq;
				a[index][2] = a[index][2] - tq;
				//a[index][9] = 1;
				update_the_queue(n);
				if(a[index][2] == 0)
				{
					a[index][3] = totaltime;
					a[index][7] = 1;
				}
				else
				{
					q.push(index);
					//a[index][9] = 1;
				}	
				if((a[index][8] - a[index][2]) == 3)
				{
					a[index][6] = totaltime-3;
					a[index][10] = 1;
				}
			}
			else
			{
				q.pop();
				if(!a[index][10])
				{
					a[index][6] = totaltime;	
				}
				totaltime = totaltime + a[index][2];
				a[index][2] = 0;
				a[index][3] = totaltime;
				a[index][7] = 1;
				//a[index][9] = 1;
				update_the_queue(n);
			}
		}
		else
		{
			totaltime = totaltime + 1;
		}
	}
	while(!q.empty())
	{
		temp1 = q.front();
			if(a[temp1][2] >= tq)
			{
				q.pop();
				totaltime = totaltime + tq;
				a[temp1][2] = a[temp1][2] - tq;
				//a[temp1][9] = 1;
				if(a[temp1][2] == 0)
				{
					a[temp1][3] = totaltime;
					a[temp1][7] = 1;
				}
				else
				{
					q.push(temp1);
					//a[index][9] = 1;
				}
				if((a[temp1][8] - a[temp1][2]) == 3)
				{
					a[temp1][6] = totaltime-3;
					a[temp1][10] = 1;
				}
			}
			else
			{
				q.pop();
				if(!a[temp1][10])
				{
					a[temp1][6] = totaltime;	
				}
				totaltime = totaltime + a[temp1][2];
				a[temp1][2] = 0;
				a[temp1][3] = totaltime;
				a[temp1][7] = 1;
				//a[temp1][9] = 1;
			}
	}
	//tat = ct - at;
	//wt = tat - bt;
	
	//tat = wt + bt;
	//ct = tat + at;
	for(i=0;i<n;i++)
	{
		a[i][4] = a[i][3] - a[i][1];
		a[i][2] = a[i][8];
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
/*
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}*/
int calculate_totaltime(int key_at,int n)
{
	int i;
	if(flag1 == 0)
	{
		for(i=0;i<n;i++)
		{
			if(a[i][1] == key_at && !a[i][7] && !a[i][9])
			{
				flag1=1;
				if(i == 0)
				{
					q.push(i);
					a[i][9] = 1;
					return -1;
				}
				q.push(i);
				a[i][9] = 1;
				return i;
			}
		}
	}
	else
	{
		if(!q.empty())
		{
			return q.front();
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
void update_the_queue(int n)
{
	int i,array[n],j=0,k,temp;
	for(i=0;i<n;i++)
	{
		if(a[i][1] <= totaltime && !a[i][7] && !a[i][9])
		{
			array[j] = i;
			j++;
		}
	}
	for(i=0;i<j-1;i++)
	{
		for(k=0;k<j-i-1;k++)
		{
			if(a[array[k]][1] > a[array[k+1]][1])
			{
				temp = array[k];
				array[k] = array[k+1];
				array[k+1] = temp;
			}
		}
	}
	for(i=0;i<j;i++)
	{
		q.push(array[i]);
		a[array[i]][9] = 1;
	}
}
