#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


 int main(int argc, string argv[])
 {
    if (argc != 2)
    {
        printf("Nope\n");
        return 1;
    }


    int k = atoi(argv[1]);

    if (k < 0)
    {
        printf("Nope\n");
        return 1;
    }
    else
    {

        string text = get_string("Plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(text); i < n; i++)
            {

                if islower(text[i])
                    printf("%c", (((text[i] + k) - 97) % 26) + 97);
                else if isupper(text[i])
                    printf("%c", (((text[i] + k) - 65) % 26) + 65);
                else
                    printf("%c", text[i]);
            }
            printf("\n");
            return 0;
    }
 }