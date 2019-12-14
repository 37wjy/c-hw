/*
	Write a GrowArray class that is templated, and that allows you to 
	allocate memory but not call the constructor for each element.
	To do this you will have to cast and use placement new syntax.

	See placementnew.cc, GrowArray.cc
	You are encouraged to write the class from scratch without looking at 
	my code, once you understand the fundamentals.

*/

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

class Person {
private:
	uint32_t len;
	char* name;
public:
	Person(const char n[]) : len(strlen(n)) {
		cout << "Person constructor\n";
		name = new char[len];
		memcpy(name, n, len);
	}
	Person(const Person& orig) : len(strlen(orig.name)){
		cout << "copying Person\n";
		name = new char[len];
		memcpy(name, orig.name, len);
	}
	~Person() {
		cout << "Destructor\n";
		delete [] name;
	}
};

/*
	You can write your code here
 */

template<typename T> 
class GrowArray{
private:
    /* data */
    T* data;
    uint64_t f;
    uint64_t n;

public:
    GrowArray(uint64_t n) :data((T*)new char[n * sizeof(T)]),n(n),f(0){}
    ~GrowArray() {;}
    void add(T obj){
        data[f]=Person(obj);
        f++;
    }
};


int main() {
	GrowArray<Person> list(1000000); // should not call constructor for Person!
	list.add(Person("Test")); // Should call the constructor once and the copy once
	/*
		Destructor should be called twice for person (once for the temp, and once for 
		the object in the array. If the optimizer somehow can do it, it could be only once. 
		But most important, you must not call the destructor 1000000 times!
	*/
}
