#include <iostream>
#include "Image.h"

int main() {
    Image img(1920, 1080, 3);
    img.printInfo();

    img.setPixel(0, 0, 0, 255);   //R=255
    img.setPixel(0, 0, 1, 128);   //G=128
    img.setPixel(0, 0, 2, 0);    //B=0

    //std::cout << "Pixel (0,0) R: " << (int)img.getPixel(0, 0, 0) << std::endl;
    //std::cout << "Pixel (0,0) G: " << (int)img.getPixel(0, 0, 1) << std::endl;
    //std::cout << "Pixel (0,0) B: " << (int)img.getPixel(0, 0, 2) << std::endl;

    Image img2(4,4,3);
    unsigned char * ptr = img2.data.data();

    for (int y = 0; y < img2.height; y++) {
        for (int x = 0; x < img2.width; x++) {
            ptr[(y * img2.width + x) * img2.channels + 0] = 21;  // R}
            std::cout << "(" << x << "," << y << ") R: " << (int)img2.getPixel(x, y, 0) << std::endl;   
        }
    }
    return 0;
}