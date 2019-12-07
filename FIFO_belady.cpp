//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1 
//input reference string
#include<iostream>
using namespace std;
void sort();
int ref[30],n,r,i,j,p,q,flag;
int page_fault = 0,page_hit=0;
int F[30][2],t,k=0,flag1=0,z,arr[100],s=0,temp5,b;
int main()
{
	cin>>t;
	temp5=t;
	while(t--)
	{
		//cout<<"Enter the number of frames : ";
	//cin>>n;
		n=2;
		n++;
	for(i=0;i<n;i++)
	{
		F[i][0] = -1;//frames
		F[i][1] = i+1;
	}
	cout<<"Enter the number of reference strings : ";
	cin>>r;
	cout<<"Enter "<<r<<" reference strings : ";
	for(i=0;i<r;i++)
	{
		cin>>ref[i];//reference strings
	}
	for(i=0;i<r;i++)
	{	
		flag=0;
		flag1=0;
		for(j=0;j<n;j++)
		{
			if(F[j][0] == -1)
			{
				flag1++;
				F[j][0] = ref[i];
				page_fault++;
				break;
			}	
			else if(F[j][0] == ref[i])
			{
				flag++;
				page_hit++;
				break;
			}
		}
		if(flag == 0 && flag1 == 0)
		{
			F[0][0] = ref[i];
			F[0][1] = n;
			for(k=1;k<n;k++)
			{
				F[k][1] = F[k][1] - 1;
			}
			page_fault++;
			sort();
		}
		cout<<endl;
		for(z=0;z<n;z++)
		{
			cout<<F[z][0];
		}
		cout<<endl;
	}
	cout<<"The number of page hits : "<<page_hit<<endl;
	cout<<"The number of page faults : "<<page_fault<<endl;
	arr[s++] = page_fault;
	}
	n=3;
	t=temp5;
	for(b=0;b<t;b++)
	{
		cout<<"For "<<n<<" frames the page faults are : "<<arr[b]<<"  "<<endl;
		n++;
	}
	return 0;
}
void sort()
{
	int temp;
	for(p=0;p<n;p++)
	{
		for(q=0;q<n-p-1;q++)
		{
			if(F[q][1] > F[q+1][1])
			{
				temp = F[q][0];
				F[q][0] = F[q+1][0];
				F[q+1][0] = temp;
				
				temp = F[q][1];
				F[q][1] = F[q+1][1];
				F[q+1][1] = temp;
			}
		}
	}
}

