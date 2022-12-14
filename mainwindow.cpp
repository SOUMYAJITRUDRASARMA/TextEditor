#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

QImage img=QImage(700,700,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame, SIGNAL(Mouse_Rel()), this, SLOT(Mouse_Released()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
//    connect(ui->frame, SIGNAL(Key_Press(int)), this, SLOT(keyPressed(int)));
//    connect(ui->frame, SIGNAL(Key_Release(int)), this, SLOT(keyReleased(int)));

    // Colors ...
    WHITE = qRgb(255, 255, 255);
    BLACK = qRgb(0, 0, 0);
    RED = qRgb(255, 0, 0);
    LIGHT_GREY = qRgb(220, 220, 220);
    LIGHT_BLUE = qRgb(173, 216, 230);
    LIGHT_GREEN = qRgb(144, 238, 144);

    // Positions and values ...
    winLimX = ui->frame->width() / Font::charX, winLimY = ui->frame->width() / Font::charY;
    winCurX = winCurY = 0;
    winCurYNodeLine = tfData.headLine;
    isSelectionOn = isControlModeOn = isDisplayResultModeOn = isShiftOn = false;
    ui->spinBoxTabSize->setMinimum(1);
    ui->spinBoxTabSize->setValue(4);

    // Getting clipboard for copy and paste ...
    clipboard = QApplication::clipboard();

    // Getting complete control of keyboard ...
    QWidget::grabKeyboard();  // If we don't do this, arrow keys and spacebar will switch between and press buttons in UI and not be signalled for listeners ...

    // Clearing the screen and setting the cursor finally ...
    clearScreen();
    drawCursor(0, 0);
    ui->frame->setPixmap(QPixmap::fromImage(img));

    // Setting title ...
    setWindowTitle("New File");
    defaultDirectory = "D://JU/Class Resources/3rd Year 1st Semester/System Programming Lab/Assignment 4/examples/";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showMousePosition(QPoint &pos)
{

}

void MainWindow::Mouse_Pressed()
{
    if(ui->frame->x < 0) ui->frame->x = 0; else if(ui->frame->x >= ui->frame->width()) ui->frame->x = ui->frame->width() - 1;
    if(ui->frame->y < 0) ui->frame->y = 0; else if(ui->frame->y >= ui->frame->height()) ui->frame->y = ui->frame->height() - 1;

    cursorX1 = (ui->frame->x + Font::charX / 2) / Font::charX;
    cursorY1 = ui->frame->y / Font::charY;

    int lineDiff = winCurY + cursorY1 - tfData.cursorY, cx, cy = tfData.cursorY;
    NodeLine *cl = tfData.curLine;  // curLine
    Node *cLoc = tfData.cursorLocation;  // cursorLocation

    cx = winCurX + cursorX1;

    if(lineDiff != 0)
    {
        if(lineDiff > 0) while(lineDiff-- && cl->next) cl = cl->next, cy++;
        else while(lineDiff++ && cl->prev) cl = cl->prev, cy--;
    }

    cLoc = cl->headChar;
    for(int i = 0; i < cx; i++)
        if(!cLoc->next){ cx = i; break; }
        else cLoc = cLoc->next;


    // updating parameters ...
    selX1 = cursorX1 = cx;
    selY1 = cursorY1 = cy;
    selCursorLoc1 = cLoc;
    selLine1 = cl;

    cout << "Pressed: (" << cx << "," << cy << ")" << endl;
}

void MainWindow::Mouse_Released()
{
    if(ui->frame->relX < 0) ui->frame->relX = 0; else if(ui->frame->relX >= ui->frame->width()) ui->frame->relX = ui->frame->width() - 1;
    if(ui->frame->relY < 0) ui->frame->relY = 0; else if(ui->frame->relY >= ui->frame->height()) ui->frame->relY = ui->frame->height() - 1;

    cursorX2 = (ui->frame->relX + Font::charX / 2) / Font::charX;
    cursorY2 = ui->frame->relY / Font::charY;

    int lineDiff = winCurY + cursorY2 - tfData.cursorY, cx, cy = tfData.cursorY;
    NodeLine *cl = tfData.curLine;  // curLine
    Node *cLoc = tfData.cursorLocation;  // cursorLocation

    cx = winCurX + cursorX2;

    if(lineDiff != 0)
    {
        if(lineDiff > 0) while(lineDiff-- && cl->next) cl = cl->next, cy++;
        else  while(lineDiff++ && cl->prev) cl = cl->prev, cy--;
    }

    cLoc = cl->headChar;
    for(int i = 0; i < cx; i++)
        if(!cLoc->next){ cx = i; break; }
        else cLoc = cLoc->next;


    // updating parameters ...
    selX2 = cursorX2 = cx;
    selY2 = cursorY2 = cy;
    selCursorLoc2 = cLoc;
    selLine2 = cl;

    cout << "Released: (" << cx << "," << cy << ")" << endl;


    if(cursorX1 == cursorX2 && cursorY1 == cursorY2)
    {
        // Cursor Placement Mode ...
        /*int lineDiff = winCurY + cursorY1 - tfData.cursorY;

        tfData.cursorX = winCurX + cursorX1;

        if(lineDiff != 0)
        {
            if(lineDiff > 0)
            {
                while(lineDiff-- && tfData.curLine->next) tfData.curLine = tfData.curLine->next, tfData.cursorY++;
            }
            else
            {
                while(lineDiff-- && tfData.curLine->prev) tfData.curLine = tfData.curLine->prev, tfData.cursorY--;
            }
        }

        tfData.cursorLocation = tfData.curLine->headChar;
        for(int i = 0; i < tfData.cursorX; i++)
            if(!tfData.cursorLocation->next){ tfData.cursorX = i; break; }
            else tfData.cursorLocation = tfData.cursorLocation->next;*/

        isSelectionOn = false;

        tfData.cursorX = cursorX1;
        tfData.cursorY = cursorY1;
        tfData.cursorLocation = selCursorLoc1;
        tfData.curLine = selLine1;

        updateScreen();
    }
    else
    {
        // Selection Mode ...
        isSelectionOn = true;
        isDisplayResultModeOn = false;

        if(cursorY2 < cursorY1 || (cursorY1 == cursorY2 && cursorX2 < cursorX1))
            swap(selX1, selX2), swap(selY1, selY2),
            swap(selCursorLoc1, selCursorLoc2), swap(selLine1, selLine2);

        cout << "Selection: " << selX1 << "," << selY1 << " -> " << selX2 << "," << selY2 << endl;

        updateScreen();
    }
}



void MainWindow::drawCharacter(int xPos, int yPos, char ch, Node *nRef, bool isSelected)
{
    int xStart = xPos * Font::charX, yStart = yPos * Font::charY;
    QVector<QVector<bool>> drawableChar = font.getDrawableMatrix(ch);
    for(int x = 0; x < Font::charX; x++)
        for(int y = 0; y < Font::charY; y++)
            img.setPixel(xStart + x, yStart + y, (drawableChar[y][x])? BLACK: (isDisplayResultModeOn)? ((setResultCharNodes.find(nRef) != setResultCharNodes.end())? LIGHT_GREEN: LIGHT_GREY): (isSelected)? LIGHT_BLUE: LIGHT_GREY);  // Light grey is used to distinguish between spaces occupied by characters or white spaces and spaces really empty ...
}

void MainWindow::drawCursor(int xPos, int yPos)
{
    int xStart = xPos * Font::charX, yStart = yPos * Font::charY;
    for(int x = 0; x < 2; x++)
        for(int y = 0; y < Font::charY; y++)
            img.setPixel(xStart + ((xPos != winLimX)? x: -(3 + x)), yStart + y, RED);
}

void MainWindow::clearScreen()
{
    for(int x = 0; x < img.width(); x++)
        for(int y = 0; y < img.height(); y++)
            img.setPixel(x, y, WHITE);
}

void MainWindow::updateScreen()
{
    clearScreen();

    bool charIsSelected = false;
    NodeLine *nLine = winCurYNodeLine;
    for(int line = 0; line < winLimY; line++, nLine = nLine->next)
    {
        if(!nLine) break;
        Node *nChar = nLine->headChar->next;
        for(int i = 0; i < winCurX; i++){ if(!nChar) break; nChar = nChar->next; }
        for(int chNo = 0; chNo < winLimX; chNo++, nChar = nChar->next)
        {
            if(!nChar) break;
            charIsSelected = ((line + winCurY > selY1) && (line + winCurY < selY2)) ||
                    ( (selY1 == selY2)?
                          (line + winCurY == selY1 && chNo + winCurX >= selX1 && chNo + winCurX < selX2):
                             ((line + winCurY == selY1 && chNo + winCurX >= selX1) ||
                             (line + winCurY == selY2 && chNo + winCurX < selX2))
                    );
//            cout << "(" << (chNo + winCurX) << "," << (line + winCurY) << " -> "
//                 << ((line + winCurY > selY1) && (line + winCurY < selY2)) << " | " <<
//                    (chNo + winCurX >= selX1 && chNo + winCurX < selX2) << " | " <<
//                    ((line + winCurY == selY1 && chNo + winCurX >= selX1) ||
//                    (line + winCurY == selY2 && chNo + winCurX < selX2)) << endl;
            drawCharacter(chNo, line, nChar->data, nChar, isSelectionOn && charIsSelected);
        }
    }

    if(!isSelectionOn) drawCursor(tfData.cursorX - winCurX, tfData.cursorY - winCurY);

    ui->frame->setPixmap(QPixmap::fromImage(img));
}




void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    cout << "Signal: " << key << endl;


    if(isControlModeOn)
    {
        if(key == Qt::Key_C)
        {
            if(!isSelectionOn) return;
            clipboard->setText(tfData.getStringFromSelection(selCursorLoc1, selLine1, selCursorLoc2));
        }
        else if(key == Qt::Key_V)
        {
            isDisplayResultModeOn = false;
            if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;
            tfData.insertString(clipboard->text());
            updateScreen();
        }
        else if(key == 16777217)
        {
            // tab not working -> so gave ctrl + tab ...
            cout << "TAB Pressed ..." << endl;
            isDisplayResultModeOn = false;
            if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;
            int num = ui->spinBoxTabSize->value();
            while(num--) tfData.insertChar(' ');

            updateScreen();
        }
        // else if(key == Qt::Key_F) on_pushButtonFind_clicked();

        return;
    }


    if(key >= Qt::Key_A && key <= Qt::Key_Z)
    {
        isDisplayResultModeOn = false;
        if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;
        tfData.insertChar(key - Qt::Key_A + (((GetKeyState(VK_CAPITAL) == 1) ^ isShiftOn)? 'A': 'a'));
    }

    else if(key >= Qt::Key_0 && key <= Qt::Key_9)
    {
        isDisplayResultModeOn = false;
        if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;
        tfData.insertChar(key - Qt::Key_0 + '0');
    }

    else if(key == Qt::Key_Control){ cout << "CTRL Pressed ..." << endl; isControlModeOn = true; return; }
    else if(key == Qt::Key_Shift){ cout << "SHIFT Pressed ..." << endl; isShiftOn = true; return; }
    else if(key == Qt::Key_Space)
    {
        isDisplayResultModeOn = false;
        if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;
        tfData.insertChar(' ');
    }
    else if(key == Qt::Key_Enter || key == Qt::Key_Return)
    {
        isDisplayResultModeOn = false;
        if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;
        tfData.insertNewLine();

        if(ui->checkBoxIndentation->isChecked())
        {
            Node *n = tfData.curLine->prev->headChar;
            while(n->next && n->next->data == ' ') n = n->next, tfData.insertChar(' ');
        }
    }
    else if(key == Qt::Key_Backspace)
    {
        isDisplayResultModeOn = false;
        if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;
        else tfData.deleteCharBackward();
    }
    else if(key == Qt::Key_Delete)
    {
        isDisplayResultModeOn = false;
        if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;
        else tfData.deleteCharForward();
    }
    else if(key == Qt::Key_Tab)
    {
        // tab not working -> so gave ctrl + tab ...
        cout << "TAB Pressed ..." << endl;
        isDisplayResultModeOn = false;
        if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;
        int num = ui->spinBoxTabSize->value();
        while(num--) tfData.insertChar(' ');
    }

    else if(key == Qt::Key_Up)
    {
        if(isSelectionOn)
        {
            isSelectionOn = false;
            tfData.curLine = selLine1;
            tfData.cursorLocation = selCursorLoc1;
            tfData.cursorX = selX1, tfData.cursorY = selY1;

            updateScreen();
            return;
        }

        if(!tfData.curLine->prev) return;

        int maxOffsetRight = tfData.cursorX;
        tfData.curLine = tfData.curLine->prev;
        tfData.cursorLocation = tfData.curLine->headChar;
        tfData.cursorX = 0;
        while(tfData.cursorLocation->next && maxOffsetRight--) tfData.cursorLocation = tfData.cursorLocation->next, tfData.cursorX++;
        tfData.cursorY--;
    }
    else if(key == Qt::Key_Down)
    {
        if(isSelectionOn)
        {
            isSelectionOn = false;
            tfData.curLine = selLine2;
            tfData.cursorLocation = selCursorLoc2;
            tfData.cursorX = selX2, tfData.cursorY = selY2;

            updateScreen();
            return;
        }

        if(!tfData.curLine->next) return;

        int maxOffsetRight = tfData.cursorX;
        tfData.curLine = tfData.curLine->next;
        tfData.cursorLocation = tfData.curLine->headChar;
        tfData.cursorX = 0;
        while(tfData.cursorLocation->next && maxOffsetRight--) tfData.cursorLocation = tfData.cursorLocation->next, tfData.cursorX++;
        tfData.cursorY++;
    }
    else if(key == Qt::Key_Left)
    {
        if(isSelectionOn)
        {
            isSelectionOn = false;
            tfData.curLine = selLine1;
            tfData.cursorLocation = selCursorLoc1;
            tfData.cursorX = selX1, tfData.cursorY = selY1;

            updateScreen();
            return;
        }

        if(tfData.cursorX > 0) tfData.cursorLocation = tfData.cursorLocation->prev, tfData.cursorX--;
        else
        {
            if(!tfData.curLine->prev) return;  // no left character , no prev line ...

            tfData.curLine = tfData.curLine->prev;
            tfData.cursorLocation = tfData.curLine->headChar;
            tfData.cursorX = 0;
            while(tfData.cursorLocation->next) tfData.cursorLocation = tfData.cursorLocation->next, tfData.cursorX++;
            tfData.cursorY--;
        }
    }
    else if(key == Qt::Key_Right)
    {
        if(isSelectionOn)
        {
            isSelectionOn = false;
            tfData.curLine = selLine2;
            tfData.cursorLocation = selCursorLoc2;
            tfData.cursorX = selX2, tfData.cursorY = selY2;

            updateScreen();
            return;
        }

        if(tfData.cursorLocation->next) tfData.cursorLocation = tfData.cursorLocation->next, tfData.cursorX++;
        else
        {
            if(!tfData.curLine->next) return;  // no right character , no next line ...

            tfData.curLine = tfData.curLine->next;
            tfData.cursorLocation = tfData.curLine->headChar;
            tfData.cursorX = 0;
            tfData.cursorY++;
        }
    }

    else if(key >= 0 && key < 256)
    {
        cout << key << endl;
        isDisplayResultModeOn = false;
        if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;
        tfData.insertChar(key);
    }

    else{ cout << "Key not registered ..." << endl; return; }  // no need of updating screen in case of unidentified key ...


    // updating screen offset so that cursor is in view ...
    if(tfData.cursorX < winCurX) winCurX = tfData.cursorX;
    else if(tfData.cursorX > winCurX + winLimX) winCurX = tfData.cursorX - winLimX;

    if(tfData.cursorY < winCurY)
    {
        int times = winCurY - tfData.cursorY;
        while(times--) winCurYNodeLine = winCurYNodeLine->prev;
        winCurY = tfData.cursorY;
    }
    else if(tfData.cursorY >= winCurY + winLimY)
    {
        int times = tfData.cursorY - (winCurY + winLimY - 1);
        while(times--) winCurYNodeLine = winCurYNodeLine->next;
        winCurY = tfData.cursorY - winLimY + 1;
    }


    updateScreen();
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    int key = event->key();

    if(key == Qt::Key_Control) isControlModeOn = false;
    else if(key == Qt::Key_Shift) isShiftOn = false;
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    cout << "Mouse Wheel: " << event->angleDelta().y() << endl;

    if(event->angleDelta().y() > 0)
    {
        // Scroll Up ...
        if(winCurY > 0) winCurY--, winCurYNodeLine = winCurYNodeLine->prev;
    }
    else if(event->angleDelta().y() < 0)
    {
        // Scroll down ...
        NodeLine *nl = winCurYNodeLine;
        for(int i = 0; i < winLimY; i++) if(nl) nl = nl->next;
        if(nl) winCurY++, winCurYNodeLine = winCurYNodeLine->next;
    }

    updateScreen();
}




void MainWindow::on_pushButtonCopy_clicked()
{
    if(!isSelectionOn) return;

    clipboard->setText(tfData.getStringFromSelection(selCursorLoc1, selLine1, selCursorLoc2));
}

void MainWindow::on_pushButtonPaste_clicked()
{
    isDisplayResultModeOn = false;
    if(isSelectionOn) tfData.deleteRange(selX1, selY1, selCursorLoc1, selLine1, selCursorLoc2), isSelectionOn = false;

    tfData.insertString(clipboard->text());
    updateScreen();
}

void MainWindow::on_pushButtonNew_clicked()
{
    // Positions and values ...
    tfData = TextFileData();
    winCurX = winCurY = 0;
    winCurYNodeLine = tfData.headLine;
    isSelectionOn = isControlModeOn = isDisplayResultModeOn = false;

    // Clearing the screen and setting the cursor finally ...
    clearScreen();
    drawCursor(0, 0);
    ui->frame->setPixmap(QPixmap::fromImage(img));

    // Setting title ...
    setWindowTitle("New File");

    // Alerting user ...
    QMessageBox mb;
    mb.setText("New file has been created ...");
    mb.exec();
}

void MainWindow::on_pushButtonOpen_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", defaultDirectory);

    QFile f(filePath);
    if(!f.open(QFile::ReadOnly | QFile::Text)){ QMessageBox::warning(this, "Error", "File cannot be opened !!!"); return; }
    QString contents = QTextStream(&f).readAll();
    f.close();

//    cout << "read: " << contents.toStdString() << endl;

    // Positions and values ...
    tfData = TextFileData();
    winCurX = winCurY = 0;
    winCurYNodeLine = tfData.headLine;
    isSelectionOn = isControlModeOn = isDisplayResultModeOn = false;
    // Setting title ...
    setWindowTitle(filePath);

    tfData.insertString(contents);
    updateScreen();

    // Alerting user ...
    QMessageBox mb;
    mb.setText("File has been opened ...");
    mb.exec();
}

