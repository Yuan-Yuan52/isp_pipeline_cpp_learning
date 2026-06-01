#pragma once
#include <vector>


class Image{
public:
    int width;
    int height;
    int channels;
    std::vector<unsigned char > data;

    Image(int w, int h ,int c);
    ~Image() ;
    void printInfo();
    void setPixel(int x, int y, int channel, unsigned char value);
    unsigned char getPixel(int x, int y, int channel);
};

