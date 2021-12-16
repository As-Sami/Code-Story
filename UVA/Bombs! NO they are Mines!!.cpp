//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 17/12/2021 - 01:47:41
//  Problem -> uva-10653 - Bombs! NO they are Mines!!

//  Concept -> Simple bfs, although getting input is hard part :3

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int N = 1005;
int g[N][N];
int dis[N][N];

int xx[] = {0,0,1,-1};
int yy[] = {1,-1,0,0};

int main()
{
    while(1){
        int r,c;
        cin >> r >> c;

        if(r==0 and c==0)
            break;

        for( int i=0 ; i<r ; i++ )
            for( int j=0 ; j<c ; j++ )
                g[i][j] = 0, dis[i][j]=-1;

        int t;
        cin >> t;

        for( int i=0 ; i<t ; i++ ){
            int x,bomb;
            cin >> x >> bomb;
            for( int j=0 ; j<bomb ; j++ )
            {
                int y;
                cin >> y;
                g[x][y] = 1; 
            }
        }

        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        queue<pair<int,int>> q;
        q.push({x1,y1});
        g[x1][y1] = 2;
        dis[x1][y1] = 0;

        while(q.size()){
            auto [x,y] = q.front();q.pop();

            for( int i=0 ; i<4 ; i++ ){

                int _x = x+xx[i], _y=y+yy[i];
                if( -1<_x and _x<r and -1<_y and _y<c and dis[_x][_y]==-1 and g[_x][_y]==0 ){
                    dis[_x][_y] = dis[x][y] + 1;
                    q.push({_x,_y});
                }
            }
        }
            
        cout << dis[x2][y2] << endl;
    }
    
    return 0;
}