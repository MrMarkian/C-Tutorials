//
//  main.cpp
//  Derived
//
//  Created by Macbook Pro on 07/06/2018.
//  Copyright © 2018 Macbook Pro. All rights reserved.
//


#include <iostream>

using namespace std;


enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB};

class Mammal
{
public:
    Mammal():itsAge(2), itsWeight(5){};
    ~Mammal(){}
    
    //accessors
    
    int GetAge() const { return itsAge;}
    
    void SetAge(int age){itsAge = age;}
    
    int GetWeight() const {return itsWeight;}
    void SetWeight(int weight) {itsWeight = weight;}
    
    void Speek() const {cout << "Mammal Sound\n";}
    
protected:
    int itsAge;
    int itsWeight;
    
    
};

class Dog:public Mammal{

public:
    //constructors
    Dog():itsBreed(GOLDEN){}
    ~Dog(){}
    
    BREED GetBreed() const {return itsBreed;}
    void SetBreed(BREED breed) {itsBreed = breed;}

    void WagTail() const {cout << "Tail Wagging... \n";}
    void BegForFood() const { cout << "Begging For Food";}
    
private:
    BREED itsBreed;
    
};

int main()
{
    
    Dog fido;
    fido.Speek();
    fido.WagTail();
    
    
    
    cout << "Fido is " << fido.GetAge() << " Years Old\n";
    
    return 0; 
}









