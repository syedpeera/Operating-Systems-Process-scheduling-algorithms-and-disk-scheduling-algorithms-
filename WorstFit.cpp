//hole_size   p1    p2    p3  ...  
int h,p,i,j,k,a[10][10],req[10],count=0,flag=0,index,maximum[10],length,z; 
#include<iostream>
using namespace std;
void sort()
{
	int temp,m,n;
	for(m=0;m<length;m++)
	{
		for(n=0;n<length-m-1;n++)
		{
			if(maximum[n] < maximum[n+1])
			{
				temp = maximum[n];
				maximum[n] = maximum[n+1];
				maximum[n+1] = temp; 
			}
		}
	}
}
int main()
{
	cout<<"Enter the number of holes : ";
	cin>>h;
	cout<<"Enter the size of each hole(KB) : ";
	for(i=0;i<h;i++)
	{
		cout<<"hole["<<i<<"] : ";
		cin>>a[i][0];
	}
	cout<<"Enter the number of process : ";
	cin>>p;
	cout<<"Enter the requirment of each process(KB) : ";
	for(i=0;i<p;i++)
	{
		cout<<"process["<<i<<"] : ";
		cin>>req[i];
	}
	cout<<"Output : "<<endl;
	j=0;
	z=0;
	while(count != p)
	{
		z=0;
		flag = 0;
		for(i=0;i<h;i++)
		{
			if(req[j] <= a[i][j])
			{
				maximum[z++] = a[i][j];
				length=z;
			}
			else
			{
				a[i][j+1] = a[i][j];
			}
		}	
		sort();
		for(i=0;i<h;i++)
		{
			if(maximum[0] == a[i][j])
			{
				flag++;
				a[i][j+1] = a[i][j] - req[j];
			}
			else
			{
				a[i][j+1] = a[i][j];
			}
		}	
		if(flag == 0)
		{
			for(k=0;k<h;k++)
			{
				a[k][j+1] = 0;
			}
			cout<<"Process["<<j<<"] : is waiting "<<endl;
		}
		j++;
		count++;
	}
	cout<<"hole \t";
	for(i=0;i<p;i++)
	{
		cout<<"p["<<i<<"]"<<"\t";
	}
	cout<<endl;
	for(i=0;i<h;i++)
	{
		for(j=0;j<p+1;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	return 0;
}
