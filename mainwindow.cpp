#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>

#include "comboboxitemdelegate.h"
#include "spinboxitemdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // main widget init
    auto groupbox = new QGroupBox("QGroupBox", this);
    auto layout = new QVBoxLayout(groupbox);
    groupbox->setLayout(layout);
    groupbox->setStyleSheet("QGroupBox {"
                            "background-color: white;"
                            "}"
                            "QGroupBox::title {"
                            "color: white;"
                            "background-color:#424242;"
                            "padding: 4 20000 4 10;"
                            "}");

    // table init
    auto tw = new QTableWidget(groupbox);
    auto comboBoxDelegate = new ComboBoxItemDelegate(tw);
    auto spinBoxDelegate = new SpinBoxItemDelegate(tw);

    tw->setColumnCount( 4 );
    tw->setRowCount( 10 );
    tw->setItemDelegateForColumn(0, spinBoxDelegate);
    tw->setItemDelegateForColumn(1, comboBoxDelegate);
    tw->setItemDelegateForColumn(2, spinBoxDelegate);

    tw->setHorizontalHeaderLabels( QStringList() << tr("QSpinBox") << tr("QComboBox" ) << tr("QSpinBox") << tr("QString") );
    tw->horizontalHeader()->setStretchLastSection(true);

    tw->setItem( 0, 1,  new QTableWidgetItem("one"));

    auto hlayout = new QHBoxLayout(groupbox);
    hlayout->addWidget(new QPushButton("btn1"));
    hlayout->addWidget(new QPushButton("btn2"));

    layout->addWidget(tw);
    layout->addLayout(hlayout);

    layout->setContentsMargins( 0, 7, 0, 0);
    this->setCentralWidget(groupbox);

}

MainWindow::~MainWindow()
{
    delete ui;
}

