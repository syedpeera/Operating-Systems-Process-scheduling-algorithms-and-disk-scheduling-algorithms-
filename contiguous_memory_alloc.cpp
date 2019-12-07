//hole_size   p1    p2    p3  ...   
#include<iostream>
int h2,p2,i2,j2,k2,a2[10][10],req2[10],count2=0,flag2=0,index2,minimum2[10],length2,z2; 
int h3,p3,i3,j3,k3,a3[10][10],req3[10],count3=0,flag3=0,index3,maximum3[10],length3,z3;
using namespace std;
void sort2()//ascending order
{
	int temp2,m2,n2;
	for(m2=0;m2<length2;m2++)
	{
		for(n2=0;n2<length2-m2-1;n2++)
		{
			if(minimum2[n2] > minimum2[n2+1])
			{
				temp2 = minimum2[n2];
				minimum2[n2] = minimum2[n2+1];
				minimum2[n2+1] = temp2; 
			}
		}
	}
}
void sort3()
{
	int temp3,m3,n3;
	for(m3=0;m3<length3;m3++)
	{
		for(n3=0;n3<length3-m3-1;n3++)
		{
			if(maximum3[n3] < maximum3[n3+1])
			{
				temp3 = maximum3[n3];
				maximum3[n3] = maximum3[n3+1];
				maximum3[n3+1] = temp3; 
			}
		}
	}
}
int main()
{
	int h1,p1,i1,j1,k1,a1[10][10],req1[10],count1=0,flag1=0,index1;
	cout<<"Enter the number of holes : ";
	cin>>h1;
	h2 = h1;
	h3 = h1;
	cout<<"Enter the size of each hole(KB) : ";
	for(i1=0;i1<h1;i1++)
	{
		cout<<"hole["<<i1<<"] : ";
		cin>>a1[i1][0];
		a2[i1][0] = a1[i1][0]; 
		a3[i1][0] = a1[i1][0];
	}
	cout<<"Enter the number of process : ";
	cin>>p1;
	p2 = p1;
	p3 = p1;
	cout<<"Enter the requirment of each process(KB) : ";
	for(i1=0;i1<p1;i1++)
	{
		cout<<"process["<<i1<<"] : ";
		cin>>req1[i1];
		req2[i1] = req1[i1];
		req3[i1] = req1[i1];
	}
	cout<<"Output : "<<endl;
	j1=0;
	while(count1 != p1)
	{
		flag1 = 0;
		for(i1=0;i1<h1;i1++)
		{
			if(req1[j1] <= a1[i1][j1])
			{
				flag1++;
				a1[i1][j1+1] = a1[i1][j1] - req1[j1];
				index1 = i1+1;
				break;	
			}
			else
			{
				a1[i1][j1+1] = a1[i1][j1];
			}
		}	
		if(flag1 == 0)
		{
			for(k1=0;k1<h1;k1++)
			{
				a1[k1][j1+1] = 0;
			}
			cout<<"Process["<<j1<<"] : is waiting "<<endl;
		}
		if(flag1 != 0)
		{
			for(k1=index1;k1<h1;k1++)
			{
				a1[k1][j1+1] = a1[k1][j1];
			}
		}
		j1++;
		count1++;
	}
	cout<<"hole \t";
	for(i1=0;i1<p1;i1++)
	{
		cout<<"p["<<i1<<"]"<<"\t";
	}
	cout<<endl;
	for(i1=0;i1<h1;i1++)
	{
		for(j1=0;j1<p1+1;j1++)
		{
			cout<<a1[i1][j1]<<"\t";
		}
		cout<<endl;
	}	cout<<"Output : "<<endl;
	j2=0;
	z2=0;
	while(count2 != p2)
	{
		z2=0;
		flag2 = 0;
		for(i2=0;i2<h2;i2++)
		{
			if(req2[j2] <= a2[i2][j2])
			{
				minimum2[z2++] = a2[i2][j2];
				length2=z2;
			}
			else
			{
				a2[i2][j2+1] = a2[i2][j2];
			}
		}	
		sort2();
		for(i2=0;i2<h2;i2++)
		{
			if(minimum2[0] == a2[i2][j2])
			{
				flag2++;
				a2[i2][j2+1] = a2[i2][j2] - req2[j2];
			}
			else
			{
				a2[i2][j2+1] = a2[i2][j2];
			}
		}	
		if(flag2 == 0)
		{
			for(k2=0;k2<h2;k2++)
			{
				a2[k2][j2+1] = 0;
			}
			cout<<"Process["<<j2<<"] : is waiting "<<endl;
		}
		j2++;
		count2++;
	}
	cout<<"hole \t";
	for(i2=0;i2<p2;i2++)
	{
		cout<<"p["<<i2<<"]"<<"\t";
	}
	cout<<endl;
	for(i2=0;i2<h2;i2++)
	{
		for(j2=0;j2<p2+1;j2++)
		{
			cout<<a2[i2][j2]<<"\t";
		}
		cout<<endl;
	}	cout<<"Output : "<<endl;
	j3=0;
	z3=0;
	while(count3 != p3)
	{
		z3=0;
		flag3 = 0;
		for(i3=0;i3<h3;i3++)
		{
			if(req3[j3] <= a3[i3][j3])
			{
				maximum3[z3++] = a3[i3][j3];
				length3=z3;
			}
			else
			{
				a3[i3][j3+1] = a3[i3][j3];
			}
		}	
		sort3();
		for(i3=0;i3<h3;i3++)
		{
			if(maximum3[0] == a3[i3][j3])
			{
				flag3++;
				a3[i3][j3+1] = a3[i3][j3] - req3[j3];
			}
			else
			{
				a3[i3][j3+1] = a3[i3][j3];
			}
		}	
		if(flag3 == 0)
		{
			for(k3=0;k3<h3;k3++)
			{
				a3[k3][j3+1] = 0;
			}
			cout<<"Process["<<j3<<"] : is waiting "<<endl;
		}
		j3++;
		count3++;
	}
	cout<<"hole \t";
	for(i3=0;i3<p3;i3++)
	{
		cout<<"p["<<i3<<"]"<<"\t";
	}
	cout<<endl;
	for(i3=0;i3<h3;i3++)
	{
		for(j3=0;j3<p3+1;j3++)
		{
			cout<<a3[i3][j3]<<"\t";
		}
		cout<<endl;
	}	
	return 0;
}

