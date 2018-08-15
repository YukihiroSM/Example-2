#include "module.h"
element *last;
//=====================================================================
element* EnterList()
{	
	element *first, *current;
	
	string answer, temp;

	cout << "Enter first string: ";
	first = current = new element;
	//cin >> temp;
	cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (true)
	{
		
		char ch = cin.get();
		if (ch != '\n')
			temp += ch;
		else{
			
			break;
		}
	}		
	
	if(temp.length() > 10){cout << "Input error! Stopping program..." << endl; exit(-3);}
	
	for(int i = 0; i < temp.length(); i++){
		current->str[i] = temp[i];
	}
	current->length = temp.length();
	cout << "Do you want enter one more string?(y/n): ";
	cin >> answer;
	while(answer == "y"){
		temp = "";
		char ch1;
		cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter string: ";
		while (true)
		{
			ch1 = cin.get();
			if (ch1 != '\n'){
				temp += ch1;
			}
			else
				break;
		}			
		current->next = new element;
		current = current->next;
		
		if(temp.length() > 10){cout << "Input error! Stopping program..." << endl; exit(-3);}
		for(int i = 0; i < temp.length(); i++){
			current->str[i] = temp[i];
		}
		current->length = temp.length();
		cout << "Do you want enter one more string?(y/n): ";
		cin >> answer;
	}
	if(answer != "n") {cout << "Input error!" << endl; exit(-3);}
	current->next = NULL;
	last = current;
	
	return first;
}
//=====================================================================

element* EnterListFromFile()
{
	element *first, *current;
	ifstream fin("input.txt", ios::in);
	
	if(!fin)
	{
		cout << "Can't open file. Had you created it?";
		exit(-5);
	}
	first = current = new element;
	long lSize;
	char *buffer;
	string word;
	//Определение размера файла
	fin.seekg(0 , ios::end);
 	lSize = fin.tellg();
 	fin.seekg(0);
	//Выделение памяти под всё, что находится в файле
	buffer = new (nothrow) char[lSize];
  	if (buffer == NULL) {
	  cerr << "It seems, that file is empty";
	  exit(2);
	}
	//================================================
	//Reading
	fin.read(buffer, lSize);
 	if (!fin) {
		cerr << "Can't read file'";
		exit(3);
	}
	//================================================
	for(long i = 0; i < lSize; i++){
		if(buffer[i] == '\n' || i == lSize-1){
			if(word.length() > 10){
				cout << "Input error!\nStopping program..." << endl;
				exit(-4);
			}
			else{
				current->length = word.length();
				for(int j = 0; j < word.length(); j++){
					current->str[j] = word[j];
					
				}
			}
			if(i != lSize-1){
				current->next = new element;
				current = current->next;
			}
			word = "";
		}
		else
			word = word + buffer[i];
	}
	current->next = NULL;
	last = current;
	
	return first;
}


//=====================================================================
int writeToFile(element* list)
{
	if(!list)
	{
		cout << "List is empty!" << endl;
		return -1;
	}
	ofstream fout("list.txt", ios::trunc);
	if(!fout)
	{
		cout << "Can't open file to write!" << endl;
		return -2;
	}
	int i = 1;
	while(list)
	{
		fout << "Element #" << i << ":\n\tString: ";
		for(int j = 0; j < list->length; j++){
			fout << list->str[j];
		}
		fout << "\n\tAdress of element: "; 
		fout << list ;
		if(list->next != NULL){
			fout << "\n\tAdress of next element: "; 
			fout << list->next << "\n";
		}
		list = list->next;
		i++;
	}
	cout << "Finished succesfull." << endl;
	return 0;
	
}

//=====================================================================
void showList(element* list)
{
	if(!list)
	{
		cout << "List is empty!" << endl;
		exit(-1);
	}
	int i = 1;
	cout << "Your list is:" << endl;
	while(list)
	{
		cout << i << ". \"";
		for(int j = 0; j < list->length; j++){
			cout << list->str[j];	
		}
		cout << "\";" << endl;
		i++;
		list = list->next;
	}	
}

//=====================================================================
int countFirst(element* list)
{
	int count = 0;
	if(!list)
	{
		cout << "List is empty!" << endl;
		exit(-1);
	}
	while(list){
		char first_l, last_l;
		first_l = list->str[0];
		last_l = list->str[list->length-1];
		if(first_l == last_l) count++;
		list = list->next;
	}
	return count;
}
//=====================================================================
int countSecond(element* list)
{
	int count = 0;
	if(!list)
	{
		cout << "List is empty!" << endl;
		exit(-1);
	}
	element *current_el, *next_el;
	while(list)
	{
		current_el = list;
		if(list->next != NULL){
			next_el = list->next;
			if(current_el->str[0] == next_el->str[0])
				count++;
		}
		list = list->next;
		
	}
	return count;
}
//=====================================================================
int countThird(element* list)
{
	if(!list){
		cout << "List is empty!" << endl;
		exit(-1);
	}
	int count = 0;
	string temp_curr, temp_last;
	while(list)
	{
		temp_curr = "";
		temp_last = "";
		if(list->next != NULL){ 
			for(int i = 0; i < list->length; i++){
				temp_curr += list->str[i];
			}
			for(int i = 0; i < last->length; i++){
				temp_last += last->str[i];
			}
			if(temp_curr == temp_last)
				count++;
		}
		list = list->next;
	}
	return count;
}
//=====================================================================
void chooseFunction(element* top){
	string answer;
	int choise;
	cout << "Choose function, which you want to apple to this list:";
	cout << "\nType 1 to count the number of words that begin and end with the same letter.\n";
	cout << "Type 2 to count the number of words that begin with the same letter as next.\n";
	cout << "Type 3 to count the number of words that are the same with last\n";
	cout << "Type 4 to write your list into file\n";
	cout << "Type 0 to exit program.\nYour choise: ";
	cin >> choise;
	while(choise < 0 || choise > 4){
		cout << "Wrong number. Try again: ";
		cin >> choise;	
	}
	switch(choise){
		case 1:
			cout << "Number of elements: " << countFirst(top) << endl;
			break;
		case 2:
			cout << "Number of elements: " << countSecond(top) << endl;
			break;
		case 3:
			cout << "Number of elements: " << countThird(top) << endl;
			break;
		case 4:
			writeToFile(top);
			break;
		default: 
			cout << "Bye!" << endl;
			exit(0);
			break;
	}
	cout << "Do you want to do something more?(y/n): ";
	cin >> answer;
	
	if(answer == "y") chooseFunction(top);
	else {
		cout << "Bye!" << endl;
		exit(0);
	}
}