#include<bits/stdc++.h>
using namespace std;

int getsum(int bit[], int ind)
{
    int a=0;
    while(ind>0)
    {
        a+=bit[ind];
        ind -= (ind&(-ind)); 
    }
    return a;
}
void update(int bit[], int ind, int n)
{
    while(ind<=n)
    {
        bit[ind]++;
        ind += (ind&(-ind)); 
    }
}
int count_inversions(int a[], int n)
{
	vector<int> temp(n);
	for(int i=0;i<n;i++)
	    temp[i]=a[i];
	sort(temp.begin(),temp.end());
	for(int i=0;i<n;i++)
	{
	    a[i]=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin()+1;
	}
	int bit[n+1];
	for(int i=0;i<n+1;i++)
	    bit[i]=0;
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
	    ans+= getsum(bit,a[i]-1);
	    update(bit,a[i],n);
	}
	return ans;
}
	