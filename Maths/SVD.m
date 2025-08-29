load Yale_32x32.mat;
size(fea);
imshow(uint8(reshape(fea(1,:),[32 32])))
size(fea);
FACE=fea’;
size(FACE);
[U,S,Vt]=svd(FACE);
size(U);
size(Vt);
diag(S);
PR=U(:,1:35)*FACE(:,1);
size(PR);
REC=U(:,1:35)*PR;
size(REC);
imshow(uint8(reshape(REC,[32 32])))
imshow(uint8(reshape(fea(1,:),[32 32])))
PR=U(:,1:120)*FACE(:,1);
size(PR);
REC=U(:,1:120)*PR;
imshow(uint8(reshape(REC,[32 32])))
imshow(uint8(reshape(fea(1,:),[32 32])))
PR=U’*FACE(:,1);
size(PR);
