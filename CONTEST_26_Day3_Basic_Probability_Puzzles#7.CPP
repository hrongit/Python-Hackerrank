//QUES LINK - https://www.hackerrank.com/contests/int213-contest26/challenges/basic-probability-puzzles-7/submissions/code/1350129473

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

struct plant
{
    float pipes_per_day;
    float failure_rate;

    void init (float ppd, float fr)
    {
        this->pipes_per_day = ppd;
        this->failure_rate = fr;
    }
};

int main ()
{
    plant A, B, C;

    A.init(500.0, .005);
    B.init(1000.0, .008);
    C.init(2000.0, .010);

    float A_prob = A.pipes_per_day * A.failure_rate;
    float B_prob = B.pipes_per_day * B.failure_rate;
    float C_prob = C.pipes_per_day * C.failure_rate;

    float top =  A_prob;
    float bottom = A_prob +  B_prob +  C_prob;

    while (top != (int) top || bottom != (int) bottom)
    {
        top*= 10;
        bottom *= 10;
    }

    int int_top= (int) top;
    int int_bottom = (int) bottom;

    ConvertToLowestTerms(int_top, int_bottom);

    printf("%d/%d", int_top, int_bottom);

    return 0;
}       