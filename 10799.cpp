#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  string s;
  stack<int> st;
  int cnt = 0;

  cin >> s;

  for(int i=0 ; i<s.size() ; i++){
    if(s[i] == '(') st.push(i);
    else if(s[i] == ')'){
      if(st.top() + 1 == i){
        st.pop();
        cnt+=st.size();
      }
      else{
        cnt+=1;
        st.pop();
      }
    }
  }

  cout << cnt << '\n';

  return 0;
}
