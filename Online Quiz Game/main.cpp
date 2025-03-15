#include <iostream>
#include <string>

using namespace std;

// Global Variables
char g_guess;
int g_total;

// Registeration Struct

struct Registeration
{
    string username;
};

// Question Class
class Question
{
private:
    string Question_Text;
    string Answer_1;
    string Answer_2;
    string Answer_3;
    string Answer_4;
    char Correct_Answer;
    int Question_Score;

public:
    void setQuestions(string, string,
                      string, string,
                      string, char, int);

    void askQuestion();
};

int main()
{
    Registeration user;
    cout << "\n\n\t\t\t\tWelcome to Quiz Game\n";
    cout << "\nPress Enter to start the quiz... \n";

    cin.get();

    cout << "Username: ";
    cin >> user.username;

    string respond;
    cout << "\nStart Quiz: Yes\n";
    cout << "Exit: No\n\n";

    cin >> respond;

    if (respond == "yes")
    {
        cout << endl;
        cout << "Let's Goooo...\n";
    }
    else
    {
        cout << "Okay Good Bye!" << endl;
        return 0;
    }

    Question question[10];

    question[0].setQuestions("What is the Capital of France ?",
                             "Berlin",
                             "Madrid",
                             "Paris",
                             "Rome",
                             'c',
                             10);
    question[1].setQuestions("Which Planet is known as the Red Planet ?",
                             "Earth",
                             "Venus",
                             "Jupiter",
                             "Mars",
                             'd',
                             10);
    question[2].setQuestions("Who wrote Romeo and Juliet ?",
                             "Charles Dickens",
                             "William Shakespeare",
                             "Mark Twain",
                             "Jane Austen",
                             'b',
                             10);
    question[3].setQuestions("What is the Chemical Symbol for Gold ?",
                             "Ag",
                             "Au",
                             "Pb",
                             "Fe",
                             'b',
                             10);
    question[4].setQuestions("How many legs does a Spider have ?",
                             "6",
                             "8",
                             "10",
                             "12",
                             'b',
                             10);
    question[5].setQuestions("Which Ocean is the largest ?",
                             "Atlantic Ocean",
                             "Indian Ocean",
                             "Arctic Ocean",
                             "Pacific Ocean",
                             'd',
                             10);
    question[6].setQuestions("Who Painted the Mona Lisa ?",
                             "Vincent van Gogh",
                             "Pablo Picasso",
                             "Leonardo da Vinci",
                             "Michelangelo",
                             'c',
                             10);
    question[7].setQuestions("What is the square root of 64 ?",
                             "6",
                             "7",
                             "8",
                             "9",
                             'c',
                             10);
    question[8].setQuestions("Which year did World War II end ?",
                             "1943",
                             "1945",
                             "1950",
                             "1939",
                             'b',
                             10);
    question[9].setQuestions("Which gas do plants absorb from the atmosphere ?",
                             "Oxgyen",
                             "Nitrogen",
                             "Carbon Dioxide",
                             "Hydrogen",
                             'c',
                             10);

    question[0].askQuestion();
    question[1].askQuestion();
    question[2].askQuestion();
    question[3].askQuestion();
    question[4].askQuestion();
    question[5].askQuestion();
    question[6].askQuestion();
    question[7].askQuestion();
    question[8].askQuestion();
    question[9].askQuestion();

    // Display the total score
    cout << "Total Score = " << g_total
         << "/100" << endl;

    // Display the results

    if (g_total >= 50)
    {
        cout << "Congrats " << user.username << " you passed the"
             << " quiz!" << endl;
    }

    else
    {
        cout << "Unfortunately! You failed the quiz."
             << endl;
        cout << "Better luck next time."
             << endl;
    }
    return 0;
}

void Question::setQuestions(
    string question, string answer_1,
    string answer_2, string answer_3,
    string answer_4, char correct_answer, int question_score)
{
    Question_Text = question;
    Answer_1 = answer_1;
    Answer_2 = answer_2;
    Answer_3 = answer_3;
    Answer_4 = answer_4;
    Correct_Answer = correct_answer;
    Question_Score = question_score;
}

void Question::askQuestion()
{
    cout << endl;

    cout << Question_Text << endl;
    cout << "A) " << Answer_1 << endl;
    cout << "B) " << Answer_2 << endl;
    cout << "C) " << Answer_3 << endl;
    cout << "D) " << Answer_4 << endl;
    cout << endl;

    cout << "Answer: ";
    cin >> g_guess;

    if (g_guess == Correct_Answer)
    {
        cout << endl;
        cout << "Correct" << endl;

        g_total += Question_Score;
        cout << "Score = " << Question_Score
             << " out of "
             << Question_Score
             << endl;
        cout << endl;
    }

    else
    {
        cout << endl;
        cout << "Wrong" << endl;
        cout << "Score = 0"
             << " out of "
             << Question_Score
             << endl;
        cout << "Correct answer = "
             << Correct_Answer
             << "." << endl;
        cout << endl;
    }
}
