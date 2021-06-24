/********************************************************************************
** Form generated from reading UI file 'FinalCodewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALCODEWIDGET_H
#define UI_FINALCODEWIDGET_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *CodeTyping;
    QPushButton *checkButton;
    QFrame *StateFrame;
    QLabel *Bomblabel;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Typinglabel_2;
    QLineEdit *lineEdit_2;
    QLabel *Typinglabel_1;
    QLineEdit *lineEdit_1;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QFrame *HintFrame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Hintlabel;
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
        Widget->setInputMethodHints(Qt::ImhNone);
        CodeTyping = new QGroupBox(Widget);
        CodeTyping->setObjectName(QString::fromUtf8("CodeTyping"));
        CodeTyping->setGeometry(QRect(80, 200, 351, 271));
        checkButton = new QPushButton(CodeTyping);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));
        checkButton->setEnabled(true);
        checkButton->setGeometry(QRect(120, 230, 121, 20));
        checkButton->setCursor(QCursor(Qt::PointingHandCursor));
        checkButton->setFocusPolicy(Qt::TabFocus);
        checkButton->setAutoDefault(false);
        checkButton->setFlat(false);
        StateFrame = new QFrame(CodeTyping);
        StateFrame->setObjectName(QString::fromUtf8("StateFrame"));
        StateFrame->setGeometry(QRect(200, 110, 131, 101));
        StateFrame->setFrameShape(QFrame::NoFrame);
        StateFrame->setFrameShadow(QFrame::Raised);
        Bomblabel = new QLabel(StateFrame);
        Bomblabel->setObjectName(QString::fromUtf8("Bomblabel"));
        Bomblabel->setEnabled(true);
        Bomblabel->setGeometry(QRect(10, 0, 111, 101));
        Bomblabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Bomblabel->setWordWrap(false);
        formLayoutWidget = new QWidget(CodeTyping);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 110, 172, 102));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(3);
        formLayout->setVerticalSpacing(3);
        formLayout->setContentsMargins(0, 0, 0, 0);
        Typinglabel_2 = new QLabel(formLayoutWidget);
        Typinglabel_2->setObjectName(QString::fromUtf8("Typinglabel_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Typinglabel_2);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setFocusPolicy(Qt::StrongFocus);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setClearButtonEnabled(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_2);

        Typinglabel_1 = new QLabel(formLayoutWidget);
        Typinglabel_1->setObjectName(QString::fromUtf8("Typinglabel_1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Typinglabel_1);

        lineEdit_1 = new QLineEdit(formLayoutWidget);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));
        lineEdit_1->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_1->sizePolicy().hasHeightForWidth());
        lineEdit_1->setSizePolicy(sizePolicy);
        lineEdit_1->setMouseTracking(false);
        lineEdit_1->setFocusPolicy(Qt::StrongFocus);
        lineEdit_1->setLayoutDirection(Qt::LeftToRight);
        lineEdit_1->setAutoFillBackground(false);
        lineEdit_1->setAlignment(Qt::AlignCenter);
        lineEdit_1->setDragEnabled(false);
        lineEdit_1->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_1->setClearButtonEnabled(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(3, QFormLayout::FieldRole, horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(0, QFormLayout::FieldRole, horizontalSpacer);

        HintFrame = new QFrame(CodeTyping);
        HintFrame->setObjectName(QString::fromUtf8("HintFrame"));
        HintFrame->setGeometry(QRect(20, 30, 311, 71));
        HintFrame->setFrameShape(QFrame::StyledPanel);
        HintFrame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(HintFrame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 311, 71));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Hintlabel = new QLabel(verticalLayoutWidget);
        Hintlabel->setObjectName(QString::fromUtf8("Hintlabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Hintlabel->sizePolicy().hasHeightForWidth());
        Hintlabel->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(Hintlabel);

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
        groupBox->setGeometry(QRect(480, 200, 129, 271));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setCursor(QCursor(Qt::IBeamCursor));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        RemaininglistView = new QListView(groupBox);
        RemaininglistView->setObjectName(QString::fromUtf8("RemaininglistView"));
        RemaininglistView->setEnabled(true);
        RemaininglistView->setGeometry(QRect(0, 20, 129, 251));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(RemaininglistView->sizePolicy().hasHeightForWidth());
        RemaininglistView->setSizePolicy(sizePolicy3);
        RemaininglistView->setFocusPolicy(Qt::NoFocus);
        RemaininglistView->setAutoFillBackground(false);
        RemaininglistView->setInputMethodHints(Qt::ImhNone);
        RemaininglistView->setEditTriggers(QAbstractItemView::NoEditTriggers);
#ifndef QT_NO_SHORTCUT
        Typinglabel_2->setBuddy(lineEdit_2);
        Typinglabel_1->setBuddy(lineEdit_1);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEdit_1, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, checkButton);

        retranslateUi(Widget);

        checkButton->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "FinalCode!!", nullptr));
        CodeTyping->setTitle(QApplication::translate("Widget", "Code Typing", nullptr));
        checkButton->setText(QApplication::translate("Widget", "click", nullptr));
        Bomblabel->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/new/label/img/bomb.png\"/></p></body></html>", nullptr));
        Typinglabel_2->setText(QApplication::translate("Widget", "2nd Number", nullptr));
        Typinglabel_1->setText(QApplication::translate("Widget", "1st Number", nullptr));
        lineEdit_1->setText(QString());
        Hintlabel->setText(QApplication::translate("Widget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        Signlabel->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/new/label/img/FinnalCodeStart.png\"/></p></body></html>", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "Remaining Stores", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALCODEWIDGET_H
