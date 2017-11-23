#include <iostream>
#include <vector>
using namespace std;

long long int N,B,C,res;
vector<int> A;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;

	for(int i=0,a ;i<N ;i++)
		cin >> a, A.push_back(a);

	cin >> B >> C;

	for(int &k : A) k-=B;

	for(int k : A)
		if(k>=0){
			if(k%C) res+= k/C+1;
			else res += k/C;
		}

	cout << res+N << '\n';
	return 0;
}