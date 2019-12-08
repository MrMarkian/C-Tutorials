//
//  main.cpp
//  VirtualMethods
//
//  Created by Macbook Pro on 07/06/2018.
//  Copyright © 2018 Macbook Pro. All rights reserved.
//

#include <iostream>

using namespace std;

class Mammal
{
public:
    
    Mammal():itsAge(1) {cout << "Mammal Constructor...\n";}
    virtual ~Mammal() {cout << "Mammal destructor...\n";}
    
    void Move() const { cout << "Mammal move one step...\n";}
    virtual void Speak() const { cout << "Mammal Speak!\n";}
    
    
    
    
protected:
    int itsAge;
};


class Dog : public Mammal
{
protected:
    int CountMammals;
    
public:
    Dog() {cout << "Dog Constructor";}
    
    virtual ~Dog() {cout << "Dog destructor...\n";}
    
    void WagTail() {cout << "Wagging Tail...1n";}
    
    void Speak() const {cout << "Woof!\n";}
    void Move() const {cout << "Dog Moves 5 steps...\n";}
    int Count() const {return CountMammals;}
};

class Cat: public Mammal
{
protected:
    int numCats;
    
public:
    Cat() {numCats++;}
    virtual ~Cat() {numCats--;}
    
    void Speak() const {cout << "Meow!\n";}
    int Count() const {return numCats;}
};

int main()
{
    

    Mammal *pDog = new Dog;
    pDog->Move();
    pDog->Speak();
    
    pDog = new Cat;
    
    pDog->Speak();
    pDog->Count();
    
    
    return 0;
}



