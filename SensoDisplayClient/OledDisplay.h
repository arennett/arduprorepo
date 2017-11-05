 /*
 * OledDisplay.h
 *
 * encapsulate all display issues
 *  128x64 size display using I2C to communicate
 */


#ifndef OLEDDISPLAY_H
#define OLEDDISPLAY_H


#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>



#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define OLED_RESET 4
#define OLED_INACTIVE false


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16


class OledDisplay {

public:

    // constructor
    OledDisplay();

    //init must be called in setup
    void init();
    void clear();

    // this function must be called inside loop()
    void demo();


    void testdrawchar(void) ;
    void testdrawcircle(void) ;
    void testfillrect(void) ;
    void testdrawtriangle(void) ;
    void testfilltriangle(void) ;
    void testdrawroundrect(void) ;
    void testfillroundrect(void) ;
    void testdrawrect(void) ;
    void testdrawline() ;
    void testscrolltext(void) ;


private:


protected:


};

#endif