void MainWindow::on_pushButtonSave_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", defaultDirectory);

    QFile f(filePath);
    if(!f.open(QFile::WriteOnly | QFile::Text)){ QMessageBox::warning(this, "Error", "File cannot be created !!!"); return; }
    QString contents = tfData.getFullString();
    QTextStream(&f) << contents;
    f.flush();
    f.close();

    // Setting title ...
    setWindowTitle(filePath);
    // Alerting user ...
    QMessageBox mb;
    mb.setText("File has been saved ...");
    mb.exec();
}

void MainWindow::on_pushButtonFind_clicked()
{
    // Getting finding string ...
    bool okClicked;
    QWidget::releaseKeyboard();
    QString key = QInputDialog::getText(this, "Find", "Enter word to find:", QLineEdit::Normal, "", &okClicked);
    QWidget::grabKeyboard();

    if(!okClicked) return;
    if(key.isEmpty()){ QMessageBox mb; mb.setText("Cannot find empty string !!!"); mb.exec(); return; }

    // Setting mode and variables ...
    isDisplayResultModeOn = true;
    setResultCharNodes.clear();

    // Finding ...
    Node *cLoc = tfData.headLine->headChar;
    NodeLine *line = tfData.headLine;

    int i = 0, j = 0, nKey = key.size(), indexCharNode = 0, cnt = 0;
    char ch;
    bool first = true;
    QVector<int> dpLps;
    QString ans;
    QVector<Node *> charNodeRef(nKey);

    // BUILDING  KEY \0 STRING

    for(QChar qCh: key)
    {
        ch = qCh.toLatin1();
        ans.push_back(ch);

        if(first)
        {
            dpLps.push_back(j = 0);
            first = false; i++; continue;
        }

        while(j && ans[i] != ans[j]) j = dpLps[j - 1];
        if(ans[i] == ans[j]) dpLps.push_back(++j);
        else dpLps.push_back(j = 0);

        i++;
    }

    // .............................................................................................................

    ch = '\0';
    ans.push_back(ch);
    while(j && ans[i] != ans[j]) j = dpLps[j - 1];
    if(ans[i] == ans[j]) dpLps.push_back(++j);
    else dpLps.push_back(j = 0);

    i++;

    // .............................................................................................................

    do
    {
        if(cLoc->next) cLoc = cLoc->next;
        else if(!line->next) break;
        else line = line->next, cLoc = line->headChar;  // consider headchar as we need to consider '\n' too ...

        if(cLoc->data == BEG_OF_LINE_CHAR) ans.push_back('\n');
        else ans.push_back(cLoc->data);

        charNodeRef[(indexCharNode + 1) % nKey] = cLoc, indexCharNode = (indexCharNode + 1) % nKey;

        while(j && ans[i] != ans[j]) j = dpLps[j - 1];
        if(ans[i] == ans[j]) dpLps.push_back(++j);
        else dpLps.push_back(j = 0);

        if(dpLps[i] == nKey)
        {
            for(Node *n: charNodeRef) setResultCharNodes.insert(n);
            cnt++;
            dpLps[i] = j = 0;
        }

        i++;
    }
    while(true);

    QMessageBox mb; mb.setText(QString::number(cnt) + " matches found ..."); mb.exec();

//    cout << ans.toStdString() << endl << endl << "   --- DONE ---" << endl << endl;
//    for(int e: dpLps) cout << e << ", ";  cout << endl;

    updateScreen();
}

