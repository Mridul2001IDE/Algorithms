//hashing implementation
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node{
public:	
	string key;
	T value;
	node* next;
	
	node(string k,T v){
		key=k;
		value=v;
		next=NULL;
	}
	
	~node(){
		if(next!=NULL){
			delete next;
		}
	}

};

template<typename T>
class hashTable{
	
	//pointer to array of pointers
	node<T>** buckets;
	
	int cs; // current size
	int ts; // total size
	
	int hashFn(string key){
		
		int L=key.length();
		int ans=0;
		int p=1;
		
		for(int i=0;i<L;i++){
			
			ans=ans+key[L-i-1]*p;
			p=p*37;
			p%=ts;
			ans%=ts;	
			
		}
		
		return ans;
		
	}
	
	void rehash(){
		
		node<T>** oldBuckets=buckets;
		
		int oldTs=ts;
		ts=ts<<1; //ts=ts*2
		
		buckets=new node<T>* [ts];
		
		for(int i=0;i<ts;i++){
			buckets[i]=NULL;
		}
		
		cs=0;
		
		//iterate over old table
		for(int i=0;i<oldTs;i++){
			
			node<T>* temp=oldBuckets[i];
			
			if(temp!=NULL){
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp=temp->next;
			}
			delete oldBuckets[i];
			}
			
			
		}
		
		delete [] oldBuckets;	
	}
	
public:

	hashTable(int ds=7){
		
		ts=ds;
		cs=0;
		buckets=new node<T>*[ts];
		
		for(int i=0;i<ts;i++){
			buckets[i]=NULL;
		}
		
	}
	
	void insert(string key,T value){
		//index
		int i=hashFn(key);
		node<T>* n=new node<T>(key,value);
		n->next=buckets[i];
		buckets[i]=n;
		cs++;
		
		//load factor
		float lf=(float) cs/ts;
		if(lf>0.7){
			rehash();
		}
	}
	
	//searching
	T* search(string key){
		
		int i=hashFn(key);
		node<T>* temp=buckets[i];
		
		while(temp!=NULL){
			if(temp->key==key){
				return &(temp->value);
			}
			temp=temp->next;
		}
		return NULL;
	}
	
	//operator overloading
	T& operator[](string key){
		T* temp=search(key);
		if(temp==NULL){
			T newBox;
			insert(key,newBox);
			return *search(key);
		}
		return *temp;
	}	
	
	void print(){
		
		for(int i=0;i<ts;i++){
			cout<<"Bucket "<<i<<" - ";
			node<T>* temp=buckets[i];
			while(temp!=NULL){
				cout<<temp->key<<" -> ";
				temp=temp->next;
			}
			cout<<"\n";
		}
		
	}
	
};

