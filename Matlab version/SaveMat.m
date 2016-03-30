function SaveMat(FilePath,Mat,SaveType)
if strcmpi(SaveType,'uint8')
    MatDataType = 0;% CV_64F  double
end
if strcmpi(SaveType,'int32')
    MatDataType = 4;% CV_64F  double
end
if strcmpi(SaveType,'float32')
    MatDataType = 5;% CV_64F  double
end
if strcmpi(SaveType,'float64')
    MatDataType = 6;% CV_64F  double
end
fid = fopen(FilePath,'wb');
MatCount = 1;
fileType = 1;
fwrite(fid,fileType,'int32');
fwrite(fid,MatCount,'int32');
fwrite(fid,MatDataType,'int32');
[rows,cols] = size(Mat);
fwrite(fid,rows,'int32');
fwrite(fid,cols,'int32');
%%
switch MatDataType
    case 0
        fwrite(fid,uint8(Mat)','uint8');
    case 4
        fwrite(fid,int32(Mat)','int32');
    case 5
        fwrite(fid,single(Mat)','float32');
    case 6
        fwrite(fid,double(Mat)','float64');
end
fclose(fid);