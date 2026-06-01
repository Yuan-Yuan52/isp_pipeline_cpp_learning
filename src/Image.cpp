#include "Image.h"
#include <iostream>

Image::Image(int w, int h, int c) {
    width = w;
    height = h;
    channels = c;
    data.resize(w*h*c,0);
}

Image::~Image() {
    std::cout << "Image (" << width << "x" << height << ") destroyed" << std::endl;
}


void Image::printInfo() {
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Channels: " << channels << std::endl;
    std::cout << "Total Size " << data.size() << " bytes" << std::endl;
}

void Image::setPixel(int x, int y, int ch, unsigned char value) { 
    data [ (y * width + x) * channels + ch ]= value;
}
//unsigned char 1byte & int 4byte處理影像資料時，使用unsigned char可以節省記憶體空間，因為每個像素的顏色值通常在0-255之間，而unsigned char正好能表示這個範圍。
//相反地，如果使用int來存儲像素值，將會浪費大量的記憶體空間，因為int需要4 bytes來存儲一個值，而unsigned char只需要1 byte。

unsigned char Image::getPixel(int x, int y, int ch) {
    return data [ (y * width + x) * channels + ch ];
}