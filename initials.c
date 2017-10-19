#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

//take name input and return uppercase initials

int main(void)
{
    printf("Name:\n");
    string str = get_string();
    int length = strlen(str);
    int upperStr[length];


    //make sure string is not null
    if( str != NULL)
    {
        //scroll through string and convert to upper case letters stored in array
        for(int i = 0; i < length; i++)
        {
            upperStr[i] = toupper(str[i]);
        }
        //scroll through upper case array
        for(int j = 0; j < length; j++)
        {
            //check to see if there is a space as the first character
            if(upperStr[0] != ' ')
            {
                if((upperStr[j] == ' ') && (upperStr[j + 1] != ' '))
                {
                    printf("%c", upperStr[j + 1]);
                }
                else if(j == 0)
                {
                    printf("%c", upperStr[j]);
                }
            }
            else if(upperStr[0] == ' ')
            {
                if((upperStr[j] != ' ') && (upperStr[j - 1] == ' '))
                    {
                        printf("%c", upperStr[j]);
                    }
            }
        }
     printf("\n");
    }
    return 0;
}
