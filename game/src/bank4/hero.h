#ifndef hero_h
#define hero_h

#include <gb/gb.h>

extern GBUInt8 heroSpawnX;
extern GBUInt8 heroSpawnY;
extern GBUInt8 heroSpawnFaceLeft;
extern GBBool heroShouldSpawnAtSpawnPoint;

void heroSpawn();
void heroUpdate();

#endif
