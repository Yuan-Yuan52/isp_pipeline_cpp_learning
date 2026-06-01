#include "raw_image.h"
#include <iostream>

using namespace std;

RawImage::RawImage(int w, int h, std::string pattern , int bl ) :Image (w,h,1){
    bayer_pattern = pattern;
    black_level = bl;
}

void RawImage::printRawInfo() {
    Image::printInfo();
    cout << "Bayer54 Pattern: " << bayer_pattern << endl;
    cout << "Black Level: " << black_level << endl;
}

void RawImage::printInfo() {
    Image::printInfo();
    cout << "Bayer32 Pattern: " << bayer_pattern << endl;
    cout << "Black Level: " << black_level << endl;
}