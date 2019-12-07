#include<iostream>
using namespace std;
int alloc[10][10],max_need[10][10],available[10],need[10][10],request[10];
int main()
{
	int n,r,i,j,id,count=0;
	cout<<"Enter the number of process : ";
	cin>>n;
	cout<<"Enter the number resources : ";
	cin>>r;
	cout<<"Enter the allocation matrix : ";
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			cin>>alloc[i][j];
		}
	}
	cout<<"Enter the maximum need : ";
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			cin>>max_need[i][j];
		}
	}
	cout<<"Enter the available resources : "<<endl;
	for(i=0;i<r;i++)
	{
		cin>>available[i];
	}
	cout<<"Enter the process that you want to check if it is granted or not(process id , resources) ";
	cin>>id;
	for(i=0;i<r;i++)
	{
		cin>>request[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			if(max_need[i][j] - alloc[i][j] < 0)
			{
				cout<<"Invalid inputs"<<endl;
				return 1;
			}
			else
			{
				need[i][j] = max_need[i][j] - alloc[i][j];	
			}	
		}
	}	
	int flag = 0;
	//req <= need
	for(i=0;i<r;i++)
	{
		if(!(request[i] <= need[id][i]))
		{
			flag = 1;
			cout<<"The request by the process cannot be granted(req is not <= to need) "<<endl;
			return 1;
		}
	}
	if(flag == 0)
	{
		cout<<"The request is <= need (satisfied) "<<endl;
	}
	flag = 0;
	//req <= available
	for(i=0;i<r;i++)
	{
		if(!(request[i] <= available[i]))
		{
			flag = 1;
			cout<<"The request by the process cannot be granted(req is not <= to available) "<<endl;
			return 1;
		}
	}
	if(flag == 0)
	{
		cout<<"The request is <= available (satisfied) "<<endl;
	}
	//checking the state
	for(i=0;i<r;i++)
	{
		alloc[id][i] = alloc[id][i] + request[i];
		need[id][i] = need[id][i] - request[i];
		available[i] = available[i] - request[i];
	}	
	int R,check=0,seq[n],k,m=0,temp[n];
	for(i=0;i<n;i++)
	{
		temp[i] = 0;
	}
	while(count != n)
	{
		for(i=0;i<n;i++)
		{
			R=0;
			for(j=0;j<r;j++)
			{
				if(need[i][j] <= available[j])
				{
					R++;
					if(R == r && !temp[i])
					{
						check++;
						for(k=0;k<r;k++)
						{
							available[k] = available[k] + alloc[i][k];
							temp[i] = 1;
						}
						seq[m++] = i;
					}
				}
			}
		}
		count++;
	}
	if(check == n)
	{
		cout<<"The safe sequence is : ";
		for(i=0;i<n;i++)
		{
			cout<<"p"<<seq[i]<<" ";
		}
		cout<<endl;
		cout<<"Request should be granted "<<endl;
	}
	else
	{
		cout<<"Request cannot be granted "<<endl;
	}
	return 0;
}
