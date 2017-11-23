// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// #define ABS(x) (x)>0?(x):-(x)

// bool cmp(const int &a,const int &b){
// 	return a>b;
// }

// int main(){
// 	ios_base::sync_with_stdio(false);

// 	int n,zero=0,one=0;
// 	cin >> n;
// 	int ans=0;
// 	vector<int> p,m;

// 	for(int i=0,x ;i<n;i++){
// 		cin >> x;
// 		if(x==1) one++;
// 		else if(x==0) zero++;
// 		else if(x>0) p.push_back(x);
// 		else if(x<0) m.push_back(x);
// 	}

// 	sort(p.begin(),p.end(),cmp);
// 	sort(m.begin(),m.end());
	
// 	for(int i=0 ;i<(int)p.size();i++){
// 		if(i == p.size()-1) ans+= p[i];
// 		else{
// 			ans+=p[i]*p[i+1];
// 			i++;
// 		}
// 	}
// 	for(int i=0 ; i < ((int)m.size()-zero) ; i++){
// 		if(i==m.size()-zero-1){
// 			ans += m[i];
// 		}
// 		else{
// 			ans += m[i]*m[i+1];
// 			i++;
// 		}
// 	}

// 	cout << ans+one << '\n';

// 	return 0;
// }
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    vector<int> plus;
    vector<int> minus;
    cin >> n;
    int zero = 0;
    int one = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            one += 1;
        } else if (x > 0) {
            plus.push_back(x);
        } else if (x < 0) {
            minus.push_back(x);
        } else {
            zero += 1;
        }
    }
    sort(plus.begin(), plus.end());
    reverse(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    if (plus.size()%2 == 1) {
        plus.push_back(1);
    }
    if (minus.size()%2 == 1) {
        minus.push_back(zero > 0 ? 0 : 1);
    }
    int ans = one;
    for (int i=0; i<plus.size(); i+=2) {
        ans += plus[i] * plus[i+1];
    }
    for (int i=0; i<minus.size(); i+=2) {
        ans += minus[i] * minus[i+1];
    }
    cout << ans << '\n';
    return 0;
}