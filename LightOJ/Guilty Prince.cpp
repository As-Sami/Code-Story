//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 17/12/2021 - 01:38:56
//  Problem -> lightoj-1012 - Guilty Prince

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define outputs(x) cout << "Case " << _t << ": " << x << endl

char g[30][30];
int xx[] = {0,0,1,-1};
int yy[] = {1,-1,0,0};

void solve(int _t){
    int n,m;
    cin >> n >> m;
    for( int i=0 ; i<m ; i++ )
        cin >> g[i];

    pair<int,int>start;
    for( int i=0 ; i<m ; i++ )
        for( int j=0 ; j<n ; j++ )
            if(g[i][j]=='@')
                {start = {i,j};break;}
        

    queue<pair<int,int>> q;

    int cnt=0;
    q.push(start);
    g[start.first][start.second] = '#';

    while(q.size()){
        auto [_x, _y] = q.front();q.pop();
        cnt++;
        for( int i=0 ; i<4 ; i++ )
        {
            int x = _x + xx[i];
            int y = _y + yy[i];
            if( -1<x and x<m and -1<y and y<n and g[x][y]=='.' )
            {
                q.push({x,y});
                g[x][y] = '#';
            }
        }
        
        
    }
    outputs(cnt);
}

int main()
{
    int t=1;
    cin >> t;
    for( int i=0 ; i<t ; i++ )
        solve(i+1);
    
    return 0;
}