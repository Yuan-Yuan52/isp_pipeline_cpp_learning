#include <iostream>
#include <opencv2/opencv.hpp>
#include <libraw/libraw.h>

using namespace std;
using namespace cv;

int main() {
    LibRaw raw;

    const char* filename = "test.ARW";

    if (raw.open_file(filename) < 0) {
        std::cout << "Could not open the RAW file" << std::endl;
        return -1;
    }

    // 解壓縮 RAW 資料
    raw.unpack();

    // 取得 Bayer 資料
    int width = raw.imgdata.sizes.width;
    int height = raw.imgdata.sizes.height;
    int raw_width = raw.imgdata.sizes.raw_width;  // 加這行

    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Raw Width: " << raw_width << endl;

    // 建立灰階影像來視覺化 Bayer 資料
    Mat bayer(height, width, CV_16UC1);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            bayer.at<uint16_t>(y, x) = raw.imgdata.rawdata.raw_image[y * raw_width + x];
        }
    }

    // 轉成 8bit 顯示
    Mat bayer_8bit;
    bayer.convertTo(bayer_8bit, CV_8UC1, 1.0 / 256.0);

    imshow("Bayer Raw Data", bayer_8bit);
    imwrite("bayer_output.png", bayer_8bit);
    waitKey(0);

    raw.recycle();
    return 0;
}