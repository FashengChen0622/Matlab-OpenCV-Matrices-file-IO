#include "MatReadWrite.h"
#include <opencv2/photo.hpp>
#include <vector>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

void MPRW_VecMat_write(String path, vector<Mat>& MP){
	//Check matrix format ��������ʽ
	//----------------------------save data ��������----------------------------
	int MatCount = MP.size();
	ofstream fout(path, ofstream::binary);
	//save the head of file �����ļ�ͷ
	int FileType = 0;//���ļ�Ϊvector<Mat>�ļ�
	fout.write((char*)& FileType, sizeof(int));
	fout.write((char*)& MatCount, sizeof(int));
	//save data ��������
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
	//close the file stream �ر��ļ���
	fout.close();
	cout<<"�ѱ���vector����."<<endl;
}

void MPRW_Mat_write(String path, Mat& MP){
	//----------------------------save data ��������----------------------------
	int MatCount = 1;
	ofstream fout(path, ofstream::binary);
	//save the head of file �����ļ�ͷ
	int FileType = 1;//���ļ�ΪMat�ļ�
	fout.write((char*)& FileType, sizeof(int));
	fout.write((char*)& MatCount, sizeof(int));
	//save data ��������
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
	//close the file stream �ر��ļ���
	fout.close();
	cout<<"�ѱ������."<<endl;
}

void MPRW_VecMat_read(String path, vector<Mat>& MP){
	//check the existence of the file ��֤�ļ�
	ifstream fin(path, ifstream::binary);
	if (!fin){
		cout << "�ļ���ȡ����" << endl;
	}

	//read the information in the head of file ��ȡ�ļ�ͷ��Ϣ
	int FileType, MatCount;
	fin.read((char*)& FileType, sizeof(int));
	if (FileType != 0){
		cout << "ERROR.�ļ����Ͳ�Ϊvector<Mat>��ȴ��ͼ�������vector<Mat>��." << endl;
		return;
	}
	fin.read((char*)& MatCount, sizeof(int));
	//read data ��ȡ����
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
	//close file stream �ر��ļ���
	fin.close();
}

void MPRW_Mat_read(String path, Mat& MP){
	//check the existence of the file ��֤�ļ�
	ifstream fin(path, ifstream::binary);
	if (!fin){
		cout << "�ļ���ȡ����" << endl;
	}

	//read the information in the head of file ��ȡ�ļ�ͷ��Ϣ
	int FileType, MatCount;
	fin.read((char*)& FileType, sizeof(int));
	if (FileType != 1){
		cout << "ERROR.�ļ����Ͳ�ΪMat��ȴ��ͼ�������Mat��." << endl;
		return;
	}
	fin.read((char*)& MatCount, sizeof(int));
	if (MatCount != 1){
		cout << "ERROR.�ļ���." << endl;
	}
	//read data ��ȡ����
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
	//close file stream �ر��ļ���
	fin.close();
}
