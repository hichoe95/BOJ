#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int d[11];

int plusNum(int n){
  if(n<=1)
    return 1;
  if(n==2) return 2;
  if(n==3) return 4;

  if(d[n])
    return d[n];

  d[n] = plusNum(n-1) + plusNum(n-2) + plusNum(n-3);

  return d[n];

}

int main(){
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;

  for(int i=0 ; i<t ;i++){
    int n;
    cin >> n;

    cout << plusNum(n) << '\n';
    memset(d,0,sizeof(int)*11);
  }

  return 0;
}
