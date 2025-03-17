#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    while (true) {
        srand(time(NULL));
        int guess, i, times;
        int rnd = rand() % 101;
        string difficulty;
        bool choice = true;
        while (choice) {
            cout << "Choose Difficulty\nEasy-> 10 Times\nMedium-> 5 Times\nHard -> 3 Times\nInsane-> 1 Time" << endl
                 << endl;
            cin >> difficulty;
            if (difficulty == "Easy" || difficulty == "easy") {
                times = 10;
                choice = false;
            } else if (difficulty == "Medium" || difficulty == "medium") {
                times = 5;
                choice = false;
            } else if (difficulty == "Hard" || difficulty == "hard") {
                times = 3;
                choice = false;
            } else if (difficulty == "Insane" || difficulty == "insane") {
                choice = false;
            } else
                cout << "Error, Try Again!" << endl;
        }
        if (difficulty == "Insane" || difficulty == "insane") {
            cout << "Enter a number between 0 to 100\n";
            cin >> guess;
            if (guess == rnd) {
                cout << "Congratulations, You Guessed the number from the first trial\n\n";
            } else
                cout << "Try Again!... The number was " << rnd << endl << endl;
        } else {
            cout << "Enter a number between 0 to 100\n";
            for (i = 0; i < times; i++) {
                cin >> guess;
                if (guess > rnd) {
                    cout << "The Number you have just entered is bigger than the wanted number\n";
                } else if (guess < rnd) {
                    cout << "The Number you have just entered is smaller than the wanted number\n";
                } else
                    break;
            }
            cout << endl;
            if (guess == rnd) {
                cout << "Congratulations, You Guessed the number after " << i + 1 << " times\n\n";
            } else
                cout << "Try Again!... The number was " << rnd << endl << endl;
        }
    }
}