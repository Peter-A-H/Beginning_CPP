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
    int tries = 0;
    int guess = 0;

    cout << "\tWelcome to Guess My Number\n\n";

    while (guess != secretNumber) 
    { 
        cout << "Enter a guess: ";
        cin >> guess;
        ++tries;

        if (guess > secretNumber)
        {
            cout << "Too high!\n\n";
        }
        else if (guess < secretNumber)
        {
            cout << "Too low!\n\n";
        }
        else
        {
            cout << "\nThat's it! You got it in " << tries << " guesses!\n";
        }
    }

    return 0;
}