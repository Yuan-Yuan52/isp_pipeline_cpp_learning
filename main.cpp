#include <iostream>
#include "Image.h"
#include "raw_image.h"

int main() {
    Image* img = new RawImage(1920, 1080, "RGGB", 64);
    img->printInfo();  // 會呼叫哪個版本？
    delete img;
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