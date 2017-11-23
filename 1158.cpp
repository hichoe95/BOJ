#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  queue<int> q;
  int n,m;

  cin >> n >> m;

  for(int i=0 ;i<n;i++)
    q.push(i+1);

  cout << '<';
  while(!q.empty()){
    for(int i=0 ;i<m-1;i++){
      q.push(q.front());
      q.pop();
    }
    if(q.size() == 1){
      cout << q.front() << '>' << '\n';
      return 0;
    }
    cout << q.front() << ", ";
    q.pop();
  }




  return 0;
}
