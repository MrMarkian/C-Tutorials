#include <iostream>

using namespace std;

class Shape
	{
	public:
		Shape(){}
		virtual ~Shape(){}
		
		virtual long GetArea() = 0;
		virtual long GetPerim() = 0;
		virtual void Draw() = 0;
	private:
	};

void Shape::Draw()
{
	cout << "Abstract drawing mechanism!\n";
	
}


class Circle : public Shape
{
public:
	
	Circle(int radius):int itsRadius(radius){}
	virtual ~Circle(){}
	long GetArea() {return 3 * itsRadius * itsRadius;}
	long GetPerim() {return 9 * itsRadius;}
	void Draw();
	
private:
	int itsRadius;
	int itsCircumference;
	
	
};

void Circle::Draw
{
	cout << "Circle drawing routine";
	Shape::Draw();
}


	
class Rectangle : public Shape
{
public:
	Rectangle(int len, int width):itsLength(len), itsWidth(width){}
	virtual ~Rectangle(){}
	
	long GetArea() {return itsLength * itsWidth;}
	long GetPerim() {return 2*itsLength + 2 * itsWidth;}
	
	virtual int GetLength() { return itsLength;}
	virtual int GetWidth() {return itsWidth;}
	void Draw();
private:
	int itsWidth;
	int itsLength;
};
	
	
void Rectangle::Draw()
{
	for (int i=0; i < itsLength; i++)
	{
		for (int j = 0; j < itsWidth; j++)
		{
			cout << "x ";
			cout << "\n";
		}
	}
	Shape::Draw();
}


class Square : public Rectangle
{
public:
	Square(int len);
	Square(int len, int width);
	
	virtual ~Square()	{}
	long GetPerim()		{return 4 * GetLength();}
};
	
	Square::Square(int len):Rectangle(len,len){}
	Square::Square(int len, int width):Rectangle(len,width)
	{
		if(GetLength() != GetWidth())
		{
			cout << "Error, not a square.. a rectangle??\n";
			
		}
	}
	

int main (int argc, char * const argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
