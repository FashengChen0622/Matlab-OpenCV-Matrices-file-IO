function Answer = loadMat(FilePath)
fid = fopen(FilePath,'r');
fileType = fread(fid,1,'int32');
MatCount = fread(fid,1,'int32');
MatDataType = fread(fid,1,'int32');
rows = fread(fid,1,'int32');
cols = fread(fid,1,'int32');
%%
Answer = zeros(rows,cols);
switch MatDataType
    case 0 %CV_8U
        Answer = uint8(Answer);
        Answer(:) = reshape(fread(fid,rows*cols,'uint8'),cols,rows)';
    case 5 %CV_32F
        Answer = single(Answer);
        Answer(:) = reshape(fread(fid,rows*cols,'float32'),cols,rows)';
    case 6 %CV_64F
        Answer = double(Answer);
        Answer(:) = reshape(fread(fid,rows*cols,'float64'),cols,rows)';
    case 4 %CV_32S
        Answer = int32(Answer);
        Answer(:) = reshape(fread(fid,rows*cols,'int32'),cols,rows)';
end
fclose(fid);