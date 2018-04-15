/*************************************************************************
*
* File:             wk2_gradingPractice.cpp
* Summary:   Program to use as practice for using criteria to grade.
*
*                    Criteria:
*                       2 pts - adherence to Style Guide
*                       2 pts - correct solution to problem
*                       1 pt  -  uses concepts covered in class
*
* Problem:      Write a program that prompts the user to input 5 integers. Instruct the
*                      user to enter values in the range -100 to 100, inclusive. The integers
*                      will be stored in an array. Then, output will show the sum of the values
*                      entered by the user. There should be a separate function for each
*                      process. (Assume we covered passing of arrays in class.)
*
*************************************************************************/

#include <iostream>
using namespace std;

const int SIZE = 5;

void fillAra(int[]);
void showSum(int);

int main()
{
    int ara[SIZE];
    int total = 0;

    fillAra(ara);

    for (int i = 0; i < SIZE; i++)
        total += ara[i];

    showSum(total);

    return 0;
}

void fillAra(int ara[])
{
cout << "Enter " << SIZE << " integers -100 to 100, pressing Enter after each.\n\n";
for (int i = 0; i < SIZE; i++)
{
    cin >> ara[i];
    if (ara[i] < -100 || ara[i] > 100)
    {
        cout << "That is outside the range required. Enter a value again.\n";
        i--;
    }
}
return;
}

void showSum(int total)
{
cout << "The sum of the values you entered is " << total << ".\n\n";
return;
}
