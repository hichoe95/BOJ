#include <iostream>
#include <set>
using namespace std;

int main(){
  set<int> s;
  for(int i=0 ;i<10 ; i++){
    int x;
    cin >> x;
    s.insert(x%42);
  }
  cout << s.size();
}
