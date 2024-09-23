#include <cs50.h>
#include <stdio.h>

int checksum(long x);
int number_of_digits(long credit);

int main(void)
{
    long number = get_long("number: ");
    int checkSumCard = checksum(number);
    int numDigit = number_of_digits(number);

    // get the first 2 digits
    int sixteen_digit = (number / 100000000000000);
    int fiftheen_digit = (number / 10000000000000);
    int thirteen_digit = (number / 1000000000000);

    if (checkSumCard == 0)
    {
        // check if card is amex
        if (numDigit == 15 && (fiftheen_digit == 34 || fiftheen_digit == 37))
        {
            printf("AMEX\n");
            return 0;
        }

        // check if card is mastercard
        else if (numDigit == 16 &&
                 (sixteen_digit == 51 || sixteen_digit == 52 || sixteen_digit == 53 ||
                  sixteen_digit == 54 || sixteen_digit == 55))
        {
            printf("MASTERCARD\n");
            return 0;
        }

        // // check if card is visa
        else if ((numDigit == 13 && thirteen_digit == 4) ||
                 (numDigit == 16 && sixteen_digit / 10 == 4))
        {
            printf("VISA\n");
            return 0;
        }
    }
    printf("INVALID\n");
}

// luhn's algorithm
int checksum(long x)
{
    // take every other digit
    int digit_1 = (x % 100 / 10);
    int digit_2 = (x % 10000 / 1000);
    int digit_3 = (x % 1000000 / 100000);
    int digit_4 = (x % 100000000 / 10000000);
    int digit_5 = (x % 10000000000 / 1000000000);
    int digit_6 = (x % 1000000000000 / 100000000000);
    int digit_7 = (x % 100000000000000 / 10000000000000);
    int digit_8 = (x % 10000000000000000 / 1000000000000000);

    // multiply them by 2
    digit_1 = (digit_1 * 2);
    digit_2 = (digit_2 * 2);
    digit_3 = (digit_3 * 2);
    digit_4 = (digit_4 * 2);
    digit_5 = (digit_5 * 2);
    digit_6 = (digit_6 * 2);
    digit_7 = (digit_7 * 2);
    digit_8 = (digit_8 * 2);

    // if num > 10 : sum digits separately
    digit_1 = (digit_1 % 100 / 10) + (digit_1 % 10);
    digit_2 = (digit_2 % 100 / 10) + (digit_2 % 10);
    digit_3 = (digit_3 % 100 / 10) + (digit_3 % 10);
    digit_4 = (digit_4 % 100 / 10) + (digit_4 % 10);
    digit_5 = (digit_5 % 100 / 10) + (digit_5 % 10);
    digit_6 = (digit_6 % 100 / 10) + (digit_6 % 10);
    digit_7 = (digit_7 % 100 / 10) + (digit_7 % 10);
    digit_8 = (digit_8 % 100 / 10) + (digit_8 % 10);

    // sum them
    int sum = digit_1 + digit_2 + digit_3 + digit_4 + digit_5 + digit_6 + digit_7 + digit_8;

    // take numbers that didn't multiply by 2
    int digit_a = (x % 10 / 1);
    int digit_b = (x % 1000 / 100);
    int digit_c = (x % 100000 / 10000);
    int digit_d = (x % 10000000 / 1000000);
    int digit_e = (x % 1000000000 / 100000000);
    int digit_f = (x % 100000000000 / 10000000000);
    int digit_g = (x % 10000000000000 / 1000000000000);
    int digit_h = (x % 1000000000000000 / 100000000000000);

    // sum them
    sum += digit_a + digit_b + digit_c + digit_d + digit_e + digit_f + digit_g + digit_h;

    // checksum
    if ((sum % 10 / 1) == 0)
        return 0;
    return 1;
}

// get card digit number
int number_of_digits(long credit_card)
{
    int count = 0;
    while (credit_card > 0)
    {
        credit_card /= 10;
        count++;
    }
    return count;
}
