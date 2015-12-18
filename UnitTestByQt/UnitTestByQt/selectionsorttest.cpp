#include "selectionsorttest.h"
#include <vector>
#include <QTest>

using std::vector;

SelectionSortTest::SelectionSortTest()
    : QObject()
{

}

SelectionSortTest::~SelectionSortTest()
{

}

void SelectionSortTest::sort(std::vector<int>& data)
{
    std::sort(data.begin(), data.end());
}

void SelectionSortTest::sort_test()
{
    QFETCH(vector<int>, inputVector);
    QFETCH(vector<int>, result);

    sort(inputVector);
    QCOMPARE(inputVector, result);
}

void SelectionSortTest::sort_test_data()
{
    QTest::addColumn<vector<int>>("inputVector");
    QTest::addColumn<vector<int>>("result");

    QTest::newRow("set 1")
        << vector<int>({ 5, 8, 9, 2, 0 })
        << vector<int>({ 0, 2, 5, 8, 9 });

    QTest::newRow("set 2")
        << std::vector<int>({ 0, 1, 0, 1, 0 })
        << std::vector<int>({ 0, 0, 0, 1, 1 });

    QTest::newRow("set 3")
        << std::vector<int>({ 9, 8, 7, 6, 5 })
        << std::vector<int>({ 5, 6, 7, 8, 9 });
}

//QTEST_APPLESS_MAIN(SelectionSortTest);
QTEST_MAIN(SelectionSortTest);