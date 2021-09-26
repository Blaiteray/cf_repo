#include <bits/stdc++.h>
using namespace std;
#define FASTio ios::sync_with_stdio(false);cin.tie(NULL);
#define DECI fixed<<setprecision(5)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;//push_back(),pop_back(),back(),size(),begin(),end(),insert(ite pos, val)
typedef vector<ll> vll;//clear(),erase(ite position),empty()
typedef map<int,int> mii;//begin(),end(),size(),insert(pair),insert({key,element}),find(key value)
//erase(ite position),erase(key value),clear(),empty()
typedef pair<int,int> pii;
typedef priority_queue<int> pqi;//pop(),push(),size(),top()[for stl::queue it's front()],empty()
typedef priority_queue<ll> pqll;//also for std::stack, std::queue [has extra: back()]
typedef priority_queue<pii> pqii;
typedef priority_queue<pii, vector<pii>, greater<pii>> pqgii;
typedef priority_queue<int,vector<int>,greater<int>> pqgi;
typedef priority_queue<ll,vector<ll>,greater<ll>> pqgl;
//std::set//insert(),begin(),end(),size(),find(key),clear(),erase(),empty()
typedef tuple<int,int,int> tiii; //make_tuple(int,int,int),get<position>(name_of_tuple)
#define pb(k) push_back(k);
#define mp(a,b) make_pair(a,b);

#define nl cout<<"\n";
#define Test(x) {static int testInt=1000;if((testInt--)>0)cout<<"(LINE "<<__LINE__<<": VALUE "<<x<<")\t";}
#define test {static int testIntx=1000;if((testIntx--)>0)cout<<"(LINE "<<__LINE__<<": CALL "<<1000-testIntx<<")\t";}
#define testarr(arr) {int* lLe=(int*)(&arr+1);for(int* xTe=arr;xTe!=lLe;xTe++) cout<<*xTe<<" ";nl}
#define testarrll(arr) {ll* lLe=(ll*)(&arr+1);for(ll* xTe=arr;xTe!=lLe;xTe++) cout<<*xTe<<" ";nl}

#define loop(i,k,n) for(int i=k;i<=n;i++)
#define rloop(i,k,t) for(int i=k;i>=t;i--)
#define stloop(i,cont) for(auto i=cont.begin();i!=cont.end();i++)

#define bigint 1000000007

/********************************************************/
int main() {
	FASTio
	int n;cin>>n;int x[n];loop(i,0,n-1)cin>>x[i];
	int out=0,f,k=0;while(k<n) {
		int r=0;
		while(x[r]==-1) r++;
		f=x[r];x[r]=-1;out++;k++;
		loop(i,r+1,n-1) if(x[i]>f) {
			f=x[i];
			x[i]=-1;
			k++;
		}
	}
	cout<<out;nl;
	return 0;
}