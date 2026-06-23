#include <stdio.h>
#include <stdint.h>

uint8_t count_bits_on_loop( uint32_t number )
{
    const uint32_t bits_len = 32;
    uint8_t counter = 0;

    for (uint32_t i=0; i<bits_len; i++)
    {
        if ( (number & 1) == 1 )
        {
            counter++;
        }
        number = number >> 1;
    }
    return counter;
}

uint32_t count_bits_on_kernighan( uint32_t number )
{
    uint32_t counter = 0;

    while (number != 0)
    {
        number = number & ( number - 1);
        counter++;
    }
    return counter;
}

uint32_t count_bits_on_lookup_table( uint32_t number )
{
    // each position represents the number bits on
    const uint8_t combinations_8bit[256] = {
    0, 1, 1, 2, 1, 2, 2, 3,
    1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,

    1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6,
    4, 5, 5, 6, 5, 6, 6, 7,

    1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6,
    4, 5, 5, 6, 5, 6, 6, 7,

    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6,
    4, 5, 5, 6, 5, 6, 6, 7,
    3, 4, 4, 5, 4, 5, 5, 6,
    4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7,
    5, 6, 6, 7, 6, 7, 7, 8
    };

    uint32_t counter = 0;
    uint32_t res;

    for ( uint32_t i=0; i<4; i++)
    {
        res = number & 0x00FF;
        counter += combinations_8bit[res];
        number = number >> 8;
    }
    return counter;
}

int main( void )

{   uint32_t res = 0;

    //res = count_bits_on(7);               // should return 3

    //res = count_bits_on_effective(6);     // should return 2

    res = count_bits_on_lookup_table(12);  // should return 2

    printf("Number of bits: %u", res);
}