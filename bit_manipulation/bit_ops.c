#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint32_t set_bit_by_position( uint32_t number, uint32_t position )
{
    number = number | (1U<<position);
    return number;
}

uint32_t clear_bit_by_position( uint32_t number, uint32_t position )
{
    number = number & ~(1U<<position);
    return number;
}

uint32_t toggle_bit_by_position( uint32_t number, uint32_t position )
{
    if ( (number & (1U<<position)) != 0 )
    {
        return clear_bit_by_position( number, position );
    }
    else
    {
        return set_bit_by_position( number, position );
    }
}

uint32_t toggle_bit_by_position_effective( uint32_t number, uint32_t position )
{
    number = number ^(1U<<position);
    return number;
}

bool check_bit_is_set( uint32_t number, uint32_t position )
{
    if ( (number & (1U<<position)) != 0 )
    {
        return true;
    }
    return false;
}

int main( void )
{
    uint32_t result;

    // 1000 -> 
    result = set_bit_by_position(8, 2);
    printf("Number 8 after setting bit at position 2: %u\n", result );

    // 1100 -> 1000
    result = clear_bit_by_position(12, 2);
    printf("Number 12 after clearing bit at position 2: %u\n", result );

    // 1000 - > 1010
    result = toggle_bit_by_position(8, 1);
    printf("Number 8 after toggling bit at position 1: %u\n", result );

    // 10100
    if ( check_bit_is_set(20, 2) == true )
    {
        printf("Bit 2 in number 20 is ON.\n");
    }
    else
    {
        printf("Bit 2 in number 20 is OFF.\n");
    }

    return 0;
}