#include <iostream>

enum BREED {GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LABRADOR};

class Mammal {

protected:
	int itsAge;
	int itsWeight;
	
public:
	//Constructors
	int GetAge() const {return itsAge;}
	void SetAge(int age) {itsAge = age;}
	
	void SetWeight(int weight) {itsWeight = weight;}
	int GetWeight() const {return itsWeight;}
	
};


class Dog : public Mammal {

public:
	Dog();
	Dog(int age);
	Dog(int age, int weight);
	Dog(int age, BREED breed);
	Dog(int age, int weight, BREED breed);
	~Dog();
	
	
private: 
	BREED itsBreed;
}

int main (int argc, char * const argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

