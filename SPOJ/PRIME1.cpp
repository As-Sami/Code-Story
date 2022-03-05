
//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 24/02/2022 - 23:10:39

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout << #x << " = " << x << endl

bool is_prime(int n){

    if(n==2)
        return true;

    if( n==1 or n%2==0)
        return false;

    for( int i=3 ; i*i<=n ; i+=2 )
        if( n%i==0 )
            return false;
    
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--){

        int x,y;
        cin >> x >> y;

        for( int i=x ; i<=y ; i++ )
            if( is_prime(i) )
                cout << i << endl;
        
        cout << endl;
    }

    return 0;
}
