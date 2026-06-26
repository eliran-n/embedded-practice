#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct mutex
{
    bool locked;      //  boolean - token
    void* ownership;  // fucntion pointer - ownership
} mutex_t;

static mutex_t mutex;

static uint32_t shared_counter = 0;

bool mutex_take(  mutex_t* mutex_handler )
{   
    if ( mutex_handler == NULL )
    {
        return false;
    }

    __disable_irq();

    if (mutex_handler->locked == false)
    {
        mutex_handler->locked = true;
        mutex_handler->ownership = CurrentTaskID();
        __enable_irq();
        return true;
    }
    __enable_irq();
    return false;
}

bool mutex_give( mutex_t* mutex_handler )
{
    if ( mutex_handler == NULL )
    {
        return false;
    }

    __disable_irq();

    if ( mutex_handler->locked == true && mutex_handler->ownership == CurrentTaskID() )
    {
        mutex_handler->locked = false;
        mutex_handler->ownership = NULL;
        __enable_irq();
        return true;
    }
    __enable_irq();
    return false;
}

bool mutex_init( mutex_t* mutex_handler )
{
    if ( mutex_handler == NULL )
    {
        return false;
    }
    mutex_handler->locked = false;
    mutex_handler->ownership = NULL;
    return true;
}

void task1( void )
{
    if( mutex_take(&mutex) )
    {
        shared_counter++;
        mutex_give(&mutex);
    }
    //printf("Increment counter++\n");
}

void task2( void )
{
    uint32_t counter_val = 0;

    if( mutex_take(&mutex) )
    {
        counter_val = shared_counter;
        mutex_give(&mutex);
    }
    //printf("Reading counter - val: %u\n", counter_val);
}

int main( void )
{   
    while(1)
    {
        task1();
        task2();
    }

    return 0;
}