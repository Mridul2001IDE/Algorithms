// vector own implementation
class Vector{
	//encapsulation
	int *arr;
	int cs; //current size
	int ms; //max size
	
public:
	//s is passed as size of vector
	Vector(int s=4){
		arr=new int[s];
		cs=0;
		ms=s;
	}	
	
	void push_back(const int d){
		if(cs==ms){
			//expand the vector if full
			//create a new array of double the prev size
			int *oldArr=arr;
			int oldSize=ms;
			ms=ms<<1;
			arr=new int[ms];
			
			for(int i=0;i<cs;i++){
				arr[i]=oldArr[i];	
			}
						
			delete[] oldArr;
			oldArr=NULL;
		}
		arr[cs]=d;
		cs++;
	}
	
	void pop_back(){
		
		if(cs>0) cs--;
		
	}
	
	int size() const{
		return cs;
	}
	
	int capacity() const{
		return ms;
	}
	
	//get ith element
	int operator[](int i){
		return arr[i];
	}
	
};
