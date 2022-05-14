#include<bits/stdc++.h>

using namespace std;

int dp[20][20001] ;

int m , n , k , p ;

struct coor {
    int x , y ;
};

int cal(coor a , coor b){
    return abs(a.x - b.x) + abs(a.y - b.y) ;
}

coor warp[20001] ;
coor out[20001] ;

int pre[20001][20001] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> m >> n >> k >> p; 

    for(int i = 0 ; i < k ; i ++ ){
        cin >> warp[i].x >> warp[i].y >> out[i].x >> out[i].y ;
    }

    warp[k].x = m , warp[k].y = n ;

    for(int i = 0 ; i < k ; i ++ ){
        for(int j = 0 ; j <= k ; j ++ ){
            if(i == j)continue ;
            pre[i][j] = cal(out[i] , warp[j]);
        }
    }

    for(int i = 1 ; i <= p ; i ++ ){
        for(int j = 0 ; j <= k ; j ++ ){
            dp[i][j] = INT_MAX ;
        }
    }

    for(int i = 0 ; i <= p ; i ++ ){

        if(i == 0){
            for(int j = 0 ; j < k ; j ++ ){
                dp[0][j] = cal({1 , 1} , out[j]) ;
            }
            dp[0][k] = cal({1 , 1} , {m , n}) ;
        }
        else if(i == 1){
            for(int j = 0 ; j < k ; j ++ ){
                dp[1][j] = cal({1 , 1} , warp[j]) ;
                dp[1][k] = min(dp[1][k] , cal(out[j] , {m , n}) + dp[1][j]) ;
            }
        }
        else {
            for(int j = 0 ; j < k ; j ++ ){
                
                for(int l = 0 ; l < k ; l ++ ){
                    if(j == l)continue ;
                    dp[i][l] = min(dp[i][l] , dp[i - 1][j] + pre[j][l] ) ;
                    dp[i][k] = min(dp[i][k] , dp[i][l] + pre[l][k]) ;
                }
            }
        }
    }

    int MIN = INT_MAX ;
    int MIN_P = INT_MAX ;
    for(int i = 0 ; i <= p ; i ++ ){
        if(dp[i][k] < MIN){
            MIN = dp[i][k] ;
            MIN_P = i ;
        }
    }

    cout << MIN << ' ' << MIN_P;
    return 0 ;
}