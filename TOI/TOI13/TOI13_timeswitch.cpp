#include<bits/stdc++.h>

using namespace std;

int n ; 
string s , ss ;

const long long hashcode = 3 ;

long long hashing(){
    
    long long res = 0 ;
    for(int i = 0 ; i < n ; i ++ ){
        res *= hashcode ;
        res += s[i] - '0' ;
    }
    return res ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> s ;
    ss = s + s ;
    long long del = 1 ;
    
    for(int i = 0 ; i < n - 1 ; i ++ ){
        del *= hashcode ;
    }

    long long target = hashing() ;
    long long now = target ;

    for(int i = 0 ; i < n ; i ++ ){
        now -= (s[i] - '0') * del ;
        now *= hashcode ;
        now += (s[i] - '0') ;

        if(now == target){
            bool is_valid = true ;
            for(int j = 0 ; j < n ; j ++ ){
                if(ss[i + j + 1] != s[j]){
                    is_valid = false ;
                }
            }
            if(is_valid){
                cout << i + 1 ;
                return 0 ;
            }
        }
    }


    
    return 0 ;
}