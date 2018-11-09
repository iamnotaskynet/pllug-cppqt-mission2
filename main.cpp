#include <iostream> //cout cin
#include <string> // strings
#include <cstdlib> // rand()
#include <ctime> // srand seed should generate always diff value

using namespace std;
// for main menu and common functions
char enterSymbolAgain();
void clearTheDisplay(string message);
int getRandomNumber(int max); // from 0 to max-1
// for rps game
int rpsGame();
string returnEnteredString();
// for gtn game
int gtnGame();
char gtnMainMenuChoose();
int gtnDifficultyMenu();
int gtnPlayMenu();
void setRandomNumber();
void gtnEachTryMenu(string message);

//------------------------------------------------------------------------------------
/*Main menu to choose the game*/
int main()
{
    char symbol;
    symbol =  enterSymbolAgain();

    if(symbol == 'r' || symbol == 'R'){
        rpsGame();
    } else if(symbol == 'g' || symbol == 'G'){
        gtnGame();
    }

    return 0;
}
int getRandomNumber(int max)
{   
    int result;
    srand(time(NULL));
    result = rand() % max;
    return result;
}
void clearTheDisplay(string message) 
{   
    
    if (system("CLS")) system("clear"); // clear the console/terminal (why it is evil?)
    cout << message ;
}
/* */
char enterSymbolAgain() 
{   
    char result;
    do { 
        clearTheDisplay("Welcome to Mission 2 Wizard!\nPlease choose game:\n\t (R)ockPaperScissors-\n\t\t\t\t or\n\t (G)uess the Number-\n\t\t\t\t or (E) to exit\n");
        cin >> result; }
    while ( result != 'r' && result != 'R' && result != 'g' && result != 'G' && result != 'e' && result != 'E');

    return result;
}

//------------------------------------------------------------------------------------
/*
Створіть гру “Камінь, ножиці, папір”.
При запуску програма виводить запрошення 
“Enter Rock, Scissors or Paper:” та чекає вводу користувача. 
Користувач має ввести одне зі слів (Rock, Scissors, Paper)
після чого програма випадковим чином теж вибирає один з варіантів (Камінь, Ножиці чи Папір).
Відповідно до правил гри результати користувача та програми порівнюються.
Якщо користувач виграв необхідно вивести повідомлення “You win!”, якщо ж ні - повідомлення “Looser!”.
Після цього програма завершується. 
*/

/* RockPaperScissors (RPS Game)*/
int rpsGame()
{   
    string result = " LOOSER!\n";
    string playerChoose;
    string computerChoose;
    int playerChooseNumber;
    srand(time(NULL)); // setting seed so rand will generate different value each time
    int computerChooseNumber = rand() % 3;

    playerChoose = returnEnteredString();
    //for artifical intelegence num to string word
    if(computerChooseNumber == 0) computerChoose = "rock";
    else if(computerChooseNumber == 1) computerChoose = "paper";
    else if(computerChooseNumber == 2) computerChoose = "scissors";
    //for player string word to number
    if(playerChoose == "rock") playerChooseNumber = 0;
    else if(playerChoose == "paper") playerChooseNumber = 1;
    else if(playerChoose == "scissors") playerChooseNumber = 2;
    // comparing player and ai number of choose
    if(playerChooseNumber == computerChooseNumber) result = " NO ONE WINS THE BATTLE!\n";
    else if(
            (playerChooseNumber == 0 && computerChooseNumber == 2) ||
            (playerChooseNumber == 1 && computerChooseNumber == 0) ||
            (playerChooseNumber == 2 && computerChooseNumber == 1)
            ) result = " YOU WIN!\n";
    
    clearTheDisplay("Who is the winner?\n");
    cout << "Your choise: " << playerChoose << endl;
    
    cout << "AI choise: "  << computerChoose << endl;

    cout << result << endl;
    cin >> playerChoose;
    return 0;
}

string returnEnteredString() // if it is valid about a game
{   
    string input;
    string result;

    while (result != "rock" & result != "paper" & result != "scissors")
    {
        clearTheDisplay("Enter Rock, Scissors or Paper: \n");
        input = "";
        result = "";
        cin >> input;

        locale loc;
        for (string::size_type i=0; i<input.length(); i++)
            result += std::tolower(input[i],loc);
    };
    
    return result;
}

