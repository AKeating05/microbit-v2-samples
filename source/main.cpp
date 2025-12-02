#include "MicroBit.h"
// testpage to flash
extern "C" void test(MicroBit &uBit);
static void (*force_ref)(MicroBit &uBit) __attribute__((used)) = test;

MicroBit uBit;

int main() 
{
    uBit.init();
    uBit.display.print("S");
}
