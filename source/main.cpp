#include "MicroBit.h"
#include "UserABIAccess.h"

MicroBit uBit;

// user code
extern "C" void user_main(void) __attribute__((section(".flash_user"), used, noinline));
void user_main(void)
{
    ABI->scroll("HELLO");
    while(1)
    {
        ABI->set_pixel(0,0,255);
        ABI->sleep(200);
        ABI->set_pixel(0,0,0);
        ABI->sleep(200);
    }
    
}

int main() 
{
    uBit.init();
    while(1)
    {
        uBit.display.scroll("SENDER");
    }
}