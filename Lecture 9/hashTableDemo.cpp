#include<iostream>
#include "hashTableImplementation.h"

int main(){
	
	hashTable<int>h;
	
	h.insert("Apple",100);
	h.insert("Apricon",50);
	h.insert("Banana",70);
	h.insert("Mango",120);
	h.insert("Rombo",10);
	
	h.print();
	
	//achieved using operator overloading
	h["potato"]=10;
	cout<<h["potato"];
	
	string fruit;
	cin>>fruit;
	
	int *price=h.search(fruit);
	if(price!=NULL)
	cout<<"Cost of fruit: "<<*price;
	else 
	cout<<"Nhi mila";
	return 0;
}
