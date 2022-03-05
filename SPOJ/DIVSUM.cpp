
//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 2022-03-02 08:02:34

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout << #x << " = " << x << endl

void solve(){
    int n;
    cin >> n;

    if(n==1){
        cout << 0 << endl;
        return;
    }

    int sum = 1;
    for( int i=2 ; i*i<=n ; i++ )
    {
        if(n%i==0){
            if(n/i == i)
                sum += i;
            else
                sum += i + n/i;
        }
    }
    cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    
    return 0;
}
