syms x1 x2 r1 r2 ; % 定义u v 是未知量
eqns=[2*x1-14+r1+r2==0,2*x2-6+r1+2*r2==0,r1*(x1+x2-2)==0,r2*(x1+2*x2-3)==0]; % 定义方程组
vars=[x1,x2,r1,r2]; % 定义求解的未知量
[solX,solY,solZ,solM]=solve(eqns,vars); % 求解eqns中的vars未知量，分别存储
sol=solve(eqns,vars); % 求解eqns中的vars未知量，以结构体的形式存储到sol中
solX1=sol.x1 % 从sol结构体中取出变量u的解
solY1=sol.x2 % 从sol结构体中取出变量v的解
solZ1=sol.r1
solM1=sol.r2