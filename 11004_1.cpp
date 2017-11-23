#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[5000001];
int main(){
  ios_base::sync_with_stdio(false);
  int n,k;
  cin >> n >> k;

  for(int i=0 ;i<n;i++)
    cin >> arr[i];

  nth_element(arr,arr+k-1,arr+n);
  cout << arr[k-1] << '\n';
  return 0;
}
