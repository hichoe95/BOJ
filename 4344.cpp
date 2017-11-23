#include <cstdio>
#include <cmath>
#define banollim(x,dig) (floor((x)*pow(10,dig)+0.5)/pow(10,dig))
using namespace std;

int main(){

	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		int a[1000];
		double sum=0;
		int k=0;
		scanf("%d",&n);

		for(int i=0 ;i<n;i++){
			scanf("%d",&a[i]);
			sum+=(double)a[i];
		}

		double avg = sum/(double)n;

		for(int i=0 ;i<n ; i++)
			if(avg < a[i]) k++;

		printf("%.3lf%%\n",(double)banollim(((double)k/(double)n)*(1.0*100),3));
	}

	return 0;
}