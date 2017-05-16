#include "test.h"

#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QCursor>
#include <QKeySequence>
#include <QPushButton>
#include <QDebug>
#include <qtoolbox.h>
//
//#include <QUuid>
//#include <qmessagebox.h>
//#include <qstring.h>
//#include <qfiledialog.h>

test::test(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);


	setWindowTitle(tr("Main Window"));
	openAction = new QAction(QIcon("doc-open"),tr("&Yes"),this);
	closeAction =  new QAction(QIcon("doc-close"),tr("NO"), this);
	//openAction->setShortcut(QKeySequence::Open);
	//openAction->setStatusTip(tr("Open an existing file"));
	connect(openAction, SIGNAL(triggered()),this,SLOT(open()));
	//file_menu = new QMenu("�ļ�")��
	connect(closeAction,SIGNAL(triggered()),this,SLOT(close()));
	statusBar();

	QMenu *file = menuBar()->addMenu(tr("&File"));
	file->addAction(openAction);
	file->addAction(closeAction);
	file->addMenu("111")->addAction(openAction);
	QToolBar *toolBar2 = addToolBar(tr("&File"));
	toolBar2->addAction(openAction);

	/*QMenu *menu1 = new QMenu("hello");
	menu1->addAction("hello l111");
	menu1->addAction("world 1111");

	if (QAction * act = menu1->exec(QCursor::pos( )))
	{
	qDebug()<<act->text()<<"triggered";

	}*/



	///QToolBox������ڲ���
	toolbox = new QToolBox;
	toolbox->setFrameShape(QFrame::Box);
	QLabel *label1 = new QLabel(tr("ĬĬ")��this);
	QLabel *label2 = new QLabel(tr("����")��this);
	QLabel *label3 = new QLabel(tr("ð��")��this);

	toolbox->insertItem(0,label1,tr("ͬѧ"));
	toolbox->insertItem(1,label2,tr("����"));
	toolbox->insertItem(2,label3,tr("İ����"));




}

test::~test()
{

}


void test::open()
{
	QMessageBox::information(this, tr("Information"),tr("Open"));
}
void test::close()
{
	QMessageBox::information(this,tr("Hello"),tr("Close"));
}
