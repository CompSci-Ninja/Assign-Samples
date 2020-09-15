/* A program to find GCD of two numbers using Euclid's algorithm */
#include <iostream>

using namespace std;

int euclidGCD(int, int); //Function declaration

int main()
{
    int no1, no2; //Variable declaration
    cout<<"Find the GCD of two numbers using Euclid's algorithm: \n\n";

    //Make sure the user enters valid input

    /*Handles the loop, to ensure user inputs are numbers.
      If true it means user inputs are valid*/
    bool proceed = true;
    do
    {

        cout<<"Enter the first number: ";
        cin>>no1;
        cout<<"\nEnter the second number: ";
        cin>>no2;

        if(cin.fail())
        {

            cout<<"\n\nInvalid inputs. Only Numbers accepted!\n";
            cout<<"\t\tExiting...\n";
            cin.clear();
            return 0;
        }

        if(no1<2|| no2<2)
        {
            cout<<"\n\nUse at least larger numbers!";
            proceed = false;
        }

        else proceed = true;

    }
    while(!proceed);

    //Everything presumed correct
    int gcd = euclidGCD(no1,no2);

    cout<<"The GCD of "<<no1<<" and "<<no2<<" is: "<<gcd;

}

int euclidGCD(int no1, int no2)
{

    int reminder; // for the

    //First make exchanges
    if(no1<no2)
    {
        int temp = no1;
        no1 = no2;
        no2 = temp;
    }

    //Get modulus
    reminder = no1 % no2;

    if(reminder == 0) return no2; //We found the GCD

    else
    {
        //Replace no1 by no2 and replace no2 by reminder. Then call function again.
        no1 = no2;
        no2 = reminder;

        euclidGCD(no1, no2); // Recursion
    }
}
