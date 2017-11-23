#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){

	string a,b;

	cin >> a >> b;

	a = "0" + a;
	b = "0" + b;

	int len1 = a.length();
	int len2 = b.length();

	int lcs[1001][1001] = {0,};

	for(int i=1 ; i<len1 ; i++){
		for(int j = 1 ; j<len2; j++){

			if(a[i] == b[j])
				lcs[i][j] = lcs[i-1][j-1] +1;
			else
				lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
		}
	}

	cout << lcs[len1-1][len2-1] << '\n';

	

	return 0;
}