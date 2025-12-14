#include "MicroBit.h"

MicroBit uBit;

// user code
extern "C" void user_main(MicroBit &uBit) __attribute__((section(".flash_user"), used, noinline));
void user_main(MicroBit &uBit)
{
    uBit.display.scroll("SENDER");
    MicroBitImage smiley("0,255,0,255, 0\n0,255,0,255,0\n0,0,0,0,0\n255,0,0,0,255\n0,255,255,255,0\n");
    while(1)
    {
        for (int y=4; y >= 0; y--)
        {
            uBit.display.image.paste(smiley,0,y);
            uBit.sleep(500);
        }
    }
    
}



int main() 
{
    uBit.init();
    user_main(uBit);
}
