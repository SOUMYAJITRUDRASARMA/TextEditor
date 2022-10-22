#ifndef TEXTFILEDATA_H
#define TEXTFILEDATA_H


#define BEG_OF_LINE_CHAR '\0'
#include <QtCore/QString>
#include <ext/rope>

// DOUBLE LINKED LIST ...

struct Node
{
    char data;
    Node *next, *prev;

    Node(char data = '\0'){ this->data = data; next = prev = nullptr; }
};

Node * newLinkedListChar();
void insertAfter(Node *prev, Node *newNode);
void deleteAfter(Node *n);




// Linked List for lines ...
struct NodeLine
{
    Node *headChar;
    NodeLine *next, *prev;

    NodeLine(){ this->headChar = newLinkedListChar(); next = prev = nullptr; }
};

NodeLine * newLinkedListLine();
void insertAfterLine(NodeLine *prev, NodeLine *newNode);
void deleteAfterLine(NodeLine *n);

class TextFileData
{
public:
    NodeLine *headLine, *curLine;
    Node *cursorLocation;
    int cursorX, cursorY;

    TextFileData();
    void insertChar(char ch);
    void insertString(QString str);
    void deleteCharBackward();
    void deleteCharForward();
    void insertNewLine();
    void deleteRange(int cursorX1, int cursorY1, Node *startCursorLoc, NodeLine *startLine, Node *endCursorLoc);
    QString getStringFromSelection(Node *startCursorLoc, NodeLine *startLine, Node *endCursorLoc);
    QString getFullString();
};

#endif // TEXTFILEDATA_H
