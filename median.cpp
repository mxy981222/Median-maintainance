#include<iostream>
#include<queue>
//#include"d-ary.h"
using namespace std;
int main() {
	priority_queue<int, vector<int>, greater<int>>min_heap;//the element in min is ascending
	priority_queue<int, vector<int>, less<int>>max_heap;//the element in max is descending
	//vector<int>in;
	while (cin) {
		int tmp;
		int min_size = min_heap.size();
		int max_size = max_heap.size();
		int size = min_size + max_size;
		cin >> tmp;
		if (size % 2 == 0) {//if size is even
			if (!min_heap.empty()) {
				if (tmp <= min_heap.top()) {
					max_heap.push(tmp);
				}
				else {
					int min = min_heap.top();
					min_heap.pop();
					max_heap.push(min);
					min_heap.push(tmp);
				}
			}
			else max_heap.push(tmp);
		}
		else {
			if (tmp >= max_heap.top()) {
				min_heap.push(tmp);
			}
			else {
				int max = max_heap.top();
				max_heap.pop();
				min_heap.push(max);
				max_heap.push(tmp);
			}
		}
		cout << "The median in the current array is : " <<max_heap.top() << endl;
	}
}
