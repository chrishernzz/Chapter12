#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//precondition: creating a student class to get data
//postcondition: passing in privates of the student information and using getters and setters to do the information
class Student{
private:
	int studentID;
	string name;
	string major;
	double gpa;
public:
	Student();
	void setStudentID(int newID);
	int getStudentID() const;
	void setName(string newName);
	string getName() const;
	void setMajor(string newMajor);
	string getMajor() const;
	void setGPA(double newGPA);
	double getGPA() const;

	friend ostream& operator <<(ostream& outs, const Student& obj);
	friend bool operator !=(const Student& obj1, const Student& obj2);
	friend bool operator ==(const Student& obj1, const Student& obj2);
};