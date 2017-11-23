#include <iostream>
#include <string>
#include <stack>
#include <string>
using namespace std;

stack<char> l,r;
string a,t;

bool check(stack<char> st,int opt){
  int len = a.length();

  if(st.size()<len) return false;

  if(opt == 1){//왼쪽
    for(int i=len-1 ;i>=0 ; i--){
      char c = st.top();
      st.pop();
      if(c != a[i]) return false;
    }
  }
  else if(opt == 2){
    for(int i=0 ; i <len ; i++){
      char c = st.top();
      st.pop();
      if(c!=a[i]) return false;
    }

  }

  return true;
}

void del(stack<char> &st){
  int len = a.length();
  for(int i=0 ;i<len ;i++) st.pop();
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> a >> t;
  int start = 0, end = t.length();

  while(start<=end){
    l.push(t[start++]);
    if(check(l,1)){
      del(l);
      while(end>=0){
        r.push(t[end--]);
        if(check(r,2)){
          del(r);
          break;
        }
      }
    }
  }
  int sz = l.size();
  for(int i=0 ;i<sz;i++) r.push(l.top()),l.pop();

  sz = r.size();
  for(int i=0 ;i<sz ; i++) cout << r.top(),r.pop();

  cout << '\n';

  return 0;
}
