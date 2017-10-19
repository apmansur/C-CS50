#include <stdio.h>
#include <cs50.h>

int pound(int n);

int main(void)
{
    printf("Height: ");
    int height = get_int();
    while (height > 23 || height < 0)
    {
        printf("Height: ");
        height = get_int();
    }
    if (height <= 23 && height >=0)
    {
    	for(int i = 0; i < height; i++)
    	{
    		// Print the required spaces
            for(int j = 0; j < height-i-1; j++)
            {
                printf("%s", " ");
            }
            // Print the '#' character.
    		for(int k = 0; k < i+2; k++)
    		{
    			printf("#");
    		}
    		printf("\n");
    	}
    }
    else
    {
        printf("Height: ");
        height = get_int();
    }

}
