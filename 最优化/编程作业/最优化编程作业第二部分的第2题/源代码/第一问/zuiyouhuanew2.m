cvx_begin sdp
variable t;
variable x(3,1);
A0=[1.5 0.5 1
0.5 0.8 0.3
1 0.3 0.8
];
A1=[1 2 3 
2 0 1
3 1 5
];
A2=[3 2 1
2 3 5
1 5 3
];
I=[1 0 0
0 1 0
0 0 1];
minimize t;
A0+x(1)*A1+x(2)*A2<=t*I;
cvx_end