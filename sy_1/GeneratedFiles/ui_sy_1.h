/********************************************************************************
** Form generated from reading UI file 'sy_1.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SY_1_H
#define UI_SY_1_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sy_1Class
{
public:
    QAction *ON_CloseThis;
    QAction *ON_CloseAll;
    QAction *ON_BigMapShow;
    QAction *actionSURF;
    QAction *ON_SURF;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *ON_OpenFile1;
    QAction *ON_OpenFile2;
    QAction *actionSURF_2;
    QWidget *centralWidget;
    QAxWidget *MapToolBarCtr1;
    QAxWidget *MapCtr1;
    QAxWidget *MapToolBarCtr2;
    QAxWidget *MapCtr2;
    QAxWidget *MapTocCtr1;
    QAxWidget *MapTocCtr2;
    QAxWidget *MapToolBarCtr4;
    QAxWidget *MapCtr4;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *bigmaptime;
    QLineEdit *bigmapmse;
    QLabel *label_3;
    QLineEdit *bigmaptime2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_1;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *sy_1Class)
    {
        if (sy_1Class->objectName().isEmpty())
            sy_1Class->setObjectName(QString::fromUtf8("sy_1Class"));
        sy_1Class->resize(1400, 1049);
        ON_CloseThis = new QAction(sy_1Class);
        ON_CloseThis->setObjectName(QString::fromUtf8("ON_CloseThis"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/File/icon/bx_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        ON_CloseThis->setIcon(icon);
        ON_CloseAll = new QAction(sy_1Class);
        ON_CloseAll->setObjectName(QString::fromUtf8("ON_CloseAll"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/File/icon/bx_close_hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        ON_CloseAll->setIcon(icon1);
        ON_BigMapShow = new QAction(sy_1Class);
        ON_BigMapShow->setObjectName(QString::fromUtf8("ON_BigMapShow"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/File/icon/treemyfav.png"), QSize(), QIcon::Normal, QIcon::Off);
        ON_BigMapShow->setIcon(icon2);
        actionSURF = new QAction(sy_1Class);
        actionSURF->setObjectName(QString::fromUtf8("actionSURF"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/File/icon/linguist-check-on.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSURF->setIcon(icon3);
        ON_SURF = new QAction(sy_1Class);
        ON_SURF->setObjectName(QString::fromUtf8("ON_SURF"));
        ON_SURF->setIcon(icon3);
        action = new QAction(sy_1Class);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(sy_1Class);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(sy_1Class);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        ON_OpenFile1 = new QAction(sy_1Class);
        ON_OpenFile1->setObjectName(QString::fromUtf8("ON_OpenFile1"));
        ON_OpenFile2 = new QAction(sy_1Class);
        ON_OpenFile2->setObjectName(QString::fromUtf8("ON_OpenFile2"));
        actionSURF_2 = new QAction(sy_1Class);
        actionSURF_2->setObjectName(QString::fromUtf8("actionSURF_2"));
        actionSURF_2->setIcon(icon2);
        centralWidget = new QWidget(sy_1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MapToolBarCtr1 = new QAxWidget(centralWidget);
        MapToolBarCtr1->setObjectName(QString::fromUtf8("MapToolBarCtr1"));
        MapToolBarCtr1->setProperty("geometry", QVariant(QRect(30, 0, 661, 31)));
        MapCtr1 = new QAxWidget(centralWidget);
        MapCtr1->setObjectName(QString::fromUtf8("MapCtr1"));
        MapCtr1->setProperty("geometry", QVariant(QRect(140, 30, 551, 451)));
        MapToolBarCtr2 = new QAxWidget(centralWidget);
        MapToolBarCtr2->setObjectName(QString::fromUtf8("MapToolBarCtr2"));
        MapToolBarCtr2->setProperty("geometry", QVariant(QRect(710, 0, 661, 31)));
        MapCtr2 = new QAxWidget(centralWidget);
        MapCtr2->setObjectName(QString::fromUtf8("MapCtr2"));
        MapCtr2->setProperty("geometry", QVariant(QRect(820, 30, 551, 451)));
        MapTocCtr1 = new QAxWidget(centralWidget);
        MapTocCtr1->setObjectName(QString::fromUtf8("MapTocCtr1"));
        MapTocCtr1->setProperty("geometry", QVariant(QRect(30, 30, 111, 451)));
        MapTocCtr2 = new QAxWidget(centralWidget);
        MapTocCtr2->setObjectName(QString::fromUtf8("MapTocCtr2"));
        MapTocCtr2->setProperty("geometry", QVariant(QRect(710, 30, 111, 451)));
        MapToolBarCtr4 = new QAxWidget(centralWidget);
        MapToolBarCtr4->setObjectName(QString::fromUtf8("MapToolBarCtr4"));
        MapToolBarCtr4->setProperty("geometry", QVariant(QRect(30, 490, 661, 31)));
        MapCtr4 = new QAxWidget(centralWidget);
        MapCtr4->setObjectName(QString::fromUtf8("MapCtr4"));
        MapCtr4->setProperty("geometry", QVariant(QRect(30, 520, 661, 451)));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(750, 520, 391, 321));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 201, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 31, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 60, 31, 20));
        bigmaptime = new QLineEdit(groupBox);
        bigmaptime->setObjectName(QString::fromUtf8("bigmaptime"));
        bigmaptime->setGeometry(QRect(60, 30, 141, 21));
        bigmapmse = new QLineEdit(groupBox);
        bigmapmse->setObjectName(QString::fromUtf8("bigmapmse"));
        bigmapmse->setGeometry(QRect(60, 60, 141, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 41, 21));
        bigmaptime2 = new QLineEdit(groupBox);
        bigmaptime2->setObjectName(QString::fromUtf8("bigmaptime2"));
        bigmaptime2->setGeometry(QRect(60, 90, 141, 21));
        sy_1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(sy_1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1400, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_1 = new QMenu(menu);
        menu_1->setObjectName(QString::fromUtf8("menu_1"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menu_2);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_3->setIcon(icon2);
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        sy_1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(sy_1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        sy_1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(sy_1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        sy_1Class->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(menu_1->menuAction());
        menu_2->addAction(ON_BigMapShow);
        menu_2->addAction(menu_3->menuAction());

        retranslateUi(sy_1Class);

        QMetaObject::connectSlotsByName(sy_1Class);
    } // setupUi

    void retranslateUi(QMainWindow *sy_1Class)
    {
        sy_1Class->setWindowTitle(QApplication::translate("sy_1Class", "sy_1", 0, QApplication::UnicodeUTF8));
        ON_CloseThis->setText(QApplication::translate("sy_1Class", "\345\205\263\351\227\255\345\275\223\345\211\215", 0, QApplication::UnicodeUTF8));
        ON_CloseAll->setText(QApplication::translate("sy_1Class", "\346\270\205\351\231\244\346\211\200\346\234\211", 0, QApplication::UnicodeUTF8));
        ON_BigMapShow->setText(QApplication::translate("sy_1Class", "\350\266\205\345\244\247\345\233\276\345\203\217\345\212\240\350\275\275\344\270\216\346\230\276\347\244\272(&B)", 0, QApplication::UnicodeUTF8));
        actionSURF->setText(QApplication::translate("sy_1Class", "SURF", 0, QApplication::UnicodeUTF8));
        ON_SURF->setText(QApplication::translate("sy_1Class", "SURF", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("sy_1Class", "\345\217\202\350\200\203\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("sy_1Class", "\345\217\202\350\200\203\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("sy_1Class", "\345\276\205\351\205\215\345\207\206\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
        ON_OpenFile1->setText(QApplication::translate("sy_1Class", "\345\217\202\350\200\203\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
        ON_OpenFile2->setText(QApplication::translate("sy_1Class", "\345\276\205\351\205\215\345\207\206\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
        actionSURF_2->setText(QApplication::translate("sy_1Class", "SURF", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("sy_1Class", "\345\244\247\345\271\205\345\233\276\345\203\217\345\214\271\351\205\215", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("sy_1Class", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("sy_1Class", "\347\262\276\345\272\246", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("sy_1Class", "\346\200\273\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("sy_1Class", "\346\226\207\344\273\266(F)", 0, QApplication::UnicodeUTF8));
        menu_1->setTitle(QApplication::translate("sy_1Class", "\346\211\223\345\274\200\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("sy_1Class", "\350\266\205\345\244\247\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("sy_1Class", "\350\266\205\345\244\247\345\233\276\345\203\217\351\205\215\345\207\206", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("sy_1Class", "\345\274\202\346\272\220\345\233\276\345\203\217\351\205\215\345\207\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sy_1Class: public Ui_sy_1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SY_1_H
