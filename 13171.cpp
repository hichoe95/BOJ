#include <iostream>
using namespace std;
#define MOD 1000000007
#define ll long long

ll POW(ll a,ll b){
    a%=MOD;
    ll r = 1;

    while(b){
        if(b&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return r;
}

int main(){
    ll a,b;
    cin >> a >> b;

    cout << POW(a,b) << "\n";
    return 0;
}