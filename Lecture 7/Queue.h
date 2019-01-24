template<typename T>
//implementing circular queue
class Queue{
	
	int f,r;
	//max size
	int ms;
	//current size
	int cs;
	T *arr;
	public:
	Queue(int s=5){
		f=0;
		r=ms-1;
		ms=s;
		cs=0;
		arr=new T[ms];
	}
	
	void push(T data){
		if(cs<ms){
			r=(r+1)%ms;
			arr[r]=data;
			cs++;
		}
	}
	
	void pop(){
		if(cs>0){
		f=(f+1)%ms;
		cs--;
	}
	}
	
	T front(){
		return arr[f];
	}
	
	bool isEmpty(){
		return cs==0;
	}
	
	bool isFull(){
		return cs==ms;
	}
	
	int size(){
		return cs;
	}
	
	~Queue(){
		if(arr!=NULL)
		delete[] arr;
	}
	
};
