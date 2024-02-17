#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    enum fields
    {
        WORD,
        HINT,
        NUM_FIELDS
    };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
    };
    size_t totalPoints = 0;

    cout << "\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";

    while (true)
    {
        srand((unsigned)time(0));
        int choice = (rand() % NUM_WORDS);
        string theWord = WORDS[choice][WORD];
        string theHint = WORDS[choice][HINT];
        size_t points = theWord.length();

        string jumble = theWord;
        size_t wordLength = jumble.size();

        for (int i = 0; i < wordLength; ++i)
        {
            int index1 = (rand() % wordLength);
            int index2 = (rand() % wordLength);
            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        }

        cout << "The jumble is: " << jumble;

        string guess = "";
        cout << "\n\nYour guess: ";
        cin >> guess;

        if (guess == "quit")
        {
            break;
        }
        if (guess == "hint")
        {
            cout << theHint << "\n\n";
        }
        else if (guess == theWord)
        {
            cout << "\nThat's it! You guessed it!\n";
            totalPoints += points;
            cout << "You have " << totalPoints << " points.\n";
        }
        else
        {
            cout << "Sorry, that's not it.\n";
            totalPoints -= points;
            cout << "You have " << totalPoints << " points.\n";
        }
    }

    cout << "\nThanks for playing.\n\n";

    return 0;
}
