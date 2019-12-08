#include <iostream>

using namespace std;

class Horse {

public: 
	void Gallop() {cout << "Galloping!.. \n";}
	virtual void Fly() {cout << "Horses Cant Fly!..\n";}
	
	void SetAge(int Age) {itsAge = Age;}
	void PrintAge() {cout << "Im " << itsAge << " Years Old..";}
	
private:
	int itsAge;
	
};


class Pegasus: public Horse {

public: 
	virtual void Fly() {cout << "I Can Fly!...\n";}
};

//Global Variables
int NumberOfHorses = 5;



int main (int argc, char * const argv[]) {
    
	int choice, i;
	
    std::cout << "Hello, World!\n";
	cout << "\n Please Enter Number of Animals:";
	cin >> NumberOfHorses;
	
	Horse * Ranch[NumberOfHorses];
	Horse * pHorse;
	

	
	for (i=0; i < NumberOfHorses; i++)
	{
		cout << "(1) Horse (2) Pegasus: ";
		cin >> choice;
		
		if(choice == 2)
			pHorse = new Pegasus;
		else
			pHorse = new Horse;
		
		
		cout << "Whats the Animals Age?:";
		cin >> choice;
		pHorse->SetAge(choice);
		Ranch[i] = pHorse;
	}
	cout << "\n";
	
	for (i=0 ; i < NumberOfHorses; i++)
	{
		Pegasus *pPeg = dynamic_cast<Pegasus *> (Ranch[i]);
	if(pPeg)
		pPeg->Fly();
	else
		cout << "Just a Horse\n";
		Ranch[i]->PrintAge();
	delete Ranch[i];
	}
    
	return 0;
}
