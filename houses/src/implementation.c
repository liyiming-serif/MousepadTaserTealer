#include "cacheofkings.h"
#include "" //?

/*Defeat greedy bot by writing to own mem more efficiently*/
void __start(int core_id, int num_crashes, unsigned char payload)
{
  int *ptr = (int *)HOME_DATA_SEGMENT;
  //write 4 copies of the payload into four bytes at once.
  unsigned int p = (unsigned int) payload;
  unsigned int w = (unsigned int) WHITE_WALKER;
  unsigned int a = (unsigned int) ARROW_BARRAGE;
  unsigned int payword = p | p << 8 | p << 16 | p << 24;
  unsigned int walker = p | p << 8 | p << 16 | w << 24;
  unsigned int archer = p | p << 8 | p << 16 | a << 24;
  
  if(core_id == 3) //works on cacheline w. index = 00
  {
  }
  
  else if(core_id == 2) //works on cacheline w. index = 01
  {
    ptr += CACHE_LINE/4; //advance by 1 cacheline
  }
	
  else if (core_id == 1) { //fbi
    //ptr += (int)OPPONENT_DATA_SEGMENT; //?
    
    Alert_Guards(2);
    Alert_Guards(3);
  }
  
  else if(core_id == 0) { //handles opponent's side of mem
    ptr += (int)OPPONENT_DATA_SEGMENT + CACHE_LINE/4;
    Sneak_Attack();
  }
  
  int mana = WHITE_WALKERS_PER_TEAM;
  int ammo = ARROW_BARRAGES_PER_TEAM;

  //main loop
  while (core_id != 1) {
    //reset offset when end of block is reached
    //next blocks of mem for an index are 2 cachelines down
    prefetch(ptr+2*CACHE_LINE/4); //->optimal place to prefetch is here
    ptr[0] = payword; //Unrolling
    ptr[1] = payword;
    ptr[2] = payword;
    ptr[3] = payword;
    ptr[4] = payword;
    ptr[5] = payword;
    ptr[6] = payword;
    ptr[7] = payword;
    ptr[8] = payword;
    ptr[9] = payword;
    ptr[10] = payword;
    ptr[11] = payword;
    ptr[12] = payword;
    ptr[13] = payword;
    ptr[14] = payword;
    ptr[15] = payword;
    ptr[16] = payword;
    ptr[17] = payword;
    ptr[18] = payword;
    ptr[19] = payword;
    ptr[20] = payword;
    ptr[21] = payword;
    ptr[22] = payword;
    ptr[23] = payword;
    ptr[24] = payword;
    ptr[25] = payword;
    ptr[26] = payword;
    ptr[27] = payword;
    ptr[28] = payword;
    ptr[29] = payword;
    ptr[30] = payword;
    ptr[31] = payword;
    ptr[32] = payword;
    ptr[33] = payword;
    ptr[34] = payword;
    ptr[35] = payword;
    ptr[36] = payword;
    ptr[37] = payword;
    ptr[38] = payword;
    ptr[39] = payword;
    ptr[40] = payword;
    ptr[41] = payword;
    ptr[42] = payword;
    ptr[43] = payword;
    ptr[44] = payword;
    ptr[45] = payword;
    ptr[46] = payword;
    ptr[47] = payword;
    ptr[48] = payword;
    ptr[49] = payword;
    ptr[50] = payword;
    ptr[51] = payword;
    ptr[52] = payword;
    ptr[53] = payword;
    ptr[54] = payword;
    ptr[55] = payword;
    ptr[56] = payword;
    ptr[57] = payword;
    ptr[58] = payword;
    ptr[59] = payword;
    ptr[60] = payword;
    ptr[61] = payword;
    ptr[62] = payword;
    if(core_id==0 && mana>0)
    {
      ptr[63] = walker;
      mana--;
    }
    else
      ptr[63] = payword;
    ptr += 2*CACHE_LINE/4;
  }
}
