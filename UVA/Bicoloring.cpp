//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 17/12/2021 - 01:47:50
//  Problem -> uva-10004 - Bicoloring

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 205;
vector<int> g[N];

int main(){
    int n,m;
    while(1){
        
        cin >> n;
        if(!n)break;

        cin  >> m;
    
        for( int i=0 ; i<n ; i++ )
            g[i].clear();
    
        for( int i=0 ; i<m ; i++ ){
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int flag=1;

        vector<int>col(n,-1);
        queue<int>q;
        q.push(0);
        col[0] = 0;

        while(q.size()){
            int u = q.front();
            q.pop();

            for( auto v : g[u] ){
                if(col[v]==-1){
                    col[v] = col[u] ? 0 : 1;
                    q.push(v);
                }else if(col[u]==col[v]){
                    flag=0;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) 
            cout << "BICOLORABLE.\n";
        else 
            cout << "NOT BICOLORABLE.\n";

    }
    return 0;
}
