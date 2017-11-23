#include <iostream>
#include <cmath>
using namespace std;

long long int m,M;
bool check[5000001];

int main(){
    cin >> m >> M;
    int cnt=0;

    for(long long int i=2 ; i*i<=M ;i++){
        if(!(m%(i*i))) check[0] = true;
        for(long long int j = i*i-(m%(i*i)) ; j <= M-m ; j+=i*i) check[j] = true;
    }

    for(int i=0 ; i<=M-m ; i++)
        if(!check[i]) cnt++;

    cout << cnt << endl;
    
    return 0;
}
