
//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 22/12/2021 - 12:49:35
//  Problem -> lightoj-1009 - Back to Underworld

// Concept -> Bicoloring, there are many connected components in 
//            the graph. bicolor all the components and count the
//            maximum color in each connected component

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout << #x << " = " << x << endl

int _t=1;

template<typename... T,typename Q>
void outputs(Q x, T&&... args) { cout << "Case " <<  _t++ << ": " << x; ((cout << " " << args), ...); cout << endl;}


void solve(){
    int n;
    cin >> n;
    map<int, vector<int>> g;

    for( int i=0 ; i<n ; i++ ){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    map<int, int>col;
    for( auto [x,y] : g ) col[x] = -1;

    
    int ans=0;

    for(auto [x,y] : col)
    {
        if(col[x]!=-1) continue;

        int zero=0,one=1;

        queue<int> q;
        q.push(x);
        col[x] = 1;

            
        while(q.size()){
            int u = q.front();q.pop();
    
            for(auto v : g[u])
                if(col[v]==-1){
                    col[v] = col[u]==1 ? 0 : 1;
                    col[v] == 1 ? one++ : zero++ ;
                    q.push(v);
                }
        }

        ans += max(zero,one);
    }
    

    outputs(ans);
}

int main()
{
    int t=1;
    cin >> t;
    while(t--)
        solve();
    
    return 0;
}
