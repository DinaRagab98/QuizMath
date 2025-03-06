# Math Quiz Game

## Overview
The Math Quiz Game is a console-based application written in C++ that generates math questions based on user-selected difficulty levels and operation types. The game provides real-time feedback and a final summary of results.

## Features
- Supports four mathematical operations: Addition, Subtraction, Multiplication, and Division.
- Offers four difficulty levels: Easy, Medium, Hard, and Mixed.
- Randomly generates math questions based on the selected difficulty and operation type.
- Tracks the number of correct and incorrect answers.
- Displays a final report with performance statistics.
- Allows users to play multiple rounds.

## Installation and Usage
### Prerequisites
- A C++ compiler (such as g++ or MSVC)
- Windows OS (for color and sound features)

### Compilation
Use the following command to compile the program using g++:
```sh
 g++ math_quiz.cpp -o math_quiz
```

### Running the Program
Run the compiled executable:
```sh
 ./math_quiz
```

### How to Play
1. Select the number of questions.
2. Choose a difficulty level (Easy, Medium, Hard, or Mixed).
3. Choose a math operation (Addition, Subtraction, Multiplication, Division, or Mixed).
4. Answer the displayed questions.
5. Receive immediate feedback on correctness.
6. View final performance statistics at the end of the quiz.
7. Choose whether to play again.

## Code Structure
- `main()`: Initializes the game and starts the quiz loop.
- `StartGame()`: Manages game sessions and allows replay.
- `PlayGame()`: Controls the flow of question generation and answer evaluation.
- `GenerateQuestions()`: Randomly generates math questions.
- `AskAndCorrectTheQuestion()`: Displays questions and checks user responses.
- `ShowFinalScreen()`: Displays the final result summary.
- `setColor()`: Changes console color based on answer correctness (Windows only).

## Known Issues
- Division by zero is handled by returning zero instead of preventing such cases.
- The game currently only supports Windows (due to system calls for color and sound effects).

## Author
Created by [Dina Ragab]. Feel free to contribute or suggest improvements!

