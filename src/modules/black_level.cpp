#include "modules/black_level.h"

using namespace cv ;
using namespace std ;

Blacklevel::Blacklevel() {}

Mat Blacklevel::process (const Mat& input , int black_level) {
    
    cout << "Black level correction with level : " << black_level << endl;

    //Translate to 32-bit 
    //input data type is CV_16UC1, 
    //we need to convert it to CV_32F

    Mat result ;
    input.convertTo(result , CV_32F) ;

    // Subtract black level
    result = result - black_level ;

    // Clip to valid range(截斷負數)
    cv::max(result , 0.0 , result) ; 
    //max() 是 OpenCV 中的函數，用於逐元素比較兩個矩陣，並返回較大的值。
    //在這裡，我們將 result 與 0 進行比較，確保所有負值都被截斷為 0。

    //但因為有衝突所以改用cv::max()，這樣就不會和 std::max() 發生衝突了。

    //Translate back to 16-bit 

    result.convertTo(result , CV_16UC1) ; 

    return result;
}




