#include <iostream>
#include <string>
using namespace std;

string isVPS(string s)
{
  int cnt=0;
  for(int i=0 ;i<s.size();i++){
    if(s[i] == '(') cnt++;
    else if(s[i] == ')') cnt--;

    if(cnt < 0 )
      return "NO";
  }
  if(cnt == 0) return "YES";
  else return "NO";
}

int main(){

  ios_base::sync_with_stdio(false);

  int Test;

  cin >> Test;

  for(int i=0 ; i<Test ; i++){
    string s;
    cin >> s;
    cout << isVPS(s) << '\n';
  }


  return 0;
}
