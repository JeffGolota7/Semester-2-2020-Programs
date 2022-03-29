#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
/* Sorting Algorithms
Author : Jeff Golota
Date: 2-18-2020
*/

//Initial struct for the list
struct people {
    string firstName, lastName;
};

//Function for the bubble sort that will return the sorted list by last name
vector<people> bubble(vector<people> list, int size) {
    for (int i = 0;i < list.size() - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < list.size() - i - 1; ++j) {
            if (list[j].lastName > list[j+1].lastName) {
                string temp1 = list[j].lastName;
                string temp2 = list[j].firstName;
                list[j].firstName = list[j+1].firstName;
                list[j].lastName = list[j+1].lastName;
                list[j+1].firstName = temp2;
                list[j+1].lastName = temp1;
                swapped = true;
            }
        }
        if (swapped == false) {
            return list;
        }
    }
}

//Function for the selection sort that will sort the list by first name
vector <people> selection(vector<people> list, int size) {
    for (int i = 0; i < list.size(); ++i) {
        int smallest = i; // This keeps track of the slots that are already sorted
        for (int j = i+1; j < list.size(); ++j){ // Locates the slot that is the smallest
            if (list[j].firstName < list[smallest].firstName) {
                smallest = j;
            }
        }
        //Swaps the first and last names of the smallest slot and i
        string tmp1 = list[i].firstName;
        string tmp2 = list[i].lastName;
        list[i].firstName = list[smallest].firstName;
        list[i].lastName = list[smallest].lastName;
        list[smallest].firstName = tmp1;
        list[smallest].lastName = tmp2;
    }
    return list;
}

int main () {
    ifstream input;
    string temp1, temp2;
    int size = 0;
    int choice;
    vector <people> list(0);
    input.open("clients.txt");

    while (!input.eof()){ // Goes through the input file and creating a vector for the first and last names
        input >> temp1 >> temp2;
        list.push_back({temp1,temp2});
        ++size; // Keeps track of the size of the vector
    }
    // Prints the initial list
    cout << "Here is the list: \n";
    for (int i = 1; i < list.size(); ++i) {
        cout << list[i].firstName << " " << list[i].lastName << endl;
    }
    do {
        //Menu
        cout << "----------------------------------------\n";
        cout << "(1) Sort names by last name\n";
        cout << "(2) Sort names by first name\n";
        cout << "(3) Add a name to the list\n";
        cout << "(4) Quit\n";
        cout << "----------------------------------------\n";
        cout << "What would you like to do?\n";
        cin >> choice;

        //Calls the bubble sort function and prints out the sorted list
        if(choice == 1) {
            list = bubble(list,size);
            cout << "Here is the list: \n";
            for (int i = 1; i < list.size(); ++i) {
                cout << list[i].firstName << " " << list[i].lastName << endl;
            }
        }
        //Calls the selection sort function and prints out the sorted list
        else if (choice == 2) {
            list = selection(list,size);
            cout << "Here is the list: \n";
            for (int i = 1; i < list.size(); ++i) {
                cout << list[i].firstName << " " << list[i].lastName << endl;
            }
        }
        //Allows the user to enter in a name and automatically formats the letters in the list
        else if (choice == 3) {
            string add1, add2;
            cout << "Enter a first and last name you would like to add to the list: ";
            cin >> add1 >> add2;
            //Makes first letter of the word uppercase
            add1[0] = toupper(add1[0]);
            add2[0] = toupper(add2[0]);
            //These loops scroll through the remaining letters and making them lowercase
            for (int i = 1; i < add1.length(); ++i) {
                add1[i] = tolower(add1[i]);
            }
            for (int i = 1; i < add2.length(); ++i) {
                add2[i] = tolower(add2[i]);
            }
            list.push_back({add1,add2});
            cout << "Here is the list: \n";
            for (int i = 1; i < list.size(); ++i) {
                cout << list[i].firstName << " " << list[i].lastName << endl;
            }
        }
        else if (choice > 4 || choice < 1){
            cout << "Not a valid option, choose again.\n";
        }

    }while (choice != 4);

    





}