#include "mainMenu.h"
#include "../memory.h"
#include "../sprites.h"
#include "../data/gfx_titleTiles.h"
#include "../data/music_titleSong.h"

#pragma bank 1

// ===
// Private Defines
// ===
#define _mainMenuPressStartY 136
#define _mainMenuPressStartCycleDuration 120

// ===
// Private Variables
// ===
GBUInt8 _mainMenuPressStartCycle;

// ===
// Private API
// ===
void _mainMenuUpdatePressStartCycle() {
    GBUInt8 x;
    
    _mainMenuPressStartCycle--;
    if(_mainMenuPressStartCycle == 0) {
        _mainMenuPressStartCycle = _mainMenuPressStartCycleDuration;
    }
    
    if(_mainMenuPressStartCycle < 30) {
        for(x = 0; x != 8; x++) {
            spriteAttributes[x].y = 0;
        }
    } else {
        for(x = 0; x != 8; x++) {
            spriteAttributes[x].y = _mainMenuPressStartY;
        }
    }
}

// ===
// Public API
// ===
void mainMenuInit() {
    _mainMenuPressStartCycle = _mainMenuPressStartCycleDuration;
}

void mainMenuWake() {
    GBUInt8 x, c;
    
    gbLCDDisable();
    
    memoryCopyBanked(gbTileMemory + 0x0800, titleTiles, titleTilesLength, titleTilesBank);
    
    audioPlayComposition(&titleSong, titleSongBank, audioLayerMusic, 0);
    
    c = 0;
    for(x = 0; x != gbTileMapWidth; x++) {
        gbTileMap0[x + 0 * gbTileMapWidth] = 128 + 15;
        gbTileMap0[x + 1 * gbTileMapWidth] = 128 + 15;
        gbTileMap0[x + 2 * gbTileMapWidth] = 128 + c;
        gbTileMap0[x + 3 * gbTileMapWidth] = 128 + 16 + c;
        gbTileMap0[x + 4 * gbTileMapWidth] = 128 + 4 + c;
        gbTileMap0[x + 5 * gbTileMapWidth] = 128 + 20 + c;
        
        c++;
        if(c == 4) {
            c = 0;
        }
    }
    
    for(x = 0; x != 20; x++) {
        gbTileMap0[x + 6 * gbTileMapWidth] = 128 + 13;
        gbTileMap0[x + 7 * gbTileMapWidth] = 128 + 13;
        gbTileMap0[x + 8 * gbTileMapWidth] = 128 + 13;
        gbTileMap0[x + 9 * gbTileMapWidth] = 128 + 13;
        
        gbTileMap0[x + 10 * gbTileMapWidth] = 128 + 64 + c;
        gbTileMap0[x + 11 * gbTileMapWidth] = 128 + 80 + c;
        gbTileMap0[x + 12 * gbTileMapWidth] = 128 + 68 + c;
        gbTileMap0[x + 13 * gbTileMapWidth] = 128 + 84 + c;
        gbTileMap0[x + 14 * gbTileMapWidth] = 128 + 72 + c;
        gbTileMap0[x + 15 * gbTileMapWidth] = 128 + 88 + c;
        
        gbTileMap0[x + 16 * gbTileMapWidth] = 128 + 14;
        gbTileMap0[x + 17 * gbTileMapWidth] = 128 + 14;
        
        c++;
        if(c == 4) {
            c = 0;
        }
    }
    
    for(x = 0; x != 12; x++) {
        gbTileMap0[x + 7 * gbTileMapWidth + 4] = 128 + 32 + x;
        gbTileMap0[x + 8 * gbTileMapWidth + 4] = 128 + 48 + x;
    }
    
    gbTileMap0[7 * gbTileMapWidth + 16] = 128 + 12;
    for(x = 0; x != 4; x++) {
        gbTileMap0[x + 8 * gbTileMapWidth + 16] = 128 + 28 + x;
        gbTileMap0[x + 9 * gbTileMapWidth + 16] = 128 + 44 + x;
        gbTileMap0[x + 10 * gbTileMapWidth + 16] = 128 + 60 + x;
        gbTileMap0[x + 11 * gbTileMapWidth + 16] = 128 + 76 + x;
        gbTileMap0[x + 12 * gbTileMapWidth + 16] = 128 + 92 + x;
        gbTileMap0[x + 13 * gbTileMapWidth + 16] = 128 + 108 + x;
    }
    
    for(x = 0; x != 8; x++) {
        spriteAttributes[x].x = 56 + x * 8;
        spriteAttributes[x].y = _mainMenuPressStartY;
        spriteAttributes[x].tileIndex = 0xE0 + x;
    }
    
    gbLCDEnable();
}

void mainMenuUpdate() {
    _mainMenuUpdatePressStartCycle();
    
    if(gbJoypadPressedSinceLastUpdate & gbJoypadStart) {
        gbLog("Start!");
    }
}

void mainMenuUpdateGraphics() {
    
}