//------------------------------------------------------------------------------------
/*
Написати консольну гру "Вгадай число".
Гра має починатися з ігрового меню "[Level 1] Woul'd like to play? [p] - play, [l]- select level, [q] - quit.'". 
На початку цього надпису - рівень складності, який можна змінювати (за замовчуванням, на початку гри == 1). При введені:
"q" - вихід з програми
"p" - початок гри
"l" - меню вибору рівня (від 1 до 10) та повернення до ігорового меню
Гра полягає в наступному:
Комп'ютер випадковим чином обирає число у проміжку (числовий проміжок задежить від рівня складності)
Користувач має 10 спроб для того, щоб вгадати число. Кожну спробу користувач вводить число:
Якщо воно більше - користувач отримує у відповідь "Greater!"
Якщо воно меньше - користувач отримує у відповідь "Less"
Якщо воно рівне тому числу - то користувач виграв та отримує повідомлення "You win!". 
Якщо користувач не виграв з 10 спроб, то програє.
Після програшу чи виграшу користувач повертається в ігрове меню.
*/
/* Guess the Number */
int difficulty = 1;
int attempt = 10;
int randomNumber;
int userChoice;

int gtnGame() 
{   
    
    char choose =  gtnMainMenuChoose();
    //cout << choose;

    if(choose == 'l' || choose == 'L') {
        
        difficulty = gtnDifficultyMenu();
        gtnGame();
    } else if (choose == 'p' || choose == 'P') {
        gtnPlayMenu();
        gtnGame();
    } else if (choose == 'q' || choose == 'Q') exit(0); 
    //using exit(0) above because functions in my program call each ather
    //so i didn't want to spend time to improove this macarony

    return 0;
}
void setRandomNumber() {
    switch(difficulty)
    {
        case 1: randomNumber = getRandomNumber(10) + 1; break;
        case 2: randomNumber = getRandomNumber(20) + 1; break;
        case 3: randomNumber = getRandomNumber(30) + 1; break;
        case 4: randomNumber = getRandomNumber(40) + 1; break;
        case 5: randomNumber = getRandomNumber(50) + 1; break;
        case 6: randomNumber = getRandomNumber(60) + 1; break;
        case 7: randomNumber = getRandomNumber(70) + 1; break;
        case 8: randomNumber = getRandomNumber(80) + 1; break;
        case 9: randomNumber = getRandomNumber(90) + 1; break;
        case 10: randomNumber = getRandomNumber(100) + 1; break;
        default: cout << "SOMETHING IS VERY WRONG"; 
    }
}
char gtnMainMenuChoose()
{   
    char result;

    while(result != 'p' && result != 'P' && result != 'l' && result != 'L' && result != 'q' && result != 'Q' )
    {
        clearTheDisplay("[Level " + to_string(difficulty) + "] Woul'd like to play? [p] - play, [l]- select level, [q] - quit.\n");
        cin >> result;
    }
    
    

    return result;
}

int gtnDifficultyMenu()
{
    int result;
    while(result < 1 || result > 10) 
    {   
        clearTheDisplay("Please choose difficulty of game [1 - 10]:\n");
        cin >> result;
    }

    return result;
}

int gtnPlayMenu()
{   
    setRandomNumber();
    //cout << randomNumber;
    gtnEachTryMenu("First try!");
    // just for enter anything to continue
    string tmp;
    cin >> tmp;
    // just for enter anything to continue
    return 0;
}

void gtnEachTryMenu(string message)
{   
    if(attempt == 0) {
        difficulty = 1;
        attempt = 10;
        clearTheDisplay("Sorry! Looser!\n");
        // just for enter anything to continue
        string tmp;
        cin >> tmp;
        // just for enter anything to continue
        gtnGame();
    }

    clearTheDisplay(message + "\nTrys: " + to_string(attempt) + "\nPlease enter the value [1 - " + to_string(10*difficulty) + " ]:\n");
    cin >> userChoice;
    if (userChoice == randomNumber) {
        difficulty = 1;
        attempt = 10;
        clearTheDisplay("Congragilations! You win!\n");
        // just for enter anything to continue
        string tmp;
        cin >> tmp;
        // just for enter anything to continue
        gtnGame();
    } else if(userChoice < randomNumber) {
        attempt--;
        gtnEachTryMenu("Your number was smaller!");
    } else if(userChoice > randomNumber) {
        attempt--;
        gtnEachTryMenu("Your number was bigger!");
    }
}