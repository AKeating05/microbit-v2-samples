#include "MicroBit.h"

MicroBit uBit;

// user code
extern "C" void user_main(MicroBit &uBit) __attribute__((section(".flash_user"), used, noinline));
void user_main(MicroBit &uBit)
{
    uBit.display.scroll("SENDER");
    
    while(1)
    {
        MicroBitImage smiley("0,255,0,255, 0\n0,255,0,255,0\n0,0,0,0,0\n255,0,0,0,255\n0,255,255,255,0\n");
        for (int y=4; y >= 0; y--)
        {
            uBit.display.image.paste(smiley,0,y);
            uBit.sleep(500);
        }

        int16_t x = 0; // The x co-ordinate
        int16_t y = 0; // The y co-ordinate


        // Turn on the pixel in location (x, y)
        uBit.display.image.setPixelValue(x, y, 255);
        // Wait for 100 ms
        uBit.sleep(100);


        // Turn off the pixel in location (x, y)
        uBit.display.image.setPixelValue(x, y, 0);

        // Consider the edge conditions, i.e., (4,0), (4,4), (0,4), (0,0)
        // and update the x and y co-ordinates accordingly,
        // so that the moving dot changes direction when it reaches 
        // a corner of the 5x5 display.
        if (x < 4 && y == 0) // The dot moves from the left to the right of the top row
            x++;
        else
        {
            if (x == 4 && y < 4) // The dot moves from the top to the bottom of the right-most column
                y++;
            else
            {
                if (x > 0 && y == 4) // The dot moves from the right to the left of the bottom row
                    x--;
                else
                {
                    if (x == 0 && y > 0) // The dot moves from the bottom to the top of the left-most column
                        y--;
                }
            }
        }

        // Turn on the pixel in location (x, y)
        uBit.display.image.setPixelValue(x, y, 255);
        // Wait for 100 ms
        uBit.sleep(100);
    }
    
}



int main() 
{
    uBit.init();
    user_main(uBit);
}
