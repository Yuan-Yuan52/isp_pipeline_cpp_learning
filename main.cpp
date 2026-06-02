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

        // 印出基本資訊
    cout << "Camera: " << raw.imgdata.idata.make << " " 
        << raw.imgdata.idata.model << endl;
    cout << "Width: " << raw.imgdata.sizes.width << endl;
    cout << "Height: " << raw.imgdata.sizes.height << endl;
    cout << "Colors: " << raw.imgdata.idata.colors << endl;

    waitKey(0); 

    return 0;

}