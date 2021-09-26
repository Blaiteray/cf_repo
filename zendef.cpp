#include <bits/stdc++.h>
using namespace std;
#define FASTio ios::sync_with_stdio(false);cin.tie(NULL);

int gen(const int &a, const int &b) {
	return a+rand()%(b-a);
}

/****************************************************/
int main(int argc, char* argv[]) {
	FASTio
	int n=11;
	srand(atoi(argv[1]));
	cout<<n<<"\n";
	for(int i=0;i<n;i++) cout<< gen(0,100) << " ";
	cout<<"\n";
	return 0;
}