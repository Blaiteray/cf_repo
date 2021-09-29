#include <bits/stdc++.h>
using namespace std;
#define FASTio ios::sync_with_stdio(false);cin.tie(NULL);
#define DECI fixed<<setprecision(5)

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

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
typedef multiset<int> msi;
//std::set//insert(),begin(),end(),size(),find(key),clear(),erase(),empty()
typedef tuple<int,int,int> tiii; //make_tuple(int,int,int),get<position>(name_of_tuple)
typedef deque<int> di;//vector, with  push_front(), pop_front()
#define pb(k) push_back(k)
#define mp(a,b) make_pair(a,b)

#define nl cout<<"\n";
#define Test(x) {static int testInt=1000;if((testInt--)>0)cout<<"(LINE "<<__LINE__<<": VALUE "<<x<<")\t";}
#define test {static int testIntx=1000;if((testIntx--)>0)cout<<"(LINE "<<__LINE__<<": CALL "<<1000-testIntx<<")\t";}
#define testarr(arr) {int* lLe=(int*)(&arr+1);for(int* xTe=arr;xTe!=lLe;xTe++) cout<<*xTe<<" ";nl}
#define testarrll(arr) {ll* lLe=(ll*)(&arr+1);for(ll* xTe=arr;xTe!=lLe;xTe++) cout<<*xTe<<" ";nl}

#define loop(i,k,n) for(int i=k;i<=n;i++)
#define rloop(i,k,t) for(int i=k;i>=t;i--)
#define stloop(i,cont) for(auto i=cont.begin();i!=cont.end();i++)

#define nax INT_MAX

/********************************************************/

int main() {
	FASTio
	int n;cin>>n; vector<tuple<int,int,int>> d,k;multiset<int> r;multiset<int,greater<int>> l;
	for(int i=0;i<n;i++) {
		int a,b;cin>>a>>b;d.push_back(make_tuple(a,b,i));k.push_back(make_tuple(a,-b,i)); r.insert(b); l.insert(b);
	}
	sort(d.begin(),d.end());
	sort(k.begin(),k.end());
	int ansf[n],anss[n];
	for(int i=0;i<n;i++) {
		auto it=r.begin();
		if(get<1>(d[i])!=*(it)) {
			ansf[get<2>(d[i])]=1;
		}
		else if(get<1>(d[i])==*(++it)) {
			ansf[get<2>(d[i])]=1;
		}
		else ansf[get<2>(d[i])]=0;
		r.erase(r.find(get<1>(d[i])));
	}
	for(int i=n-1;i>=0;i--) {
		auto it=l.begin();
		if((-get<1>(k[i]))!=*(it)) {
			anss[get<2>(k[i])]=1;
		}
		else if((-get<1>(k[i]))==*(++it)) {
			anss[get<2>(k[i])]=1;
		}
		else anss[get<2>(k[i])]=0;
		l.erase(l.find(-get<1>(k[i])));
	}
	for(int i=0;i<n;i++) cout<<ansf[i]<<" ";nl
	for(int i=0;i<n;i++) cout<<anss[i]<<" ";nl
	return 0;
}