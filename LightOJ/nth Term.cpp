
//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 2022-03-05 18:52:09

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout << #x << " = " << x << endl

//   _      _     _       _     _      _
//  | f(n)   |   | a 0 b c |   | f(n-1) |
//  | f(n-1) | = | 1 0 0 0 | X | f(n-2) | 
//  | f(n-2) |   | 0 1 0 0 |   | f(n-3) |
//  |_  1   _|   |_0 0 0 1_|   |_   1  _|

//_______________________________________

//   _      _     _       _       _    _
//  | f(n)   |   | a 0 b c |^n-2 | f(2) | f(2) = 0
//  | f(n-1) |   | 1 0 0 0 |     | f(1) | f(1) = 0
//  | f(n-2) | = | 0 1 0 0 |  X  | f(0) | f(0) = 0
//  |_  1   _|   |_0 0 0 1_|     |_  1 _|

#define int long long 
#define matrix array< array<int, 4>, 4>
const int m=10007;

matrix multiply( matrix a, matrix b ){

    matrix c;
    c[0] = {0,0,0,0};
    c[1] = {0,0,0,0};
    c[2] = {0,0,0,0};
    c[3] = {0,0,0,0};

    for( int i=0 ; i<4 ; i++ )
        for( int j=0 ; j<4 ; j++ )
            for( int k=0 ; k<4 ; k++ )
                c[i][j] += a[i][k] * b[k][j], c[i][j] %= m;
    return c;
}

matrix exp(matrix a, int b){
    matrix res;
    res[0] = {1,0,0,0};
    res[1] = {0,1,0,0};
    res[2] = {0,0,1,0};
    res[3] = {0,0,0,1};

    while(b){

        if( b&1 )
            res = multiply(res,a);

        a = multiply(a, a);
        b >>= 1;
    }

    return res;
}

void solve(int t){
    int n,a,b,c;
    cin >> n >> a >> b >> c;

    if( n<3 ){
        cout << "Case " << t << ": " << 0 << endl;
        return;
    }

    matrix x;
    x[0] = {a,0,b,c};
    x[1] = {1,0,0,0};
    x[2] = {0,1,0,0};
    x[3] = {0,0,0,1};

    x = exp(x, n-2);
    
    cout << "Case " << t << ": " << x[0][3] << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    for( int i=0 ; i<t ; i++ )
        solve(i+1);       
          
    return 0;
}