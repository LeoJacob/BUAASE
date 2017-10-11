#include "myQLineEdit.h"



myQLineEdit::myQLineEdit(QWidget *parent):QLineEdit(parent)
{
	QLineEdit();
}


myQLineEdit::~myQLineEdit()
{
}

/*
void myQLineEdit::mousePressEvent(QMouseEvent *event)
{
	int rowId, colId;
	if (this->isEnabled() && this->text().isEmpty())
	{
		if (qApp->mouseButtons() == Qt::LeftButton)
			setFocus();
		else if (qApp->mouseButtons() == Qt::RightButton)
		{
			colId = (geometry().left() - LEFT_MARGIN) / BOX_SIDE_LENGTH;
			rowId = (geometry().top() - TOP_MARGIN) / BOX_SIDE_LENGTH;
			emit getTips(rowId, colId);
		}
	}
}
*/

void myQLineEdit::contextMenuEvent(QContextMenuEvent *event)
{
	int rowId, colId;
	if (this->isEnabled() && this->text().isEmpty())
	{
		colId = (geometry().left() - LEFT_MARGIN) / BOX_SIDE_LENGTH;
		rowId = (geometry().top() - TOP_MARGIN) / BOX_SIDE_LENGTH;
		emit getTips(rowId, colId);
	}
}
		
