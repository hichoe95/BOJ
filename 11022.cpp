#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;

  for(int i=1 ; i<=t;i++){
    int a,b;
    cin >> a >> b;
    cout << "Case #" << i <<": "<< a << " + " << b << " = " << a+b <<'\n';
  }
  return 0;
}
