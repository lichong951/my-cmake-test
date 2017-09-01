#include <hs/Stamp.hpp>
#include <hs/HighResolutionClock.hpp>

int main()
{

	hs::Timestamp begin = hs::stampMs();

	for(int i=0;i<100000;i++){

	}
	hs::Timestamp end = hs::stampMs();


return 0;
}
