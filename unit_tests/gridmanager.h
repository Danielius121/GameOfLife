#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H


class gridmanager
{
public:
    gridmanager();
    int** createGrid(int data[], int sizeX, int sizeY);
    bool compareGrid(int **grid, int **result, int XAxis, int YAxis);
private:
    int** grid;
};

#endif // GRIDMANAGER_H
