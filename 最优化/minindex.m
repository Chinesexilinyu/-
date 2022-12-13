function class=minindex(class_num,face_train_projection,face_test_projection)

distance=zeros(length(face_train_projection),1);
for p=1:length(face_train_projection)
    distance(p)=normest(face_test_projection(:,class_num)-face_train_projection(:,p));
end
[num,index ]=min(distance);
class=ceil(index/5);
