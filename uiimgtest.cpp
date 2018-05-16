#include "uiimgtest.h"
#include "ui_uiimgtest.h"

UIImgTest::UIImgTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIImgTest)
{
    ui->setupUi(this);
    this->showMaximized();

    myMap = new MapCanvas( this );
    myMap->setMinimumSize( 1024, 768 );
    this->setCentralWidget( myMap );

    ui->tableView->setModel( myMap->ImgMetaModel() );// 初始化图像元数据模型
    ui->tableView->setEditTriggers( QAbstractItemView::NoEditTriggers );
    ui->fileTreeView->setModel( myMap->FileListModel() );// 初始化文件列表
    ui->fileTreeView->setEditTriggers( QAbstractItemView::NoEditTriggers );
    // 连接信号、槽
    connect( ui->actionAbout, SIGNAL( triggered() ), qApp, SLOT( aboutQt() ) );
    connect( ui->actionImage, SIGNAL( triggered() ), this, SLOT( PickOpenFile() ) );
    connect( ui->actionExit, SIGNAL( triggered() ), this, SLOT( Exit() ) );
    connect( ui->actionFile_List, SIGNAL( triggered() ), this, SLOT( ShowFileListWindow() ) );
    connect( ui->actionInformation, SIGNAL( triggered() ), this, SLOT( ShowInforWindow() ) );
    connect( ui->actionZoom_Int, SIGNAL( triggered() ), this->myMap, SLOT( ZoomIn() ) );
    connect( ui->actionZoom_Out, SIGNAL( triggered() ), this->myMap, SLOT( ZoomOut() ) );

}

UIImgTest::~UIImgTest()
{
    delete ui;
}

/// <summary>
/// 退出
/// </summary>
void UIImgTest::Exit()
{
    this->close();
}

/// <summary>
/// 选择文件
/// </summary>
void UIImgTest::PickOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(
                           this,
                           tr( "Pick a image file to open..." ),
                           QDir::currentPath(),
                           tr( "jpg(*.jpg);;tiff(*.tif);;img(*.img);;All files(*.*)" ) );
    if ( !fileName.isNull() )
    {
        myMap->ReadImg( fileName );
    }
    ui->fileTreeView->expandAll();
}

/// <summary>
/// Shows the file list window
/// </summary>
void UIImgTest::ShowFileListWindow()
{
    ui->FileListDockWidget->toggleViewAction();
}

/// <summary>
/// Shows the information window.
/// </summary>
void UIImgTest::ShowInforWindow()
{
    ui->infoDockWidget->toggleViewAction();
}
