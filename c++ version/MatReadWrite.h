#include <opencv2/photo.hpp>
#include <vector>
#include <iostream>
#include <fstream>

#ifndef _MAT_READ_WRITE
#define _MAT_READ_WRITE

using namespace cv;
using namespace std;

void MPRW_VecMat_write(String path, vector<Mat>& MP);//该函数保存Vector<Mat> MP
void MPRW_Mat_write(String path, Mat& MP);//该函数保存Mat MP
void MPRW_VecMat_read(String path, vector<Mat>& MP);////该函数读取Vector<Mat> 到MP
void MPRW_Mat_read(String path, Mat& MP);////该函数读取Mat 到MP
#endif // !_MAT_READ_WRITE
