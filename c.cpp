#include <bits/stdc++.h>
using namespace std;
#define FASTio ios::sync_with_stdio(false);cin.tie(NULL);
#define DECI fixed<<setprecision(5)

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_multiset;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;//push_back(),pop_back(),back(),size(),begin(),end(),insert(ite pos, val)
typedef vector<vector<int>> vvi;//clear(),erase(ite position),empty()
typedef map<int,int> mii;//begin(),end(),size(),insert(pair),insert({key,element}),find(key value)
//erase(ite position),erase(key value),clear(),empty()
typedef pair<int,int> pii;
typedef priority_queue<int> pqi;//pop(),push(),size(),top()[for stl::queue it's front()],empty()
typedef priority_queue<pii> pqii;//also for std::stack, std::queue [has extra: back()]
typedef priority_queue<int,vector<int>,greater<int>> pqgi;
typedef set<int> si;
typedef multiset<int> msi;
//std::set//insert(),begin(),end(),size(),find(key),clear(),erase(),empty()
typedef tuple<int,int,int> tiii; //make_tuple(int,int,int),get<position>(name_of_tuple)
typedef deque<int> di;//vector, with  push_front(), pop_front()
#define pb(k) push_back(k)
#define mp(a,b) make_pair(a,b)
#define B begin();
#define E end();
#define nl cout<<"\n"

#define DB(x) {static int testInt=1000;if((testInt--)>0)cout<<"(LINE "<<__LINE__<<": VALUE "<<x<<")\t";}
#define LB {static int testIntx=0;if(testIntx<1000)cout<<"(LINE "<<__LINE__<<","<<testIntx+1<<")\t";else return;testIntx++;}
#define TA(arr) {int* lLe=(int*)(&arr+1);for(int* xTe=arr;xTe!=lLe;xTe++) cout<<*xTe<<" ";nl;}

#define nax 1000000007

/********************************************************/
int cou(int d[], int s) {
	int k=0;
	for(int i=s-1;i>=0;i--) k=10*k+d[i];
	return k;
}
bool chk(vi x,int k) {
	for(int i=0;i<x.size();i++) if(x[i]==k) return true;
	return false;
}
void perm(int d[],int m, ll &ans,int k, vi x) {
	if(k==m) {
		int n=x.size();
		int u[n],v[m-n];
		for(int i=0,j=0,k=0;i<m;i++) {
			if(chk(x,i)) {u[j]=d[i];j++;}
			else {v[k]=d[i];k++;}
		}
		sort(u,u+n);
		sort(v,v+m-n);
		ans=max(ans,ll(cou(u,n))*ll(cou(v,m-n)));
		return;
	}
	x.push_back(k);
	perm(d,m,ans,k+1,x);
	x.pop_back();
	perm(d,m,ans,k+1,x);
}

int main() {
	FASTio
	int n;cin>>n;
	int z=0;int m=0;
	for(int i=n;i>0;i/=10) {
		if(i%10==0) z++;
		else m++;
	}
	int d[m];
	for(int i=n,j=0;i>0;i/=10) if(i%10!=0) {d[j]=i%10;j++;}
	vi x;ll ans=0;
	perm(d,m,ans,0,x);
	ll ou=ans;
	while((--z)>=0) ou*=10;
	cout<< ou;nl;
	return 0;
}