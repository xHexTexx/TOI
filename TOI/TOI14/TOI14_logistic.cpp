#include<bits/stdc++.h>
#define endll '\n'
#define vec vector
#define umap unordered_map
using namespace std;
struct path{
	int cost , fuel , u , free ;
	bool operator <(const path & p2)const {
		return p2.cost < cost ;
	}
};
struct edge {
	int v , w ;
};
bool visited[101][101][2] ;
int main(){
	ios_base :: sync_with_stdio(0),cin.tie(0);
	int n , str , stp , fullfuel , m ; cin >> n;
	
	vec<int>fuelcost(n + 1 , 0);for(int i = 1 ; i <= n ; i++ )cin >> fuelcost[i] ;
	vec<vec<edge>>graph(n + 1);
	
	cin >> str >> stp >> fullfuel ;
	cin >> m ;
	while(m -- ){
		int U  , V , W ; cin >> U >> V >> W ;
		graph[U].push_back({V , W});
		graph[V].push_back({U , W});
	}
	
	priority_queue<path>pq ; 
	pq.push({0 , 0 , str , 1});
	
	while(!pq.empty()){
		auto temp = pq.top();
		pq.pop();
		
		if(temp.u == stp && temp.fuel == fullfuel){
			cout << temp.cost ;
			return 0;
		}
		
		if(visited[temp.u][temp.fuel][temp.free])continue ;
		visited[temp.u][temp.fuel][temp.free] = true ;
		
		if(temp.free){
			pq.push({temp.cost , fullfuel , temp.u , 0});
		}
		if(temp.fuel < fullfuel){
			pq.push({temp.cost + fuelcost[temp.u] , temp.fuel + 1 , temp.u , temp.free });
		}
		for(auto i : graph[temp.u]){
			if(temp.fuel < i.w)continue ;
			pq.push({temp.cost , temp.fuel - i.w , i.v , temp.free});
		}
	}
	return 0;
}

