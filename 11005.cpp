#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int n,b;
  cin >> n >> b;
  string a="";
  while(n){
    int r = n%b;
    if(r<10)
      a+=(char)(r+'0');
    else
      a+=(char)(r-10+'A');
    n/=b;
  }
  reverse(a.begin(),a.end());
  cout << a << '\n';

  return 0;
}
