function Answer = loadCellMat(FilePath)
fid = fopen(FilePath,'r');
fileType = fread(fid,1,'int32');
MatCount = fread(fid,1,'int32');
Answer = cell(MatCount,1);
for k=1:MatCount
    MatDataType = fread(fid,1,'int32');
    rows = fread(fid,1,'int32');
    cols = fread(fid,1,'int32');
    switch MatDataType
        case 0
            Temp = uint8(zeros(rows,cols));
            Temp(:) = reshape(fread(fid,rows*cols,'uint8'),cols,rows)';
            Answer{k} = Temp;
        case 4
            Temp = int32(zeros(rows,cols));
            Temp(:) = reshape(fread(fid,rows*cols,'int32'),cols,rows)';
            Answer{k} = Temp;
        case 5
            Temp = single(zeros(rows,cols));
            Temp(:) = reshape(fread(fid,rows*cols,'float32'),cols,rows)';
            Answer{k} = Temp;
        case 6
            Temp = double(zeros(rows,cols));
            Temp(:) = reshape(fread(fid,rows*cols,'float64'),cols,rows)';
            Answer{k} = Temp;
    end
end
fclose(fid);