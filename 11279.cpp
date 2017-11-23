#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  priority_queue<int> q;
  cin >> n;
  for(int i=0,x ;i<n; i++){
    cin >> x;
    if(!x){
      cout << (q.empty() ? 0 : q.top()) <<'\n';
      if(q.size()) q.pop();
    }
    else q.push(x);
  }
  return 0;
}
