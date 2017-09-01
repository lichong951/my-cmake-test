#include "stdio.h"
#include "hello.h"
#include "world.h"
#include <thired.hpp>
#include <hs/Stamp.hpp>
#include <hs/HighResolutionClock.hpp>

int main()
{
	HelloPrint();
	WorldPrint();

	return 0;
}
