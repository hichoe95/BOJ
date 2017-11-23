#include <iostream>
using namespace std;

int gcd(int a,int b){
  return b?gcd(b,a%b) : a;
}

int main(){

  int a,b,g;
  cin >> a >> b;
  g=gcd(a,b);
  cout << g << endl;
  cout << g*(a/g)*(b/g)<<endl;

  return 0;
}
