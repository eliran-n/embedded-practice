#include <stdint.h>
#include <stdio.h>

// Given two numbers x and x+2,
// compute their middle value (x + 1).
//
// Constraint:
// Must be solved using bitwise operations only
// (no arithmetic operators allowed: +, -, *, /)

// Example:

// Odd number - Clear y LSB
// 011  = 3 (x)
// 101  = 5 (y)
// --------
// 100  = 4

// Even number - Set x LSB
// 100  = 4 (x)
// 110  = 6 (y)
// --------
// 101  = 5

uint32_t find_middle_value( uint32_t x, uint32_t y )
{
    uint32_t mid;

    // if number is odd
    if ( (x & 1) == 1 )
    {
        mid = (y & (~1));
    }
    // if number is even
    else
    {
        mid = (x | 1);
    }
    return mid;
}

int main( void )
{
    uint32_t middle_val;

    middle_val = find_middle_value(3, 5);
    printf("The middle value is: %u\n", middle_val);

    middle_val = find_middle_value(4, 6);
    printf("The middle value is: %u\n", middle_val);

    return 0;
}