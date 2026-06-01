#include <iostream>
#include "Image.h"
#include "raw_image.h"

int main() {
    // 建立一張 8x8 的圖片
    Image img(8, 8, 3);

    // 填滿紅色
    img.fill(255, 0, 0);
    std::cout << "Original image:" << std::endl;
    img.printInfo();
    std::cout << "Pixel (0,0) R: " << (int)img.getPixel(0, 0, 0) << std::endl;

    // 裁切左上角 4x4
    Image cropped = img.crop(0, 0, 4, 4);
    std::cout << "\nCropped image:" << std::endl;
    cropped.printInfo();
    std::cout << "Pixel (0,0) R: " << (int)cropped.getPixel(0, 0, 0) << std::endl;

    return 0;
}