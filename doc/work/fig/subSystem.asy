settings.tex = "xelatex";
usepackage("xeCJK");
texpreamble("\setCJKmainfont{AR PL UKai CN}");

real picSize = 100;
size(currentpicture, picSize, picSize);

pair A=(0, 0), B=(0, picSize), C=(picSize, picSize), D=(picSize, 0);
path outLine = A--B--C--D--cycle;

filldraw(outLine, white, black);
label("Qe引擎", D, NW, black);

pair center = (B.x + 20, B.y - 7.5);
draw("源解析", box, center);

pair center = (C.x - 8, C.y - 29);
draw(minipage("控制解析", 12), box, center);

pair center = (14.5, 14.5);
draw(minipage("输出控制", 25), box, center);

pair center = (picSize/2, picSize / 2);
draw(minipage("引擎核心", 25), box, center);

