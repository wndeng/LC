#include "util.h"

using namespace std;

class MinQueue {
public:
	MinQueue(vector<int>& tmp): heap(tmp) {makeHeap();}
	MinQueue() {}

	bool empty() {return heap.empty();}
	size_t size() {return heap.size();}
	void pop() {popHeap();}
	void push(int v) {pushHeap(v);}
	int front() {
		if(!heap.empty()) return heap[0];
		return INT32_MAX;
	}
	void printHeap() {print(heap);}

private:
	void makeHeap() {
		for(int i = (heap.size() >> 1) - 1; i >= 0; --i) heapify(i);
	}
	void heapify(int i) {
		int l = 2*i+1 >= (int) heap.size() ? INT32_MAX : heap[2*i+1], r = 2*i+2 >= (int) heap.size() ? INT32_MAX : heap[2*i+2];
		if(l < r && heap[i] > l) {
			swap(heap[i], heap[2*i+1]);
			heapify(2*i+1);
		}
		else if(heap[i] > r) {
			swap(heap[i], heap[2*i+2]);
			heapify(2*i+2);
		}
	}
	void popHeap() {
		if(heap.empty()) return;
		heap[0] = heap[heap.size()-1];
		heap.pop_back();
		heapify(0);
	}
	void pushHeap(int v) {
		int i = heap.size(), p = i >> 1;
		heap.push_back(v);
		while(heap[p] > heap[i]) {
			swap(heap[p], heap[i]);
			i = p; p >>= 1;
		}
	}
	vector<int> heap;
};

int main() {
	MinQueue a;
	for(int i = 10; i >= 0; --i) a.push(i);
	while(!a.empty()) {
		cout << a.front() << " ";
		a.pop();
	}
	cout << '\n';

}