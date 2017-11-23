#include <iostream>
#include <cstdio>

using namespace std;

bool ck[5000][5000];
void tristar(int now) {
	for (int i = now + 1; i <= now * 2; i++) {
		for (int j = 1; j <= (i - now) * 2 - 1; j++) {
			ck[i][j] = ck[i][j + (2 * now)] = ck[(i-now)][j];
		}
	}
}
int main(){
  ios_base::sync_with_stdio(0);

	int n;

	cin >> n;
	ck[1][1]= ck[2][1] = ck[3][1] = ck[2][3] = ck[3][2] = ck[3][3] = ck[3][4] = ck[3][5] = true;

	for (int k = 3; k < n; k *= 2) tristar(k);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= (n - i); j++)cout << " ";
		for (int j = 1; j <= 2 * i - 1; j++) {
			if (ck[i][j])cout << "*";
			else cout << " ";
		}
		for (int j = 1; j <= (n - i); j++)cout << " ";
		cout << '\n';
	}

	return 0;
}
