#ifndef DQMOFFLINE_LUMIZCOUNTING_MINIBACONDEFS_H
#define DQMOFFLINE_LUMIZCOUNTING_MINIBACONDEFS_H

#include <bitset>

const unsigned int kNTrigBit = 128;
typedef std::bitset<kNTrigBit> TriggerBits;
const unsigned int kNTrigObjectBit = 256;
typedef std::bitset<kNTrigObjectBit> TriggerObjects;

#endif
