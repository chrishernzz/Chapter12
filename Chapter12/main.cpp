//Name: Christian Hernandez
//Date: 11/27/2023
//subscription: CMPR131

//Credit: Christian Hernandez,Bryan Alarcon,Thanh Tran, Joe Bryant,Erik Santana, Saul Merino

#include <iostream>
#include <iomanip>
#include "input (1).h"
#include <random>
#include <string>
#include "DynamicArray.cpp"
#include"Hash.h"
using namespace std;

// Function Prototypes
void challenge1();
void challenge2();
void challenge3();

// Main Function
int main()
{
    do{
        system("cls");
        cout << "\n\tCMPR131 Chapter 12: Searches and hashing by Christian Hernandez (11/27/2023)";
        cout << "\n\t" + string(85, char(205));

        cout << "\n\t\t1> Searching from an unsorted dynamic array ";
        cout << "\n\t\t2> Searching from a sorted dynamic array";
        cout << "\n\t\t3> Application using hashing";

        cout << "\n\t" + string(85, char(196));
        cout << "\n\t\t0> Quit";
        cout << "\n\t" + string(85, char(205));

        switch (inputInteger("\n\t\tOption: ", 0, 9))
        {
        case 0: exit(1); break;
        case 1: system("cls"); challenge1(); break;
        case 2: system("cls"); challenge2(); break;
        case 3: system("cls"); challenge3(); break;
        default: cout << "\t\tERROR - Invalid option."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

//Precondition: NA
//Postcondition: Display Challenge 1
void challenge1(){
    DynamicArray<string> dynamic_array;
    int size = 0;
    int number = 0;
    srand(time(0));
    string random_element = " ";
    do{
        system("cls");
        cout << "\n\t1> Searching from an unsorted dynamic string array";
        cout << "\n\t" + string(85, char(205));

        cout << "\n\t\tA> Randomly generate a list of data and store into the dynamic array";
        cout << "\n\t\tB> Add an element to the dynamic array";
        cout << "\n\t\tC> Display elements from the array";
        cout << "\n\t\tD> Search for an element from the array";
        cout << "\n\t\tE> Clear the array";

        cout << "\n\t" + string(85, char(196));
        cout << "\n\t\t0> Quit";
        cout << "\n\t" + string(85, char(205));

        switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("ABCDE0")))){
        case '0': return;
        case 'A':{
            // clear the vector 
            dynamic_array.clear();

            size = inputInteger("\n\t\tEnter the size of the dynamic array: ", true);

            for (int i = 0; i < size; i++){
                random_element = "str#";

                number = (rand() % 3) + 1;
                random_element.append(to_string(number));

                dynamic_array.insert(random_element);
            }

            cout << "\n\t\tRandom elements have been populated into the array.\n";
        }
                break;
        case 'B':{
            string input = inputString("\n\t\tEnter a string element: ", false);
            dynamic_array.insert(input);
            cout << "\n\t\tElement \"" + input + "\" has been added to the array.\n";
        }
                break;
        case 'C':{
            //Validation
            if (dynamic_array.getSize() == 0){
                cout << "\n\t\tThe array is empty.\n";
                break;
            }

            cout << "\n\t\t";
            for (int i = 0; i < dynamic_array.getSize(); i++){
                cout << dynamic_array[i] << " ";
            }
            cout << "\n";
        }
                break;
        case 'D':{
            //Validation
            if (dynamic_array.getSize() == 0){
                cout << "\n\t\tThe array is empty.\n";
                break;
            }

            int index = 0;

            cout << "\n\t\tSTL serial search";
            cout << "\n\t\t" + string(50, char(196));

            string search = inputString("\n\t\tEnter a string element to search: ", false);

            if (dynamic_array.serial_search(search, index)){
                cout << "\n\t\t\"" << search << "\" is found at index " + to_string(index) + " in the unsorted array.\n";
               
            }
            else{
                cout << "\n\t\t\"" << search << "\" is not found in the unsorted array.\n";
            }
        }
                break;
        case 'E':{
            //Validation
            if (dynamic_array.getSize() == 0){
                cout << "\n\t\tThe array is empty.\n";
                break;
            }
            dynamic_array.clear();
            cout << "\n\t\tThe array has been cleared.\n";
        }
                break;

        default: cout << "\t\tERROR - Invalid option."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

//Precondition: NA
//Postcondition: Display Challenge 2
void challenge2(){
    DynamicArray<string> dynamic_array;
    int size = 0;
    int number = 0;
    srand(time(0));
    string random_element = " ";
    do{
        system("cls");
        cout << "\n\t2> Searching from a sorted dynamic array";
        cout << "\n\t" + string(85, char(205));

        cout << "\n\t\tA> Randomly generate a list of data and store into the dynamic array";
        cout << "\n\t\tB> Add an element to the dynamic array";
        cout << "\n\t\tC> Display elements from the array";
        cout << "\n\t\tD> Search for an element from the array";
        cout << "\n\t\tE> Clear the array";

        cout << "\n\t" + string(85, char(196));
        cout << "\n\t\t0> Quit";
        cout << "\n\t" + string(85, char(205));

        switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("ABCDE0")))){
        case '0': return;
        case 'A':{
            // clear the vector 
            dynamic_array.clear();

            size = inputInteger("\n\t\tEnter the size of the dynamic array: ", true);

            for (int i = 0; i < size; i++){
                random_element = "str#";
                number = (rand() % 3) + 1;
                random_element.append(to_string(number));
                dynamic_array.insert(random_element);
            }

            dynamic_array.sort_array();

            cout << "\n\t\tRandom elements have been populated into the array.\n";
        }
                break;
        case 'B':{
            string input = inputString("\n\t\tEnter a string element: ", false);

            dynamic_array.insert(input);
            dynamic_array.sort_array();
            cout << "\n\t\tElement \"" + input + "\" has been added to the array.\n";
        }
                break;
        case 'C':{
            //Validation
            if (dynamic_array.getSize() == 0){
                cout << "\n\t\tThe array is empty.\n";
                break;
            }

            cout << "\n\t\t";
            for (int i = 0; i < dynamic_array.getSize(); i++){
                cout << dynamic_array[i] << " ";
            }
            cout << "\n";
        }
                break;
        case 'D':{
            //Validation
            if (dynamic_array.getSize() == 0){
                cout << "\n\t\tThe array is empty.\n";
                break;
            }
            int index = 0;
            char input = toupper(inputChar("\n\t\tChoose search type (S)Serial or (B)Binary: ", 'S', 'B'));
            switch (input){
            case 'S':{
                cout << "\n\t\tSTL serial search";
                cout << "\n\t\t" + string(50, char(196));

                string search = inputString("\n\t\tEnter a string element to search: ", false);

                if (dynamic_array.serial_search(search, index)){
                    cout << "\n\t\t\"" << search << "\" is found at index " + to_string(index) + " in the sorted array.\n";
                    break;
                }
                else{
                    cout << "\n\t\t\"" << search << "\" is not found in the sorted array.\n";
                    break;
                }

            }
                    break;
            case 'B':{
                int first = 0;
                int last = dynamic_array.getSize() - 1;

                cout << "\n\t\tSTL binary search";
                cout << "\n\t\t" + string(50, char(196));

                string search = inputString("\n\t\tEnter a string element to search: ", false);

                if (dynamic_array.binary_search(search, first, last, index)){
                    cout << "\n\t\t\"" << search << "\" is found at index " + to_string(index) + " in the sorted array.\n";
                    break;
                }
                else{
                    cout << "\n\t\t\"" << search << "\" is not found in the sorted array.\n";
                    break;
                }

            }
                    break;
            }
        }
                break;
        case 'E':{
            //Validation
            if (dynamic_array.getSize() == 0){
                cout << "\n\t\tThe array is empty.\n";
                break;
            }
            dynamic_array.clear();
            cout << "\n\t\tThe array has been cleared.\n";
        }
                break;
        default: cout << "\t\tERROR - Invalid option."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

//Precondition: NA
//Postcondition: Display Challenge 3
void challenge3() {
    Hash menu;
    menu.hashMenu();
}