#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	string a,b;
	cin >> a >> b;
	int ans = 1e9;
	int len_a = a.length(), len_b = b.length();

	for(int i=0 ;i+len_a<=len_b ; i++){
		int cnt =0 ;
		for(int j=0 ; j<len_a; j++)
			if(a[j]!=b[j+i]) cnt++;
		ans = min(cnt,ans);
	}
	cout << ans;
	return 0;
}