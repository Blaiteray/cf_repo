#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common files
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_multiset;

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