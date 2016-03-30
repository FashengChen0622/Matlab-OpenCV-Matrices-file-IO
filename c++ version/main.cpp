#include"MatReadWrite.h"
#include <opencv2/photo.hpp>
#include <vector>
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;
int main(){

	vector<Mat> data;
	Mat matrix1 = Mat::zeros(2, 2, CV_8U);
	Mat matrix2 = Mat::zeros(3, 3, CV_64F);
	data.push_back(matrix1);
	data.push_back(matrix2);
	//save matrix array 
	MPRW_VecMat_write("data.vecmat",data);
	//load matrix array
	vector<Mat> load_data;
	MPRW_VecMat_read("data.vecmat", load_data);

	//save matrix
	MPRW_Mat_write("data.selfmat", matrix1);
	//load matrix
	Mat load_mat;
	MPRW_Mat_read("data.selfmat", load_mat);

}