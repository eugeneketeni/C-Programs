#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/*Author:Eugene Mawuli Keteni.
Date: 03/23/2016
Description: This program will accept user input for various class grades and calculate the overall grade for the the user.*/

/*Pseudocode: The program should display to the user what this program is about. The program is a grade calculator.
The program will ask the user to input his various grades earned for each assignment. There are variables declared in the program which are going to receive
and store input from the user. Since grades are been calculated, there is an variable that calculates the average for each section. The function created performs
various function by been called in the main function.  The average grades calculated are however added up to calculate the overall grade.*/


void DisplayGrades();

int menu() //Displays menu.
{
   int choice;
    {
    cout << "\tMenu! Select your choice" << endl << endl;
    cout << "1. Show the Grades in a Tabular Format" << endl;
    cout << "2. Show the Overall Grade (number and letter)" << endl;
	cout << "3. Exit if any other input" << endl << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
   }
   return choice;
}



void DisplayGrades() //Function prototype

{
    int fieldlenght = 15;
    cout << "The grades are calculated based on the following breakdown!" << endl << endl;
    cout << setw(8) << "Assignment 1-4" << "\t" << setw(14) << "Each 5%" << "\t" <<  setw(14) << "Total 20%" << endl;
    cout << setw(8) << "Lab Test 1-3" << "\t" << setw( fieldlenght) << "Each 10%" << setw(fieldlenght) << "Total 30%" << endl;
    cout << setw(8) << "Lecture Test 1-4" << setw(fieldlenght) << "Each 10%" << setw(fieldlenght) << "Total 40%" << endl;
    cout << setw(8) << "Post Labs 1-9" << "\t" << setw( fieldlenght) << "Each .3%" << "\t" << setw( fieldlenght) << "Total 2.7%" << endl;
    cout << setw(8) << "Quizzes 1-9" << "\t" << setw( fieldlenght) << "Each .4%" << "\t" << setw( fieldlenght) << "Total 3.6%" << endl;
    cout << setw(8) << "Clickers" << "\t" << setw( fieldlenght) << " " << "\t" << setw( fieldlenght) << "Total 3.7%" << endl << endl << endl;
}
// This function is used to calculate total weight of assignment towards final grade
float AssignmentGrade(float sumA)
{   float AsgnAvg, numOfAssignment = 4;
    AsgnAvg = (sumA / numOfAssignment)*0.2;
    return AsgnAvg;
}
// this function will calculate total weight of lab test grades towards final grade
float LabTestGrade (float sumL)
{   float LabAvg, numOfLab = 3;
    LabAvg = (sumL / numOfLab)*0.3;
    return LabAvg;
}
// This function will calculate total weight of lecture test grades towards final grade
float LectureTestGrade(float sumLe)
{   float lectureAvg, numOfLe = 4;
    lectureAvg = (sumLe / numOfLe )*0.4;
    return lectureAvg;
}

// This function calculate total weight of Post lab grades towards final grade
float PostLabGrade ( float sumP)
{  float PostAvg, numOfPostLab = 9;
   PostAvg = (sumP / numOfPostLab)*0.027;
   return PostAvg;
}

// This function calculate total weight of Quiz grades towards final grade
float QuizGrade (float sumQ)
{   float QuizAvg, numOfQuiz = 9;
    QuizAvg = (sumQ /numOfQuiz)*0.036;
    return QuizAvg;
}

// This function calculate total weight of clicker towards final grade
float clickerGrade(float clicker)
{   float clickAvg; //amtOfPoints = 0;
    clickAvg = (clicker * 0.037);
    return clickAvg;
}

//This function assigns letter grade to the various grades earned
void letterGrade(float AllGrade)
{
    if (AllGrade >=90 && AllGrade <= 100)
    {
        cout << "Letter grade is: A " << endl;
    }
    else if (AllGrade >= 80 && AllGrade <= 89)
    {
        cout << "Letter grade is: B " << endl;
    }
    else if (AllGrade >= 70 && AllGrade <= 79)
    {
        cout << "Letter grade is: C " << endl;
    }
    else if (AllGrade >= 60 && AllGrade <= 69)
    {
        cout << "Letter grade is: D " << endl;
    }
    else
    {
        cout << "Letter grade is: F " << endl;
    }


}

// should be called for option 2 of menu which will display the overall grade and the letter grade
void OverAllGrade(float AsgnAvg, float LabAvg, float lectureAvg, float PostAvg, float QuizAvg, float clickAvg)
{
  float AllGrade = (AsgnAvg + LabAvg + lectureAvg + PostAvg + QuizAvg + clickAvg);

    cout << "Your Overall grade is: " << AllGrade << "%" << endl;
    letterGrade(AllGrade);
}

