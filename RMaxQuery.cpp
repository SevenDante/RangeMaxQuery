#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll power(ll x,ll y)
{
 ll res=1;
 while(y>0)
   {

      if(y&1)
       {
           res=res*x;
       }
       y=y>>1;
       x=x*x;

   }
   return res;

}


ll input[100010],segtree[100010]={-99999999};

ll rangemax(ll qlow,ll qhigh,ll low,ll high,ll pos)  //position is root
{

  if(qlow <= low && high <=qhigh)  //total overlap
       return segtree[pos];

   
  if(qlow > high || qhigh < low ) //no overlap
      return -99999999;               //return very low number

    ll mid=(low+high)/2;

    return max( rangemax(qlow,qhigh,low,mid,2*pos+1),rangemax(qlow,qhigh,mid+1,high,2*pos+2));

}



void buildtree(ll low,ll high,ll pos)
{
   if(low==high) { segtree[pos]=input[low]; return;  }
   
    ll mid=(low+high)/2;

   buildtree(low,mid,2*pos+1);
   buildtree(mid+1,high,2*pos+2);
  
    segtree[pos]=max( segtree[2*pos+1],segtree[2*pos+2]);

}





int main()
{
    ll n;
    cin>>n;
    
    for(ll i=0;i<n;i++)
      cin>>input[i];
      
      
      buildtree(0,n-1,0);
      
      ll q;
      cin>>q;
      while(q--)
      {
          ll l,h;
          cin>>l>>h;
          l--; h--;    //Zero based index
          
          cout<<rangemax(l,h,0,n-1,0)<<endl;
          
      }
    
    return 0;
}
