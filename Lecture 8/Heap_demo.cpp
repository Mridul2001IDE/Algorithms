#include<iostream>
#include "HeapImplementation.h"

int main(){
	//min heap
	Heap h;
	// max heap - Heap h(false);
	
	//also known as heapsort
	int a[]={12,7,6,8,4,9,1,2,10,15};
	
	for(int i=0;i<10;i++){
		h.push(a[i]);
	}
	
	while(!h.isEmpty()){
		cout<<h.getTop()<<" ";
		h.pop();
	}
	
	return 0;
}
