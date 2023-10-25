#include "mainwindow.h"

#include <QDebug>
#include <QToolButton>
#include <QMenu>
#include <QActionGroup>
#include <QLayout>
#include <QStatusBar>

#include "qxwidget/tinytabbar.h"
#include "qxwidget/tinynavbar.h"
#include "qxwidget/menuaccessbutton.h"

QX_WIDGET_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QIcon icon(":/logo");

    // TinyTabBar
    TinyTabBar *tb = new TinyTabBar(this);
    addToolBar(tb);

    tb->addTab(icon, tr("tab1"));
    tb->addTab(icon, tr("tab22"));
    tb->addTab(icon, tr("tab333"));
    tb->addTab(icon, tr("tab4444"));
    tb->setTabEnabled(1, false);
    tb->insertTab(2, icon, tr("tabN"));
    tb->setTabVisible(3, false);
    tb->setCurrentIndex(0);

    connect(tb, &TinyTabBar::currentChanged, this, [tb](int index) {
        qDebug() << "currentChanged:" << index << tb->isTabChecked(index);
    });

    connect(tb, &TinyTabBar::currentToggled, this, [&](int index, bool checked) {
        qDebug() << "currentToggled:" << index << checked;
    });

//    QToolButton *button = new QToolButton(this);
//    button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
//    button->setToolButtonStyle(Qt::ToolButtonTextOnly);
//    button->setPopupMode(QToolButton::InstantPopup);

    MenuAccessButton *button = new MenuAccessButton(this);
    connect(tb, &TinyTabBar::orientationChanged, button, &MenuAccessButton::setOrientation);
    connect(tb, &TinyTabBar::toolButtonStyleChanged, button, &MenuAccessButton::setToolButtonStyle);

    tb->addWidget(button);

    QMenu *menu = new QMenu(this);
    button->setMenu(menu);
    QActionGroup *actGroup = new QActionGroup(this);
    actGroup->setExclusive(true);

    QAction *act = new QAction(tr("ToolButtonTextOnly"), this);
    act->setCheckable(true);
    connect(act, &QAction::triggered, this, [tb, button]() {
        tb->setTabStyle(Qt::ToolButtonTextOnly);
        qDebug() << button->toolButtonStyle();
        tb->layout()->setSpacing(2);
    });
    menu->addAction(act);
    actGroup->addAction(act);
    act = new QAction(tr("ToolButtonIconOnly"), this);
    act->setCheckable(true);
    connect(act, &QAction::triggered, this, [tb, button]() {
        tb->setTabStyle(Qt::ToolButtonIconOnly);
        qDebug() << button->toolButtonStyle();
        tb->layout()->setSpacing(0);
    });
    menu->addAction(act);
    actGroup->addAction(act);

    // TinyNavBar
    TinyNavBar *nb = new TinyNavBar(this);
    nb->layout()->setSpacing(2);
    nb->addTab(tr("nav1"));
    nb->addTab(tr("nav2"));
    nb->addTab(tr("nav3"));
    nb->addTab(tr("nav4"));
    nb->addTab(tr("nav5"));
    nb->removeTab(3);
    nb->insertTab(2, tr("navN"));
    nb->setTabVisible(3, false);
//    addToolBar(Qt::BottomToolBarArea, nb);
    QStatusBar *sb = statusBar();
    sb->addWidget(nb);

    setWindowTitle(tr("TinyTabBar Example"));
    setWindowIcon(icon);
    resize(400, 200);
}

MainWindow::~MainWindow()
{
}
