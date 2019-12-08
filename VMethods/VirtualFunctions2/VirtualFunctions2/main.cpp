//
//  main.cpp
//  VirtualFunctions2
//
//  Created by Macbook Pro on 07/06/2018.
//  Copyright © 2018 Macbook Pro. All rights reserved.
//

#include <iostream>

using namespace std;

class Mammal
{
    
protected:
    int itsAge;
public:
    Mammal():itsAge(1){cout<<"Mammal Constructor\n";}
    
    virtual ~Mammal() { cout << "Mammal Destructor\n";}
    void Move() const { cout << "Mammal Move One Step!\n";}
    
    virtual void Speak() const {cout << "Mammal Speak";}
    
};

class Dog : public Mammal
{
protected:
    
public:
    Dog() { cout << "Dog Constructor..\n";}
    virtual 
};