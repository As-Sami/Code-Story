//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 17/12/2021 - 01:45:13
//  Problem -> lightoj-1174 - Commandos

//  Concept ->  we have to calculate (shortest path from s to i) + 
//              (shortest path from d to i) for all commandos, 
//              and find the maximum value among these.

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define outputs(x) cout << "Case " << _t << ": " << x << endl

const int N = 102;
vector<int>g[N];

void solve(int _t){

    int n,m;
    cin >> n >> m;

    for( int i=0 ; i<n ; i++ )
        g[i].clear();
    

    for( int i=0 ; i<m ; i++ ){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int s,d;
    cin >> s >> d;
    
    vector<int> dis1(n,-1), dis2(n,-1);

    queue<int>q;
    
    q.push(s);
    dis1[s] = 0;
    while(q.size()){
        int u = q.front();q.pop();

        for( auto v : g[u] )
            if(dis1[v]==-1){
                dis1[v] = dis1[u] + 1;
                q.push(v);
            }
    }

    q.push(d);
    dis2[d] = 0;
    while(q.size()){
        int u = q.front();q.pop();

        for( auto v : g[u] )
            if(dis2[v]==-1){
                dis2[v] = dis2[u] + 1;
                q.push(v);
            }
    }

    int mx = -1;
    for( int i=0 ; i<n ; i++ )
        mx = max(mx, dis1[i]+dis2[i]);

    outputs(mx);
}

int main()
{
    int t=1;
    cin >> t;
    for( int i=0 ; i<t ; i++ )
        solve(i+1);
    
    return 0;
}