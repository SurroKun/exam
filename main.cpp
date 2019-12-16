#include "l1.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    L1 w;
    w.show();

    return a.exec();
}
