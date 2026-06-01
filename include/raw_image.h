#pragma once
#include "image.h"
#include <string>

class RawImage : public Image {
public:
    std::string bayer_pattern;  // "RGGB", "BGGR" 等
    int black_level;            // 黑電位值

    RawImage(int w, int h, std::string pattern, int bl);
    void printRawInfo();
};