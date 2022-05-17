#include<bits/stdc++.h>

using namespace std ;

struct act {
    int idx , type , idx_book ;
    bool operator < (const act & rhs)const { 
        if(idx != rhs.idx) return idx < rhs.idx ;
        return type < rhs.type ;
    }
};

bitset<500001>visited ;
vector<act>vec ;
    
int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    int n , k , q , l , r , cnt = 0; cin >> n >> k >> q ;
    
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> l >> r ;
        vec.push_back({l , 1 , i}) ;
        vec.push_back({r + 1 , 0 , i}) ;
    }

    sort(vec.begin(), vec.end());

    for(auto temp : vec){
        if(temp.type){
            if(cnt < k){
                cnt ++ ;
                visited[temp.idx_book] = true ;
            }
        }
        else {
            if(visited[temp.idx_book])cnt -- ;
        }
    }
    
    while(q -- ){
        int idx ; cin >> idx ;
        (visited[idx]) ? cout << "Y " : cout << "N " ;
    }
    return 0 ;
}