//merge 2 sorted array
#include<iostream>
using namespace std;

void merge(int *a,int *b){
	
	int arr[100];
	int i=0,j=0,k=0;
	
	while(a[i]!='\0'||b[j]!='\0'){
		if(a[i]<b[j]){
			arr[k]=a[i];
			k++;
			i++;
		}else if(a[i]>b[j]){
			arr[k]=b[j];
			k++;
			j++;
		}else {
			arr[k]=b[j];
			j++;
			i++;
		}
	}
	
	if(a[i]!='\0'){
		while(a[i]!='\0'){
			arr[k]=a[i];
			k++;
			i++;
		}
	}
	
	if(b[j]!='\0'){
		while(b[j]!='\0'){
			arr[k]=b[j];
			k++;
			j++;
		}
	}
	
	for(int i=0;i<k;i++) cout<<arr[i]<<" ";
	
}

int main(){
	
	int a[]={1,9,10};
	int b[]={2,7,8};
	merge(a,b);
	return 0;
}
