//  bfs
vector<int> bfs(int v,vector<vector<int>> graph){
	vector<int> ans;
	vector<int> vis(v+1,-1);

	for(int i=1;i<=v;i++){
		if(vis[i]==-1){
			queue<int> q;
			q.push(i);
			vis[i]=1;
			while(!q.empty()){
				int node=q.front();
				q.pop();
				ans.push_back(node);
				for(auto it:graph[node]){
					if(vis[it]==-1){
						q.push(it);
						vis[it]=1;
					}
				}
			}
		}
	}
}

void dfs(int node,vector<vector<int>> &graph,vector<int> &storedfs,vector<int> &vis){
	storedfs.push_back(node);
	vis[node]=1;
	for(auto it:graph[node]){
		if(vis[it]==-1){
			dfs(it,graph,storedfs,vis);
		}
	}

}

// cycle Detection

bool cyclebfs(int v,vector<vector<int>> graph){
 vector<int>  vis(v+1,0);

 for(int i=1;i<=v;i++){
 	if(!vis[i]){
 		queue<pair<int,int>> q;
 		q.push({i,-1});
 		vis[i]==1;
 		while(!q.empty()){
         int node=q.front().first;
         int par=q.front().second;
         q.pop();

 		for(auto it:graph[node]){
 			if(!vis[it]){
 				q.push({it,node});
 				vis[it]=1;
 			}else if(it!=par){
 				return true;
 			}
 		}
 	}
 	}
 }

 return false;
}

bool cycledfs(int node,int par){
	vis[node]=1;
	for(auto it:graph[node]){
		if(!vis[it]){
			if(cycledfs(it,node))
				return true;
		}else if(it!=par){
			return true;
		}
	}
	return false;
}

// bipartite
bool checkbipartite(int node){
	if(color[node]==-1) color[node]=1;

	for(auto it:graph[node]){
		if(color[it]==-1){
			color[it]=1-color[node];
			if(!bipartite(it))return false;
		}else if(color[it]==color[node])
		       return false;
	}
	return true;
}

// using bfs
 bool check(int node){
 	queue<int> q;
 	q.push(node);
 	color[node]=1;
 	while(!q.empty()){
 		int nod=q.front();
 		q.pop();
 		for(auto it:graph[nod]){
         if(color[it]==-1){
         	color[it]=1-color[nod];
         	q.push(it);
         }else if(color[it]==color[nod])
               return false;
 		}
 	}

 	return true;
 }


// cycle in directed

 void check(int node){
 	vis[node]=1;
 	dfsvis[node]=1;

 	for(auto it:graph[node]){
 		if(!vis[it]){
 			if(check[it])
 				return true;
 		}else if(dfsvis[it])
 		      return true;
 	}

 	dfsvis[node]=0;
 	return false;
 }

 // topo sort

 void dfs(int node)
 {
 	vis[node]=1;
 	for(auto it:graph[node]){
 		if(!vis[it]){
 			dfs(it);
 		}
 	}

 	st.push(node);
 }

 vector<int> topo;
 while(!st.empty()){
 	topo.push_back(st.top());
 	st.pop();
 }


 ////topo sort using bfs kahn's algorithm

vector<int> bfs(int v)
{
	queue<int> q;
	vector<int> indeg(v,0);
	vector<int> topo;

	for(int i=0;i<v;i++){
		for(auto it:graph[i]){
			indeg[it]++;
		}
	}

	for(int i=0;i<v;i++){
		if(indeg[i]==0)
			q.push(i);
	}

	while(!q.empty()){
		int node=q.front();
		q.pop();
        topo.push_back(node);
		for(auto it:graph[node]){
			indeg[it]--;
			if(indeg[it]==0)
				q.push(it);
		}
	}

	return topo;
}

///shortest path in undirected

void bfs(int src,int n){
	int dis[n];
	for(int i=0;i<n;i++)
		dis[i]=INT_MAX;

	dis[src]=0;


	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto it:graph[node]){
			if(dis[node]+1<dis[it]){
				dis[it]=dis[node]+1;
				q.push(it);
			}
		}
	}
}

// shortest path in weighted DAG

// first we find the topo as element before src in topo cant be reached;

void bfs(int src){
	vector<int> vis(n,0);
	stack<int> st;

	for(int i=0;i<n;i++){
		if(!vis[i])
			findtopo(i,st);
	}

	int dis[n];
	for(int i=0;i<n;i++)
		dis[i]=INT_MAX;
	dis[src]=0;

	while(!st.empty()){
		int node=st.top();
		 st.pop();
		 if(dis[node]!=INT_MAX){
		 	for(auto it:graph[node]){
		 		if(dis[node]+it.second<dis[it.first])
		 		{
		 			dis[it.first]=dis[node]+dis[it.second];
		 		}
		 	}
		 }
	}
}

///shortest in weighted undirecteed      dijkstra 

void bfs(int src){
	vector<int> dis(n,INT_MAX);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dis[src]=0;
	pq.push({0,src});
	while(!pq.empty()){
		int node=pq.front().second;
         pq.pop();
		for(auto it:graph[node]){
			if(dis[node]+it.second<dis[it.first]){
				dis[it.first]=dis[node]+it.second;
				pq.push({dis[it.first],it.first});
			}
		}
	}
}

