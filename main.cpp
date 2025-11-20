#include <QApplication>
#include "gamestartscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gamestartscene w;
    w.show();
    return a.exec();
}
