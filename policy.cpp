#include <bits/stdc++.h>
using namespace std;
#define FASTio ios::sync_with_stdio(false);cin.tie(NULL);
#define DECI fixed<<setprecision(5)

#include <ext/pb_ds/assoc_container.hpp> // Common files
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_multiset;

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
#define B begin()
#define E end()
#define nl cout<<"\n"

#define DB(x) {static int testInt=1000;if((testInt--)>0)cout<<"(LINE "<<__LINE__<<": VALUE "<<x<<")\t";}
#define LB {static int testIntx=0;if(testIntx<1000)cout<<"(LINE "<<__LINE__<<","<<testIntx+1<<")\t";else break;testIntx++;}
#define TA(arr) {int* lLe=(int*)(&arr+1);for(int* xTe=arr;xTe!=lLe;xTe++) cout<<*xTe<<" ";nl;}

#define nax 1000000007

/********************************************************/

int main() {
	indexed_multiset s;
	s.insert(9);
	s.insert(2);
	s.insert(2);
	s.insert(7);
	s.insert(3);
				//arranged in (2,2,3,7,9) order
	auto x = s.find_by_order(1);
	cout << *x << "\n"; // 3; The function find_by_order returns an iterator to the element at a given position

	cout << s.order_of_key(7) << "\n"; // 2; And the function order_of_key returns the position of a given element

	cout << s.order_of_key(6) << "\n"; // 2;If the element does not appear in the set, 
	                                   //we get the position that the element would have in the set:
	cout << s.order_of_key(8) << "\n"; // 3
	cout<< s.order_of_key(2) << "\n";
}