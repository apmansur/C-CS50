#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool isValidNum(long long n);
int numPlaces(long long n);

int main(void)
{
  printf("Credit Card Number: ");
  long long cNumber = get_long_long();
  long long digits = numPlaces(cNumber);
  int number[digits];
  int oSum = 0;
  int eSum = 0;
  int tSum = oSum + eSum;
  bool validation = false;

    if (digits <= 16 && digits >=13)
      {
         int modNumber[digits];
         //make array of each digit in credit card number (does so in reverse order so first number in array
         //is last numberof original)
          for (int i = 0; i < digits; i++)
            {
            number[i] = cNumber % 10;
            cNumber = cNumber / 10;
            }
         //math involved for the validation of the number
         for (int j = 0; j < digits; j++)
         {
             //for every other number starting with the second to last number
             if (j%2 == 1)
             {
                 modNumber[j]= number[j] * 2;
                 if (modNumber[j] >= 10)
                 {
                     modNumber[j] = (1 + (modNumber[j]-10));
                     oSum += modNumber[j];
                 }
                 else
                 {
                    oSum += modNumber[j];
                 }
             }
             // accounts for other numbers
             else if (j%2 == 0 || j == 0)
             {
                 modNumber[j] += eSum;
             }
         }
         // checks if sum is divisible by 10
       if((tSum%10) == 0)
       {
          validation = true;
       }
        else
        {
         printf("INVALID\n");
         validation = false;
        }
      }

//check to see what type of card it is

     if (validation == true)
     {
         switch(number[digits-1])
         {
             case 4:
             printf("VISA\n" );
             break;
             case 5:
                if(number[digits-2] == 1 || number[digits-2] == 2|| number[digits-2] == 3 ||number[digits-2] == 4 || number[digits-2] == 5){
                    printf("MASTERCARD\n");
                }
             break;
             case 3:
                if(number[digits-2] == 4 || number[digits-2] == 7){
                    printf("AMEX\n" );
                }
            break;
            default:
                printf("INVALID\n");
         }
     }
     else
     {
         printf("INVALID\n");
     }
 return 0;
}




// function used to get number of digits in credit card number
int numPlaces(long long n)
{
    if (n < 0)
    {
     return 17;
    };
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    if (n < 10000000000) return 10;
    if (n < 100000000000) return 11;
    if (n < 1000000000000) return 12;
    if (n < 10000000000000) return 13;
    if (n < 100000000000000) return 14;
    if (n < 1000000000000000) return 15;
    if (n < 10000000000000000) return 16;

    return 17;
}
