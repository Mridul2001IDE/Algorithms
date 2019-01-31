#include<bits/stdc++.h>
#include<unordered_map>
# define mp make_pair<string,Fruit>

using namespace std;
class Fruit{
	
	public:
		string name;
		int price;
		string city;
		string country;
		
		Fruit(){}
		
		Fruit(string n,string c,int p){
			name=n;
			city=c;
			country="INDIA";
			price=p;
		}
		
};

int main(){
	
	unordered_map<string , Fruit>hf;
	
	Fruit f("Guava","Goa",100);
	Fruit f2("Apple","Himachal",120);
	Fruit f3("kiwi","Delhi",20);
	
	hf.insert(mp(f.city,f));
	hf.insert(mp(f2.city,f2));
	hf.insert(mp(f3.city,f3));
	string city;
	cout<<"Enter city:";
	cin>>city;
	
	auto fs=hf.find(city);
	if(fs!=hf.end()){
		cout<<fs->first<<" "<<fs->second.name;
	}
	
	return 0;
}
