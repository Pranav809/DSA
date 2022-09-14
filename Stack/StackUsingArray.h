template<typename T>
class StackUsingArray{
	
	T *data;
	int nextIndex;
	int capacity;
	
	public:
		StackUsingArray(){
			data = new T[4];
			nextIndex = 0;
			capacity = 4;
		}
		
		int size(){
			return nextIndex;
		}
		
		bool isEmpty(){
			return nextIndex == 0;
		}
		
		void push(T element){
			T *newData = new T[2 * capacity];
			if(nextIndex == capacity){
				for(int i=0;i<capacity;i++){
					newData[i] = data[i];
				}
				capacity *= 2;
				delete [] data;
				data = newData;
			}
			data[nextIndex] = element;
			nextIndex++;
		}
		
		T pop(){
			if(isEmpty()){
				cout << "Stack empty" << endl;
				return 0;
			}
			nextIndex--;
			return data[nextIndex];
		}
		
		T top(){
			if(isEmpty()){
				cout << "Stack empty" << endl;
				return 0;
			}
			return data[nextIndex-1];
		}
};
