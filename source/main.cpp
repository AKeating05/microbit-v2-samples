#include "MicroBit.h"

MicroBit uBit;

extern "C" void user_stub(MicroBit &uBit);
extern "C" void init_user_abi(MicroBit &uBit);

int main() 
{
    uBit.init();
    init_user_abi(uBit);
    user_stub(uBit);
}