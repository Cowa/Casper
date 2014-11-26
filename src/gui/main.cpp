#include <QApplication>
#include <QSplashScreen>

#include "../../include/gui/mainWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //imgae de commencement
    QSplashScreen *splash = new QSplashScreen();
    splash->setPixmap(QPixmap("imgs/001.png"));
    splash->show();

    //如果后面加了就不显示字了，为了毛线球啊……
    //il n'affiche pas quand il y a autres chose suivre(il affiche au meme temps)
    Qt::Alignment placeMsg = Qt::AlignRight|Qt::AlignTop;
    splash->showMessage(QObject::tr("please wait......"), placeMsg, Qt::darkGray);
    //sleep(1);//quand il ne reste pas longtemps on peut le mettre.

    MainWindow mainWin;
    mainWin.show();
    splash->finish(&mainWin);
    delete splash;
/*
    QMainWindow *main = new QMainWindow;
    GridWidget gridWidget;
    main->setCentralWidget(&gridWidget);
    main->show();
*/

    return app.exec();
}
