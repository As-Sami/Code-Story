
//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 2022-03-05 19:56:51

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout << #x << " = " << x << endl

//   _      _     _                _     _      _
//  | f(n)   |   | a1 b1 c1 0  0  0 |   | f(n-1) |
//  | f(n-1) | = | 1  0  0  0  0  0 |   | f(n-2) |
//  | f(n-2) |   | 0  1  0  0  0  0 |   | f(n-3) |
//  | g(n)   |   | 0  0 c2  a2 b2 0 | X | g(n-1) |
//  | g(n-1) | = | 0  0  0  1  0  0 |   | g(n-2) |
//  |_g(n-2)_|   |_0  0  0  0  1  0_|   |_g(n-3)_|

//______________________________________

//   _      _     _                _       _    _
//  | f(n)   |   | a1 b1 c1 0  0  0 |^n-2 | f(2) |
//  | f(n-1) | = | 1  0  0  0  0  0 |     | f(1) |
//  | f(n-2) |   | 0  1  0  0  0  0 |     | f(0) |
//  | g(n)   |   | 0  0 c2  a2 b2 0 |  X  | g(2) |
//  | g(n-1) | = | 0  0  0  1  0  0 |     | g(1) |
//  |_g(n-2)_|   |_0  0  0  0  1  0_|     |_g(0)_|


#define int long long 
#define matrix array< array<int, 6>, 6> // int a[6][6]
int m;

matrix multiply( matrix a, matrix b ){

    matrix c;

    for( int i=0 ; i<6 ; i++ )
        for( int j=0 ; j<6 ; j++ )
            c[i][j] = 0;

    for( int i=0 ; i<6 ; i++ )
        for( int j=0 ; j<6 ; j++ )
            for( int k=0 ; k<6 ; k++ )
                c[i][j] += a[i][k] * b[k][j], c[i][j] %= m;
    return c;
}

matrix exp(matrix a, int b){
    matrix res;

    for( int i=0 ; i<6 ; i++ )
        for( int j=0 ; j<6 ; j++ )
            res[i][j] = (i==j);

    while(b){

        if( b&1 )
            res = multiply(res,a);

        a = multiply(a, a);
        b >>= 1;
    }

    return res;
}

void solve(int t){
    int a1, b1, c1, a2, b2, c2;
    int f0, f1, f2, g0, g1, g2;

    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    cin >> f0 >> f1 >> f2 >> g0 >> g1 >> g2;

    cin >> m;

    matrix x;
    x[0] = {a1, b1,  0,  0,  0, c1};
    x[1] = { 1,  0,  0,  0,  0,  0};
    x[2] = { 0,  1,  0,  0,  0,  0};
    x[3] = { 0,  0, c2, a2, b2,  0};
    x[4] = { 0,  0,  0,  1,  0,  0};
    x[5] = { 0,  0,  0,  0,  1,  0};

    cout << "Case " << t << ":" << endl;

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;

        if( n==0 ){
            cout << f0%m << ' ' << g0%m << endl;
            continue;
        }else if( n==1 ){
            cout << f1%m << ' ' << g1%m << endl;
            continue;
        }else if( n==2 ){
            cout << f2%m << ' ' << g2%m << endl;
            continue;
        }

        matrix y = exp(x, n-2);
        int fn = y[0][0]*f2 + y[0][1]*f1 + y[0][2]*f0 + y[0][3]*g2 + y[0][4]*g1 + y[0][5]*g0;
        int gn = y[3][0]*f2 + y[3][1]*f1 + y[3][2]*f0 + y[3][3]*g2 + y[3][4]*g1 + y[3][5]*g0;

        cout << fn%m << ' ' << gn%m << endl;
    }
    
}

int32_t main()
{
    int t;
    cin >> t;
    for( int i=0 ; i<t ; i++ )
        solve(i+1);       

    return 0;
}