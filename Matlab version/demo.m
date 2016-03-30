%% Matrix cell
% save
data = cell(2,1);
data{1} = int32(zeros(2,2));
data{2} = zeros(3,3);
saveCellMat('vec_mat.vecmat',data)
% load
load_data = loadCellMat('vec_mat.vecmat');
%% Matrix
% save
data = zeros(3,3);
saveMat('data.selfmat',data,'int32')
% load
load_data = loadMat('data.selfmat');