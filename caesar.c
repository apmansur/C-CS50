#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
//expecting name of the program and one user argument only
    if(argc != 2){
        printf("error, only one non-negative integer can be passed");
        return 1;
    }
    else
    {
        printf("plaintext:");
        string plainText = get_string();
        int length = strlen(plainText);
        //make array value into integer
        int k = atoi(argv[1]);

        //scroll through string
        printf("ciphertext:");
        for(int i= 0; i< length; i++)
        {
                //check if the letter is uppercase or lowercase then convert
                if islower(plainText[i])
                    printf("%c", (((plainText[i] + k) - 97) % 26) + 97);
                else if isupper(plainText[i])
                    printf("%c", (((plainText[i] + k) - 65) % 26) + 65);
                else
                    printf("%c", plainText[i]);
           }
            printf("\n");
        }

}
