#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout> 
#include <QGridLayout>
#include <QFile>
 #include <QLCDNumber>
#include <QFrame>

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

private:
    QWidget * window;
    QTextEdit *editor;
    QString texto;
    QLCDNumber *lcd;
    int contador;


};
