#include<iostream>
using namespace std;
//#include<conio.h>
class edge
{       public:
	int v1;
	int v2;
	int w;
};
edge *E;
int v,e;

class node
{
	public:
	int no;
	node *next;
	node()
	{
		next=NULL;

	}
};
node *vlist,**comp;
void input()
{
	cout<<"\n\n\tEnter the no of vertices";
	cin>>v;
	cout<<"\n\n\tEnter the no of edges";
	cin>>e;
	cout<<"\n\n\tenter detail of edeges in format v1 v2 and  w ";
	vlist=new node[v+1];
	for(int i=1;i<=v;i++)
	        vlist[i].no=i;
	E=new edge[e+1];
	for( int i=1;i<=e;i++)
	{
		cout<<"\n\n\tenter edge no"<<i<<"\n";
		cin>>E[i].v1>>E[i].v2>>E[i].w;
	}
}
void create_comp()
{
	comp=new node*[v+1];
	for(int i=1;i<=v;i++)
	{
		comp[i]=&vlist[i];
	}
}
void sort();
void kruskel()
{
	node *h1,*h2;
	create_comp();
	sort();
	for(int i=1;i<=e;i++)
	{
	if(comp[E[i].v1]!=comp[E[i].v2])
	{
	h1=comp[E[i].v1];
	h2=comp[E[i].v2];
	while(h1->next!=NULL)
	h1=h1->next;
	h1->next=h2;
	comp[E[i].v2]=comp[E[i].v1];
	while(h2!=NULL)
	{
	comp[h2->no]=comp[E[i].v1];
	h2=h2->next;
	}
	cout<<"("<<E[i].v1<<","<<E[i].v2<<")\t";
	}
	}
}
void sort()
{
	int j;
	edge temp;
	for(int i=2;i<=e;i++)
	{
	     j=i-1;
	     temp.v1=E[i].v1;
	     temp.v2=E[i].v2;
	     temp.w=E[i].w;
	     while(j>0&&E[j].w>temp.w)
	     {
	       E[j+1].v1=E[j].v1;
	       E[j+1].v2=E[j].v2;
	       E[j+1].w=E[j].w;
	       j--;
	     }


	      E[j+1].v1=temp.v1;
	       E[j+1].v2=temp.v2;
	       E[j+1].w=temp.w;
	}
}


int main()
{
	//clrscr();
	input();
	kruskel();
	//getch();
}

