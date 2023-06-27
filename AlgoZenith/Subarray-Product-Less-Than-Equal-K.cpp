#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       ll n,k;
       cin>>n>>k;
       ll arr[n];
       for(int i=0;i<n;i++)cin>>arr[i];
       if(k==0)
       {
       	cout<<"0\n";
       	continue;
       }
       ll p = 1;
       ll start = 0;
       ll ans = 0;
       ll i = 0;
       ll prevZero = 0;
       while(i<n){
           if(arr[i]==0){
               ans+=(i-prevZero+1)*(n-i);
               i++;
               start = i;
               prevZero = i;
               p = 1;
               continue;
           }
           while(start<i and ((p>k/arr[i]) or (p*arr[i]>=k)))
               p/=arr[start],start++;
           p*=arr[i];
           if(p>=k)
               p/=arr[i],start++;
           ans+=i-start+1;
           i++;
       }
       cout<<ans<<"\n";
   }
}
