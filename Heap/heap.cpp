#include "util.h"

using namespace std;

class MinQueue {
public:
	MinQueue(vector<int>& tmp): heap(tmp) {makeHeap(heap);}
	MinQueue() {}

	bool empty() {return heap.empy()}
	size_t size() {return heap.size();}
	void pop() {popHeap();}
	void push(int v) {pushHeap(v);}
	int front() {return heap[0];}
	void print() {print(heap);}

private:
	void makeHeap() {
		
	}
	void popHeap() {

	}
	void pushHeap(int v) {

	}
	vector<int> heap;


};

int main() {

}