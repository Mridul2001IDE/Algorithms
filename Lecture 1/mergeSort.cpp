#include<iostream>
using namespace std;

void merge(int a[],int x[],int y[],int s,int e){
	int mid=(s+e)/2;
	int i=s,j=mid+1,k=s;
	
	while(i<=mid&&j<=e){
		if(x[i]<y[j]){
			a[k]=x[i];
			k++;
			i++;
		}else{
			a[k]=y[j];
			k++;
			j++;
		}
	}
	

	while(i<=mid){
		a[k++]=x[i++];
	}
	

	while(j<=e){
		a[k++]=y[j++];
	}
	
	return;
}

void mergeSort(int a[],int s,int e){
	//base case
	if(s>=e) return;
	
	//rec call
	// divide into 2 parts
	int x[100],y[100];
	int mid=(s+e)/2;
	
	for(int i=0;i<=mid;i++){
		x[i]=a[i];
	}
	
	for(int i=mid+1;i<=e;i++){
		y[i]=a[i];
	}
	
	//sort them recur
	mergeSort(x,s,mid);
	mergeSort(y,mid+1,e);
	
	//merge the sorted array
	merge(a,x,y,s,e);
	
	
}

int main(){
	int a[]={5,7,6,8,3,1};
	int n=sizeof(a)/sizeof(int);
	mergeSort(a,0,n-1);
	
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	
	return 0;
}
