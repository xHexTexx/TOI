#include<bits/stdc++.h>

using namespace std;

struct path {
    int v , w ;
    bool operator < (const path & rhs)const {
        return rhs.w > w ;
    }
};

vector<path>graph[200001] ;

long long res = 0 ;

bitset<200001>visited ;

priority_queue<path>pq ;

int m , n , x , y , w ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n >> m  ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y >> w ;
        -- w ;
        graph[x].push_back({y , w});
        graph[y].push_back({x , w});
    }

    visited[1] = true ;
    for(auto i : graph[1])pq.push(i);

    while(!pq.empty()){

        auto temp = pq.top() ;
        pq.pop() ;

        if(visited[temp.v])continue ;

        visited[temp.v] = true ;

        res += temp.w ;

        for(auto i : graph[temp.v]){
            pq.push(i) ;
        }
    }

    cout << res ;
    
    return 0 ;
}