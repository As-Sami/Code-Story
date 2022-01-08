
//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 08/01/2022 - 18:15:34
//  Problem -> SPOJ - FACTCG - Easy Factorization

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); // This line is need to avoid TLE
    ll n;
    while(cin >> n)
    {
        cout << "1";
        while(n%2==0){
            cout << " x 2";
            n /= 2;
        }
        for(ll i=3 ; i*i<=n ; i+=2 )
        {   
            while(n%i==0){
                cout << " x " << i;
                n /= i;
            }
        }
    
        if(n!=1)
            cout <<  " x " <<  n;

        cout << endl;
    }    
    return 0;
}
