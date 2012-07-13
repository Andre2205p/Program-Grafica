#include <QDialog>

#include <QDialogButtonBox>
#include <QTextEdit>

#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include <QGroupBox>

#include <QLabel>
#include <QLineEdit>

#include <QPushButton>

#include <QFrame>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog();

private:
    void createMenu();
    void createHorizontalGroupBox();
    void createGridGroupBox();
    void createFormGroupBox();

    enum { NumGridRows = 3, NumButtons = 4 };

    QTextEdit *bigEditor;
    QDialogButtonBox *buttonBox;

    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction *exitAction;

    QGroupBox *horizontalGroupBox;
    QPushButton *buttons[NumButtons];

    QGroupBox *gridGroupBox;
    QTextEdit *smallEditor;
    QLabel *labels[NumGridRows], *label;
    QLineEdit *lineEdits[NumGridRows];

    QGroupBox *formGroupBox;
};



