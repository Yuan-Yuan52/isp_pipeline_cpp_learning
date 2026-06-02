#include <iostream>
#include <opencv2/opencv.hpp>
#include "isp_pipeline.h"

using namespace std;
using namespace cv;

int main() {
    ISPPipeline pipeline;
    pipeline.process("test.ARW");
    return 0;
}