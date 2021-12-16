//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 17/12/2021 - 01:47:10
//  Problem -> lightoj-1094 - Farthest Nodes in a Tree

//  Concept -> Use BFS or DFS twice

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define outputs(x) cout << "Case " << _t << ": " << x << endl

const int N = 30005;
vector<pair<int,ll>>g[N];
vector<ll>dis;

void dfs(int u, int prev, ll w){

    dis[u] = w;

    for(auto [v,x] : g[u])
        if(v^prev)
            dfs(v,u,w+x);

}

void solve(int _t){
    int n;
    cin >> n;

    dis.resize(n,-1);
    for( int i=0 ; i<n ; i++ )
        g[i].clear();
    
    for( int i=1 ; i<n ; i++ ){
        int x,y; ll z;
        cin >> x >> y >> z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    
    dfs(0,-1,0);
    int maxx = max_element(dis.begin(), dis.end()) - dis.begin();
    dis.resize(n,-1);

    dfs(maxx,-1,0);
    outputs(*max_element(dis.begin(), dis.end()));
}

int main()
{
    int t;
    cin >> t;
    for( int i=0 ; i<t ; i++ )
        solve(i+1);
    
    return 0;
}