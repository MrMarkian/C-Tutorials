#include <iostream>

using namespace std;

class Cat
	{
	public:
		Cat(int Age):itsAge(Age){HowManyCats++;}
		virtual ~Cat(){HowManyCats--;}
		virtual int GetAge(){return itsAge;}
		virtual void SetAge(int age) {itsAge = age;}
		static int HowManyCats;
	private:
		int itsAge;
	};

int Cat::HowManyCats = 0;



int main (int argc, char * const argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
	
	const int MaxCats = 5; int i;
	
	Cat *CatHouse[MaxCats];
	
	for (i = 0 ; i < MaxCats; i++)
		CatHouse[i] = new Cat(i);
	
	for (i = 0; i < MaxCats; i++)
	{
		cout << "There are ";
		cout << Cat::HowManyCats;
		cout << " cats left!\n";
		cout << "Deleting the one which is ";
		cout << CatHouse[i]->GetAge();
		cout << " years old\n";
		
		delete CatHouse[i];
		CatHouse[i] = 0;
	}
	
	
    return 0;
}
