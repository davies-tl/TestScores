/*
Program name: TestScores.cpp
Programmer: Tyler Davies
Date: 9-18-21
Version: 1.0
Description: This program demonstrates the created TestScores class which holds three test scores. The class
             has a created default constructor, accessor and mutator functions for the test score fields, and
             a member function that returns the average of the test scores. The main function creates an instance
             of the class and asks the user to enter three test scores, which are then stored in the TestScores
             object. It then displays the average of the test scores reported by the TestScores object.
*/

#include<iostream>
#include<iomanip>

using namespace std;

//Class declaration; this class holds three test scores and calculates their average.
class TestScores
{
    private:
        float score1, score2, score3;
    public:
        TestScores();
        TestScores(float, float, float);
        void setTestScore(int, float);
        float getTestScore(int);
        float calcAvgTestScore();
};

//Constructor (test scores unknown)
TestScores::TestScores()
{
    score1 = 0.0;
    score2 = 0.0;
    score3 = 0.0;
}

//Overloaded constructor (test scores known)
TestScores::TestScores(float test1, float test2, float test3)
{
    score1 = test1;
    score2 = test2;
    score3 = test3;
}

/*
This function sets a test score. Rather than having three different functions (one per test),
this function accepts an integer parameter indicating which of the three test scores will be
updated; if anything other than 1, 2, or 3 is entered, an error will print (nothing will update).
*/
void TestScores::setTestScore(int testNum, float score)
{
    if (testNum == 1)
        score1 = score;
    else if (testNum == 2)
        score2 = score;
    else if (testNum == 3)
        score3 = score;
    else
        cout << "Error: test number entered not recognized. \nNo score was updated!" << endl;
}

/*
This function returns a test score. Rather than having three different return functions (one per test),
this function accepts an integer parameter indicating which of the three test scores will be updated;
if anything other than 1, 2, or 3 is entered, an error will print (temporary value 0.0 is returned).
*/
float TestScores::getTestScore(int testNum)
{
    if (testNum == 1)
        return score1;
    else if (testNum == 2)
        return score2;
    else if (testNum == 3)
        return score3;
    else
    {
        cout << "Error: test number entered not recognized. \nNo score received!" << endl;
        return 0.0;
    }
}

//This function calculates and returns the average of the three test scores.
float TestScores::calcAvgTestScore()
{
    return (score1 + score2 + score3) / 3;
}

/*
The main function asks the user for three test scores, stores them in a TestScores object, and
prints the average reported by the TestScores object's calcAvgTestScores function.
*/
int main()
{
    TestScores scores;
    float test1, test2, test3;

    cout << "Enter three (3) test scores:" << endl;
    cin >> test1 >> test2 >> test3;

    scores.setTestScore(1, test1);
    scores.setTestScore(2, test2);
    scores.setTestScore(3, test3);

    cout << left << fixed << setprecision(1);
    cout << "Average Test Score: " << scores.calcAvgTestScore() << endl;

    exit(0);
}