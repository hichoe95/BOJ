#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  string s;
  char command,c;
  int n;
  stack<char> left, right;

  cin >> s >> n;

  for(int i =0 ; i<s.size() ; i++)
    left.push(s[i]);

  for(int i=0 ; i<n ;i++){
    cin >> command;
    if(command=='L' && !left.empty()){
      right.push(left.top());
      left.pop();
    }
    if(command == 'D' && !right.empty()){
      left.push(right.top());
      right.pop();
    }
    if(command == 'B' && !left.empty())
      left.pop();
    if(command == 'P'){
      cin >> c;
      left.push(c);
    }
  }

    while(!left.empty()){
      right.push(left.top());
      left.pop();
    }

    while(!right.empty()){
      cout << right.top();
      right.pop();
    }
    cout << '\n' ;



  return 0;
}
