#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int RSP(char a, char b){
  if(a=='R' && b=='S') return 1;
  if(a=='R' && b=='P') return 0;
  if(a=='S' && b=='P') return 1;
  if(a=='S' && b=='R') return 0;
  if(a=='P' && b=='R') return 1;
  if(a=='P' && b=='S') return 0;

  return 2;
}

int main(){
  ios_base::sync_with_stdio(false);
  int t,n;

  cin >> t;

  while(t--){
    cin >> n;
    int cnt_a=0,cnt_b=0;

    for(int i=0 ;i<n;i++){
      char a,b;
      int temp;
      cin >> a >> b;
      temp = RSP(a,b);
      if(temp == 2) continue;
      if(temp) cnt_a++;
      else cnt_b++;
    }
    if(!(cnt_a-cnt_b))
      cout << "TIE" << '\n';
    else if(cnt_a>cnt_b) cout << "Player 1" << '\n';
    else cout << "Player 2" << '\n';
  }

  return 0;
}
