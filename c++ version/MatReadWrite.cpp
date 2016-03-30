#include "MatReadWrite.h"
#include <opencv2/photo.hpp>
#include <vector>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

void MPRW_VecMat_write(String path, vector<Mat>& MP){
	//Check matrix format 检验矩阵格式
	//----------------------------save data 保存数据----------------------------
	int MatCount = MP.size();
	ofstream fout(path, ofstream::binary);
	//save the head of file 保存文件头
	int FileType = 0;//该文件为vector<Mat>文件
	fout.write((char*)& FileType, sizeof(int));
	fout.write((char*)& MatCount, sizeof(int));
	//save data 保存数据
	for (int num = 0; num < MatCount; num++){
		int MatDataType = MP[num].type();
		int rows = MP[num].rows;
		int cols = MP[num].cols;
		fout.write((char*)& MatDataType, sizeof(int));
		fout.write((char*)& rows, sizeof(int));
		fout.write((char*)& cols, sizeof(int));
		if (MatDataType == CV_8U){
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					fout.write((char*)& MP[num].at<uchar>(i, j), sizeof(uchar));
			continue;
		}
		if (MatDataType == CV_32F){
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					fout.write((char*)& MP[num].at<float>(i, j), sizeof(float));
			continue;
		}
		if (MatDataType == CV_64F){
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					fout.write((char*)& MP[num].at<double>(i, j), sizeof(double));
			continue;
		}
		if (MatDataType == CV_32S){
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					fout.write((char*)& MP[num].at<int>(i, j), sizeof(int));
			continue;
		}
	}
	//close the file stream 关闭文件流
	fout.close();
	cout<<"已保存vector矩阵."<<endl;
}

void MPRW_Mat_write(String path, Mat& MP){
	//----------------------------save data 保存数据----------------------------
	int MatCount = 1;
	ofstream fout(path, ofstream::binary);
	//save the head of file 保存文件头
	int FileType = 1;//该文件为Mat文件
	fout.write((char*)& FileType, sizeof(int));
	fout.write((char*)& MatCount, sizeof(int));
	//save data 保存数据
	int MatDataType = MP.type();
	int rows = MP.rows;
	int cols = MP.cols;
	fout.write((char*)& MatDataType, sizeof(int));
	fout.write((char*)& rows, sizeof(int));
	fout.write((char*)& cols, sizeof(int));
	if (MatDataType == CV_8U)
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				fout.write((char*)& MP.at<uchar>(i, j), sizeof(uchar));
	if (MatDataType == CV_32F)
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				fout.write((char*)& MP.at<float>(i, j), sizeof(float));
	if (MatDataType == CV_64F)
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				fout.write((char*)& MP.at<double>(i, j), sizeof(double));
	if (MatDataType == CV_32S)
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				fout.write((char*)& MP.at<int>(i, j), sizeof(int));
	//close the file stream 关闭文件流
	fout.close();
	cout<<"已保存矩阵."<<endl;
}

void MPRW_VecMat_read(String path, vector<Mat>& MP){
	//check the existence of the file 验证文件
	ifstream fin(path, ifstream::binary);
	if (!fin){
		cout << "文件读取错误" << endl;
	}

	//read the information in the head of file 读取文件头信息
	int FileType, MatCount;
	fin.read((char*)& FileType, sizeof(int));
	if (FileType != 0){
		cout << "ERROR.文件类型不为vector<Mat>，却试图将其存入vector<Mat>中." << endl;
		return;
	}
	fin.read((char*)& MatCount, sizeof(int));
	//read data 读取数据
	for (int num = 0; num < MatCount; num++){
		int MatDataType, rows, cols;
		fin.read((char*)& MatDataType, sizeof(int));
		fin.read((char*)& rows, sizeof(int));
		fin.read((char*)& cols, sizeof(int));
		if (MatDataType == CV_8U){
			Mat Temp = Mat::zeros(rows, cols, CV_8U);
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					fin.read((char*)& Temp.at<char>(i, j), sizeof(char));
			MP.push_back(Temp);
			continue;
		}
		if (MatDataType == CV_32F){
			Mat Temp = Mat::zeros(rows, cols, CV_32F);
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					fin.read((char*)& Temp.at<float>(i, j), sizeof(float));
			MP.push_back(Temp);
			continue;
		}
		if (MatDataType == CV_64F){
			Mat Temp = Mat::zeros(rows, cols, CV_64F);
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					fin.read((char*)& Temp.at<double>(i, j), sizeof(double));
			MP.push_back(Temp);
			continue;
		}
		if (MatDataType == CV_32S){
			Mat Temp = Mat::zeros(rows, cols, CV_32S);
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					fin.read((char*)& Temp.at<int>(i, j), sizeof(int));
			MP.push_back(Temp);
			continue;
		}
	}
	//close file stream 关闭文件流
	fin.close();
}

void MPRW_Mat_read(String path, Mat& MP){
	//check the existence of the file 验证文件
	ifstream fin(path, ifstream::binary);
	if (!fin){
		cout << "文件读取错误" << endl;
	}

	//read the information in the head of file 读取文件头信息
	int FileType, MatCount;
	fin.read((char*)& FileType, sizeof(int));
	if (FileType != 1){
		cout << "ERROR.文件类型不为Mat，却试图将其读入Mat中." << endl;
		return;
	}
	fin.read((char*)& MatCount, sizeof(int));
	if (MatCount != 1){
		cout << "ERROR.文件损坏." << endl;
	}
	//read data 读取数据
	int MatDataType, rows, cols;
	fin.read((char*)& MatDataType, sizeof(int));
	fin.read((char*)& rows, sizeof(int));
	fin.read((char*)& cols, sizeof(int));
	if (MatDataType == CV_8U){
		Mat Temp = Mat::zeros(rows, cols, CV_8U);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				fin.read((char*)& Temp.at<char>(i, j), sizeof(char));
		MP = Temp;
	}
	if (MatDataType == CV_32F){
		Mat Temp = Mat::zeros(rows, cols, CV_32F);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				fin.read((char*)& Temp.at<float>(i, j), sizeof(float));
		MP = Temp;
	}
	if (MatDataType == CV_64F){
		Mat Temp = Mat::zeros(rows, cols, CV_64F);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				fin.read((char*)& Temp.at<double>(i, j), sizeof(double));
		MP = Temp;
	}
	if (MatDataType == CV_32S){
		Mat Temp = Mat::zeros(rows, cols, CV_32S);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				fin.read((char*)& Temp.at<int>(i, j), sizeof(int));
		MP = Temp;
	}
	//close file stream 关闭文件流
	fin.close();
}
