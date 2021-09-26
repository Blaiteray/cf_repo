#include <bits/stdc++.h>
using namespace std;
#define FASTio ios::sync_with_stdio(false);cin.tie(NULL);

int gen(const int &a, const int &b) {
	return a+rand()%(b-a);
}

/****************************************************/

int r[12],bm[12];
int main(int argc, char* argv[]) {
	FASTio
	int n=12;
	srand(atoi(argv[1]));
	cout<<n<<"\n";
	for(int i=0;i<n;i++) {
		int k=gen(1,13);
		while(bm[k]!=0) {
			k=gen(1,13);
		}
		r[i]=k;
		bm[k]=1;
	}
	for(int i=0;i<12;i++)cout<<r[i]<<" ";
	cout<<"\n";
	return 0;
}