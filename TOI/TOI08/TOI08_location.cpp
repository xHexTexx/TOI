#include<bits/stdc++.h>

using namespace std;

int qs[1001][1001];
int m , n , k , MAX = INT_MIN ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    cin >> m >> n >> k ;
    for(int i = 1 ; i <= m ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> qs[i][j] ;
            qs[i][j] += qs[i][j - 1] + qs[i - 1][j] - qs[i - 1][j - 1] ;
        }
    }

    for(int i = k; i <= m; i ++){
        for(int j = k ; j <= n ; j ++){
            MAX = max(MAX , qs[i][j] - qs[i][j - k] - qs[i - k][j] + qs[i - k][j - k]);
        }
    }
    cout << MAX ;
    return 0 ;
}