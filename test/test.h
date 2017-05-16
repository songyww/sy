#ifndef TEST_H
#define TEST_H

#include <QtGui/QMainWindow>
#include "ui_test.h"
#include <QToolBox>
#include <qlabel.h>


class test : public QMainWindow
{
	Q_OBJECT

public:
	test(QWidget *parent = 0, Qt::WFlags flags = 0);
	~test();

private:
	Ui::testClass ui;

private slots:
	void open();
	void close();
private:
	QAction *openAction, *closeAction;



public:
	QToolBox *toolbox;
};


////读取给定路径下的当前文件夹名字


#endif // TEST_H
