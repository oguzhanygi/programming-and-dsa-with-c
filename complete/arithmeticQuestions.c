/* This program generates simple and random arithmetic
 * questions */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// minimum required grade to pass
#define PASS 75

// give a random number with desired amount of digits
int randomNumber(int digitAmount);
// ask question
int question(int questionType, int x, int y);
// reaction to answers
void reply(int key);
// starting function
void startAsking(int pass);

// driver function
int main(void) {

  srand(time(NULL));

  startAsking(PASS);
}

// give a random number with desired amount of digits
int randomNumber(int digitAmount) {
  switch (digitAmount) {
  case 1:
    return rand() % 10 + 1;
    break;
  case 2:
    return rand() % 90 + 10;
    break;
  case 3:
    return rand() % 900 + 100;
    break;
  default:
    return rand() % 1000 + 1;
  }
}

// ask question
int question(int questionType, int x, int y) {

  int answer, correctAnswer;

  switch (questionType) {
  case 1:
    printf("How much is %d plus %d? (-1 to exit, 0 to skip): ", x, y);
    scanf("%d", &answer);
    correctAnswer = x + y;
    break;
  case 2:
    if (x == y) { // answer = 0 is preserved. so they shouldn't be equal.
      x++;
    } else if (x > y) {
      printf("How much is %d minus %d? (-1 to exit, 0 to skip): ", x, y);
      scanf("%d", &answer);
      correctAnswer = x - y;
    } else if (x < y) { // do not ask questions that has negative answers
      printf("How much is %d minus %d? (-1 to exit, 0 to skip): ", y, x);
      scanf("%d", &answer);
      correctAnswer = y - x;
    }
    break;
  case 3:
    printf("How much is %d times %d? (-1 to exit, 0 to skip): ", x, y);
    scanf("%d", &answer);
    correctAnswer = x * y;
    break;
  }

  if (answer == -1) // stop the program
    return -1;
  else if (answer == 0) // skip the question
    return 0;
  else if (answer == correctAnswer) // correct
    return 1;
  else
    return 2; // everything else is wrong
}

// reaction to answers
void reply(int key) {

  switch (key) {
  case 0:
    puts("No. Please try again.");
    break;
  case 1:
    puts("Wrong. Try once more.");
    break;
  case 2:
    puts("Don't give up!");
    break;
  case 3:
    puts("No. Keep trying.");
    break;
  default:
    break;
  }

  switch (key) {
  case 4:
    puts("Very good!");
    break;
  case 5:
    puts("Excellent!");
    break;
  case 6:
    puts("Nice work!");
    break;
  case 7:
    puts("Keep up the good work!");
    break;
  default:
    break;
  }
}

void startAsking(int pass) {
  int x, y, answer = -2, difficulty;
  int questionAmount = 0, correct = 0, grade;
  int questionType, randomSelection;

  printf("%s", "1- Addition\t2- Subtraction\t3- Multiplication\t4- All\n");
  printf("%s", "Select a topic (Enter the number): ");
  scanf("%d", &questionType);

  /* if '4' is selected as question type, or something irrelevant is selected,
   * ask all types of questions */
  if (!(questionType == 1 || questionType == 2 || questionType == 3))
    randomSelection = 1;

  // difficulty determines the digit amount of numbers in questions
  printf("%s", "Choose a difficulty level [1-3]: ");
  scanf("%u", &difficulty);

  // - 1 is the signal to stop the program
  while (answer != -1) {

    x = randomNumber(difficulty);
    y = randomNumber(difficulty);

    if (randomSelection == 1)
      questionType = rand() % 3 + 1;

    answer = question(questionType, x, y);

    questionAmount++;

    // 1 is the signal for correct answers
    if (answer == 1)
      correct++;

    // If none of bellow signals sent, keep asking the same question.
    while (answer != 1 && answer != -1 && answer != 0) {

      // give a random reaction to wrong answer
      reply(rand() % 4);

      answer = question(questionType, x, y);

      // Stop the program, or skip the question
      if (answer == -1 || answer == 0)
        break;
    }

    // give a random reaction to right answer
    if (answer == 1)
      reply(rand() % 4 + 4);

    if (questionAmount == 10) {
      grade = correct * 10;
      if (grade < pass)
        puts("Please ask your teacher for extra help.");
      else
        puts("Congratulations, you are ready to go to the next level!");
      break;
    }
  }
}
