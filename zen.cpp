#include <bits/stdc++.h>
using namespace std;
#define FASTio ios::sync_with_stdio(false);cin.tie(NULL);

int gen(const int &a, const int &b) {
	return a+rand()%(b-a+1);
}

/****************************************************/


int main(int argc, char* argv[]) {
	FASTio
	int n=1000000,d=1;
	// srand(atoi(argv[1]));
	srand(8);
	cout<<1<<"\n";
	cout<<n<<" "<<d<<"\n";
	for(int i=0;i<n;i++) {
		cout<<gen(0,1)<<" ";
	}
	cout<<"\n";
	return 0;
}