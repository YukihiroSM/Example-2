#include "module.h"
int main()
{
	element *current, *top;
	
	int howToEnterList = 0;
	cout << "\aAttention! You should use only 10 or less-symbols words!" << endl;
	cout << "Hello, if you want to type your list, push 1. \nIf you want to get it from file, write your list to file \"Input.txt\" and push 2: ";
	cin >> howToEnterList;
	switch(howToEnterList){
		case 1: 
			top = EnterList();
			current = top;
			break;
		case 2:
			top = EnterListFromFile();
			current = top;
			break;
		default: 
			cout << "Whong number!" << endl;
			exit(0);
			break;
	}

	showList(top);
	chooseFunction(top);

	return 0;
}

