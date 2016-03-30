# Matlab-OpenCV-Matrices-file-IO
In order to exchange matrix data between matlab and openCV (c++) without any loss of precision, I write this code. I designed a file format which can restore  matrix array and matrix. Both matlab version and c++ version can read and write them. 

In the matlab version, the matrix is restored in a cell, different element of the cell means different matrix, and each of the elments can have different size and data type, such as int32, int64, float and double. In the openCV version, the matrix array is retored in vector<Mat>. The template vector<> belongs to the c++ Standard Library, and the Mat belongs to openCV. The available data type and size is same as matlab version. 

If you need additional reference of this code, please check in the file.  User Guide.doc
