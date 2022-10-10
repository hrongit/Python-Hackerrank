#QUES LINK - https://www.hackerrank.com/contests/int213-contest25/challenges/basic-probability-puzzles-6/submissions/code/1350052848

IN C++

#include <stdbool.h>
#include <stdio.h>

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

struct bag
{
    int white_balls;
    int black_balls;
    int poss;

    void init (int wb, int bb)
    {
        this->white_balls = wb;
        this->black_balls = bb;
        this->poss = wb + bb;
    }
};

int main ()
{
    bag X, Y;

    X.init(5,4);
    Y.init(7,6);

    int tot_poss = X.poss * (Y.poss + 1);
    int draw_first_black_top = X.black_balls * (Y.black_balls + 1);
    int draw_first_white_top = X.white_balls * Y.black_balls;

    int top = draw_first_black_top + draw_first_white_top;
    int bottom = tot_poss;

    ConvertToLowestTerms(top, bottom);

    printf("%d/%d", top, bottom);

    return 0;
}