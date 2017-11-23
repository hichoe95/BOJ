#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int a,b,cnt_a=0,cnt_d=0;
  cin >> a;
  for(int i=0 ;i<7;i++){
    cin >> b;
    if(b==a-1) cnt_d++;
    else if(b==a+1) cnt_a++;
    a=b;
  }

  if(cnt_d == 7) cout << "descending" << '\n';
  else if(cnt_a == 7) cout << "ascending" << '\n';
  else cout << "mixed" << '\n';
  return 0;
}
