//cylinders : 20
//request : 8
//98 183 37 122 14 124 65 67
//current head : 56
//previous movement : 1(forward)

#include<iostream>
#include<stdlib.h>
using namespace std;
int a[20],b[21],c[20][3];
int mov,n,cylinder,p,i,j,sum=0,k,count=0,temp,temp2;
void sort();
int main()
{
	cout<<"Enter the number of cylinders : ";
	cin>>cylinder;
	cout<<"Enter the number of requests : ";
	cin>>n;
	cout<<"Enter "<<n<<" requests : ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(!(a[i] >= 0 && a[i] <= cylinder-1))
		{
			cout<<"invalid input"<<endl;
			return 0;
		}
	}
	cout<<"Enter the current position of the head : ";
	cin>>p;
	
	if(!(p >= 0 && p <= cylinder-1))
	{	
		cout<<"invalid input"<<endl;
		return 0;
	}
	
	cout<<"Enter the previous movement of the head(0 or 1) : ";
	cin>>mov;
	
	//FCFS
	cout<<"FCFS : "<<endl;
	cout<<endl<<"Scheduling the request in the following order : ";
	b[0] = p;
	for(i=1;i<n+1;i++)
	{
		b[i] = a[i-1];
	}
	for(i=0;i<n;i++)
	{
		sum = sum + abs(b[i+1] - b[i]);
		cout<<b[i]<<" ";
	}
	cout<<b[i]<<endl;
	cout<<"Total Head Movement : "<<sum<<endl<<endl;
	
	//SSTF
	cout<<"SSTF : "<<endl;
	sum=0,k=0,count=0;
	temp2 = p;
	b[k++] = p;
	cout<<endl<<"Scheduling the request in the following order : ";
	for(i=0;i<n;i++)
	{
		c[i][0] = a[i];
		c[i][1] = 0;
		c[i][2] = a[i];
	}
	while(count != n)
	{
		for(i=0;i<n;i++)
		{	
			c[i][0] = abs(p-c[i][2]);
		}
		sort();	
		for(i=0;i<n;i++)
		{
			if(c[i][1] == 0)
			{
				c[i][1] = 1;
				b[k++] = c[i][2];
				p = c[i][2];	
				count++;
				break; 
			}
		}
	}
	for(i=0;i<n;i++)
	{
		sum = sum + abs(b[i+1] - b[i]);
		cout<<b[i]<<" ";
	}
	cout<<b[i]<<endl;
	cout<<"Total Head Movement : "<<sum<<endl<<endl;
	
	//SCAN
	cout<<"SCAN : "<<endl;
	p=temp2,sum=0,k=0;
	b[k++] = p;
	cout<<endl<<"Scheduling the request in the following order : ";
	if(mov == 0)
	{
		for(i=p;i>0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}					
		}
		b[k++] = 0;
		for(i=p+1;i<cylinder;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];		
					break;
				}
			}
		}
	}
	else
	{
		for(i=p;i<cylinder;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}
		}
		b[k++] = cylinder - 1;
		for(i=p-1;i>=0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}
		}
	}
	for(i=0;i<n+1;i++)
	{
		sum = sum + abs(b[i+1] - b[i]);
		cout<<b[i]<<" ";
	}
	cout<<b[i]<<endl;
	cout<<"Total Head Movement : "<<sum<<endl<<endl;
	
	//CSCAN
	cout<<"CSCAN : "<<endl;
	sum=0,k=0;
	b[k++] = p;
	cout<<endl<<"Scheduling the request in the following order : ";
	if(mov == 0)
	{
		for(i=p;i>0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}					
		}
		b[k++] = 0;
		b[k++] = cylinder-1; 
		for(i=cylinder-2;i>p;i--)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];		
					break;
				}
			}
		}
	}
	else
	{
		for(i=p;i<cylinder;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}
		}
		b[k++] = cylinder - 1;
		b[k++] = 0;
		for(i=1;i<p;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}
		}
	}
	for(i=0;i<n+2;i++)
	{
		sum = sum + abs(b[i+1] - b[i]);
		cout<<b[i]<<" ";
	}
	cout<<b[i]<<endl;
	cout<<"Total Head Movement : "<<sum<<endl<<endl;
	
	//LOOK
	cout<<"LOOK : "<<endl;
	sum=0,k=0;
	b[k++] = p;
	cout<<endl<<"Scheduling the request in the following order : ";
	if(mov == 0)
	{
		for(i=p;i>=0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}					
		}
		for(i=p+1;i<cylinder;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];		
					break;
				}
			}
		}
	}
	else
	{
		for(i=p;i<cylinder;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}
		}
		for(i=p-1;i>=0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		sum = sum + abs(b[i+1] - b[i]);
		cout<<b[i]<<" ";
	}
	cout<<b[i]<<endl;
	cout<<"Total Head Movement : "<<sum<<endl<<endl;
	
	//ClOOK
	cout<<"CLOOK : "<<endl;
	sum=0,k=0;
	b[k++] = p;
	cout<<endl<<"Scheduling the request in the following order : ";
	if(mov == 0)
	{
		for(i=p;i>=0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}					
		}
		for(i=cylinder-1;i>p;i--)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];		
					break;
				}
			}
		}
	}
	else
	{
		for(i=p;i<cylinder;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}
		}
		for(i=0;i<p;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j] == i)
				{
					b[k++] = a[j];
					break;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		sum = sum + abs(b[i+1] - b[i]);
		cout<<b[i]<<" ";
	}
	cout<<b[i]<<endl;
	cout<<"Total Head Movement : "<<sum<<endl<<endl;
	
	return 0;
}
void sort()
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(c[j][0] > c[j+1][0])
			{
				temp = c[j][0];
				c[j][0] = c[j+1][0];
				c[j+1][0] = temp;
				
				temp = c[j][1];
				c[j][1] = c[j+1][1];
				c[j+1][1] = temp;
				
				temp = c[j][2];
				c[j][2] = c[j+1][2];
				c[j+1][2] = temp;
			}
		}
	}
}
