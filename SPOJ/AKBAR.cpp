
//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 08/01/2022 - 18:09:47
//  Problem -> SPOJ - AKBAR - Akbar , The great


#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6+6;
vector<int> g[N];
 
void solve(){

    int n, r, m;
    cin >> n >> r >> m;
 
    for(int i=0 ; i<n ; i++)
        g[i+1].clear();
 
    vector<int>dis(n+1,-1);
    for(int i=0 ; i<r ; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    vector<pair<int,int>> l;
    for(int i=0 ; i<m ; i++){
        int node, val;
        cin >> node >> val;
        l.push_back({val,node});
    }
 
    sort(l.begin(), l.end());
    for(auto [val,u] : l){
 
        queue<int> q;
        q.push(u);
        dis[u] = 0;
 
        while(q.size()){
            u = q.front(); q.pop();
            if(dis[u]>=val) continue;
 
            for(auto v : g[u])
                if(dis[v]==-1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
        }
    }

    for(int i=1 ; i<=n ; i++ ){
        if(dis[i]==-1){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
 
int main(){
 
    int t;
    cin >> t;
    while(t--)
        solve();
}