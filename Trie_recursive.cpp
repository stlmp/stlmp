#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct t{
   t* character[26];
    bool last_node;
    
    t()
    {
        for(int i=0;i<26;i++)
        character[i]=NULL;
        last_node=false;
        
    }
    
};

 int count(t* temp) //to count the 
 {
     int c=0;
   
     if(temp->last_node==true)
         c+=1;
     
     for(int i=0;i<26;i++)
     {
         if(temp->character[i]!=NULL)
         {
             c=c+count(temp->character[i]);
         }
         
     }
     
     return c;
     
 }

int main() {
    ios_base::sync_with_stdio(false);
    int n,q,i;
    cin>>n>>q;
    t* root = new t();
    t* temp = new t();
   string k;
    while(n--)  // take n strings as an input
    {
        temp=root;
        cin>>k;
        for(i=0;i<k.length();i++)
        {
            if(temp->character[k[i]-'a']==NULL )
               temp->character[k[i]-'a'] = new t();
            temp=temp->character[k[i]-'a'];
            if(i==k.length()-1)
                temp->last_node=true;
            
        }
        
     
        
    }
    int c;
    
    while(q--)  //for each query determine it is prefix of how  many strigs
    {
        temp=root;
        c=0;
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
        if(i==k.length()) //if query string matches the string
        {
            c=count(temp);
            
        }
        cout<<c<<"\n";
        
    }
    
    
    return 0;
}
