//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1 
//input reference string
#include<iostream>
using namespace std;
void sort();
void sort2();
int ref[30],n,r,i,j,p,q,flag;
int page_fault = 0,page_hit=0;
int F[30][4],k=0,flag1=0,z,g,h,d,t,y,e,temp2,u,c,v;
int index; 
int main()
{
	cout<<"Enter the number of frames : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		F[i][0] = -1;//frames
		F[i][1] = i+1;
		F[i][2] = 0;
		F[i][3] = i+1;//FIFO order
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
			int Flag=0,final_flag=0;
			index = i;
			for(g=0;g<n;g++)
			{
				Flag=0;
				for(h=index;h<r;h++)
				{
					if(F[g][0] == ref[h])
					{
						Flag++;
						F[g][1] = h;
						break;
					}
				}
				if(Flag == 0)
				{
					final_flag++;
					F[g][2] = 1;//if the element is not found in the future
				}
			}
			if(final_flag == 0)
			{
				page_fault++;
				sort();
				F[0][0] = ref[i];
				temp2 = F[0][3];
				for(u=0;u<n;u++)
				{
					if(F[u][3] > temp2)
					{
						F[u][3] = F[u][3] - 1;
					}
				}
				F[0][3] = n;
				for(d=0;d<n;d++)
				{
					F[d][1] = 0;
					F[d][2] = 0;
				}
			}
			else
			{
				sort2();
				for(e=0;e<n;e++)
				{
					if(F[e][2] == 1) 
					{
						page_fault++;
						F[e][0] = ref[i];
						F[e][2] = 0;
						temp2 = F[e][3];
						for(u=0;u<n;u++)
						{
							if(F[u][3] > temp2)
							{
								F[u][3] = F[u][3] - 1;
							}
						}
						F[e][3] = n;
						break;
					}
				}
			}
		}
		cout<<endl;
		for(z=0;z<n;z++)
		{
			cout<<F[z][0];
		}
		cout<<endl;
		for(d=0;d<n;d++)
		{
			F[d][1] = 0;
			F[d][2] = 0;
		}
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
			if(F[q][1] < F[q+1][1])
			{
				temp = F[q][0];
				F[q][0] = F[q+1][0];
				F[q+1][0] = temp;
				
				temp = F[q][1];
				F[q][1] = F[q+1][1];
				F[q+1][1] = temp;
				
				temp = F[q][2];
				F[q][2] = F[q+1][2];
				F[q+1][2] = temp;
				
				temp = F[q][3];
				F[q][3] = F[q+1][3];
				F[q+1][3] = temp;
			}
		}
	}
}
void sort2()
{
	int temp;
	for(c=0;c<n;c++)
	{
		for(v=0;v<n-c-1;v++)
		{
			if(F[v][3] > F[v+1][3])
			{
				temp = F[v][0];
				F[v][0] = F[v+1][0];
				F[v+1][0] = temp;
				
				temp = F[v][1];
				F[v][1] = F[v+1][1];
				F[v+1][1] = temp;
				
				temp = F[v][2];
				F[v][2] = F[v+1][2];
				F[v+1][2] = temp;
				
				temp = F[v][3];
				F[v][3] = F[v+1][3];
				F[v+1][3] = temp;
			}
		}
	}
}
