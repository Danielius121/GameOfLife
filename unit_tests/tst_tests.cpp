#include <QtTest>
#include "../mythread.h"
#include "../mythread.cpp"
#include "gridmanager.h"



class tests : public QObject
{
    Q_OBJECT

public:
    tests();
    ~tests();

private slots:
    void FourLiveNeighbours();
    void LessThanTwoLiveNeighbours();
    void TwoLiveNeighbours();
    void ThreeLiveNeighbours();
    void DeadCellWithThreeLiveNeighbours();
private:
    mythread *mthread;
    bool check;
    int** grid;
    int** result;
    const int XAxis = 3;
    const  int YAxis = 3;

    gridmanager manager;
};

tests::tests()
{

}

tests::~tests()
{

}
void tests::DeadCellWithThreeLiveNeighbours()
{
       int entry[9] = {1,1,0,
                       1,0,0,
                       0,0,0};

       int expected[9] = {1,1,0,
                          1,1,0,
                          0,0,0};

       grid = manager.createGrid(entry,XAxis,YAxis);
       result = manager.createGrid(expected,XAxis,YAxis);
       mthread = new mythread(grid,XAxis,YAxis);
       mthread->run();
       check = manager.compareGrid(grid, result, XAxis, YAxis);

       QVERIFY(check);
}
void tests::FourLiveNeighbours()
{
    int entry[9] = {1,1,1,
                    1,1,0,
                    0,0,0};

    int expected[9] = {1,0,1,
                       1,0,1,
                       0,0,0};
    grid = manager.createGrid(entry,XAxis,YAxis);
    result = manager.createGrid(expected,XAxis,YAxis);
    mthread = new mythread(grid,XAxis,YAxis);
    mthread->run();
    check = manager.compareGrid(grid, result, XAxis, YAxis);

    QVERIFY(check);
}
void tests::ThreeLiveNeighbours()
{
    int entry[9] = {1,1,1,
                    0,1,0,
                    0,0,0};

    int expected[9] = {1,1,1,
                       1,1,1,
                       0,0,0};
    grid = manager.createGrid(entry,XAxis,YAxis);
    result = manager.createGrid(expected,XAxis,YAxis);
    mthread = new mythread(grid,XAxis,YAxis);
    mthread->run();
    check = manager.compareGrid(grid, result, XAxis, YAxis);

    QVERIFY(check);
}
void tests::TwoLiveNeighbours()
{
    int entry[9] = {1,0,0,
                    1,0,0,
                    1,0,0};

    int expected[9] = {0,0,0,
                       1,1,0,
                       0,0,0};
    grid = manager.createGrid(entry,XAxis,YAxis);
    result = manager.createGrid(expected,XAxis,YAxis);
    mthread = new mythread(grid,XAxis,YAxis);
    mthread->run();
    check = manager.compareGrid(grid, result, XAxis, YAxis);

    QVERIFY(check);
}
void tests::LessThanTwoLiveNeighbours()
{
    int entry[9] = {1,0,1,
                    0,0,0,
                    0,0,0};

    int expected[9] = {0,0,0,
                       0,0,0,
                       0,0,0};

    grid = manager.createGrid(entry,XAxis,YAxis);
    result = manager.createGrid(expected,XAxis,YAxis);
    mthread = new mythread(grid,XAxis,YAxis);
    mthread->run();
    check = manager.compareGrid(grid, result, XAxis, YAxis);

    QVERIFY(check);
}


QTEST_APPLESS_MAIN(tests)

#include "tst_tests.moc"
