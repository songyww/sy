#include "test.h"
#include <QtGui/QApplication>
#include "Pyramid_Class.h"
#include <vector>
#include <qstring>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{

	QString S =  "E:\\0_SY\\1_TheSecondYear\\5_MAP\\3\\3.tif";
	string str1 = S.toStdString();
	S = QString::fromStdString(str1);

	int pos = str1.find_last_of('\\');
	string str2 = str1.substr(0,pos + 1);
	cout<<str1<<endl;
	cout<<str2<<endl;
	system("pause");
	







	//PyramidBase pyramid1;
	//pyramid1.InFilePath = "E:\\0_SY\\1_TheSecondYear\\5_MAP\\3\\3.tif";

	//pyramid1.Path = ExtractFilePath(pyramid1.InFilePath);
	//pyramid1.CheckPyramid();
	////pyramid1.CreatePyramid();
	//for (int i = 0;i < pyramid1.iOverViewCount; i++)
	//{
	//	pyramid1.ReadPyramidFile(1,i);
	//	i++;
	//}



	QApplication a(argc, argv);
	test w;
	w.show();
	return a.exec();
}
