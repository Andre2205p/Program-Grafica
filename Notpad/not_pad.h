#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout> 
#include <QGridLayout>
#include <QFile>
#include <QLCDNumber>
#include <QFrame>
#include <QTimer>
#include <QProgressBar>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMainWindow>

#include <QScrollArea>
#include <QLabel>
#include <QImage>

#include <QGroupBox>

class Not_pad : public QMainWindow //public QObject
{
    Q_OBJECT

public:
    Not_pad(QApplication *app);
    void show();
    void setarTexto(QString string);    
    void createMenu();

public slots:
    void exibirTexto();
    void incrementaDisplay();
    void incrementaDisplayAuto();
    void chamaNovaTela();
    void open();
    void barraDeProgresso();
    void play();

private:
     int contadorAuto, contador, contadorBarra, baseTempo;

    QWidget *window, *newWindow;
    QTextEdit *editor;
    QString texto, log, temp;
    QLCDNumber *lcd1, *lcd2;
    QTimer *tempo;
    QBoxLayout *QBoxlayout;
    QApplication * aplc;
    QMenuBar *menuBar;
    QMenu *fileMenu, *helpMenu;
    QAction *exitAction, *openAction, *newAction, *helpAction;
    QPushButton * botaoSair, *botaoIncrementaDisplay, *botaoNovaJanela, *botaoBarraProgresso, *botaoSound;
    QGridLayout *QGridlayout;
    QFile *file;
    QProgressBar *barraProgresso;

    //QGridLayout* gridLayout;
    QImage* inputImg;
    QLabel* imgDisplayLabel;
    QScrollArea* scrollArea;



};
