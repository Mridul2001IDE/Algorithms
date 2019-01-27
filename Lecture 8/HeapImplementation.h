//Heap implementation
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Heap{
	
	bool minHeap;
	vector<int> v;
	
	bool compare(int a,int b){
		
		if(minHeap){
			return a<b;
		}else return a>b;
		
	}
	
	//i is the index 
	void heapify(int i){
		
		int min_index=i;
		int left=i<<1; //same as 2*i
		int right=left+1;
		
		int lastIndex=v.size()-1;
		
		if(left<=lastIndex && compare(v[left],v[min_index])){
			min_index=left;
		}
		
		if(right<=lastIndex && compare(v[right],v[min_index])){
			min_index=right;
		}
		
		if(min_index!=i){
			swap(v[i],v[min_index]);
			heapify(min_index);
		}
		
		
	}
	
public:
	
	Heap(bool minH=true){
		
		//by default min heap
		minHeap=minH;
		// -1 at 0 index since we will be using indexing from 1
		v.push_back(-1);
		
	}		
	
	void push(int d){
		
		v.push_back(d);
		int index=v.size()-1;
		
		while(index>1 && compare(v[index],v[index/2])){
			
			swap(v[index],v[index/2]);
			index=index/2;
			
		}
		
	}
	
	
	int getTop(){
		if(v.size()>1){
			return v[1];
		}
		
	}
	
	int size(){
		return v.size()-1;
	}
	
	bool isEmpty(){
		return v.size()==1;
	}
	
	
	void pop(){
		
		int index=v.size()-1;
		swap(v[1],v[index]);
		v.pop_back();
		
		heapify(1);
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
};
