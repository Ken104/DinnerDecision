#ifndef FINALCODEWIDGET_H
#define FINALCODEWIDGET_H

#include <QWidget>
#include <QStringList>
#include <QStringListModel>
#include "fcmediator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget;}
QT_END_NAMESPACE

class FinalCode;


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void playFC();

private:
    void replayFC(FcSignal);

private:
    Ui::Widget *ui;
    FinalCode *fc;
};

class FinalCode
{
private:
    FcMediator *med;
    QStringList mStores;
    QStringList mRemains;
    std::vector<int> mStoreNo;
    int sup;
    int n_store;
    int inf;

public:
    FinalCode(QString);
    ~FinalCode();
    QStringList Stores() const;
    QStringList Remains() const;
    void setMediator(FcMediator*);
    FcMediator* getMediator();
    int get_sup() const;
    int get_inf() const;
    int get_size() const;
    std::vector<int> randIdx();
    FcSignal play(int, int);
    bool refresh();
};



#endif // FINALCODEWIDGET_H
