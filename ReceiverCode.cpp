#include "MicroBit.h"
#include "UserABIAccess.h"

MicroBit uBit;

// user code running on receiver micro:bit, this is overwritten with code transferred by sender
extern "C" void user_main(void) __attribute__((section(".flash_user"), used, noinline));
void user_main(void)
{
    //simple display animation turning pixels on column by column, row by row
    while(1)
    {    
        for(int y=0; y<5; y++)
        {
            for(int x=0; x<5; x++)
            {
                ABI->set_pixel(x,y,255);
                ABI->sleep(200);
            }
        }
        //clear each pixel
        for(int y=0; y<5; y++)
        {
            for(int x=0; x<5; x++)
            {
                ABI->set_pixel(x,y,0);
                ABI->sleep(200);
            }
        }
    }

}


extern "C" void user_stub(MicroBit &uBit);
extern "C" void init_user_abi(MicroBit &uBit);

int main() 
{
    uBit.init();
    init_user_abi(uBit);
    user_stub(uBit);
}