#include "cacheofkings.h"
#include ""

/*Defeat greedy bot by writing to own mem more efficiently*/
void __start(int core_id, int num_crashes, unsigned char payload)
{
  int *ptr = (int *)HOME_DATA_SEGMENT;
  //write 4 copies of the payload into four bytes at once.
  unsigned int p = (unsigned int) payload;
  unsigned int payword = p | p << 8 | p << 16 | p << 24;
  
  if(core_id == 0) //works on cacheline w. index = 00
  {
  }
  
  else if(core_id == 1) //works on cacheline w. index = 01
  {
    ptr += CACHE_LINE/4; //advance by 1 cacheline
  }
	
  else if (core_id == 2) { //works on cacheline 10 (opponent)
    ptr += (int)OPPONENT_DATA_SEGMENT;
    
    Alert_Guards();
  }
  
  else if(core_id == 3) { //workds on cacheline 11 (opponent)
    ptr += (int)OPPONENT_DATA_SEGMENT + CACHE_LINE/4;
    Sneak_Attack();
  }

  int i = 0; //offset
  //main loop
  while (1) { //TODO: detect when to prefetch here
    if(i >= (CACHE_LINE/4))
    {
      i = 0; //reset offset when end of block is reached
      ptr += 2*CACHE_LINE/4; //next blocks of mem for an index are 2 cachelines down
    }
    ptr[0] = payword;
    ptr[1] = payword;
    ptr[2] = payword;
    ptr[3] = payword;
    ptr[4] = payword;
    ptr[5] = payword;
    ptr[6] = payword;
    ptr[7] = payword;
    ptr[8] = payword;
    ptr[] = payword;
    ptr[] = payword;
    ptr[] = payword;
    ptr[] = payword;
    ptr[] = payword;
  }
}
