#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int die = (randomNumber % 6) + 1;
    cout << "You rolled a " << die << endl;
    return 0;
}