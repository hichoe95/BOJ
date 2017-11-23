#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MOD 1000000

long long int d[5001];

bool check(char a,char b){
  if(!(b-'0'))
    return false;
  int temp = (b-'0')*10 + a-'0';
  return temp <=26 && temp >=10;
}

int main(){
  ios_base::sync_with_stdio(false);
  string code;
  cin >> code;
  int len = code.size();

  if(code == "0") d[0] = 0;
  else d[0] = 1;

  if(code[1]-'0') d[1] = 1;
  if(check(code[1],code[0])) d[1]+=1;

  for(int i = 2 ; i < len ; i++){
    int x = code[i]-'0';
    if(x>=1 && x<=9)
      d[i] = d[i-1]%MOD;

    if(check(code[i],code[i-1])){
      d[i] += d[i-2];
      d[i] %= MOD;
    }
  }

  cout << d[len-1]%MOD << '\n';

  return 0;
}
