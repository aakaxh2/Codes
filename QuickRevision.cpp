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




= = = = = = = = cycle detection in graph = = = = = = = =
	=> undirected graph
	=> directed graph

=> Code : undirected graph

bool dfs(vector<int>v[], int vis[], int x, int pr)
{
	/* 
	vis[x]=1 means dfs is not finished yet for node x 
	mtlb abhi bhi x ke children aur unke children ke children aur .... pe abhi bhi dfs chal rha hai recursively
	aur hum gum ke vapas x pe aaye h mtlb x ke niche kisi node se ek aur path se hum x tak pahuch rahe h iska mtlb yaha loop hai
	*/
	if(vis[x]==1) return true; 
	
	// ye node pura ho chaka hai
	if(vis[x]==2) return false;

	vis[x]=1;
	for(int i=0;i<v[x].size();++i)
	{
	    int child=v[x][i];
	    if(child==pr) continue;

	    if(dfs(v,vis,child,x)) return true;
	}
	
	/*
	vis[x]=2 mtlb node x ke under jite bhi children aur unke aage aur children the un sab pe hum visit karke aa gye h 
	aur hame koi loop ni mila h 
	aur ab yaha se niklte hi x pe dfs khatam ho jayega
	*/
	vis[x]=2;
	return false;
}


int n,m;
cin>>n>>m;

for(int i=1;i<=m;++i) {
	int x,y;
	cin>>x>>y;
	v[x].pb(y);
	v[y].pb(x);
}


int vis[n+2];
memset(vis, 0, sizeof(vis));

for(int i=0;i<n;++i)
{
    if(vis[i]==0 && dfs(v,vis,i,-1))
    {
	cout<<"there is cycle";
    }
}
cout<<"there is no cycle";


=> Code : directed graph

bool dfs(vector<int>v[], int vis[], int x, int pr)
{
	/* 
	vis[x]=1 means dfs is not finished yet for node x 
	mtlb abhi bhi x ke children aur unke children ke children aur .... pe abhi bhi dfs chal rha hai recursively
	aur hum gum ke vapas x pe aaye h mtlb x ke niche kisi node se ek aur path se hum x tak pahuch rahe h iska mtlb yaha loop hai
	*/
	if(vis[x]==1) return true; 
	
	// ye node pura ho chaka hai
	if(vis[x]==2) return false;

	vis[x]=1;
	for(int i=0;i<v[x].size();++i)
	{
	    int child=v[x][i];
		
	    /*
		if(child==pr) continue; 
		this line is diffrent from undirected graph
		because there can be edge from x->y ans y->x
		or x->x
		so we will skip this part x->y and y->x, i.e. there is a cycle in x and y
		there is no need to keep parent node with x
	    */

	    if(dfs(v,vis,child,x)) return true;
	}
	
	/*
	vis[x]=2 mtlb node x ke under jite bhi children aur unke aage aur children the un sab pe hum visit karke aa gye h 
	aur hame koi loop ni mila h 
	aur ab yaha se niklte hi x pe dfs khatam ho jayega
	*/
	vis[x]=2;
	return false;
}


int n,m;
cin>>n>>m;

for(int i=1;i<=m;++i) {
	int x,y;
	cin>>x>>y;
	v[x].pb(y);
	v[y].pb(x);
}


int vis[n+2];
memset(vis, 0, sizeof(vis));

for(int i=0;i<n;++i)
{
    if(vis[i]==0 && dfs(v,vis,i,-1))
    {
	cout<<"there is cycle";
    }
}
cout<<"there is no cycle";


= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =



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


= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =



-bellmon



= = = = = = = = floyd warshall = = = = = = = =
	
|| EXPLANATION ||
	
this algo works correctly in both directed and undirected graph
time complexity : o(n^3)
/*
        
        after including k-th node
        
        case 1 : 
        new distance means we are considering that path from node i to node j will be passed through node k and distance will be = dis[i][k]+dis[k][j]
        
        case 2 :
        old distance will be remain same as minimum between node i and node j 
        means inlcuding 1 to k-1 nodes we get shortest distance between node i and node j is  = dis[i][j]
        and the new node (node k) will not affect min distance between i and j
        
        Equation for both the cases is : dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
        
*/

	
/*
        
        basic idea behind the algorithm is : 
        
        at current time we are at k-th level
        then the nodes in the shortest path between any node i and j (1<=i,j<=n) have values 1 to k-1
        means shortest path is becoming considereing node 1 to k-1
        
        after k-th level 
        shortest path will become considereing node 1 to k
        
        and so on...
        
*/
	
Code : 
int N=505, INF=1e12;
int dis[N][N];

// initialise with infinide distance
for(int i=0;i<N;++i)
{
    for(int j=0;j<N;++j)
    {
	if(i==j) dis[i][j]=0;
	else dis[i][j]=INF;
    }
}

// n nodes and m edges
int n,m;
cin>>n>>m;

// node are 1 based index i.e. 1,2,3, ... n
for(int i=0;i<m;++i)
{
    // weight of edge between node x and node y
    int x,y,wt;
    cin>>x>>y>>wt;

    dis[x][y]=wt;
}

for(int k=1;k<=n;++k)
{
    for(int i=1;i<=n;++i)
    {
	for(int j=1;j<=n;++j)
	{
	    if(dis[i][k]!=INF && dis[k][j]!=INF)
		dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
	}
    }
}

// dis[i][j] = min distance between node i and node j
for(int i=1;i<=n;++i)
{
    for(int j=1;j<=n;++j) 
    if(dis[i][j]==INF) cout<<"I "; else cout<<dis[i][j]<<" ";
    cout<<endl;
} 


= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
	
	



	
= = = = = = = = prim = = = = = = = =
	
Code :

int n;
cin>>n;

for(int i=0;i<n;++i) 
{
	int x,y,wt;
	cin>>x>>y>>wt;
	v[x].pb({y,wt});
	v[y].pb({x,wt});
}

int vis[n+2];
memset(vis,0,sizeof(vis));
multiset<pair<int,int>>ms;
ms.insert({0,0}); // dis, node


/*
currently we have many edges in this graph
we have to pick n-1 edges such that total weight is min and all nodes are connected 
i.e. final graph will be a tree with n-1 edges and n nodes
*/

int cost=0;
while(ms.size())
{
    /*
    gives lowest weighted edge 
    */
    pair<int,int>p=*ms.begin();
    ms.erase(ms.begin());

    
    /*
    current edge detail :
    edge weight = p.first
    node one = p.second
    another node is the parent of x 
    
    so parent of x is already taken part in new graph
    and if x is also taken part in new graph then just skip this edge
    else go furthure...
    */
	
    int x=p.second;
    if(vis[x]) continue;
    vis[x]=1;
    

    cost+=p.first;

    for(int i=0;i<v[x].size();++i)
    {
	int child=v[x][i].first;
	if(vis[child]==0) {
	    ms.insert({v[x][i].second,child});
	}
    }
}

cout<<cost<<endl;


= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =






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




