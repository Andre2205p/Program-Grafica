#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout> 
#include <QGridLayout>

class Not_pad : public QObject
{
    Q_OBJECT

public:
    Not_pad(QApplication *app);
    void show();
    void setarTexto(QString string);


public slots:
    void exibirTexto();

private:
    QWidget * window;
    QTextEdit *editor;
    QString texto;

};