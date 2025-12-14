#include "MicroBit.h"

MicroBit uBit;

// user code
extern "C" void user_main(MicroBit &uBit) __attribute__((section(".flash_user"), used, noinline));
void user_main(MicroBit &uBit)
{
    
    while(1)
    {
        uBit.display.scroll("RECEIVER");
    }
    
}



int main() 
{
    uBit.init();
    user_main(uBit);
}