#include <iostream>
using namespace std;

int main(){

    int n,cnt=0;
    cin >> n;
    if(n<6){
        cout << 0 << endl;
        return 0;
    }

    n-=6;
    while(n>=0){
        cnt+= (n/2+1);
        if((n-2)>=0) n-=2;
        else break;
    }

    cout << cnt << endl;

    return 0;
}