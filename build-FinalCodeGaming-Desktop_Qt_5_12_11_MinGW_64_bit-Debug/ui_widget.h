/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QUndoView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *CodeTyping;
    QPushButton *pushButton;
    QUndoView *TypingHint;
    QFrame *StateFrame;
    QLabel *label_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Typinglabel_1;
    QLineEdit *lineEdit_1;
    QLabel *Typinglabel_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progressBar;
    QFrame *frame;
    QLabel *Signlabel;
    QGroupBox *groupBox;
    QListView *RemaininglistView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->setEnabled(true);
        Widget->resize(700, 500);
        Widget->setMouseTracking(false);
        Widget->setTabletTracking(false);
        CodeTyping = new QGroupBox(Widget);
        CodeTyping->setObjectName(QString::fromUtf8("CodeTyping"));
        CodeTyping->setGeometry(QRect(80, 200, 321, 251));
        pushButton = new QPushButton(CodeTyping);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(110, 210, 121, 20));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        TypingHint = new QUndoView(CodeTyping);
        TypingHint->setObjectName(QString::fromUtf8("TypingHint"));
        TypingHint->setGeometry(QRect(20, 30, 281, 41));
        TypingHint->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        TypingHint->setInputMethodHints(Qt::ImhPreferUppercase);
        TypingHint->setFrameShape(QFrame::Box);
        TypingHint->setFrameShadow(QFrame::Sunken);
        StateFrame = new QFrame(CodeTyping);
        StateFrame->setObjectName(QString::fromUtf8("StateFrame"));
        StateFrame->setGeometry(QRect(170, 90, 131, 101));
        StateFrame->setFrameShape(QFrame::NoFrame);
        StateFrame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(StateFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(10, 0, 111, 101));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2->setWordWrap(false);
        formLayoutWidget = new QWidget(CodeTyping);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 90, 141, 102));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(3);
        formLayout->setVerticalSpacing(3);
        formLayout->setContentsMargins(0, 0, 0, 0);
        Typinglabel_1 = new QLabel(formLayoutWidget);
        Typinglabel_1->setObjectName(QString::fromUtf8("Typinglabel_1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Typinglabel_1);

        lineEdit_1 = new QLineEdit(formLayoutWidget);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));
        lineEdit_1->setEnabled(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_1);

        Typinglabel_2 = new QLabel(formLayoutWidget);
        Typinglabel_2->setObjectName(QString::fromUtf8("Typinglabel_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Typinglabel_2);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setTabletTracking(true);
        lineEdit_2->setClearButtonEnabled(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(2, QFormLayout::SpanningRole, horizontalSpacer);

        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(false);
        progressBar->setGeometry(QRect(80, 20, 531, 23));
        progressBar->setValue(26);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setInvertedAppearance(false);
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(80, 60, 531, 121));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        Signlabel = new QLabel(frame);
        Signlabel->setObjectName(QString::fromUtf8("Signlabel"));
        Signlabel->setGeometry(QRect(0, 0, 531, 121));
        Signlabel->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(480, 200, 129, 249));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setCursor(QCursor(Qt::IBeamCursor));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        RemaininglistView = new QListView(groupBox);
        RemaininglistView->setObjectName(QString::fromUtf8("RemaininglistView"));
        RemaininglistView->setEnabled(true);
        RemaininglistView->setGeometry(QRect(0, 20, 129, 228));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(RemaininglistView->sizePolicy().hasHeightForWidth());
        RemaininglistView->setSizePolicy(sizePolicy1);
#ifndef QT_NO_SHORTCUT
        Typinglabel_1->setBuddy(lineEdit_1);
        Typinglabel_2->setBuddy(lineEdit_2);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEdit_1, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, pushButton);
        QWidget::setTabOrder(pushButton, RemaininglistView);
        QWidget::setTabOrder(RemaininglistView, TypingHint);

        retranslateUi(Widget);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "FinalCode!!", nullptr));
        CodeTyping->setTitle(QApplication::translate("Widget", "Code Typing", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\347\242\272\345\256\232", nullptr));
        label_2->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/new/label/img/bomb.png\"/></p></body></html>", nullptr));
        Typinglabel_1->setText(QApplication::translate("Widget", "1st Number", nullptr));
        lineEdit_1->setText(QString());
        Typinglabel_2->setText(QApplication::translate("Widget", "2nd Number", nullptr));
        Signlabel->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/new/label/img/FinnalCodeStart.png\"/></p></body></html>", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "Remaining Stores", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
