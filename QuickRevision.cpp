                                                                     // Author : Aakash //

= = = = = = = = BIT [binary index tree] = = = = = = = =

|| EXPLANATION ||

x&(-x) gives right most bit 
x-=(x&(-x)) remove right most bit from x

now come to bit array :
bit array stores a partial sum of original array(let we an array 'a')

let we have two index i and j
where j=remove last bit of (i)

bit[] = 0 1 2 3 4 5 6 7 8 9 10 11 12 13
	=>bit[i] = sum of all numbers from index j+1 to i
	
let i=13
then j will be i-(i&(-i)) i.e. j=12
so, bit[13] = sum from index j+1 to i means 13 to 13

j' = remove last bit of j
then j'=j-(j&(-j))=8
so, bit[12] = sum from j'+1 to j means 9 to 12

j" = remove last bit of j'
then j"=j'-(j'&(-j'))=0
so, bit[8] = sum from j"+1 to j' means 1 to 8

.
.
and so on for every i (1<=i<=N)
			
			|| GET SUM ||
			
[Q] how to get sum from l to r of original array  ?

int sum=fun(r)-fun(l);

// this fun gives sum from 1 to i-th index of original array(int a[])
int fun(int i)
{
	int x = 0;
	for(;i>0;i-=i&(-i))
	{
		x+=bit[i]
	}
	return x;
}

			|| CONSTRUCT BIT ARRAY ||

let we have an index i
then add a[i] to bit array 
[Q] how will we do it ?

un sab indexs me a[i] ko add karo jinki last bit hatane par milne vale index ki range me i aaye
i me se i&(-i) minus karo to hame j+1 se i tak ka index milta h
to i me i&(-i) add karenge to hame vo index milega jiski range me i aata h, to ye process hum tab karte jayega jab tak ki i<=N na ho

let i=13 and we want to add a[i] to bit array
then 
k=i+i&(-i) means k=14 

removing last bit of 14 we get 12 means bit[14] store sum from 13 to 14
and this is correct as we have done that k will store i-th sum means i is in the range to k-(k&(-k))

here is code : 
add x or a[i] to i-th position
void update(int i, int x)
{
	for(;i<=N;i+=i&(-i))
	{
		bit[i]+=x;
	}
}

= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

-bit masking

-bridges in tree
-cycle in graph [4]

= = = = = = = = dijkshtra = = = = = = = =

|| BFS ||
  
int vis[100005]={0};
int dis[100005]; // dis[i] is shortest dis from root node to i 
vector<pair<int,int>>v[100005];
int path[100005]; // parent of i is path[i]

void dijkstra(int node)
{
	dis[node]=0; // make dis of root node 0

	multiset<pair<ll,ll>>ms;
	ms.insert({0,node}); // distance, node

	while(!ms.empty())
	{
		pair<ll,ll>p=*ms.begin(); // minimun distance node come forward
		ms.erase(ms.begin());
		ll x=p.second;
		

		if( vis[x]==1 ) continue;
         	vis[x] = 1;

		for(int i=0;i<v[x].size();++i){
			int e = v[x][i].first; 
			ll wt = v[x][i].second;

			if(dis[e]> wt + dis[x]){ // if child node's distance is greater than dis[parent]+edge(between child and parent) then make this distance short, means the updated path for child will be come through its current parent
				dis[e]=wt+dis[x]; // min dis
				path[e]=x;
				ms.insert({dis[e],e});
			}
		}
	}
}





-bellmon
-floyd warshall
-prim
-kruskal
-lca
-binary lifting
-strongly connected graph
-union find

-kmp
-z

-merge sort
-quick sort

-find path in matrix [BFS/DFS]
--island
--string
--longest increasing path
--




