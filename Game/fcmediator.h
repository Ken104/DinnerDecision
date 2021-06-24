#ifndef FCMEDIATOR_H
#define FCMEDIATOR_H
#include <QWidget>
#include <QStringListModel>
#include <QListView>
#include <QProgressBar>
#include <QLabel>

#ifndef FINALCODEWIDGET_H
#define FINALCODEWIDGET_H
#include "FinalCode.h"
#endif

enum class FcSignal
{
    Over = 0,
    Continue = 1,
    Replay = 2
};

class FcMediator
{
public:
    FcMediator();
    void validHandler(int inf, int sup, int pregress, QStringList&);
    void invalidHandler(int inf, int sup);
    void NoneHandler(int inf, int sup);
    FcSignal EndHandler(int progress, QString&, int);

    void regRemainlistview(QListView*);
    void regBomblabel(QLabel*);
    void regSignLabel(QLabel*);
    void regHintlabel(QLabel*);
    void regProgress(QProgressBar*);
    ~FcMediator();

private:
    QListView *mRemainlistview;
    QLabel *mBomblabel;
    QLabel *mSignlabel;
    QLabel *mHintlabel;
    QProgressBar *mProgress;
};

#endif // FCMEDIATOR_H

