#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <vector>
#include <QWidget>
#include <QStringListModel>
#include <QListView>
#include <QProgressBar>
#include <QLabel>
#include <QImage>
#include "ui_FinalCodewidget.h"
#include "fcmediator.h"

FcMediator::FcMediator()
{
}

void FcMediator::regRemainlistview(QListView *lv)
{
    if(lv==nullptr)
        return;
    mRemainlistview = lv;
}

void FcMediator::regBomblabel(QLabel *bl)
{
    if(bl == nullptr)
        return;
    mBomblabel = bl;
}

void FcMediator::regHintlabel(QLabel *hl)
{
    if(hl == nullptr)
        return;
    mHintlabel = hl;
}

void FcMediator::regSignLabel(QLabel *sl)
{
    if(sl == nullptr)
        return;
    mSignlabel = sl;
}

void FcMediator::regProgress(QProgressBar *pb)
{
    if(pb == nullptr)
        return;
    mProgress = pb;
}


void FcMediator::validHandler(int inf, int sup, int progress, QStringList &remains)
{
    QImage Bombimg(":/new/label/img/bomb.png");
    QImage Signimg(":/new/label/img/FinnalCodeStart.png");
    QStringListModel *lvmodel = new QStringListModel(remains);
    QAbstractItemModel *m = mRemainlistview->model();

    mHintlabel->setText(QString("請輸入區間在 [%1, %2] 兩個不同的數字").arg(inf).arg(sup));
    mBomblabel->setPixmap(QPixmap::fromImage(Bombimg));
    mSignlabel->setPixmap(QPixmap::fromImage(Signimg));

    mRemainlistview->setModel(lvmodel);
    delete m;

    mProgress->setValue(progress);

}

void FcMediator::invalidHandler(int inf, int sup)
{
    QImage Signimg(":/new/label/img/WrongTyping.png");

    mHintlabel->setText(QString("格式錯誤，請依照格式重新輸入。\n請輸入區間在 [%1, %2] 兩個不同的數字").arg(inf).arg(sup));
    mSignlabel->setPixmap(QPixmap::fromImage(Signimg));
}

void FcMediator::NoneHandler(int inf, int sup)
{
    QImage Signimg(":/new/label/img/None.png");

    mHintlabel->setText(QString("Miss! 請輸入新的一組數字。\n請輸入區間在 [%1, %2] 兩個不同的數字").arg(inf).arg(sup));
    mSignlabel->setPixmap(QPixmap::fromImage(Signimg));
}

FcSignal FcMediator::EndHandler(int progress, QString &final, int code)
{
    QImage Bombimg(":/new/label/img/boom.png");
    QImage Signimg(":/new/label/img/GameOver.png");

    mBomblabel->setPixmap(QPixmap::fromImage(Bombimg));
    mSignlabel->setPixmap(QPixmap::fromImage(Signimg));
    mProgress->setValue(progress);
    QAbstractItemModel *m = mRemainlistview->model();
    delete m;

    QMessageBox EndMsg;
    EndMsg.setText(QString("恭喜您的下一餐是： 【%1】\n Samuel's Lucky Code: 【%2】").arg(final).arg(code));
    EndMsg.setInformativeText("不滿意這個結果嗎，\n是否要重新開始？");
    QPushButton *replaybtn = EndMsg.addButton(QString("重新開始"), QMessageBox::ActionRole);
    QPushButton *savebtn = EndMsg.addButton(QString("我很滿意"), QMessageBox::ActionRole);

    EndMsg.setDefaultButton(savebtn);
    EndMsg.exec();


    if(EndMsg.clickedButton() == replaybtn)
    {
        // Refresh and Replay
        return FcSignal::Replay;
    } else if(EndMsg.clickedButton() == savebtn)
    {
        // Close the Widget and save the result in Store.txt
        /* 複寫給host
        QFile file("src/Store.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return FcSignal::Replay;
        }
        QTextStream out(&file);

        out.setCodec("UTF-8");
        out << final;


        file.close();
        */

        return FcSignal::Over;
    } else
        return FcSignal::Replay;
}

FcMediator::~FcMediator()
{
    delete mRemainlistview;
    delete mBomblabel;
    delete mSignlabel;
    delete mHintlabel;
    delete mProgress;
}
