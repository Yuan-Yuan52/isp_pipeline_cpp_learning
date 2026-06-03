#include "isp_pipeline.h"
#include <iostream>

using namespace std;
using namespace cv;

ISPPipeline::ISPPipeline() {

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

    float r_gain = raw.imgdata.color.cam_mul[0];
    float g_gain = raw.imgdata.color.cam_mul[1];
    float b_gain = raw.imgdata.color.cam_mul[2];

    Mat bayer (height,width,CV_16UC1);
    for (int y=0 ; y < height ; y++){
        for (int x=0 ; x < width ; x++){
            bayer.at<uint16_t>(y,x) = raw.imgdata.rawdata.raw_image [y*raw_width + x];
        }
    }

    //bayer

    Mat bayer_small;
    resize(bayer, bayer_small, Size(), 0.1,0.1);

    //step 1 BLC

    Mat blc_level_result = black_level_.process(bayer_small , bl);

    //step 2 white_bal

    r_gain /= g_gain ; 
    b_gain /= g_gain ;
    g_gain /= 1.0f ;

    Mat White_bal_result = white_balance_.process(bayer_small , r_gain , g_gain , b_gain);


        //visualize 

    Mat before_8bit, after_8bit;
    blc_level_result.convertTo(before_8bit, CV_8UC1, 1.0/64.0);
    White_bal_result.convertTo(after_8bit, CV_8UC1, 1.0/64.0);

    imshow("After BLC", before_8bit);
    imshow("After WB", after_8bit);
        
    waitKey(0);

    raw.recycle();

    return blc_level_result;
}
