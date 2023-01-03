//
// Copyright (c) 2017 The Altra64 project contributors
// Portions (c) 2013 saturnu (Alt64) based on libdragon, Neo64Menu, ED64IO, libn64-hkz, libmikmod
// See LICENSE file in the project root for full license information.
//

#include "sram.h"
#include "everdrive.h"
#include "sys.h"
#include "rom.h"
#include "cic.h"
#include <libdragon.h>

void pif_boot()
{
    //TODO: implement
}



int is_valid_rom(unsigned char *buffer) {
    /* Test if rom is a native .z64 image with header 0x80371240. [ABCD] */
    if((buffer[0]==0x80)&&(buffer[1]==0x37)&&(buffer[2]==0x12)&&(buffer[3]==0x40))
        return 0;
    /* Test if rom is a byteswapped .v64 image with header 0x37804012. [BADC] */
    else if((buffer[0]==0x37)&&(buffer[1]==0x80)&&(buffer[2]==0x40)&&(buffer[3]==0x12))
        return 1;
    /* Test if rom is a wordswapped .n64 image with header  0x40123780. [DCBA] */
    else if((buffer[0]==0x40)&&(buffer[1]==0x12)&&(buffer[2]==0x37)&&(buffer[3]==0x80))
        return 2;
    else
        return 0;
}

void swap_header(unsigned char* header, int loadlength) {
    unsigned char temp;
    int i;

    /* Btyeswap if .v64 image. */
    if( header[0]==0x37) {
        for (i = 0; i < loadlength; i+=2) {
            temp= header[i];
            header[i]= header[i+1];
            header[i+1]=temp;
            }
        }
    /* Wordswap if .n64 image. */
    else if( header[0]==0x40) {
        for (i = 0; i < loadlength; i+=4) {
            temp= header[i];
            header[i]= header[i+3];
            header[i+3]=temp;
            temp= header[i+1];
            header[i+1]= header[i+2];
            header[i+2]=temp;
        }
    }
}

u8 getCicType(u8 bios_cic) {
    u8 cic_buff[2048];
    volatile u8 cic_chip;
    volatile u32 val;
    if (bios_cic) {
        evd_setCfgBit(ED_CFG_SDRAM_ON, 0);
        sleep(10);
        val = *(u32 *) 0xB0000170;
        dma_read_s(cic_buff, 0xB0000040, 1024);
        cic_chip = get_cic(cic_buff);
        evd_setCfgBit(ED_CFG_SDRAM_ON, 1);
        sleep(10);
    }
    else {
        val = *(u32 *) 0xB0000170;
        dma_read_s(cic_buff, 0xB0000040, 1024);
        cic_chip = get_cic(cic_buff);
    }

    return cic_chip;
}

//send game id for n64digital hdmi mod
//source: https://gitlab.com/pixelfx-public/n64-game-id
void send_game_id(uint8_t* crc_hi, uint8_t* crc_lo, uint8_t media_format, uint8_t country_id)
{
    #define N64_CONTROLLER_PORT 0
    #define GAME_ID_COMMAND 0x1D
    
    uint8_t out[10];
    uint8_t dummy[1];

    memcpy(out, crc_hi, 4);
    memcpy(&out[4], crc_lo, 4);

    out[8] = media_format;
    out[9] = country_id;

    execute_raw_command(N64_CONTROLLER_PORT, GAME_ID_COMMAND, sizeof(out), sizeof(dummy), out, dummy);
}

// get the country and region string from country code "headerdata[0x3E]" (region type via www.bubblevision.com/PAL-NTSC.htm)
// NTSC, PAL, MPAL or unknown 
void get_country_and_region(unsigned char ccode, char* region_string)
{
    switch (ccode)
    {
        case '7': strcpy(rom_name, "Beta"); break;               
        case 'A': strcpy(rom_name, "Asia-NTSC"); break;          
        case 'B': strcpy(rom_name, "Brazil-MPAL"); break;              
        case 'C': strcpy(rom_name, "China-PAL"); break;
        case 'D': strcpy(rom_name, "Germany-PAL"); break;
        case 'E': strcpy(rom_name, "NorthAmerica-NTSC"); break;
        case 'F': strcpy(rom_name, "France-PAL"); break;
        case 'G': strcpy(rom_name, "Gateway64-NTSC"); break;
        case 'H': strcpy(rom_name, "Netherlands-PAL"); break;
        case 'I': strcpy(rom_name, "Italy-PAL"); break;
        case 'J': strcpy(rom_name, "Japan-NTSC"); break;
        case 'K': strcpy(rom_name, "Korea-NTSC"); break;
        case 'L': strcpy(rom_name, "Gateway64-PAL"); break;
        case 'N': strcpy(rom_name, "Canada-NTSC"); break;
        case 'P': strcpy(rom_name, "Europe-PAL"); break;
        case 'S': strcpy(rom_name, "Spain-PAL"); break;
        case 'U': strcpy(rom_name, "Australia-PAL"); break;
        case 'W': strcpy(rom_name, "Scandinavia-PAL"); break;
        case 'X': strcpy(rom_name, "Europe-PAL"); break;
        case 'Y': strcpy(rom_name, "Europe-PAL"); break;
        case 'Z': strcpy(rom_name, "Europe-PAL"); break;
        default:  strcpy(rom_name, "No Country");
    }
}

// get the region from country code "headerdata[0x3E]" (region type via www.bubblevision.com/PAL-NTSC.htm)
unsigned char get_region(unsigned char ccode)
{
    switch (ccode)
    {
        case '7': return REGION_UNKNOWN;               
        case 'A': return REGION_NTSC;          
        case 'B': return REGION_PAL_M;              
        case 'C': return REGION_PAL;
        case 'D': return REGION_PAL;
        case 'E': return REGION_NTSC;
        case 'F': return REGION_PAL;
        case 'G': return REGION_NTSC;
        case 'H': return REGION_PAL;
        case 'I': return REGION_PAL;
        case 'J': return REGION_NTSC;
        case 'K': return REGION_NTSC;
        case 'L': return REGION_PAL;
        case 'N': return REGION_NTSC;
        case 'P': return REGION_PAL;
        case 'S': return REGION_PAL;
        case 'U': return REGION_PAL;
        case 'W': return REGION_PAL;
        case 'X': return REGION_PAL;
        case 'Y': return REGION_PAL;
        case 'Z': return REGION_PAL;
        default:  return REGION_UNKNOWN;
    }
    return REGION_UNKNOWN;
}