#include <stdio.h>
#include <string.h>
int main()
{
    int count = 0;
    char correct[] = "HELLO", guess[10];
    printf("\n\n--------INSTRUCTIONS---------\n");
    printf("\nWrite in CAPITAL LETTERS AND WORD CONSISTS OF ONLY 5 LETTERS\n");
    printf("YOU HAVE ONLY 5 ATTEMPTS !\n\n");
    printf("* Yellow Indicates Right Letter in Wrong position\n");
    printf("* Green Indicates Right Letter in Right position\n");
    printf("* Red Indicates Non-Existing Letter\n");
    int attempts = 0;
    for (int i = 0; i < 5; i++)
    {
        count = 0;
            printf("\nEnter The Guess Word\n");
            fgets(guess, sizeof(guess), stdin);
            while (strlen(guess) != 6)
            {
                printf("Enter exactly 5 letters!\n");
                fgets(guess, sizeof(guess), stdin);
            }
            for (int j = 0; j < 5; j++)
            {
                int found = 0;
                if (guess[j] == correct[j])
                {
                    printf("\033[0;32m%c\033[0m ", guess[j]);
                    count++;
                    if (count == 5)
                    {
                        printf("\n YOU SUCCESSFULLY ! GUESSED THE CORRECT WORD WHICH WAS %s", guess);
                        printf("\n TOTAL ATTEMPTS ARE: %d", i + 1);
                        return 0;
                    }
                }
                else
                {
                    for (int k = 0; k < 5; k++)
                    {
                        if (guess[j] == correct[k])
                        {
                            found = 1;
                        }
                    }
                    if (found == 1)
                    {
                        printf("\033[1;33m%c\033[0m", guess[j]);
                    }
                    else
                    {
                        printf("\033[1;31m%c\033[0m ", guess[j]);
                    }
                }
        }
    }
    printf("You Ran Out of ATTEMPTS");
}