settings.tex = "xelatex";
usepackage("xeCJK");
texpreamble("\setCJKmainfont{AR PL UKai CN}");

real scale = 10;
real picWidth = 13 * scale;
real picHeight = 16 * scale;
real engineSize = 10 * scale;
real engineYMargin = (picHeight - engineSize) / 2;
real halfChar = 6.8;
size(currentpicture, picWidth, picHeight);

pair A=(0, engineYMargin),
     B=(0, engineYMargin + engineSize),
     C=(engineSize, engineYMargin + engineSize),
     D=(engineSize, engineYMargin);

path outLine = A--B--C--D--cycle;
filldraw(outLine, white, black);
pair center = (0, picHeight / 2);
label(minipage("Qe引擎", 25), center, E, black);

pair center = ((B.x + C.x) / 2, B.y - halfChar);
object objSrcParse = draw("源解析", box, center, filltype=Draw);
real yOffset = 20;
pair center = (center.x, center.y + yOffset);
object objSrc = draw("源文件", box, center, filltype=Draw);

pair center = (center.x, A.y + halfChar);
object outCtrl = draw("输出控制", box, center);
real xOffset = 25;
real yOffset = 20;
pair center = (center.x - xOffset, center.y - yOffset);
object outFile = draw("输出文件", box, center);
pair center = (center.x + xOffset*2, center.y);
object objCrt = draw("显示器", box, center);

pair center = (C.x - halfChar, picHeight/2);
object ctrlParse = draw(minipage("控制解析", 12), box, center);
real xOffset = 20;
pair center = (center.x + xOffset, center.y);
object ctrlScript = draw(minipage("控制脚本", 12), box, center);

pair center = ((A.x + B.x + C.x + D.x ) / 4, (A.y + B.y + C.y + D.y ) / 4);
object engineCore = draw(minipage("引擎核心", 25), box, center);


draw(point(objSrc, S) -- point(objSrcParse, N), Arrow);
draw(point(objSrcParse, S) -- point(engineCore, N), Arrow);
draw(point(engineCore, S) -- point(outCtrl, N), Arrow);
draw(point(ctrlScript, W) -- point(ctrlParse, E), Arrow);
draw(point(ctrlParse, W) -- point(engineCore, E), Arrow);
draw(point(outCtrl, S) .. point(outFile, N), Arrow);
draw(point(outCtrl, S) .. point(objCrt, N), Arrow);

