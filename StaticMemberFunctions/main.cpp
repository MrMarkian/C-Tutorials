#include <iostream>

using namespace std;

class Cat
	{
	private:
		int itsAge;
		static int HowManyCats;	
		
	public:
		Cat(int age):itsAge(age){HowManyCats++;}
		virtual ~Cat(){HowManyCats--;}
		
		virtual int GetAge(){return itsAge;}
		virtual void SetAge(int age) {itsAge = age;}
		static int GetHowMany(){return HowManyCats;}
		
		

	};
int Cat::HowManyCats = 0;

void TelepathicFunction();

int main (int argc, char * const argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
	const int MaxCats = 5;
	Cat *CatHouse[MaxCats]; int i;
	
	for (i=0; i < MaxCats; i++)
	{
		CatHouse[i] = new Cat(i);
		TelepathicFunction();
	}
	
	for (i =0; i < MaxCats; i++)
	{
		delete CatHouse[i];
		TelepathicFunction();
	}
	
	
	return 0;
	
	}

void TelepathicFunction(){
	
	cout << "There are " << Cat::GetHowMany() << " cats alive! \n";
	
	}
