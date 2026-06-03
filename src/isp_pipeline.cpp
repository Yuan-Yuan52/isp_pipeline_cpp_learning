#include "isp_pipeline.h"
#include <iostream>

using namespace std;
using namespace cv;

ISPPipeline::ISPPipeline() {
    // 初始化各個處理模組
    cout << "Initializing ISP Pipeline..." << endl;
}


Mat ISPPipeline::process(const std::string& raw_file) {
    cout << "Processing RAW file: " << raw_file << endl;

    // read Raw file 
    LibRaw raw;
    if (raw.open_file(raw_file.c_str()) != LIBRAW_SUCCESS) {
        cout << "Failed to open RAW file!" << endl;
        return Mat();
    }
    raw.unpack();

    //
    int width = raw.imgdata.sizes.width;
    int height = raw.imgdata.sizes.height;
    int raw_width = raw.imgdata.sizes.raw_width;
    int raw_height = raw.imgdata.sizes.raw_height;
    int bl = raw.imgdata.color.black;

    Mat bayer (height,width,CV_16UC1);
    for (int y=0 ; y < height ; y++){
        for (int x=0 ; x < width ; x++){
            bayer.at<uint16_t>(y,x) = raw.imgdata.rawdata.raw_image [y*raw_width + x];
        }
    }

    // 建立 Bayer Mat 之後加這行
    Mat bayer_small;
    resize(bayer, bayer_small, Size(), 0.1,0.1);

    //step 1 BLC

    Mat blc_level_result = black_level_.process(bayer_small , bl);

    //visualize 

    Mat before,after ;
    normalize(bayer_small,before, 0 , 255 ,NORM_MINMAX,CV_8UC1);
    normalize(blc_level_result , after , 0 , 255 ,NORM_MINMAX,CV_8UC1);

    imshow ("before BLC",before);
    imshow ("After BLC",after);
    
    waitKey(0);

    raw.recycle();

    return blc_level_result;
}
