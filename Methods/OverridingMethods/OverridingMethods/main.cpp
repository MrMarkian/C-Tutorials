//
//  main.cpp
//  OverridingMethods
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
    int itsWeight;
    
public:
    void Move() const { cout << "Mammal Move One Step\n";}
    void Move(int distance) const{ cout << "Mammal Move " << distance; cout << " Steps\n";}
    
    
};

class Dog:public Mammal
{
    
public:
    void Move()const {cout << "In Dog.. Move... \n"; Mammal::Move();}

    
    
};

int main(){
    Mammal bigAnimal;
    Dog Fido;
    
    bigAnimal.Move(2);
    Fido.Mammal::Move(6);
    
    return 0;
}