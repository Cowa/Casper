#include "mainWindow.hpp"
#include <sstream>

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    
    //和数据链接 les valeur, il faut avec plugin
    maxTour=100;//0-99
    gridWide=15;//1-5
    gridHeight=15;//1-5
    
    //les images vont changer apres
    imageEmpty = new QImage("/Users/evawawa/Documents/m1/interface-vers1/Casper/imgs/empty.png");
    imageUse = new QImage("/Users/evawawa/Documents/m1/interface-vers1/Casper/imgs/use.png");
    
    //各种控件 creation sur les button, label, image....
    createGrid();
    createActions();
    createMenus();
    
    changeToUse(3,4);//从0开始计算 test
    
    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0,maxTour+1);
    tourSpinBox = new QSpinBox();
    slider->setRange(0,maxTour+1);
    
    previousButton = new QPushButton(tr("previous"));
    nextButton = new QPushButton(tr("next"));
    playButton = new QPushButton(tr("play"));
    pauseButton = new QPushButton(tr("pause"));
    tourLabel = new QLabel(tr("tour: "));


    //底层界面 layout en bas
    bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(previousButton);
    bottomLayout->addWidget(nextButton);
    bottomLayout->addWidget(playButton);
    bottomLayout->addWidget(pauseButton);
    bottomLayout->addStretch();
    bottomLayout->addWidget(tourLabel);
    bottomLayout->addWidget(tourSpinBox);
    bottomLayout->addStretch();
    
    //基础界面 layout global
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gridLayout);
    mainLayout->addWidget(slider);
    mainLayout->addLayout(bottomLayout);
    
    //显示 afficher
    widget->setLayout(mainLayout);
    setCentralWidget(widget);
    setWindowTitle(tr("title"));
    setMinimumSize(800,600);
    
    //signal
    QObject::connect(slider, SIGNAL(valueChanged(int)), tourSpinBox, SLOT(setValue(int)));
    QObject::connect(tourSpinBox, SIGNAL(valueChanged(int)),slider, SLOT(setValue(int)));
    QObject::connect(previousButton, SIGNAL(clicked()), this, SLOT(previousClicked()));
    QObject::connect(nextButton, SIGNAL(clicked()), this, SLOT(nextClicked()));
    QObject::connect(playButton, SIGNAL(clicked()), this, SLOT(playClicked()));
    QObject::connect(pauseButton, SIGNAL(clicked()), this, SLOT(pauseClicked()));
}

MainWindow::~MainWindow()
{}

//il y a la possibilite les cle ne marche pas a cause de meme cle utiliser 2 endrois (-> et <-)
void MainWindow::createActions()
{
    previousAction = new QAction(tr("Previous"),this);
    previousAction->setShortcut(Qt::Key_Left);
    QObject::connect(previousAction, SIGNAL(triggered()), this, SLOT(previousClicked()));
    
    nextAction = new QAction(tr("Next"),this);
    nextAction->setShortcut(Qt::Key_Right);
    QObject::connect(nextAction, SIGNAL(triggered()), this, SLOT(nextClicked()));
    
    playAction = new QAction(tr("Play"),this);
    playAction->setShortcut(Qt::Key_Up);
    QObject::connect(playAction, SIGNAL(triggered()), this, SLOT(playClicked()));
    
    pauseAction = new QAction(tr("Pause"),this);
    pauseAction->setShortcut(Qt::Key_Down);
    QObject::connect(pauseAction, SIGNAL(triggered()), this, SLOT(pauseClicked()));
    
    changeAction = new QAction(tr("&Change"),this);
    helpAction = new QAction(tr("&Help"),this);
    
    addAction(previousAction);
    addAction(nextAction);
    addAction(playAction);
    addAction(pauseAction);
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

//creation de menu, si vous voulez ajouter autres choses il faut pense de cree action dans createAction
void MainWindow::createMenus()
{
    editMenu = menuBar()->addMenu(tr("&Edit"));
    
    moveMenu = editMenu->addMenu(tr("&Move"));
    moveMenu->addAction(previousAction);
    moveMenu->addAction(nextAction);
    moveMenu->addAction(playAction);
    moveMenu->addAction(pauseAction);
    
    editMenu->addSeparator();
    editMenu->addAction(changeAction);
    
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAction);
    
}

//creation de grid, utiliser 2 image differant pour vide et utiliser. la taille d'image en defaut(ca depant de nombre de case).
void MainWindow::createGrid()
{
    gridLayout = new QGridLayout;
    gridLayout->setAlignment(Qt::AlignHCenter);
    gridLayout->setSpacing(2);
    gridLayout->setMargin(20);
    
    for (int i=0; i< gridHeight*gridWide; i++)
    {
        QString s;
        s.setNum(i);
        
        //l ne peut pas mettre hore de for sinon il affiche juste un label.
        QLabel *l = new QLabel(s);
        l->setPixmap(QPixmap::fromImage(*imageEmpty));
        vecLabel.push_back(l);
    }
    
    int num(0);
    for (int i=0; i<gridHeight; i++)
    {
        for (int j=0; j<gridWide; j++)
        {
            gridLayout->addWidget(vecLabel[num],i,j,1,1);
            num++;
        }
    }
}

//fonction public si maxTour=100 il va compter de 0-99
void MainWindow::setMaxTour(int i)
{
    maxTour=i;
}
//fonction public si gridHeight=5 il va compter de 1-5
void MainWindow::setGridHeight(int i)
{
    gridHeight=i;
}
//fonction public si gridWide=5 il va compter de 1-5
void MainWindow::setGridWide(int i)
{
    gridWide=i;
}

//fonction public height et wide compte de 0 a un nombre.
void MainWindow::changeToUse(int height, int wide)
{
    int place = (wide + height*(gridWide-1) +height);
    vecLabel[place]->setPixmap(QPixmap::fromImage(*imageUse));
}

//fonction public height et wide compte de 0 a un nombre.
void MainWindow::changeToEmpty(int height, int wide)
{
    int place = (wide + height*(gridWide-1) +height);
    vecLabel[place]->setPixmap(QPixmap::fromImage(*imageEmpty));
}

//les signal
//pas besoin d'ecrire pour slide car quand tourSpinBox changer, slide change au meme temps.
void MainWindow::previousClicked()
{
    int num=slider->value()-1;
    tourSpinBox->setValue(num);
}

void MainWindow::nextClicked()
{
    int num=slider->value()+1;
    tourSpinBox->setValue(num);
}

//timer->start(1000) = 1 second
void MainWindow::playClicked()
{
    timer = new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(nextClicked()));
    timer->start(1000);
}

void MainWindow::pauseClicked()
{
    timer->stop();
}




