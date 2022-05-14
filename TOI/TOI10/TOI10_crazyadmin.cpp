#include<bits/stdc++.h>

using namespace std;

int l , r , mid , t , n , cnt , sum ;
int arr[101] , MAX = 0 ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> t >> n ;
    
    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
        MAX = max(MAX , arr[i]) ;
    }


    l = MAX , r = 150000 ;

    while(l < r){

        cnt = 1 ;
        sum = 0 ;
        mid = (l + r) >> 1 ;

        for(int i = 0 ; i < n ; i ++ ){
            
            if(sum + arr[i] > mid){
                cnt ++ ;
                sum = arr[i] ;
            }
            else {
                sum += arr[i] ;
            }
        }

        if(cnt <= t)r = mid ;
        else l = mid + 1 ;

    }

    cout << l ;

    return 0 ;
}