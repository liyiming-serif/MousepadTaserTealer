#include "cacheofkings.h"

/*Defeat greedy bot by writing to own mem more efficiently*/
void __start(int core_id, int num_crashes, unsigned char payload) {
  int *ptr = (int *)HOME_DATA_SEGMENT + (rand() % HOME_DATA_SIZE);
  //write 4 copies of the payload into four bytes at once.
  unsigned int p = (unsigned int) payload;
  unsigned int payword = p | p << 8 | p << 16 | p << 24;
	
  if (core_id >= 2) {
    ptr += HIMEM;  // move pointer to opponent's half of memory
    Sneak_Attack();
  }

  int i = 0;
  while (1) {
    ptr[i++] = payword;
  }
}
