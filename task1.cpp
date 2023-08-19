#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;
int main()
{   srand(time(0));
    int random ,tries =0 ;
    random = rand() % 10 + 1;
    
    cout << "Guess a random digit between 1 to 10" << endl;
    int guess;
    while (true)
    {
        cin >> guess;
        tries++;
        if (guess == random)
        {
            cout << "you've won in " << tries << " tries " << endl;
            break;
        }
        else if(guess > random){cout << "Your guess is larger than mine \n" << "Try again " << endl;}

        else {cout << " Your guess is smaller than mine. \n " << "Try again" << endl ;}
    }

    return 0;
}