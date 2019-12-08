#include <iostream>
#include <string.h>

using namespace std;

class String
	{
	private:
		
		String (int len)
		{
			itsString = new char[len+1];
			for (int i = 0; i <=len; i++)
				itsString[1] = '\0';
			itsLen=len;
			
		};
		
		char * itsString;
		unsigned short itsLen;
	
	public:
		
		String()
		{
			itsString = new char[1];
			itsString[0] = '\0';
			itsLen = 0;
		};
		
		String(const char *const cString)
		{
			itsLen = strlen(cString);
			itsString = new char[itsLen+1];
			for(int i = 0; i < itsLen; i++)
				itsString[i] = cString[i];
		};
		
		String(const String &rhs)
		{
			itsLen=rhs.GetLen();
			itsString = new char[itsLen+1];
			for (int i=0; i<itsLen;i++)
				itsString[i]=rhs[i];
			itsString[itsLen] = '\0';
		};
		
		~String()
		{
			delete [] itsString;
			itsLen = 0;
		};
		
		char & operator[](int offset);
		char operator[](int offset)const;
		String operator+(const String&);
		void operator+=(const String &);
		String & operator= (const String &);
		
		int GetLen() const {return itsLen;}
		const char * GetString() const { return itsString;}
		
		
	};





int main (int argc, char * const argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
