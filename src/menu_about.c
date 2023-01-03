
#include <libdragon.h>
#include <stdio.h>
#include "types.h"
#include "menu.h"
#include "version.h"
#include "main.h"
#include "everdrive.h"


void menu_about(display_context_t disp)
{
    char version_str[32];
    char firmware_str[32];

    sprintf(version_str, "Altra64: v%s", Altra64_GetVersionString());
    printText(version_str, 9, 7, disp);                                     //1
    sprintf(firmware_str, "ED64 firmware: v%03x", evd_getFirmVersion());
    printText(firmware_str, 9, -1, disp);                                   //2
    printText("by JonesAlmighty", 9, -1, disp);                             //3
    printText("Based on ALT64 by Saturnu", 9, -1, disp);                    //4 
    printText("Credits:", 9, -1, disp);                                     //5
    printText("Jay Oster,Krikzz,", 9, -1, disp);                            //6
    printText("Richard Weick,ChillyWilly,", 9, -1, disp);                   //7
    printText("ShaunTaylor,Conle,", 9, -1, disp);                           //8
    printText("adrianopteodoro,AriaHiro64,", 9, -1, disp);                  //9
    printText("moparisthebest,Skawo,", 9, -1, disp);                        //10
    printText("ottelo9", 9, -1, disp);                                      //11
    printText(" ", 9, -1, disp);                                            //12
    printText("Z: Next page", 9, -1, disp);                                 //13
                                                                            //16 max!
} //TODO: make scrolling text, should include libraries used.
