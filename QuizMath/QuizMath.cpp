
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<Windows.h>

using namespace std;

enum enLevel { easy = 1, meduim = 2, hard = 3, mixLevel = 4 };
enum enType { add = 1, sub = 2, mul = 3, division = 4, Mix = 5 };
struct stQuestion {
    int number1 = 0, number2 = 0;
    enType type;
    enLevel level;
    int playerAnswer;
    int correctAnswer;
    bool isCorrerctOrNot = false;
};
struct stQuiz {
    stQuestion QuesitonList[100];
    short numberOfquestion;
    enType type;
    enLevel level;
    int numOfWrongAnswers = 0, numOfRightAnswers = 0;
    bool isPass = false;
};
int RandNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}
void setColor(bool correct) {
    if (correct) {
        system("color 2f");
    }
    else {
        system("color 4f");
        cout << "\a";
    }
}
enType ReadWhatType() {
    int type;
    do {
        cout << "what is the type you want [1]add/[2]sub/[3]mul/[4]div/[5]mix : ";
        cin >> type;
    } while (type < 1 || type>5);
    return (enType)type;
}
string NameOfTypes(enType type) {
    string arrOfTypes[] = { "add","sub","mul","div","mix" };
    return arrOfTypes[type - 1];
}
enType mixType() {
    int Mix = RandNumber(1, 4);
    return (enType)Mix;
}
string WhatTypeWant(enType type) {
    switch (type)
    {
    case add:
        return "+";
        break;
    case sub:
        return "-";
        break;
    case mul:
        return "*";
        break;
    case division:
        return "/";
        break;

    default:
        return "Mix";
        break;
    }
}
enLevel ReadTheLevel() {
    int level;
    do {
        cout << "What Level you want [1]easy/[2]meduim/[3]hard/[4]mix : ";
        cin >> level;

    } while (level < 1 || level>4);
    return(enLevel)level;
}

string NameOfLevel(enLevel level) {
    string arrOfLevel[] = { "easy","meduim","hard","mix" };
    return arrOfLevel[level - 1];
}

int simpleCalculator(int num1, int num2, enType op) {
    switch (op)
    {
    case add:
        return num1 + num2;
        break;
    case sub:
        return num1 - num2;
        break;
    case mul:
        return num1 * num2;
        break;
    case division:
        return(num2 != 0) ? num1 / num2 : 0;
        break;
    default:
        return num1 + num2;
        break;

    }
}
int ReadTheNumberOfQuestion() {
    int numOfQuestion;
    cout << "How Many Number of Questions you want to play ? ";
    cin >> numOfQuestion;
    return numOfQuestion;
}
stQuestion GenerateQuestions(enType type, enLevel level) {
    stQuestion question;
    if (type == enType::Mix) {
        type = mixType();
    }
    if (level == enLevel::mixLevel) {
        level = (enLevel)RandNumber(1, 3);
    }
    switch (level)
    {
    case easy:
        question.number1 = RandNumber(1, 10);
        question.number2 = RandNumber(1, 10);
        break;
    case meduim:
        question.number1 = RandNumber(10, 50);
        question.number2 = RandNumber(10, 50);
        break;
    case hard:
        question.number1 = RandNumber(50, 100);
        question.number2 = RandNumber(50, 100);
        break;

    }
    question.correctAnswer = simpleCalculator(question.number1, question.number2, type);
    question.level = level;
    question.type = type;
    return question;
}

void AskAndCorrectTheQuestion(stQuiz& quiz) {
    for (short questionNumber = 0;questionNumber < quiz.numberOfquestion;questionNumber++) {
        cout << "[" << questionNumber + 1 << " / " << quiz.numberOfquestion << "]\n";
        cout << quiz.QuesitonList[questionNumber].number1 << " ";
        cout << WhatTypeWant(quiz.QuesitonList[questionNumber].type) << endl;
        cout << quiz.QuesitonList[questionNumber].number2;

        cout << "\n------\n";
        cin >> quiz.QuesitonList[questionNumber].playerAnswer;
        if (quiz.QuesitonList[questionNumber].playerAnswer == quiz.QuesitonList[questionNumber].correctAnswer) {
            cout << "correct ! ";
            quiz.numOfRightAnswers++;
            quiz.QuesitonList[questionNumber].isCorrerctOrNot = true;
        }
        else {
            cout << "\nwrong   the Right answer is " << quiz.QuesitonList[questionNumber].correctAnswer;
            quiz.numOfWrongAnswers++;
            quiz.QuesitonList[questionNumber].isCorrerctOrNot = false;
        }
        setColor(quiz.QuesitonList[questionNumber].isCorrerctOrNot);
        cout << endl;
    }
    quiz.isPass = (quiz.numOfRightAnswers >= quiz.numOfWrongAnswers);
}

void ShowFinalScreen(stQuiz quiz) {

    cout << "\n\t\t\t\t-----------------[final result]---------------------------------\n";

    if (quiz.isPass)cout << "\n\t\t\t\tyou are pass :) ";
    else cout << "\n\t\t\t\tyou are failed :( ";

    cout << "\n\t\t\t\tthe number of questions : " << quiz.numberOfquestion << endl;
    cout << "\t\t\t\tthe type of questions : " << NameOfTypes(quiz.type) << endl;
    cout << "\t\t\t\tthe level of questions : " << NameOfLevel(quiz.level) << endl;
    cout << "\t\t\t\tthe number of right answers of questions : " << quiz.numOfRightAnswers << endl;
    cout << "\t\t\t\tthe number of wrong answers of questions : " << quiz.numOfWrongAnswers << endl;
    cout << "\n\t\t\t\t----------------------------------------------------------------\n";


}
void PlayGame() {

    stQuiz Quiz;
    Quiz.numberOfquestion = ReadTheNumberOfQuestion();
    Quiz.level = ReadTheLevel();
    Quiz.type = ReadWhatType();

    for (short QuestionNumber = 0; QuestionNumber < Quiz.numberOfquestion; QuestionNumber++)
    {
        Quiz.QuesitonList[QuestionNumber] = GenerateQuestions(Quiz.type, Quiz.level);
    }

    AskAndCorrectTheQuestion(Quiz);
    ShowFinalScreen(Quiz);

}
void ResetColor() {
    system("cls");
    system("color 0f");
}
void StartGame() {
    char again = 'Y';
    do {
        ResetColor();
        PlayGame();
        cout << "Do you want to play again ?[y]yes/[n]no  ";
        cin >> again;
    } while (again == 'Y' || again == 'y');
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}

