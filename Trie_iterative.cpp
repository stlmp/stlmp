#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//To determine that the string is prefix of how many string

struct t{
   t* character[26];
   int count; // how many strings have passed by me
    
    t()
    {
        for(int i=0;i<26;i++)
        {
            character[i]=NULL;
            count=0;
        }
        
    }
    
};


int main() {
    ios_base::sync_with_stdio(false);
    int n,q,i;
    cin>>n>>q;
    t* root = new t();
    t* temp = new t();
   string k;
    while(n--)
    {
        temp=root;
        cin>>k;
        for(i=0;i<k.length();i++)
        {
            if(temp->character[k[i]-'a']==NULL )
               temp->character[k[i]-'a'] = new t();
            
            temp=temp->character[k[i]-'a'];
            temp->count++;
                
            
        }
        
     
        
    }
    int c;
    
    while(q--)
    {
        temp=root;
        cin>>k;
        for(i=0;i<k.length();i++)
        {
            if(temp->character[k[i]-'a']!=NULL)
            {
            
                temp=temp->character[k[i]-'a'];
            }
            else 
                break;
            
        }
        if(i==k.length())
        {
            c=temp->count;
            
        }
        cout<<c<<"\n";
        
    }
    
    
    return 0;
}
