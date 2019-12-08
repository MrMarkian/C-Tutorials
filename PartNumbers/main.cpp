#include <iostream>

/*
 Description:
	Provide a linked list demo program
 
	Holds Part Numbers and potentially other information about parts
 */

using namespace std;

class Part //Abstract base class of parts
	{

	private:
		int itsPartNumber;

	public:
		Part():itsPartNumber(1){;}
		Part(int PartNumber):itsPartNumber(PartNumber){;}
		
		virtual ~Part(){};
		int GetPartNumber() const {return itsPartNumber;}
		virtual void Display() const = 0; // must be overridden
		

		
		
	};

void Part::Display() const
{
	cout << "\nPart Number: " << itsPartNumber << endl;
}


//*** Car Part

class CarPart : public Part
	{
	private:
		int itsModelYear;
		
	public:
		CarPart():itsModelYear(94){}
		CarPart(int year, int PartNumber);
		virtual void Display() const
		{
			Part::Display(); cout << "Model Year:";
			cout << itsModelYear << endl;
		}
		
	};
CarPart::CarPart(int year, int PartNumber):itsModelYear(year), Part(PartNumber){}


class AirPlanePart : public Part
	{
	private:
		int itsEngineNumber;
	public:
		AirPlanePart():itsEngineNumber(1){};
		AirPlanePart(int EngineNumber, int PartNumber);
		
		virtual void Display() const
		{
			Part::Display(); cout << " Engine No: ";
			cout << itsEngineNumber << endl;
			
		}
	};

AirPlanePart::AirPlanePart(int EngineNumber, int PartNumber):itsEngineNumber(EngineNumber), Part(PartNumber){}


//***Part Nodes


class PartNode
	{
	public:
		PartNode (Part*);
		~PartNode();
		
		void SetNext(PartNode * node) {itsNext = node;}
		PartNode * GetNext() const;
		Part *GetPart() const;
	private:
		Part *itsPart;
		PartNode *itsNext;
	};
PartNode::PartNode(Part *pPart):itsPart(pPart),itsNext(0){}

PartNode::~PartNode()
{
	delete itsPart;
	itsPart = 0;
	delete itsNext;
	itsNext = 0;
}

PartNode *PartNode::GetNext() const
{
	return itsNext;
}

Part *PartNode::GetPart() const
{
	if (itsPart)
		return itsPart;
	else {
		return NULL; // error
	}

}

//** Part List

class PartsList
	{
	public:
		PartsList();
		~PartsList();
		
		Part *Find(int &position, int PartNumber) const;
		int GetCount() const {return itsCount;}
		
		Part *GetFirst() const;
		static PartsList & GetGlobalPartsList()
		{
			return GlobalPartsList;
		}
		void Insert(Part *);
		void Iterate(void (Part::*f)()const) const;
		Part * operator[](int) const;
		
		
	private:
		PartNode *pHead;
		int itsCount;
		static PartsList GlobalPartsList;
	};

PartsList PartsList::GlobalPartsList;

PartsList::PartsList():pHead(0), itsCount(0){}
PartsList::~PartsList(){delete pHead;}

Part * PartsList::GetFirst() const
{
	if (pHead)
		return pHead->GetPart();
	else {
		return NULL;
		
	}

}

Part * PartsList::operator[](int offSet) const
{
	PartNode * pNode = pHead;
	if (!pHead)
		return NULL;
	if (offSet > itsCount)
		return NULL;
	for (int i=0; i < offSet; i++)
		pNode = pNode->GetNext();
	
	return pNode->GetPart();
}

Part * PartsList::Find(int & position, int PartNumber) const
{
	PartNode * pNode = 0 ;
	for (pNode = pHead, position = 0, pNode !=NULL; pNode = pNode->GetNext(); position++)
	{
		if (pNode->GetPart()->GetPartNumber() == PartNumber)
			break;
	}
	if (pNode == NULL)
		return NULL;
	else {
		return pNode->GetPart();
	}

}

void PartsList::Iterate(void (Part::*func)()const) const
{
	if (!pHead)
		return;
	PartNode * pNode = pHead;
	do
		(pNode->GetPart()->*func)();
	while (pNode = pNode->GetNext());
}

void PartsList::Insert(Part * pPart)
{
	PartNode * pNode = new PartNode(pPart);
	PartNode * pCurrent = pHead;
	PartNode * pNext = 0;
	
	int New = pPart->GetPartNumber();
	int Next = 0;
	
	itsCount++;
	
	if(!pHead)
	{
		pHead = pNode;
		return;
	}
	
	if (pHead->GetPart()->GetPartNumber() > New)
	{
		pNode->SetNext(pHead);
		pHead = pNode;
		return;
	}
	
	for (;;) // ever
	{
		if (!pCurrent->GetNext())
		{
			pCurrent->SetNext(pNode);
			return;
		}
		
		pNext = pCurrent->GetNext();
		Next = pNext->GetPart()->GetPartNumber();
		if (Next > New)
		{
			pCurrent->SetNext(pNode);
			pNode->SetNext(pNext);
			return;
		}
		pCurrent = pNext;
	}
}

int main (int argc, char * const argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
	
	PartsList &pl = PartsList::GetGlobalPartsList();
	Part * pPart = 0;
	int PartNumber;
	int Somevalue;
	int choise;
	
	while (1)
	{
		cout << "(0)Quit, (1) Car, (2)Plane: ";
		cin >> choise;
		if(!choise)
			break;
		cout << "New PartNumber?: ";
		cin >> PartNumber;
		if(choise == 1)
		{
			cout << "Model year?: ";
			cin >> Somevalue;
			pPart = new CarPart(Somevalue, PartNumber);
		}
		else {
			cout << "Engine Number?: ";
			cin >> Somevalue;
			pPart = new AirPlanePart(Somevalue,PartNumber);
		}
		pl.Insert(pPart);

	}
	
	void (Part::*pFunc)()const = &Part::Display;
	pl.Iterate(pFunc);
	
	
    return 0;
}
