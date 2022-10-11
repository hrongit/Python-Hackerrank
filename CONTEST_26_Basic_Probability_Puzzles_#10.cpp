//Ques Link - https://www.hackerrank.com/contests/int213-contest26/challenges/basic-probability-puzzles-10/submissions/code/1350129838



#include <stdbool.h>
#include <stdio.h>
#include  <iostream>

using namespace std;

void ConvertToLowestTerms(int &firstNum, int &secondNum)
{
    int Low_Value, High_Value;

    if(firstNum > secondNum)
    {
        Low_Value = secondNum;
         High_Value = firstNum;
    }
    else
    {
        High_Value = secondNum;
        Low_Value = firstNum;
    }

    for(int i = Low_Value; i > 0;i--)
    {
        if((Low_Value % i == 0) && (High_Value % i == 0))
        {
            firstNum = firstNum/i;
            secondNum = secondNum/i;

            break;
        }
   }
}

struct candidate
{
    int selected_top;
    int not_selected_top;
    int bottom;

    void init (int top, int bottom)
    {
        this->selected_top = top;
        this->bottom = bottom;
        this->not_selected_top = bottom - top;
    }
};

int main ()
{
    candidate Bill, Nina;
    Bill.init(1,3);
    Nina.init(1,5);

    int top = (Bill.selected_top * Nina.not_selected_top)  +
              (Bill.not_selected_top * Nina.selected_top);
    int bottom = Bill.bottom * Nina.bottom;

    ConvertToLowestTerms(top, bottom);

    printf("%d/%d", top, bottom);

    return 0;
}