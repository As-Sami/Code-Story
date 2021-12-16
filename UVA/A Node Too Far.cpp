//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 17/12/2021 - 01:48:03
//  Problem -> uva - A node too far

//  Concept -> have to manage graph with map or unordered_map

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main()
{
    int cs=1;
    while(true){
        int c;
        cin >> c;

        unordered_map<int, vector<int>> g;

        if(c==0)break;

        for( int i=0 ; i<c ; i++ ){
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }


        while(true){
            unordered_map<int,int> dis;
            
            for( auto [x,y] : g )
                dis[x] = -1;

            int st, t;
            cin >> st >> t;

            if( st==0 and t==0 )break;

            queue<int> q;
            q.push(st);
            dis[st] = 0;

            int cnt=0;
            while(q.size()){
                int u = q.front();q.pop();
                cnt++;

                for(auto v : g[u])
                    if(dis[v]==-1){
                        dis[v] = dis[u] + 1;
                        if(dis[v]<=t)
                            q.push(v);
                    }
            }

            cout << "Case " << cs++ << ": " << (int)g.size()-cnt << 
            " nodes not reachable from node " << st << " with TTL = " << t << "." << endl;
        }
    }
    
    return 0;
}