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

    return Mat();
}
