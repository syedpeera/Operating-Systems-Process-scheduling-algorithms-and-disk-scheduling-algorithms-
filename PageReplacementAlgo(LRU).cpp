//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1 
//input reference string
#include<iostream>
using namespace std;
void sort();
int ref[30],n,r,i,j,p,q,flag;
int page_fault = 0,page_hit=0;
int F[30][2],k=0,flag1=0,z,g,h,d;
int index; //this is for checking the least recently used one
int main()
{
	cout<<"Enter the number of frames : ";
	cin>>n;
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
			index = i;
			for(g=0;g<n;g++)
			{
				for(h=0;h<index;h++)
				{
					if(F[g][0] == ref[h])
					{
						F[g][1] = h;
					}
				}
			}
			page_fault++;
			sort();
			F[0][0] = ref[i];
			for(d=0;d<n;d++)
			{
				F[d][1] = 0;
			}
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
