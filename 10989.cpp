#include <iostream>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int arr[10001]={0};

  for(int i=0 ;i<n;i++){
    int num=0;
    cin >> num;
    arr[num]++;
  }

  for(int i=1; i<=10000;i++)
    for(int j=0 ;j<arr[i];j++)
      cout << i << '\n';

  return 0;
}
