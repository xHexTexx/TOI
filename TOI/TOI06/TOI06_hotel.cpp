#include<bits/stdc++.h>

using namespace std;

map<int , int>mpp ;
int arr[] = {1 , 2 , 5 , 15} ;

int solve(int n){
    if(n == 0)return 0 ;
    if(mpp[n])return mpp[n] ;
    int MIN = INT_MAX ;
    for(int i = 0 ; i < 4 ; i ++ ){
        MIN = min(MIN , solve( max(0 , n - arr[i]) ) + mpp[arr[i]]);
    }
    mpp[n] = MIN ;
    return mpp[n] ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    mpp[1] = 500 ;
    mpp[2] = 800 ;
    mpp[5] = 1500 ;
    mpp[15] = 3000 ;
    int n ; cin >> n ; 
    cout << solve(n) ;

    return 0 ;
}