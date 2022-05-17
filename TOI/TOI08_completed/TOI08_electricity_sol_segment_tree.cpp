#include<bits/stdc++.h>
using namespace std ;
const int N = 500001 ;
int arr[N] ;
class Segment {
    public : 
        int seg[4 * N] ;
        void build(int l , int r , int now){
            if(l == r){
                seg[now] = arr[l];
                return ;
            }
            int mid = (l + r) >> 1 ;
            build(l , mid , now * 2) ; build(mid + 1 , r , now * 2 + 1) ;
            seg[now] = min(seg[now * 2] , seg[now * 2 + 1]);
            return ;
        }
        void update(int l , int r , int idx , int val , int now){
            if(r < idx || l > idx)return ;
            if(l == r){
                seg[now] = val ;
                return ;
            }
            int mid = (l + r) >> 1;
            update(l , mid , idx , val , now * 2) ; update(mid + 1 , r , idx , val , now * 2 + 1) ;
            seg[now] = min(seg[now * 2]  , seg[now * 2 + 1]);
            return ;
        }
        int query(int l , int r , int nl , int nr , int now){
            if(nl > r || nr < l)return INT_MAX;
            if(nl >= l && nr <= r)return seg[now];
            int mid = (nl + nr) >> 1 ;
            return min(query(l , r , nl , mid , now * 2) , query(l , r , mid + 1  , nr , now * 2 + 1)) ;
        }
}Seg;
int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);
    int n , k , ans ; cin >> n >> k ;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
        arr[i] += Seg.query( max(i - k , 0) , max(i - 1 , 0) , 0 , n - 1 , 1);
        Seg.update(0 , n - 1 , i , arr[i] , 1) ;
    }
    cout << arr[n - 1] ;
    return 0 ;
}