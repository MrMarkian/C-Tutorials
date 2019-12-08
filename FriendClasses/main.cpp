#include <iostream>

using namespace std;

class Part
	{
	public:
		Part():itsPartNumber(1){};
		Part(int PartNumber):itsPartNumber(PartNumber){};
		
		virtual ~Part(){};
		
		int GetPartNumber() const {return itsPartNumber;}
		
		virtual void Display() const =0;
		
		
	private:
		int itsPartNumber;
	};

class CarPart : public Part
	{
	private:
		int itsModelYear;
	
	public:
		CarPart():itsModelYear(94){};
		CarPart(int year, int PartNumber):itsModelYear(year), Part(PartNumber){};
		virtual void Display() const
		{
			Part::Display();
			cout << "Model Year:" ;
			cout << itsModelYear << endl;
		}
	};


class AirplanePart: public Part {
private:
	int itsEngineNumber;
	
public:
	AirplanePart():itsEngineNumber(1){};
	AirplanePart(int EngineNumber, int PartNumber):itsEngineNumber(EngineNumber), Part(PartNumber){};
	
	virtual void Display() const
	{
		Part::Display();
		cout << "Engine No..:";
		cout << itsEngineNumber << endl;
	}
};

class PartNode
	{
	private:
		Part *itsPart;
		PartNode *itsNext;
		
	public:
		friend class PartsList;
		PartNode (Part * pPart):itsPart(pPart), itsNext(0){	};
		~PartNode()
		{
			delete itsPart;
			itsPart = 0;
			delete itsNext;
			itsNext = 0;
		};
		
		void SetNext(PartNode * node){itsNext = node;}
		
		PartNode * GetNext() const {return itsNext;}
		
		
		Part * GetPart() const
		{
			if(itsPart)
				return itsPart;
			else {
				return NULL;
			}

		}
		
	};


class PartsList
	{
	private:
		PartNode * pHead;
		int itsCount;
		static Partslist GlobalPartsList;
		
	public:
		PartsList():pHead(0),itsCount(0){}
		
		~PartsList();
		
		void Iterate(void (Part::*f)()const) const;
		Part* Find(int & position, int PartNumber){return 0;}
		
		Part * GetFirst() const
		{
			if(pHead)
				return pHead->itsPart;
			else {
				return NULL;
			}

		}
		void Insert(Part *);
		Part* operator[](int offset) const
		{
			PartNode * pHead = pHead;
			
			if(!pHead)
				return NULL;
		}
		int GetCount() const {return itsCount;}
		
		static Partslist & GetGlobalPartsList()
		{
			return GlobalPartsList; 
		}
		
		
		
	};


Partslist Partslist::GlobalPartsList;


int main (int argc, char * const argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
