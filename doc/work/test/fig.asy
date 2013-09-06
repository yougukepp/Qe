settings.tex = "xelatex";
usepackage("xeCJK");
texpreamble("\setCJKmainfont{AR PL UKai CN}");

/*
size(200,200);
draw(unitcircle);
fill(unitcircle,yellow);
label("$O$",(0,0));
*/

/*
size(200);
pair A=(0,0), B=(1,0), C=(0,1);
draw (A--B--C);
dot(A);
dot(B,UnFill);
dot(C);
*/

/*
size(200);
pair A=(0,0),B=(1,0),C=(1,1),D=(0,1);
draw(A--B,solid);
draw(B--C,dashed);
draw(C--D,dashdotted);
draw(D--A,dotted);
*/

/*
size(200,0);
draw((0,3)--(2,3),Arrow);
draw((0,2)--(2,2),EndArrow);
draw((0,1)--(2,1),BeginArrow);
draw((0,0)--(2,0),Arrows);
draw((0,-1)--(2,-1),MidArrow);
*/

/*
size(200);
pair O=(0,0);
draw(O--E,Arrow);
draw(O--NE,Arrow);
draw(O--N,Arrow);
draw(O--NW,Arrow);
draw(O--W,Arrow);
draw(O--SW,Arrow);
draw(O--S,Arrow);
draw(O--SE,Arrow);
label("$E$",E,E);
label("$N$",N,N);
label("$W$",W,W);
label("$S$",S,S);
label("$NE$",position=NE,align=NE);
*/

/*
size(200);
pair O=(0,0);
draw(Label("$E$",EndPoint),O--E,Arrow);
draw(Label("$N$",EndPoint),O--N,Arrow);
draw(Label("$W$",EndPoint),O--W,Arrow);
draw(Label("$S$",EndPoint),O--S,Arrow);
draw(Label("$NE$",EndPoint),O--NE,Arrow);
draw(Label("$NW$",EndPoint),O--NW,Arrow);
draw(Label("$SE$",EndPoint),O--SE,Arrow);
draw(Label("$SW$",EndPoint),O--SW,Arrow);
draw(Label("$NNE$",EndPoint),O--NNE,Arrow);
draw(Label("$NNW$",EndPoint),O--NNW,Arrow);
draw(Label("$SSE$",EndPoint),O--SSE,Arrow);
draw(Label("$SSW$",EndPoint),O--SSW,Arrow);
draw(Label("$ENE$",EndPoint),O--ENE,Arrow);
draw(Label("$ESE$",EndPoint),O--ESE,Arrow);
draw(Label("$WNW$",EndPoint),O--WNW,Arrow);
draw(Label("$WSW$",EndPoint),O--WSW,Arrow);
draw(Label("西南西",position=EndPoint,red),O--WNW,Arrow);
*/

/*
size(200);
pair A, B, C;
A=(0,0); B=(4,0); C=(1,2);
pair D,E,F;
D=midpoint(A--B);
E=midpoint(B--C);
F=midpoint(C--A);
draw(A--B--C--cycle);
filldraw(D--E--F--cycle,red);
*/

/*
size(200);
filldraw((0,0)--(0,2cm)--(2cm,0)--cycle,fillpen=yellow,drawpen=red);
*/

/*
size(200);
pair A,B,C,D;
A=(0,0);B=(1,0);C=(1,1);D=(0,1);
real t=1/5;
pair X=interp(A,B,t);
pair Y=interp(B,C,t);
pair Z=interp(C,D,t);
pair W=interp(D,A,t);
draw(A--B--C--D--cycle);
draw(X--Y--Z--W--cycle,red);
arrow("$t=\frac{1}{5}$",X,SE);
*/

/*
size(200);
draw(E..N..W..S..cycle);
dot("$E$",E,E);
dot("$N$",N,N);
dot("$W$",W,W);
dot("$S$",S,S);
*/

/*
size(200);
draw((0,0)--(2.5,2.5),linewidth(1),Arrow);
filldraw((0,1)..(1,2)..(2,0)..(1,-2)..(0,-3)..(0,-3)..(-1,-2)..(-2,0)..(-1,2)..(0,1)..cycle,pink,red+linewidth(3));
draw((-3,-3)--(0,0),linewidth(1));
*/

/*
import graph;
size(200);
pair min=(-2,-2);
pair max=(2,2);
pair O=(0,0);
pair A=(2,0);
draw(box(min,max),red);
draw(circle(O,1),magenta);
draw(ellipse(O,2,1),green);
*/

/*
size(200);
draw(unitcircle);
filldraw(polygon(5),lightgreen);
*/

/*
size(200);
defaultpen(linewidth(4));
pair O=(0,0);
draw(arc(O,2cm,0,120),red);
draw(arc(O,2cm,120,180),green);
*/

/*
import geometry;
size(200);
pair O=(0,0);
pair P=(2,0);
pair Q=(2,2);
dot("$P$",P);
dot("$Q$",Q);
dot("$O$",O,W);
draw(P--O--Q);
draw(arc(P,O,Q,0.5),red,Arrow);
draw(arc(P,O,Q,1),green,Arrow);
draw(arc(Q,O,P,1.5),blue,Arrow);
draw(arc(Q,O,P,2),black,Arrow);
//arc(角起点, 角转点, 角终点, 距离角起点的距离)
*/

/*
import geometry;
size(200);
real a=3,b=4,c=5;
pair A=(0,0);
pair B=(a+b,0);
pair C=(a+b,a+b);
pair D=(0,a+b);
pair X=(a,0);
pair Y=(a+b,a);
pair Z=(b,a+b);
pair W1=(0,b);
draw(A--B--C--D--cycle);
perpendicular(A,NE);
draw(X--Y--Z--W1--cycle);
perpendicular(X, NE, X--Y);
perpendicular(X,NE,X--Y);
perpendicular(Y,NE,Y--Z);
perpendicular(Z,NE,Z--W1);
perpendicular(W1,NE,W1--X);
dot("$A$",A, SW);
dot("$B$",B, SE);
dot("$C$",C, NE);
dot("$D$",D, NW);
dot("$X$",X, S);
dot("$Y$",Y, E);
dot("$Z$",Z, N);
dot("$W$",W1, W);
*/

/*
import graph;
size(200);
real f(real x){return x^2;}
path p=graph(f,-2,2,operator..);
draw(p,red);
xaxis("$x$",Arrow);
yaxis("$y$",Arrow);
*/

import graph;
size(200,0);
real f1(real x){return x;}
real f2(real x){return x^2;}
real f3(real x){return x^3;}
guide f1=graph(f1,0,1.5,operator..);
guide f2=graph(f2,0,1.5,operator..);
guide f3=graph(f3,0,1.5,operator..);
draw(f1,green);
draw(f2,red);
draw(f3,blue);
label(Label("$y=x$",position=EndPoint,align=E),f1);
label(Label("$y=x^2$", EndPoint,E),f2);
label(Label("$y=x^3$", EndPoint,E),f3);
xaxis("$x$",Arrow);
yaxis("$y$",Arrow);


