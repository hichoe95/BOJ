#include <iostream>
#include <algorithm>
using namespace std;
#define inf 987654321

int d[1000001];

int makeOne(int n){

  if(n<=1)
    return 0;

  if(d[n])
    return d[n];

  d[n] = makeOne(n-1)+1;

  if(!(n%2)){
    int temp = makeOne(n/2)+1;
    if(d[n]>temp)
      d[n] = temp;
  }

  if(!(n%3)){
    int temp = makeOne(n/3)+1;
    if(d[n]>temp)
      d[n] = temp;
  }
  return d[n];

}

int main(){
  ios_base::sync_with_stdio(false);

  int n;

  cin >> n;

  cout << makeOne(n) << '\n';

  return 0;
}
