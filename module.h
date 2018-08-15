#ifndef MODULE_H_INCLUDED
    #define MODULE_H_INCLUDED
#endif // MODULE_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <limits>
//#include <conio.h>

using namespace std;

//Structures
typedef char TE[10];
struct element
{
	TE str;
	int length;
	element* next;
};
//============================
//Variables

//=============================
//Functions
element* EnterList();//Entering list
element* EnterListFromFile();

int writeToFile(element*);//Writing list to file
void showList(element*);//Showing list to console
int countFirst(element*);//Counts the number of words that begin and end with the same letter
int countSecond(element*);//Counts the number of words that begin with the same letter as next
int countThird(element*);//Counts the number of words that are the same with last
void chooseFunction(element*);
//============================