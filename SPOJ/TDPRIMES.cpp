
//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 24/02/2022 - 22:58:56

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout << #x << " = " << x << endl

#define int long long 

const int N = 1e8+2;
bool siv[N];
vector<int>pr{2};

int32_t main()
{
    for( int i=3 ; i*i<N ; i+=2 )
        if(!siv[i])
            for( int j = i*i ; j<N ; j += i+i )
                siv[j] = 1;
    
    for( int i=3 ; i<N ; i+=2 )
        if(!siv[i])
            pr.push_back(i);
    
    for( int i=0 ; i<pr.size() ; i+=100 )
        cout << pr[i] << endl;
    

    return 0;
}
