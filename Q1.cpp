#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
 
vector<int>v;
void update(int n, int idx, int val)
{
    v[idx+n]=val; // update value at index idx, original index of idx in the vector is n+idx
    
    for(int i=(n+idx)/2;i>=1;i/=2) {
        v[i]=v[2*i]+v[(2*i)+1]; // update all the ranges in which this index'x sum is added.
    }
}
 
 
int fun(int l, int r, int left, int right, int cr)
{
	if(r<left || l>right) return 0; // if current query if out of range from query range, then simple return 0, because we don't neet that range sum.
	if(left<=l && r<=right) return v[cr]; // if current range in query range then return the sum of current range
 
	int mid=(l+r)/2;
	return fun(l,mid,left,right,2*cr)+fun(mid+1,r,left,right,2*cr+1); // split current range into left part and right part; left part contains range [i,mid], and right part contains range [mid+1,r]
}
 
 
signed main()
{
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w", stdout);
	#endif

    
	int n,q,n1;
	cin>>n>>q;
	n1=n;
 
	//  make n in the form of 2^x
	while(__builtin_popcount(n)!=1)
	{
		n++;
	}
	v.resize(2*n);
 
   // array values are store from index n to 2n-1
	for(int i=0;i<n1;++i) {
		cin>>v[i+n];
	}

   // from index 1 to n-1, every index i store sum/min in range of 2i to 2i+1
	for(int i=n-1;i>=1;i--)
	{
		v[i]=v[2*i]+v[2*i+1];
	}
 
	while(q--)
	{
	    int type;
	    cin>>type;
	    if(type==1)
	    {
	        int idx,val;
	        cin>>idx>>val;
	        idx--;
	        
	        update(n,idx,val);
	    }
	    else {
    		int l,r;
    		cin>>l>>r;
            l--,r--;
    		cout<<fun(0,n-1,l,r,1)<<endl;
	    }
	}
	return 0;
}