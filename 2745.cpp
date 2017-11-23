#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
  int b;
  string n="";
  cin >> n >> b;
  int a=0;

  for(int i=0;i<n.size();i++){
    if(n[i]>='A')
      a=a*b + (n[i] - 'A' +10);
    else
      a=a*b + (n[i]-'0');
  }

  cout << a << '\n';

  return 0;
}
