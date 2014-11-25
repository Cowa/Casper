#ifndef FINDDIALOG_HPP
#define FINDDIALOG_HPP

#include <QtGui>
#include <vector>

class QSlider;
class QPushButton;
class QLabel;
class QSpinBox;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow();
    ~MainWindow();
    
    void setMaxTour(int i);
    void setGridHeight(int i);
    void setGridWide(int i);
    void changeToUse(int, int);
    void changeToEmpty(int, int);
    
private:
    int maxTour;
    int gridHeight, gridWide;
    QTimer *timer;
    QImage *imageEmpty;
    QImage *imageUse;
    //GridWidget *gridWidget;
    std::vector<QLabel*> vecLabel;
    QSlider *slider;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QLabel *tourLabel;
    QSpinBox *tourSpinBox;
    
    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *bottomLayout;
    
    QAction *previousAction;
    QAction *nextAction;
    QAction *playAction;
    QAction *pauseAction;
    QAction *changeAction;
    QAction *helpAction;
    
    QMenu *editMenu;
    QMenu *moveMenu;
    QMenu *helpMenu;
    
    void createActions();
    void createMenus();
    void createGrid();

private slots:
    void previousClicked();
    void nextClicked();
    void playClicked();
    void pauseClicked();
};
#endif