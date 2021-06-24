#include <QTextStream>
#include <QFile>
#include <QStringListModel>
#include <QMessageBox>
#include <QFileDialog>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "FinalCodewidget.h"
#include "ui_FinalCodewidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    //, fc(new FinalCode(QString(":/new/src/srcfile/Store.txt"))) /*debug phase*/
    , fc(new FinalCode(QString("src/Store.txt")))
{
    ui->setupUi(this);

    FcMediator *fcm = new FcMediator();
    fcm->regRemainlistview(ui->RemaininglistView);
    fcm->regBomblabel(ui->Bomblabel);
    fcm->regSignLabel(ui->Signlabel);
    fcm->regHintlabel(ui->Hintlabel);
    fcm->regProgress(ui->progressBar);

    fc->setMediator(fcm);

    ui->lineEdit_1->setValidator(new QIntValidator(ui->lineEdit_1));
    ui->lineEdit_2->setValidator(new QIntValidator(ui->lineEdit_2));
    QStringListModel *model = new QStringListModel(fc->Stores());
    ui->RemaininglistView->setModel(model);
    ui->progressBar->setMaximum(fc->get_size());
    ui->progressBar->setValue(0);

    ////////Test////////
    ui->Hintlabel->setText(
                QString("歡迎來到【終極密碼】~\n") +
                QString("在這個遊戲中，您將不斷地猜出您的最終密碼，右側列表是\n") +
                QString("您每次抉擇後剩下的結果，最後存留的店家將是留給您的最\n") +
                QString("佳選擇。讓我們開始吧！\n") +
                QString("請輸入區間在 [%1, %2] 兩個不同的數字：").arg(fc->get_inf()).arg(fc->get_sup())
                );

    ////////Test////////
    connect(ui->checkButton, &QPushButton::clicked, this, &Widget::playFC);
}

void Widget::playFC()
{
    int a, b;
    bool ok_a, ok_b;
    FcSignal fc_stat;

    a = ui->lineEdit_1->text().toInt(&ok_a);
    b = ui->lineEdit_2->text().toInt(&ok_b);

    if(ok_a && ok_b)
    {
        fc_stat = fc->play(a, b);
    } else
        fc_stat = FcSignal::Continue;

    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();

    replayFC(fc_stat);
}

void Widget::replayFC(FcSignal fc_stat)
{
    QStringListModel *lvmodel;
    QAbstractItemModel *m;
    QImage *Bombimg;
    QImage *Signimg;

    switch (fc_stat) {
    case FcSignal::Replay:
        // refresh
        fc->refresh();
        Bombimg = new QImage(":/new/label/img/bomb.png");
        Signimg = new QImage(":/new/label/img/FinnalCodeStart.png");
        lvmodel = new QStringListModel(fc->Remains());
        m = ui->RemaininglistView->model();

        ui->Hintlabel->setText(QString("請輸入區間在 [%1, %2] 兩個不同的數字").arg(fc->get_inf()).arg(fc->get_sup()));
        ui->Bomblabel->setPixmap(QPixmap::fromImage(*Bombimg));
        ui->Signlabel->setPixmap(QPixmap::fromImage(*Signimg));

        ui->RemaininglistView->setModel(lvmodel);
        delete m;

        ui->progressBar->setValue(0);
        break;

    case FcSignal::Over:
        // Close Widget;
        this->close();
        break;
    default:
        break;
    }
}

Widget::~Widget()
{
    delete ui;
    delete fc;
}


FinalCode::FinalCode(QString filename)
{
    QFile file(filename);
    QString store;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");
    while(!in.atEnd())
    {
        store = in.readLine();
        mStores << store;
    }
    file.close();

    n_store = mStores.size();
    sup = (ceil(n_store / 100) + 1) * 100;
    inf = 0;

    mRemains = mStores;
    mStoreNo = std::vector<int>();
}

QStringList FinalCode::Stores() const
{
    return mStores;
}

QStringList FinalCode::Remains() const
{
    return mRemains;
}

void FinalCode::setMediator(FcMediator *m)
{
    if(m == nullptr)
        return;
    med = m;
}

FcMediator* FinalCode::getMediator()
{
    return med;
}

int FinalCode::get_inf() const
{
    return inf;
}

int FinalCode::get_sup() const
{
    return sup;
}

int FinalCode::get_size() const
{
    return n_store;
}

bool FinalCode::refresh()
{
    if (mStores.empty())
    {
        return false;
    }
    n_store = mStores.size();
    sup = (ceil(n_store / 100) + 1) * 100;
    inf = 0;
    mStoreNo = std::vector<int>();
    mRemains = mStores;

    return true;
}

FcSignal FinalCode::play(int a, int b)
{
    std::vector<int> buffer;
    bool is_existed = false;

    srand(time(NULL));

    if(mStoreNo.empty())
        mStoreNo = randIdx();

    if(mRemains.size() > 1)
    {
        // check the order of a, b
        if(a > b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }

        if((a==b) || (a < inf) || (b > sup))
        {
            // address Invalid()
            med->invalidHandler(inf, sup);
            return FcSignal::Continue;
        }

        is_existed = false;
        buffer = mStoreNo;
        for(int i=0; i < mRemains.size(); ++i)
        {
            if((mStoreNo[i] >= a) && (mStoreNo[i] < b))
                is_existed = true;
            else
                buffer[i] = 0;
        }

        if(!is_existed)
        {
            // address None()
            med->NoneHandler(inf, sup);
            return FcSignal::Continue;
        }

        for(int i = buffer.size()-1; i >= 0; --i)
        {
            if(buffer[i] == 0)
            {
                mRemains.erase(mRemains.begin() + i);
                mStoreNo.erase(mStoreNo.begin() + i);
            }
        }

        inf = a;
        sup = b;

        if(mRemains.size() == 1)
        {
            return med->EndHandler(n_store, mRemains.front(), mStoreNo.front());
        }
        med->validHandler(inf, sup, n_store-mRemains.size(), mRemains);
        return FcSignal::Continue;
    } else
        return med->EndHandler(n_store, mRemains.front(), mStoreNo.front());
}

std::vector<int> FinalCode::randIdx()
{
    std::vector<int> myIdx(n_store, 0);
    bool is_used;

    for (int i = 0; i < n_store; i++)
    {
        do
        {
            is_used = false;
            myIdx[i] = rand() % sup;
            for (int j = 0; j < i; j++)
            {
                if(myIdx[i] == myIdx[j])
                {
                    is_used = true;
                    break;
                }
            }
        }
        while (is_used);
    }

    return myIdx;
}

FinalCode::~FinalCode()
{
    delete med;
}
