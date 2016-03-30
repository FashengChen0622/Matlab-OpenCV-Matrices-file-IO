# Matlab-OpenCV-Matrices-file-IO
In order to exchange matrix data between matlab and openCV (c++) without any loss of precision(for example, you trained a neural networks in matlab , and want to implement it in c++, you need to exchange the matrices data), I write this code. I designed a file format which can restore  matrix array and matrix. Both matlab version and c++ version can read and write them. 

In the matlab version, the matrix is restored in a cell, different element of the cell means different matrix, and each of the elments can have different size and data type, such as uint8, int32, float and double. In the openCV version, the matrix array is retored in vector<Mat>. The template vector<> belongs to the c++ Standard Library, and the Mat belongs to openCV. The available data type and size is same as matlab version. 

If you need additional reference of this code, please check in the file.  User Guide.doc
