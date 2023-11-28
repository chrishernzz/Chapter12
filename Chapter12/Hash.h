#pragma once
#include<iostream>
#include"Student.h"
#include"string"
#include<vector>
#include<fstream>
using namespace std;

char inputChar(string prompt, string options);
int inputInteger(string prompt, int startRange, int endRange);
int inputInteger(string prompt, bool posNeg);
string inputString(string prompt, bool spaces);
double inputDouble(string prompt, double startRange, double endRange);

//precondition: creating a has class
//postcondition: creating a vector to keep track of the student data
class Hash{
private:
	vector<Student> s;
	int size;
public:
	void hashMenu();
	void initializeVector();
	int hash(int key);
	void hashDisplay();
	void hashSearch();
	void hashDelete();
	void hashInsert();
};