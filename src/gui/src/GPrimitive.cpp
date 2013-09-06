#include "GPrimitive.h"

void GPrimitive::AddVertex(GVertex& vertex)
{
    vertexs.push_back(vertex);
}

void GPrimitive::draw(void)
{
    if(indexes.empty())
    {
        int size = (GPosition::GetSize() + GColor::GetSize()) / 4;
        int num = vertexs.size() * size;
        float *vertexArrayBuf = new float[num];

        int i = 0;
        int j = 0;
        static int k = 0;

        for(i=0;i<vertexs.size();i++)
        {
            cerr << i << ":\t";
            vertexArrayBuf[j++] = vertexs[i].GetX();
            cerr << vertexs[i].GetX() << "\t";
            vertexArrayBuf[j++] = vertexs[i].GetY();
            cerr << vertexs[i].GetY() << "\t";
            vertexArrayBuf[j++] = vertexs[i].GetZ();
            cerr << vertexs[i].GetZ() << "\t";
            vertexArrayBuf[j++] = vertexs[i].GetW();
            cerr << vertexs[i].GetW() << "\t";
            vertexArrayBuf[j++] = vertexs[i].GetR();
            cerr << vertexs[i].GetR() << "\t";
            vertexArrayBuf[j++] = vertexs[i].GetG();
            cerr << vertexs[i].GetG() << "\t";
            vertexArrayBuf[j++] = vertexs[i].GetB();
            cerr << vertexs[i].GetB() << "\t";
            vertexArrayBuf[j++] = vertexs[i].GetA();
            cerr << vertexs[i].GetA() << "\n";
           
            assert(j == size * (i+1));
        }

        for(j=0;j<vertexs.size();j++) 
        {
            for(i=0;i<size;i++)
            {
                cerr << vertexArrayBuf[j*size + i] << "\t";
            }
            cerr << "\n";
        }


        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, size, vertexArrayBuf + 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, size, vertexArrayBuf + 4);
        glEnableVertexAttribArray(1); 
        
        glDrawArrays(GL_LINES, 0, 2);


        /*
        glClearColor( 1.0f, 0.0f, 0.0f, 0.0f );
        glEnable(GL_DEPTH_TEST);
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        */

        glFinish(); 
        //while(1);

        delete []vertexArrayBuf;
    }
    else
    {
        cerr << "Not Implentment.\n";
    }
}