/////MST Prims

void prim(){
 int par[n];
 int key[n];
 bool mst[n];
 for(int i=0;i<n;i++)
  par[i]=-1,key[i]=INT_MAX,mst[i]=false;
 
 key[0]=0;

 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
 pq.push({0,0});

 for(int i=0;i<n;i++){
 	int node=pq.front().second;
 	pq.pop();
 	mst[node]=true;
 	for(auto it:graph[node]){
 		if(mst[it]==false&&key[it.first]>it.second)
 		{
 			par[it.first]=node;
 			key[it.first]=it.second;
 			pq.push({key[it.first],it.first});
 		}
 	}
 }
}

////kruskal algorithm
int parent[n]; //={-1};
int rank[n];  //={0};

struct node{
	int u;
	int v;
	int wt;
	node(int a,int b,int c){
		u=a;
		v=b;
		wt=c;
	}
}

bool comp(node a,node b){
	return a.wt<b.wt;
}

int findparent(int u){
	if(u==parent[u]) return u;

	return parent[u];
}

void union(int u,int v){
	u=findparent(u);
	v=findparent(v);

	if(rank[u]<rank[v]){
		parent[u]=v;
		
	}
	else if(rank[u]>rank[v])
		parent[v]=u;
	else{
		parent[v]=u;
		rank[u]++;
	}
}

void krskal(){
	vector<node> edges;
	for(int i=0;i<n;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		edges.push_back(node(u,v,wt));
	}

	sort(edges.begin(),edges.end(),comp);

	int cost=0;
	vector<pair<int,int>> mst;
	for(auto it:edges){
		if(findparent(it.u)!=findparent(it.v)){
			cost+=it.wt;
			mst.push_back({u,v});
			union(it.u,it.v);
		}
	}

	cout<<cost;
    for(auto it:mst){
    	cout<<it.first<<"-"<<it.second<<endl;
    }
}

// //// kosaraju  (strongly connected components)
void revdfs(int node,vector<int> arr[],vector<int> &vis){
	cout<<node<<" ";
	vis[node]=1;
	for(auto it:arr[node]){
		if(!vis[it]){
			revdfs(it,arr,vis);
		}
	}
}
int main()
{
 int n,e;
 cin>>n>>e;
 vector<int> arr[n];
 for(int i=0;i<e;i++){
   int u,v;
   cin>>u>>v;
   arr[u].push_back(v);
 }

 stack<int> st;
 vector<int> vis(n,0);
 for(int i=0;i<n;i++){
 	if(!vis[i]){
 		topo(i,st,arr,vis);
 	}
 }
 
 vector<int> taranspose[n];
 for(int i=0,i<n;i++){
 	vis[i]=0;
 	for(auto it:arr[i]){
 		taranspose[it].push_back(i);
 	}
 }

 while(!st.empty()){
 	int node=st.top();
 	st.pop();
 	if(!vis[node]){
 		cout<<"SCC ";
 		revdfs(node,taranspose,vis);
 		cout<<endl;
 	}
 }
 return 0;

}

//////bellman ford
int main(){
	int n;
	int e;
	cin>>n>>e;
	vector<node> edges;
	for(int i=0;i<e;i++){
		int u,v,wt;
		edges.push_back({u,v,wt});
	}

	vector<int> dis(n,INT_MAX);
	dis[0]=0;

	for(int i=1;i<=n-1;i++){
		for(auto it:edges){
			if(dis[it.u]+it.wt<dis[it.v])
				dis[it.v]=dis[it.u]+it.wt;
		}
	}
        int fl=0;
	for(auto it: edges){
		if(dis[it.u]+it.wt<dis[it.v]){
			fl=1;
			break;
		}
	}

	if(fl){
		cout<<"negative cycle"<<endl;
	}
	else{
		for(auto it:dis){
			cout<<it<<" ";
		}
	}
}

///// bridges in graph
int timer=0;
 void dfs(int node,int parent,vector<int> &tin,vector<int> &low){
    vis[node]=1;
    tin[node]=low[node]=timer++;

    for(auto it:graph[node]){
    	if(it==parent) continue;

    	if(!vis[i]){
    		dfs(it,node,tin,low);
    		low[node]=min(low[node],low[it]);
    		if(low[it]>tin[node]){
    			cout<<node<<"-"<<it<<endl;
    		}
    	}
    		else{
    			low[node]=min(low[node],tin[it]);
    		}
    	
    }
 }

 ////articulation point
 void dfs(int node,int parent,vector<int> &isarticulation){
 	vis[node]=1;
 	tin[node]=low[node]=timer++;
 	int child=0;
 	for(auto it:graph){
 		if(it===parent) continue;

 		if(!vis[it]){
 			dfs(it,node,isarticulation);
 			low[node]=min(low[node],low[it]);
 			if(low[it]>=tin[node]&&parent!=-1){
 				isarticulation[node]=1;
 			}
 			child++;
 		}
 		else{
 			low[node]=min(low[node],tin[it]);
 		}
 	}

 	if(parent==-1&&child>1)
 		isarticulation[node]=1; 
 }