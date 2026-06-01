#include <iostream>
#include "Image.h"
#include "raw_image.h"

int main() {
    RawImage raw_img(1920, 1080, "RGGB", 1024);
    raw_img.printRawInfo();

    raw_img.setPixel(0, 0, 0, 255);   //R=255
    raw_img.setPixel(0, 0, 1, 128);   //G=128
    raw_img.setPixel(0, 0, 2, 0);    //B=0

    std::cout << "Pixel (0,0) R: " << (int)raw_img.getPixel(0, 0, 0) << std::endl;
    //std::cout << "Pixel (0,0) G: " << (int)img.getPixel(0, 0, 1) << std::endl;
    //std::cout << "Pixel (0,0) B: " << (int)img.getPixel(0, 0, 2) << std::endl;

    Image img2(2,3,3);
    unsigned char * ptr = img2.data.data();

    for (int y = 0; y < img2.height; y++) {
        for (int x = 0; x < img2.width; x++) {
            ptr[(y * img2.width + x) * img2.channels + 0] = 255;  // R}
            std::cout << "(" << x << "," << y << ") R: " << (int)img2.getPixel(x, y, 0) << std::endl;   
        }
    }
    return 0;
}