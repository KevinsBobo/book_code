#include <iostream>

// 上机题2、3
// 线性表的顺序存储
#define MAXLEN 100
typedef enum { outOfTheSide = -2, arrIsEmpty = -1} theError;
template <class T>
class CArrTab
{
public:
	CArrTab(){
		len = 0;
	}
	CArrTab(CArrTab &obj){
		len = obj.len;
		memcpy(arr , obj.arr , len);
	}

	theError insert(int i , T e){
		if(i < 0 || i > len)
			return outOfTheSide;
		for(int j = len; j >= i; j--){
			arr[ j ] = arr[ j - 1 ];
		}
		arr[ i ] = e;
		++len;
	}
	theError del(int i , T &e){
		if(i < 0 || i >= len)
			return outOfTheSide;
		else if(len == 0)
			return arrIsEmpty;
		
		e = arr[ i ];
		while(i < len - 1){
			arr[ i ] = arr[ i + 1 ];
			i++;
		}
		--len;
	}
	theError set(int i , T e){
		if(i < 0 || i >= len)
			return outOfTheSide;
		else if(len == 0)
			return arrIsEmpty;

		arr[ i ] = e;
	}
	int find(T e){
		int i = 0;
		for(; i < len; i++){
			if(arr[ i ] = e)
				return i;
		}
		return -1;
	}
	T operator[](int i)
	{
		if(i < len && i >= 0)
			return arr[ i ];
		else
			return (T)-1;
	}

	int getlen(){
		return len;
	}
	void clr(){
		len = 0;
	}
	void echo(){
		for(int i = 0; i < len; i++)
			std::cout << arr[ i ] << " ";
			std::cout << std::endl;
	}
private:
	T arr[ MAXLEN ];
	int len;
};



int main(){
	CArrTab<int> myArr;

	for(int i = 0 ; i < 50 ; i++){
		myArr.insert(i, i);
	}
	myArr.echo();
	myArr.insert(10 , 0);
	myArr.echo();
	int e;
	myArr.del(31 , e);
	std::cout << "delete: " << e << std::endl;
	myArr.echo();
	std::cout << "find: " << myArr.find(5) << std::endl;
	std::cout << "the 6: " << myArr[ 6 ] << std::endl;
	std::cout << "len: " << myArr.getlen() << std::endl;

	return 0;
}