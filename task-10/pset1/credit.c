#include <cs50.h>
#include <stdio.h>

int get_length_(long creditcard);
int get_sum_(long creditcard);

int main(void){
    long creditcard = get_long("Number: ");
    int lengthofcard = get_length_(creditcard);
    int sum = get_sum_(creditcard);

    // checks if the lenngth is valid
    if (lengthofcard != 13 && lengthofcard != 15 && lengthofcard != 16)
    {
        printf("INVALID\n");
        return 0;
    }


    else{
        //checks luhns algorithm
        if (sum % 10 != 0){

            printf("INVALID\n");
            return 0;
        }
        // checks what card it is
        else{
            long start = creditcard;
            do{
                start = start/10;
            }
            while (start>100);

            if (start==51 || start == 52 || start == 53 || start == 54 || start == 55){
                printf("MASTERCARD\n");
            }
            else if (start/10 == 4){
                printf("VISA\n");
            }
            else if (start==34 || start==37){
                printf("AMEX\n");
            }
            else{
                printf("INVALID\n");
            }

        }
    }


    }

//function to get length of cc number
int get_length_(long creditcard){
    int i = 0;
    long cc = creditcard;
    while (cc > 0)
    {
        cc = cc / 10;
        i++;
    }
    return i;
}

//function to calculate the sum as required in the question
int get_sum_(long creditcard){
    int sum1 = 0;
    int sum2 = 0;
    long x = creditcard;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;    do
    {
        // Remove last digit and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;        // Remove second last digit
        mod2 = x % 10;
        x = x / 10;        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);    total = sum1 + sum2;
    return total;
}