//This function checks to see if the grades entered are valid.
bool gradeIsvalid(float grade)
{
    if(grade > 100 || grade < 0)
    {
       return false;
    }
    else if(grade <=100 || grade >= 0)
    {
        return true;
    }
}
//This function checks if choice is valid
bool menuChoiceIsValid (float choice)
{
    float AsgnAvg, LabAvg, lectureAvg, PostAvg, QuizAvg,clickAvg,AllGrade;

    if (choice !=1 && choice !=2 && choice != 3)
        {

        cout << "Invalid. Enter again: ";
       cin >> choice;
        menuChoiceIsValid(choice);
        return false;
    }
    if (choice == 1)
    {
         DisplayGrades();
    }

    else if (choice ==2)
    {

        //OverAllGrade( AsgnAvg,LabAvg, lectureAvg, PostAvg, QuizAvg,clickAvg);
       // letterGrade(AllGrade);
    }
    else if (choice == 3)
    {
        exit(0);
    }
        return true;
}



//This is the main function
int main()
{
  //Variables declaration and initialization
    float asgnment, clicker,  AsgnAvg,  LabAvg,  lectureAvg, PostAvg, AllGrade, QuizAvg, amtOfPoints,  clickAvg; //asgnment2, asgnment3, asgnment4, test1, test2, test3, test4, clickScore, grade;
    const int numOfPostLab = 9;
    float sumP = 0;
    float inputP;

    const int numofQuiz = 9;
    float sumQ = 0;
    float inputQ;

    float numOfAssignment = 4;
    float inputA;
    float sumA = 0;

    float sumL = 0, inputL, numOfLab = 3;
    float inputLe, sumLe = 0, numOfLe = 4;

//This output displays to the user what this program is about
    cout << "This program will accept students grades for the semester for each section of Intro to Programming 1, and also calculatethe overall"
    " grades for the semester."
    << endl;
    system("pause");

    cout << endl;

//Accepts users Assignment Grades
     for (float asgnment = 1; asgnment <= numOfAssignment; asgnment++)
    {   float grade;

        cout << "Enter your assignment " << asgnment << " grade: ";
        cin >> inputA;
       if(gradeIsvalid(inputA) == true)
        {
           sumA += inputA;
        }
        else
        {
           asgnment--;
        }

    }
    AsgnAvg = AssignmentGrade(sumA);

     cout << "Your overall Assignment Average is: " << AssignmentGrade(sumA) <<"%" << endl;
    cout << endl;

    //Accepts Users Lab Grades
    for (float lab = 1; lab <= numOfLab; lab++)
    {

        cout << "Enter your Lab " << lab << " grade: ";
        cin >> inputL;
        if(gradeIsvalid(inputL) == true)
        {
           sumL += inputL;
        }
        else
        {
           lab--;
        }


    }
    LabAvg = LabTestGrade(sumL);
    cout << "Your overall Lab Average is: " << LabTestGrade(sumL) << "%" << endl;
    cout << endl;

    //Accepts users Lecture Grades
    for (float le = 1; le <= numOfLe; le++)
    {

        cout << "Enter your Lecture " << le << " grade: ";
        cin >> inputLe;
        if(gradeIsvalid(inputLe) == true)
        {
           sumLe += inputLe;
        }
        else
        {
           le--;
        }


    }
    lectureAvg = LectureTestGrade(sumLe);

    cout << "Your overall Lecture Average is: " << LectureTestGrade(sumLe) << "%" << endl;

    cout << endl;

//Get 9 input from user.
    for (float postLab = 1; postLab <= numOfPostLab; postLab++)
    {
        cout << "Enter your postlab " << postLab << " grade: ";
        cin >> inputP;
        if(gradeIsvalid(inputP) == true)
        {
           sumP += inputP;
        }
        else
        {
           postLab--;
        }


    }
    PostAvg = PostLabGrade (sumP);
    cout << "Your overall post lab Average is: " << PostLabGrade (sumP) << "%" << endl;
    cout << endl;

//Get 9 input from user.
    for (int Quiz = 1; Quiz <= numofQuiz; Quiz ++)
    {

        cout << "Enter your Quiz " << Quiz << " grade: ";
        cin >> inputQ;
        if(gradeIsvalid(inputQ) == true)
        {
           sumQ += inputQ;
        }
        else
        {
           Quiz--;
        }

    }
    QuizAvg = QuizGrade(sumQ);
    cout << "Your overall Quiz Average is: " << QuizGrade(sumQ) << "%" << endl;
        cout << endl;

//Accepts Clicker score
        cout << "Enter clicker grade score: ";
        cin >> clicker;
        if(gradeIsvalid(clicker) == true)
        {
          clicker;
        }
        else
        {
           clicker--;
        }

        cout << "Your overall clicker grades is: " << clickerGrade(clicker) << "%" << endl;
        clickAvg = clickerGrade(clicker);


        cout << endl;

int choice;
choice = menu();
menuChoiceIsValid (choice);
OverAllGrade( AsgnAvg,LabAvg, lectureAvg, PostAvg, QuizAvg,clickAvg);




return 0;
}















