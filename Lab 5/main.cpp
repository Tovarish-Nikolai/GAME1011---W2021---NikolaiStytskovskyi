#include <iostream>
#include "DynTempStack.h"
#include "DynTempQueue.h"

using namespace std;

class Object
{
private:
	int value;
	char letter;
public:
	Object(int v = 1, char c = 'a') { value = v; letter = c; }

	friend ostream& operator<<(ostream& os, const Object& obj)
	{
		os << "Value of this Object: " << obj.value <<
			" Letter of this object: " << obj.letter << endl;
		return os;
	}
};

int main()
{
	Object objectOne(1, 'a'),
		objectTwo(2, 'b'),
		objectThree(3, 'c'),
		objectFour(4, 'd'),
		objectFive(5, 'e');

	cout << " Creating 2 DynTempStack objects.. " << endl;
	DynTempStack<int> intStack;
	DynTempStack<Object> objectStack;

	cout << "\n [1] Pushing 69 into the Integer DynTempStack object.." << endl;
	intStack.push(69);
	cout << " [2] Pushing Object One into the Object DynTempStack object.." << endl;
	objectStack.push(objectOne);

	cout << "\n Displaying DTS object one : \n" << endl;
	intStack.displayStack(intStack.getTop());
	cout << "\n Displaying DTS object two : \n" << endl;
	objectStack.displayStack(objectStack.getTop());

	cout << "\n [3 & 4] Popping both DTSs.." << endl;
	int catchVar;
	Object catchObj;

	intStack.pop(catchVar);
	objectStack.pop(catchObj);

	intStack.displayStack(intStack.getTop());
	objectStack.displayStack(objectStack.getTop());

	system("pause");
	system("CLS");

	cout << " [5 & 6] Pushing 1337 and 420 into the INT DTS object.." << endl;
	intStack.push(420);
	intStack.push(1337);

	cout << " [7 & 8] Pushing Object Two and Object Three into the OBJ DTS object.." << endl;
	objectStack.push(objectTwo);
	objectStack.push(objectThree);

	cout << "\n Displaying INT DTS with two integers: " << endl;
	intStack.displayStack(intStack.getTop());
	
	cout << "\n Displaying OBJ DTS with two objects: " << endl;
	objectStack.displayStack(objectStack.getTop());

	cout << "\n [9] Pushing one more number on top of the INT DTS.." << endl;
	intStack.push(69);
	cout << "\n [10] Pushing one more Object on top of the OBJ DTS.." << endl;
	objectStack.push(objectFive);

	cout << "\n Displaying :" << endl;

	intStack.displayStack(intStack.getTop());
	objectStack.displayStack(objectStack.getTop());

	cout << "\n [11] Popping two integers off the INT DTS.." << endl;
	intStack.pop(catchVar);
	cout << "\n [12] Popping two Objects off the OBJ DTS.." << endl;
	objectStack.pop(catchObj);  

	cout << "\n Displaying :" << endl;

	intStack.displayStack(intStack.getTop());
	objectStack.displayStack(objectStack.getTop());

	system("pause");
	system("CLS");

	cout << "\n Creating 2 DynTempQueue objects.." << endl;
	DynTempQueue<int> intQueue;
	DynTempQueue<Object> objectQueue;

	cout << "\n [1, 2 & 3] Pushing values 12 24 and 37 into Integer DynTempQueue.." << endl;

	intQueue.enqueue(12);
	intQueue.enqueue(24);
	intQueue.enqueue(37);

	cout << "\n [4, 5 & 6] Pushing three objects into Object DynTempQueue.." << endl;

	objectQueue.enqueue(objectFive);
	objectQueue.enqueue(objectThree);
	objectQueue.enqueue(objectOne);

	cout << "\n Displaying INT DTQ.." << endl;
	intQueue.displayQueue(intQueue.getFront());

	cout << "\n Displaying OBJ DTQ.." << endl;
	objectQueue.displayQueue(objectQueue.getFront());

	system("pause");
	system("CLS");

	cout << " [7 & 8] Popping 2 values off INT DTQ.." << endl;
	intQueue.dequeue(catchVar);
	intQueue.dequeue(catchVar);

	cout << " [9 & 10] Popping 2 Objects off OBJ DTQ.." << endl;
	objectQueue.dequeue(catchObj);
	objectQueue.dequeue(catchObj);

	cout << " Displaying INT DTQ.. " << endl;
	intQueue.displayQueue(intQueue.getFront());

	cout << " Displaying OBJ DTQ.. " << endl;
	objectQueue.displayQueue(objectQueue.getFront());

	cout << "\n\n\n\n That's it folks! \n\n\n\n\n" << endl;

	return 0;
}