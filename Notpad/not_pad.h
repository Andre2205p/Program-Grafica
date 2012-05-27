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

class Not_pad : public QObject
{
    Q_OBJECT

public:
    Not_pad(QApplication *app);
    void show();
    void setarTexto(QString string);    


public slots:
    void exibirTexto();
    void incrementaDisplay();
    void incrementaDisplayAuto();
    void chamaNovaTela();

private:
    QWidget *window, *newWindow;
    QTextEdit *editor;
    QString texto;
    QLCDNumber *lcd1, *lcd2;
    QFile *fila;
    QTimer *tempo;
    QBoxLayout *layout;
    int contadorAuto, contador;


};
