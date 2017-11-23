#include <iostream>
using namespace std;

bool s[1010];

int main(){
  ios_base::sync_with_stdio(false);

  int n;

  for(int i=2 ; i<=1000;i++){
    if(!s[i])
      for(int j=2*i ; j<=1000; j+=i)
        s[j]=true;
  }

  cin >> n;
  int temp,cnt=0;
  s[1] = true;

  while(n--){
    cin >> temp;
    if(!s[temp])
      cnt++;
  }
  cout << cnt << '\n';

  return 0;
}
