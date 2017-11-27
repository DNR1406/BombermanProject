#include "BMPLoader.h"
#include <BMPheader.h>
#include "include.h"
#include <SD.h>

BMPLoader::BMPLoader() {

}

uint8_t BMPLoader::OpenBMPFile(char *file, int16_t x, int16_t y)
{
    File myFile;
    uint8_t buf[40]; //read buf (min. size = sizeof(BMP_DIPHeader))
    BMP_Header *bmp_hd;
    BMP_DIPHeader *bmp_dip;
    int16_t width, height, w, h;
    uint8_t pad;

    //open file
    myFile = SD.open(file);
    if (myFile)
    {
        //BMP Header
        myFile.read(&buf, sizeof(BMP_Header));
        bmp_hd = (BMP_Header *)&buf[0];
        if ((bmp_hd->magic[0] == 'B') && (bmp_hd->magic[1] == 'M') && (bmp_hd->offset == 54))
        {
            //BMP DIP-Header
            myFile.read(&buf, sizeof(BMP_DIPHeader));
            bmp_dip = (BMP_DIPHeader *)&buf[0];
            if ((bmp_dip->size == sizeof(BMP_DIPHeader)) && (bmp_dip->bitspp == 24) && (bmp_dip->compress == 0))
            {
                //BMP Data (1. pixel = bottom left)
                width = bmp_dip->width;
                height = bmp_dip->height;
                pad = width % 4; //padding (line is multiply of 4)
                if ((x + width) <= lcd.getWidth() && (y + height) <= lcd.getHeight())
                {
                    lcd.setArea(x, y, x + width - 1, y + height - 1);
                    for (h = (y + height - 1); h >= y; h--) //for every line
                    {
                        for (w = x; w < (x + width); w++) //for every pixel in line
                        {
                            myFile.read(&buf, 3);
                            lcd.drawPixel(w, h, RGB(buf[2], buf[1], buf[0]));
                        }
                        if (pad)
                        {
                            myFile.read(&buf, pad);
                        }
                    }
                }
                else
                {
                    lcd.drawText(x, y, "Pic out of screen!", RGB(0, 0, 0), RGB(255, 255, 255), 1);
                }
            }
        }

        myFile.close();
    }
}

void BMPLoader::readFromSDCard(char *file)
{
    //init SD-Card and calibrate touchscreen
    if (SD.begin(4))
    {
        OpenBMPFile(file, 0, 0);
    }
    else
    {
        lcd.drawText(5, 5, "Mislukt", RGB(0, 0, 0), RGB(255, 255, 255), 1);
    }
}
