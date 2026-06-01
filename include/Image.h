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
    virtual void printInfo();
    void setPixel(int x, int y, int channel, unsigned char value);
    unsigned char getPixel(int x, int y, int channel);
    void fill (unsigned char r , unsigned char g, unsigned char b);
    Image crop (int x , int y , int w , int h);

};

