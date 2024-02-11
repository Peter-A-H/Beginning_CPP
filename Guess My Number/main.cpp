#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    srand((unsigned)time(NULL));

    int secretNumber = (rand() % 100) + 1;
    int maxValue = 100;
    int minValue = 0;
    int difference = 0;
    int guess = (maxValue - minValue) / 2;
    int tries = 1;

    cout << "\tWelcome to Guess My Number\n\n"
         << "Pick a number between 0-100: ";

    cin >> secretNumber;

    while (guess != secretNumber) 
    { 
        if (guess > secretNumber)
        {
            cout << "\n" << guess << " is too high!\n";
            maxValue = guess;
            difference = maxValue - minValue;
            guess -= difference / 2;
        }
        if (guess < secretNumber)
        {
            cout << "\n" << guess << " is too low!\n";
            minValue = guess;
            difference = maxValue - minValue;
            guess += difference / 2;
        }

        ++tries;
    }

    cout << "\n" << guess << "! The computer got it in " << tries << " guesses!\n";

    return 0;
}