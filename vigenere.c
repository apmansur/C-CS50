#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>


//encode plaintext using vigenere cipher. program uses 1 command line argument as key to encode plaintext

int main(int argc, string argv[])
{
//expecting name of the program and one user argument only
    if(argc != 2)
    {
        printf("error, only one string argument is accepted. Abort.\n");
        return 1;
    }

    int keyLength = strlen(argv[1]);

    for(int j = 0; j<keyLength; j++)
    {
          if(isalpha(argv[1][j]) == 0)
          {
             printf("error, all characters in argument must be alphabetical.\n");
             return 1;
          }
    }

        printf("plaintext:");
        string plainText = get_string();
        int length = strlen(plainText);
        int keyCount = 0;


        //scroll through string
        printf("ciphertext: ");

        for(int i= 0; i< length; i++)
        {
            if (isalpha(plainText[i]))
            {
                //check if the letter is uppercase or lowercase then convert
                if (islower(plainText[i]) && islower(argv[1][keyCount]))
                {
                    printf("%c", (((plainText[i] - 97) + (argv[1][keyCount] - 97)) % 26) + 97);
                    keyCount = (keyCount + 1)%keyLength;
                }
                else if (isupper(plainText[i]) && islower(argv[1][keyCount]))
                {
                    printf("%c", (((plainText[i] - 65) + (argv[1][keyCount] - 97)) % 26) + 65);
                    keyCount = (keyCount + 1)%keyLength;
                }
                else if (islower(plainText[i]) && isupper(argv[1][keyCount]))
                {
                    printf("%c", (((plainText[i] - 97) + (argv[1][keyCount] - 65)) % 26) + 97);
                    keyCount = (keyCount + 1)%keyLength;
                }
                else if (isupper(plainText[i]) && isupper(argv[1][keyCount]))
                {
                    printf("%c", (((plainText[i] - 65) + (argv[1][keyCount] - 65)) % 26) + 65);
                    keyCount = (keyCount + 1)%keyLength;
                }
            }
            else
            {
                printf("%c", plainText[i]);
            }

        }
        printf("\n");
        return 0;
}


