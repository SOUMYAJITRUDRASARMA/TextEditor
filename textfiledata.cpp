#include "textfiledata.h"

TextFileData::TextFileData()
{
    headLine = new NodeLine();

    curLine = headLine;
    cursorLocation = headLine->headChar;  // points to character after which new letters will be entered ...
    cursorX = cursorY = 0;
}

void TextFileData::insertChar(char ch)
{
    insertAfter(cursorLocation, new Node(ch));
    cursorLocation = cursorLocation->next;
    cursorX++;
}

void TextFileData::insertString(QString str)
{
    char ch;
    for(QChar qCh: str)
    {
        ch = qCh.toLatin1();
        if(ch == '\n') insertNewLine();
        else insertChar(ch);
    }
}

void TextFileData::deleteCharBackward()
{
    if(cursorLocation->prev)
    {
        cursorLocation = cursorLocation->prev;
        cursorX--;
        deleteAfter(cursorLocation);
    }
    else
    {
        if(!curLine->prev) return;  // if no more lines before and no char before -> nothing to backspace ...

        int cx = 0;
        curLine = curLine->prev;
        Node *n = curLine->headChar;
        while(n->next) n = n->next, cx++;
        n->next = curLine->next->headChar->next;
        if(n->next) n->next->prev = n;
        deleteAfterLine(curLine);

        cursorLocation = n;
        cursorX = cx;
        cursorY--;
    }
}

void TextFileData::deleteCharForward()
{
    if(cursorLocation->next)
    {
        deleteAfter(cursorLocation);
    }
    else
    {
        if(!curLine->next) return;  // if no more lines ahead and no char ahead -> nothing to del ...

        Node *nextLineContents = curLine->next->headChar->next;
        deleteAfterLine(curLine);
        cursorLocation->next = nextLineContents;
        if(nextLineContents) nextLineContents->prev = cursorLocation;
    }
}

void TextFileData::insertNewLine()
{
    insertAfterLine(curLine, new NodeLine());
    curLine = curLine->next;

    curLine->headChar->next = cursorLocation->next;
    if(curLine->headChar->next) curLine->headChar->next->prev = curLine->headChar;
    cursorLocation->next = nullptr;
    cursorLocation = curLine->headChar;

    cursorX = 0;
    cursorY++;
}

void TextFileData::deleteRange(int cursorX1, int cursorY1, Node *startCursorLoc, NodeLine *startLine, Node *endCursorLoc)
{
    cursorX = cursorX1, cursorY = cursorY1;
    cursorLocation = startCursorLoc;
    curLine = startLine;

    bool endReached = false;
    while(!endReached)
    {
        if(cursorLocation->next == endCursorLoc) endReached = true;
        deleteCharForward();
    }
}

QString TextFileData::getStringFromSelection(Node *startCursorLoc, NodeLine *startLine, Node *endCursorLoc)
{
    Node *cLoc = startCursorLoc;
    NodeLine *line = startLine;

    QString ans;
    do
    {
        if(cLoc->next) cLoc = cLoc->next;
        else line = line->next, cLoc = line->headChar;  // consider headchar as we need to consider '\n' too ...

        if(cLoc->data == BEG_OF_LINE_CHAR) ans.push_back('\n');
        else ans.push_back(cLoc->data);
    }
    while(cLoc != endCursorLoc);

    return ans;
}

QString TextFileData::getFullString()
{
    Node *cLoc = headLine->headChar;
    NodeLine *line = headLine;

    QString ans;
    do
    {
        if(cLoc->next) cLoc = cLoc->next;
        else if(!line->next) break;
        else line = line->next, cLoc = line->headChar;  // consider headchar as we need to consider '\n' too ...

        if(cLoc->data == BEG_OF_LINE_CHAR) ans.push_back('\n');
        else ans.push_back(cLoc->data);
    }
    while(true);

    return ans;
}




Node * newLinkedListChar()
{
    return new Node(BEG_OF_LINE_CHAR);
}

void insertAfter(Node *prev, Node *newNode)
{
    newNode->next = prev->next;
    newNode->prev = prev;

    if(prev->next) prev->next->prev = newNode;
    prev->next = newNode;
}

void deleteAfter(Node *n)
{
    if(!n->next) return;

    Node *tmp = n->next;
    n->next = tmp->next;
    if(tmp->next) tmp->next->prev = n;
    delete tmp;
}




// Linked List for lines ...
NodeLine * newLinkedListLine()
{
    return new NodeLine();
}

void insertAfterLine(NodeLine *prev, NodeLine *newNode)
{
    newNode->next = prev->next;
    newNode->prev = prev;

    if(prev->next) prev->next->prev = newNode;
    prev->next = newNode;
}

void deleteAfterLine(NodeLine *n)
{
    if(!n->next) return;

    NodeLine *tmp = n->next;
    n->next = tmp->next;
    if(tmp->next) tmp->next->prev = n;
    delete tmp->headChar;
    delete tmp;
}
