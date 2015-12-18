#ifndef SELECTIONSORTTEST_H
#define SELECTIONSORTTEST_H

#include <QObject>

class SelectionSortTest : public QObject
{
    Q_OBJECT

public:
    SelectionSortTest();
    ~SelectionSortTest();

    void sort(std::vector<int>& data);

private slots:
    void sort_test();
    void sort_test_data();
    
};

#endif // SELECTIONSORTTEST_H
