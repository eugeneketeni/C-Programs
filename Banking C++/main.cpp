/*  Name: Eugene Keteni.
    Date: 04/17/2016.
    Purpose: create a banking program for user to create an account, login, withdraw, deposit and review transaction from an ATM machine
    Algorithms: The code first ask the user to create a login and prompts him to login with that same credentials used. These credentials are stored in a file
    called file fileA. If the user enters wrong id and password, the user is prompted to write to correct credentials. After the user enter the right login, the
    system grants grants the user to access the account menu. The user is allowed to withdraw, deposit, check balance, review account activities, and quit the program
    The file history are also store in a file called transactions and keeps track of what is going on with the transaction. The system prompts the user to enter only valid amount to withdraw, else transaction would
    be decline. After the transaction is over, the user has the permission to exit the program. */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
//function prototype
bool choiceValid(char choice);
void createAccount();
void withdraw();
bool accountValid(char choiceB);
void deposit();
void displayBalance();
float totalD();
string getTime();
void showTransHistory();

float balance = 0;
int counter = 0;
char mainMenu()
{
    char choice; // Display Menu
    cout << "*****************************************************************\n";
    cout << "Hi! Welcome to Future Computer Programmer ATM Machine!\nPlease select an option from the menu below:\n\n";
    cout << "C) Create new account (Create an account with userId/ password)\n";
    cout << "L) Login\n";
    cout << "V) View promotions\n";
    cout << "Q) Quit the program\n";
    cout << "******************************************************************\n";
    cin >> choice;
    cout << endl;
    choiceValid(choice);// function call for choice validation
    return choice;

}
// login function
void login()
{
    string userId, password;
    cout << "*********Login***********\n";
    cout << "Please enter your userId: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    string x, y;
    ifstream inpV;
    inpV.open("fileA.txt");
    getline(inpV, x);
    getline(inpV, y);

    if( x == userId && y == password)
    {

        cout << "Access Granted! Transferring to Account Menu!\n" << endl;
        //accountValid(choiceB);
    }

    else
    {
        cout<< "Invalid! Try again" <<endl;
        mainMenu();
    }
    //mainMenu();
}
// createAccount function prototype
void createAccount()
{
    string userId, password;


    cout << "*******Create a new account.*********\n";
    cout << "Please enter your userId: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;
    ofstream outP;
    outP.open("fileA.txt", std::ios_base::app); //remember this. add the second part to do the append thing
    outP << userId << "\n" << password << "\n";

    outP.close();
    cout << "Thank you! Your account has been created!" << endl;
    mainMenu(); // function call for main Menu
}


void deposit() // deposit function
{

    float deposit = 0;

    cout << "How much would you like to deposit: $";
    cin >> deposit;
    balance += deposit;
    cout << "$" << deposit << " was deposited into your account\n";
    cout << "Your balance is: " << balance << endl;

    ofstream file;
    file.open("history", ios_base::app);
    file << getTime() << "\t\t deposit\t" << deposit << "\tOKAY\n";
    file.close();
}

//withdraw function
void withdraw()
{
    float withdraw;
    cout << "How much would you like to withdraw: ";
    cin >> withdraw;
    if (withdraw > balance) // input validation to alert overdraft
    {
        cout << "Sorry withdrawal amount exceeds the balance. Can't withdraw !\n";
        //cin >> withdraw;
        system("PAUSE");
        ofstream file;
        file.open("history", ios_base::app);
        file << getTime() << "\t\t withdraw\t" << withdraw << "\tNot OKAY\n";
        file.close();
    }
    else
    {
        balance -= withdraw;
        cout << "$" << withdraw << " was withdrawn from your account\n";
        cout << "Your balance is: " << balance << endl;
        //records transaction history
        ofstream file;
        file.open("history", ios_base::app);
        file << getTime() << "\t\t withdraw\t" << withdraw << "\tOKAY\n";
        file.close();

    }
}

void displayBalance()// display balance Function
{
    cout << "Your balance now is: " << balance << endl;
    ofstream file;
    file.open("history", ios_base::app);
    file << getTime() << "\t\t displayBalance\t" << displayBalance << "\tOKAY\n";
    file.close();
}

void showTransHistory()// show transaction function
{
    ifstream x;
    x.open ("history");
    string a;
    while(getline(x,a))
    {
        cout << a << endl;
    }
    x.close();
}

void entry(string a, string b, float c, string d)
{
    ofstream abc;
    abc.open("history",ios ::app);
    a=getTime();

    abc << a << "\t" << b << "\t" << c << "\t" << d << endl;
    abc.close();
    return;
}
// Getting the time function
string getTime()
{
    time_t now = time(0);


    char* dt = ctime(&now);
    int c = -1;
    do
    {
        c++;
    }
    while(dt[c] != '\0');

    dt[c-1] = ' ';

    return dt;
}

char bankingMenu() // Banking Menu function
{
    char choiceB;
    cout << "---------------------------------------------------\n";
    cout << "Please select an option from the following menu\n";
    cout << "W) Withdraw money \n";
    cout << "D) Deposit money \n";
    cout << "B) Request balance \n";
    cout << "R) Review account activities \n";
    cout << "Q) Quit the program \n----------------------------------------------------\n";
    cin >> choiceB;

    return choiceB;
}

bool accountValid(char choiceB)
{
    if (choiceB != 'Q' && choiceB != 'q')
    {
        choiceB = bankingMenu();
    }
    else
    {
        return true;
    }
    switch(choiceB)
    {
    case 'W':
    case 'w':
        withdraw();
        break;

    case 'D':
    case 'd':
        deposit();

        break;

    case 'B':
    case 'b':
        displayBalance();
        break;
    case 'R':
    case 'r':
        cout << " Date and Time\t\t\t\tTransaction\tAmount\t\Status\n";
        showTransHistory();
        break;
    case 'q':
    case 'Q':
        cout << "Logout successful!\n";
        mainMenu();
        break;
    default:
        cout << "Invalid option! Enter again\n\n";

    }
    accountValid(choiceB);


    cout << endl;

    return true;
}

bool choiceValid(char choice) // function to validate choices
{
    switch(choice)
    {
    case 'C':
    case 'c':
        createAccount();
        break;
    case 'L':
    case 'l':
        login();
        break;
    case 'v':
    case 'V':
        cout << "Thank you for using our bank and Future Computer Programmer ATM Machine!";
        cout << "For your continued support, we are offering \n3% cash back on all debit purchases. \n" ;
        mainMenu();
        break;
    case 'q':
    case 'Q':
        cout << "GoodBye! Thanks for stopping by.\n";
        return 0;
        break;


    default:

        cout << "Invalid option! Enter C, L, V, Q\n\n";

        mainMenu();

        //return false;
    }

    return 0;
}

//main function
int main()
{
    char choice, choiceB;
    choice = mainMenu();
    choiceB = accountValid(choiceB);


    return 0;
}
