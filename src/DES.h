// 
// Implementation of DES coded by:
//     - David Wong, moi@davidwong.fr
//     - Jacques Monin, jacques.monin@u-bordeaux.fr
//     - Hugo Bonnin, hugo.bonnin@u-bordeaux.fr
//
// Tables bellow can be verified on wikipedia:
// http://en.wikipedia.org/wiki/DES_supplementary_material#Initial_permutation_.28IP.29
//

#ifndef DES_H
#define DES_H

//
//             USEFUL DEFINES 
//

#define FIRSTBIT 0x8000000000000000 // 1000000000...

//
//             PROTOTYPES
//

// useful function to print a char in binary
void printbits(uint64_t v);

// Verify if the parity bits are okay
bool key_parity_verify(uint64_t key);

// Key Schedule
// input :
//   * next_key : uint64_t next_key 0;
//   * round : [[1, 16]]
// changes :
//   * [key] is good to be used in the XOR in the rounds
//   * [next_key] is the combined leftkey+rightkey to be used
//     in the key_schedule for next round
void key_schedule(uint64_t* key, uint64_t* next_key, int round);

#endif
