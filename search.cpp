/* This program allows the user to generate and search through an array of 
random numbers, using linear and binary searching
*/
#include <iostream>
#include <math.h>       // This library lets us access random numbers
#include <ctime>        // This library lets us access the computer's clock
using namespace std;

int Search(int list[], int n, int searchNumber) {
   int mid = 0;
   int low = 0;
   int high = n - 1;
   
   while (high >= low) {
      mid = (high + low) / 2;
      if (list[mid] < searchNumber) {
         low = mid + 1;
      }
      else if (list[mid] > searchNumber) {
         high = mid - 1;
      }
      else {
         return searchNumber;
      }
   }
   
   return -1; // not found
}



int main()
{
    int time = clock(); // Stores the computer's time in the variable time
    srand(time);
    int menu_choice, n;
    cout << "Enter a number length that you would want the list to be: ";
    cin >> n;
    
    int list[n];
    list[0] = rand() % 10;
    for(int i = 1; i<n; ++i) {
        list[i] = list[i - 1] + rand() % 10;
    }
    cout << "----------------------------------------" << endl;
    cout << "This is what the list looks like: " << endl;
    for(int i = 0; i < n; ++i) {
        cout << list[i] << " ";
    }

    do
    {
        cout << endl << "1. Linear Search || 2. Binary Search || 3. Quit\n";
        cout << "What do you want to do now: ";
        cin >> menu_choice;
        cout << endl;

        if(menu_choice == 1)
        {
            int searchNumber;
            int count = 0;
            bool found = false;
            cout << "Smallest #: " << list[0] << "  |  Largest #: " << list[n-1] << endl;
            cout << "Enter a number to linear search for: ";
            cin >> searchNumber;
            cout << endl;
            for (int i = 0; i < n; ++i) {
                if (list[i] == searchNumber) {
                    ++count;
                    found = true;
                    break;
                }
                else if (list[i] > searchNumber) {
                    ++count;
                    break;
                }
                ++count;
            }
            if (found) {
                cout << "Number found!\n";
                cout << "Rounds: " << count;
            }
            else if (!found) {
                cout << "Number not found\n";
                cout << "Rounds: " << count;
            }
        }
        else if (menu_choice == 2)
        {
            int searchNumber;
            int count = 0;
            cout << "Smallest #: " << list[0] << "  |  Largest #: " << list[n-1] << endl;
            cout << "Enter a number in between the smallest and largest amount to linear search for: ";
            cin >> searchNumber;
            cout << endl;
            int result = Search(list, n, searchNumber);

            if (result == -1) {
                cout << "Number not found.\n" << endl;
            }
            else{
                cout << "Your number " << result << " was found.\n";
            }

        }
    } while (menu_choice != 3);

    return 0;
}