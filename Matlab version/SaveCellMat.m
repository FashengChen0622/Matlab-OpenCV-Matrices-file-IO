function SaveCellMat(FilePath,CellMat)
fid = fopen(FilePath,'wb');
MatCount = size(CellMat,1);
fileType = 0;
fwrite(fid,fileType,'int');
fwrite(fid,MatCount,'int');
for k=1:MatCount
    Temp = CellMat{k};
    MatDataType = 6;% CV_64F  double
    fwrite(fid,MatDataType,'int');
    [rows,cols] = size(Temp);
    fwrite(fid,rows,'int');
    fwrite(fid,cols,'int');
    fwrite(fid,double(Temp)','double');
end
fclose(fid);