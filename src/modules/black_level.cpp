#include "modules/black_level.h"

using namespace cv ;

Blacklevel::Blacklevel() {

}

Mat Blacklevel::process (const Mat& input , int black_level) {

    return input.clone();
}




