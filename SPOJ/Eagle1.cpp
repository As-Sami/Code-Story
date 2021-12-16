//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 17/12/2021 - 01:46:32
//  Problem -> SPOJ - EAGLE1 - Eagle and Dogs

//  Concept -> Find the endpoints of the diameter(node x,y), ans[i]
//             is max(distance from x, distance form y). 

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N = 1e5+5;
vector<pair<int,int>> g[N];
ll dis[N], ans[N];

void dfs(int u, int prev){

    for( auto [v,w] : g[u] )
        if(v^prev){
            dis[v] = dis[u] + w;
            dfs(v,u);
        }
}

void solve(){
    int n;
    cin >> n;

    for( int i=1 ; i<n ; i++ ){
        int x,y,z;
        cin >> x >> y >> z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    
    dfs(1,0);
    int root = max_element(dis+1, dis+n+1) - (dis);
    dis[root] = 0;
    dfs(root, 0);
    
    for( int i=1 ; i<=n ; i++ )
        ans[i] = dis[i];

    
    root = max_element(dis+1, dis+n+1) - (dis);    
    dis[root] = 0;
    dfs(root, 0);
    
    for( int i=1 ; i<=n ; i++ )
        ans[i] = max(ans[i], dis[i]);


    for( int i=1 ; i<=n ; i++ )
        cout << ans[i] << " \n"[i==n];


    // clearing graph and stuff
    for( int i=1 ; i<=n ; i++ ){
        g[i].clear(); dis[i]=ans[i]=0;
    }
    
}

int main()
{
    int t=1;
    cin >> t;
    while(t--)
        solve();
    
    return 0;
}
