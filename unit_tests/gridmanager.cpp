#include "gridmanager.h"

gridmanager::gridmanager()
{

}

int** gridmanager::createGrid(int data[], int sizeX, int sizeY)
{       int x=0;
        grid = new int*[sizeX];
        for(int i =0; i<sizeX; i++)
        {   grid[i]=new int[sizeY];

            for(int j=0; j<sizeY; j++)
            {  grid[i][j] = data[x];
                x+=1;
            }
        }
            return grid;
}

bool gridmanager::compareGrid(int **grid, int **result, int XAxis, int YAxis)
{   bool check = true;
    for(int i=0; i<XAxis; i++)
       {
           for(int j=0; j<YAxis; j++)
           {
               if(grid[i][j] != result [i][j]) check = false;

           }
       }
    return check;
}
