#include <bits/stdc++.h>
using namespace std;

void update(int bit[], int n, int i, int x) // create bit array
{
   for (; i <= n; i += ((i) & (-i)))
   {
      bit[i] += x; //add x in bit[i] $$
   }
   return;
}

int sum(int bit[], int i) // sum of the array from 1 to i
{
   int ans = 0;
   for (; i > 0; i -= ((i) & (-i)))
   {
      ans += (bit[i]);
   }
   return ans;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   int n, q;
   cin >> n >> q;

   
   int bit[n + 1] = {0};
   int a[n+1];
   for(int i=1;i<=n;++i) {
      int x; cin>>x;
      update(bit,n,i,x);
      a[i]=x;
   }

   while (q--)
   {
      int type;
      cin >> type;

      if (type == 2)
      {
         int i, val;
         cin >> i >> val;

         update(bit, n, i, val-a[i]);
         a[i]=val;
      }

      if (type == 1)
      {
         int l,r;
         cin>>l>>r;

         int tot = sum(bit, r) - sum(bit, l - 1);
         cout<<tot<<endl;
         
      }
   }
}