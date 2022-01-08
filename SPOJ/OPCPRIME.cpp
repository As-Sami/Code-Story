
//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 08/01/2022 - 18:07:55
//  Problem -> SPOJ - OPCPRIME - Prime Factorization

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ll n;
    cin >> n;

    if(n%2==0){
        cout << 2 << endl;
        while(n%2==0)
            n /= 2;
    }

    for(ll i=3 ; i*i<=n ; i+=2 )
    {   
        if(n%i==0){
            cout << i << endl;
            while(n%i==0)
                n /= i;
        }
    }

    if(n!=1)
        cout << n;
    
    return 0;
}
