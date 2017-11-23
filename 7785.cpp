#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);

  int n;
  set<string> s;
  cin >> n;

  for(int i=0 ;i<n ;i++){
    string name, status;
    cin >> name >> status;
    if(status == "enter") s.insert(name);
    else s.erase(s.find(name));
  }
  for(auto i = s.rbegin(); i!=s.rend() ; i++)
    cout << *i << '\n';
  return 0;
}
