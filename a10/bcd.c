#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bcd.h"
// #include "../distribution/assignments/a10/src/bcd.h"

int audit_digits(Digit *d)
{
    if (d == NULL)
    {
        return 0;
    }

    if ((d->digit <= 0 || d->digit >= 9) && (d->next_higher_digit == NULL || audit_digits(d->next_higher_digit)))
    {
        return 1;
    }

    return 1;
}

char *bcd_to_string(BCD *bcd)
{
    Digit *d = bcd->least_significant_digit;

    int len = 0;

    while (d != NULL)
    {
        len++;
        d = d->next_higher_digit;
    }

    char *s = malloc(len + 1);
    s[len] = '\0';
    d = bcd->least_significant_digit;

    for (int i = len - 1; i >= 0; i--)
    {
        s[i] = d->digit + '0';
        d = d->next_higher_digit;
    }

    return s;
}

BCD *string_to_bcd(char *s)
{
    BCD *bcd = malloc(sizeof(BCD));
    bcd->least_significant_digit = NULL;

    Digit head;
    head.next_higher_digit = bcd->least_significant_digit;
    Digit *last = &head;

    int len = strlen(s);

    for (int i = len - 1; i >= 0; i--)
    {
        Digit *d = malloc(sizeof(Digit));
        d->digit = s[i] - '0';
        d->next_higher_digit = NULL;

        last->next_higher_digit = d;
        last = last->next_higher_digit;
    }

    bcd->least_significant_digit = head.next_higher_digit;
    return bcd;
}

BCD *read_bcd()
{
    char *s = malloc(100);
    if (scanf("%s", s) == EOF)
    {
        free(s);
        return NULL;
    }
    BCD *bcd = string_to_bcd(s);
    free(s);
    return bcd;
}

BCD *zero()
{
    return string_to_bcd("0");
}

BCD *add_bcd(BCD *a, BCD *b)
{
    BCD *sum = malloc(sizeof(BCD));
    sum->least_significant_digit = NULL;

    Digit head;
    head.next_higher_digit = sum->least_significant_digit;
    Digit *last = &head;

    Digit *a_digit = a->least_significant_digit;
    Digit *b_digit = b->least_significant_digit;

    Digit *carry = NULL;

    while (a_digit != NULL || b_digit != NULL || carry != NULL)
    {
        int a_val = a_digit == NULL ? 0 : a_digit->digit;
        int b_val = b_digit == NULL ? 0 : b_digit->digit;
        int carry_val = carry == NULL ? 0 : carry->digit;

        int sum_val = a_val + b_val + carry_val;

        Digit *new_digit = malloc(sizeof(Digit));
        new_digit->digit = sum_val % 10;
        new_digit->next_higher_digit = NULL;

        last->next_higher_digit = new_digit;
        last = last->next_higher_digit;

        if (sum_val >= 10)
        {
            if (carry == NULL)
            {
                carry = malloc(sizeof(Digit));
                carry->digit = sum_val / 10;
                carry->next_higher_digit = NULL;
            }
            else
            {
                carry->digit = (sum_val / 10);
            }
        }
        else
        {
            carry = NULL;
        }

        a_digit = a_digit == NULL ? NULL : a_digit->next_higher_digit;
        b_digit = b_digit == NULL ? NULL : b_digit->next_higher_digit;
    }

    if (carry != NULL)
    {
        Digit *new_digit = malloc(sizeof(Digit));
        new_digit->digit = carry->digit;
        new_digit->next_higher_digit = sum->least_significant_digit;
        sum->least_significant_digit = new_digit;
    }

    sum->least_significant_digit = head.next_higher_digit;
    return sum;
}

BCD *scale_bcd(BCD *a, int scale)
{
    BCD *product = malloc(sizeof(BCD));
    product->least_significant_digit = NULL;

    Digit head;
    head.next_higher_digit = product->least_significant_digit;
    Digit *last = &head;

    Digit *a_digit = a->least_significant_digit;

    Digit *carry = NULL;

    while (a_digit != NULL || carry != NULL)
    {
        int a_val = a_digit == NULL ? 0 : a_digit->digit;
        int carry_val = carry == NULL ? 0 : carry->digit;

        int product_val = (a_val * scale) + carry_val;

        Digit *new_digit = malloc(sizeof(Digit));
        new_digit->digit = product_val % 10;
        new_digit->next_higher_digit = NULL;

        last->next_higher_digit = new_digit;
        last = last->next_higher_digit;

        if (product_val >= 10)
        {
            if (carry == NULL)
            {
                carry = malloc(sizeof(Digit));
                carry->digit = product_val / 10;
                carry->next_higher_digit = NULL;
            }
            else
            {
                carry->digit = (product_val / 10);
            }
        }
        else
        {
            carry = NULL;
        }

        a_digit = a_digit == NULL ? NULL : a_digit->next_higher_digit;
    }

    if (carry != NULL)
    {
        Digit *new_digit = malloc(sizeof(Digit));
        new_digit->digit = carry->digit;
        new_digit->next_higher_digit = product->least_significant_digit;
        product->least_significant_digit = new_digit;
    }

    product->least_significant_digit = head.next_higher_digit;
    return product;
}

BCD *multiply_bcd(BCD *a, BCD *b)
{
    return NULL;
}