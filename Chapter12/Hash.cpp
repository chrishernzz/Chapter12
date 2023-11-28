#include"Hash.h"

//Precondition: NA
//Postcondition: Displays Menu
void Hash::hashMenu(){
	s.resize(40);
	do{
		cout << "\n\t\t3> Application using hashing\n";
		cout << "\t\t" << string(100, char(205)) << endl;
		cout << "\t\t\tA> Read data file, hash and insert into the dynamic array\n";
		cout << "\t\t\tB> Search an element from the dynamic array\n";
		cout << "\t\t\tC> Insert an element into the dynamic array\n";
		cout << "\t\t\tD> Remove an element from the dynamic array\n";
		cout << "\t\t\tE> Display all records from the array\n";
		cout << "\t\t" << string(100, char(196)) << endl;
		cout << "\t\t\t0> return\n";
		cout << "\t\t" << string(100, char(205)) << endl;

		switch (toupper(inputChar("\t\t\tOption: ", "ABCDE0")))
		{
		case 'A':
			initializeVector();
			break;
		case 'B': hashSearch();
			break;
		case 'C': hashInsert();
			break;
		case 'D': hashDelete();
			break;
		case 'E': hashDisplay();
			break;
		case '0': return;
			break;
		}

	} while (true);
}
//Precondition: NA
//Postcondition: initializes the vector
void Hash::initializeVector(){
	ifstream read;

	string iD;
	string studentName;
	string studentMajor;
	string studentGPA;
	int key;
	int index;
	bool hasEntry = false;
	Student student;
	Student placeHolder;

	s.clear();
	s.resize(40);
	read.open("Students.dat");
	if (!read)
	{
		cout << "\n\t\t\tERROR: FILE DID NOT OPEN\n\n";
		exit(1);
	}

	size = inputInteger("\n\t\t\tEnter a number of read-in records: ", 1, 40);
	cout << "\n\t\t\t" << size << " records have been inserted.\n\n";

	for (int i = 0; i < size; i++)
	{
		getline(read, iD, ',');
		student.setStudentID(stoi(iD));
		key = stoi(iD);

		getline(read, studentName, ',');
		student.setName(studentName);

		getline(read, studentMajor, ',');
		student.setMajor(studentMajor);

		getline(read, studentGPA);
		student.setGPA(stod(studentGPA));

		index = hash(key);

		while (s[index] != placeHolder)
		{
			index = (index + 1) % s.size();
		}

		s[index] = student;

	}

	read.close();

	system("pause");
}
//Precondition: a positive integer
//Postcondition: returns hash value
int Hash::hash(int key)
{
	return key % s.size();
}
//Precondition: NA
//Postcondition: Displays the student vector
void Hash::hashDisplay(){
	Student compare;
	bool emptyVector = true;

	for (int n = 0; n < s.size(); n++)
	{
		if (s[n] != compare)
		{
			emptyVector = false;
		}
	}

	if (emptyVector)
	{
		cout << "\n\t\t\tERROR: No record found.\n\n";
		system("pause");
		return;
	}

	cout << endl;

	for (int i = 0; i < s.size(); i++)
	{
		if (compare != s[i])
		{
			cout << "\t\t\t[" << i << "] - " << s[i] << endl;
		}
	}

	cout << endl;
	system("pause");
}
//Precondition: NA
//Postcondition: Searches vector for matching key
void Hash::hashSearch(){
	int tempKey;
	bool found = false;


	tempKey = inputInteger("\n\t\t\tEnter a student ID to search: ", true);

	for (int m = hash(tempKey); m < s.size(); m++)
	{
		if (s[m].getStudentID() == tempKey)
		{
			cout << "\n\t\t\tStudent record found at index #" << m << "\n";
			cout << "\t\t\t\tStudentID    : " << s[m].getStudentID() << endl;
			cout << "\t\t\t\tName         : " << s[m].getName() << endl;
			cout << "\t\t\t\tMajor        : " << s[m].getMajor() << endl;
			cout << "\t\t\t\tGPA          : " << s[m].getGPA() << endl << endl;
			found = true;
			system("pause");
			break;
		}
	}
	if (found == false)
	{
		cout << "\n\t\t\tERROR: ID not found.\n\n";
		system("pause");
	}
}
//Precondition: NA
//Postcondition: deletes student from vector
void Hash::hashDelete(){
	int keyHolder;
	bool found = false;
	Student temp;


	keyHolder = inputInteger("\n\t\t\tEnter a student ID to remove: ", true);

	for (int k = hash(keyHolder); k < s.size(); k++)
	{
		if (s[k].getStudentID() == keyHolder)
		{
			cout << "\n\t\t\tStudent record index #" << k << " with ID: " << keyHolder << " has been removed.\n\n";
			found = true;
			s[k] = temp;
			system("pause");
			break;
		}
	}
	if (found == false)
	{
		cout << "\n\t\t\tERROR: ID not found.\n\n";
		system("pause");
	}
}
//Precondition: NA
//Postcondition: inserts new student into vector
void Hash::hashInsert(){
	Student newStudent;
	Student empty;
	int tempID;
	int newKey;
	int index;
	bool full = true;
	string tempName;
	string tempMajor;
	double tempGPA;

	for (int j = 0; j < s.size(); j++)
	{
		if (s[j] == empty)
		{
			full = false;
		}
	}

	if (full)
	{
		cout << "\n\t\t\tERROR: Array is full. Cannot insert any more record.\n\n";
		system("pause");
		return;
	}

	tempID = inputInteger("\n\t\t\tEnter a new student ID: ", true);

	for (int m = hash(tempID); m < s.size(); m++)
	{
		if (s[m].getStudentID() == tempID)
		{
			cout << "\n\t\t\tERROR: ID has already inserted.\n\n";
			system("pause");
			return;
		}
	}

	newStudent.setStudentID(tempID);
	newKey = tempID;

	tempName = inputString("\t\t\tEnter the student's name: ", true);
	newStudent.setName(tempName);

	tempMajor = inputString("\t\t\tEnter the student's major: ", true);
	newStudent.setMajor(tempMajor);

	tempGPA = inputDouble("\t\t\tEnter a student's GPA (1.0..4.0): ", 1.0, 4.0);
	newStudent.setGPA(tempGPA);

	index = hash(newKey);



	while (s[index] != empty)
	{
		index = (index + 1) % s.size();
	}

	s[index] = newStudent;

	cout << "\n\t\t\tInserted the new record.\n\n";

	system("pause");

}