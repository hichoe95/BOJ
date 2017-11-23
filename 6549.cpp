#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define ll long long

int main(){

  ios_base::sync_with_stdio(false);

  while(1){
    int n;
    int h[100001]={0,};
    ll ret = 0;

    cin >> n;

    if(!n) break;

    for(int i=0 ;i<n;i++) cin >> h[i];

    stack<ll> s;

    for(int i=0 ;i<n;i++){

      while(!s.empty() && h[i] < h[s.top()]){
        ll height = h[s.top()];
        s.pop();
        ll w = i;
        if(!s.empty()) w = i-s.top()-1;
        if(ret < w*height) ret = w*height;
      }
      s.push(i);
    }
    while(!s.empty()){
      ll height = h[s.top()];
      s.pop();
      ll w = n;
      if(!s.empty()) w = n-s.top()-1;
      if(ret < height*w) ret = height*w;
    }
    cout << ret << '\n';
  }

  return 0;
}
