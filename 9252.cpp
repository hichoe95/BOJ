#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

int lcs[1001][1001] = {0,};
string a,b;

void print(int x, int y){
	if(!lcs[x][y]) return;
	if(a[x] == b[y]){
		print(x-1,y-1);
		cout << a[x];
	}
	else lcs[x-1][y]>lcs[x][y-1] ? print(x-1,y):print(x,y-1);
}

int main(){


	cin >> a >> b;

	a = "0" + a;
	b = "0" + b;

	int len1 = a.length();
	int len2 = b.length();



	for(int i=1 ; i<len1 ; i++){
		for(int j = 1 ; j<len2; j++){

			if(a[i] == b[j])
				lcs[i][j] = lcs[i-1][j-1] +1;
			else
				lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
		}
	}

	cout << lcs[len1-1][len2-1] << '\n';
	print(len1-1,len2-1);
	return 0;
}