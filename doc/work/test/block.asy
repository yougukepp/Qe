settings.tex = "xelatex";
usepackage("xeCJK");
texpreamble("\setCJKmainfont{AR PL UKai CN}");

/* 框图可以直接画 */

size(200);

pair A=(0, 0), B=(0, 100), C=(100, 100), D=(100, 0);
path outLine = A--B--C--D--cycle;

picture boxPic;
filldraw(boxPic, outLine, red, green);
add(boxPic);

label("hello", (50, 50), white);

struct hyBox{
    path mOutline;
    pen mFillColor;
    pen mDrawColor;
    string mString;
    pair mStrPos;
}

hyBox box;

pair A=(0, 0), B=(0, 50), C=(50, 50), D=(50, 0);
path outLine = A--B--C--D--cycle;
box.mOutline = outLine;
box.mFillColor = white;
box.mDrawColor = black;
box.mString = "box框图";
box.mStrPos = (0,0); // E N W N OR

void filldraw(picture pic=currentpicture, hyBox box)
{
    filldraw(pic, box.mOutline, box.mFillColor, box.mDrawColor); 

    // 需要计算 path的左下点
    label("hello", (20, 20), yellow);
}

filldraw(box);

