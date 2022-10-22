#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QClipboard>
#include "font.h"
#include "textfiledata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void Mouse_Released();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();

    void on_Draw_clicked();

    void on_set_point1_clicked();

    void on_set_point2_clicked();

    void on_pushButton_clicked();

    void on_pushButtonCopy_clicked();

    void on_pushButtonPaste_clicked();

    void on_pushButtonNew_clicked();

    void on_pushButtonOpen_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonFind_clicked();

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    Font font;
    int winLimX, winLimY, winCurX, winCurY;  // Properties for the window ...
    NodeLine *winCurYNodeLine;
    int cursorX1, cursorY1, cursorX2, cursorY2;

    bool isSelectionOn, isControlModeOn, isDisplayResultModeOn;;
    int selX1, selY1, selX2, selY2;
    Node *selCursorLoc1, *selCursorLoc2;
    NodeLine *selLine1, *selLine2;
    QSet<Node *> setResultCharNodes;

    QRgb WHITE, BLACK, RED, LIGHT_GREY, LIGHT_BLUE, LIGHT_GREEN;
    TextFileData tfData;
    QClipboard *clipboard;

    QString defaultDirectory;

    void point(int, int, QRgb);
    void drawCharacter(int xPos, int yPos, char ch, Node *nRef, bool isSelected = false);
    void drawCursor(int xPos, int yPos);
    void clearScreen();
    void updateScreen();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
};

#endif // MAINWINDOW_H
