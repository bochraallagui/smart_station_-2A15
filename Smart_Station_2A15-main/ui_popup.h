/********************************************************************************
** Form generated from reading UI file 'popup.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP_H
#define UI_POPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Popup
{
public:
    QGridLayout *gridLayout;
    QLabel *title;
    QPushButton *button;
    QLabel *description;

    void setupUi(QDialog *Popup)
    {
        if (Popup->objectName().isEmpty())
            Popup->setObjectName(QStringLiteral("Popup"));
        Popup->resize(200, 70);
        gridLayout = new QGridLayout(Popup);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        title = new QLabel(Popup);
        title->setObjectName(QStringLiteral("title"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);

        gridLayout->addWidget(title, 0, 0, 1, 1);

        button = new QPushButton(Popup);
        button->setObjectName(QStringLiteral("button"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button->sizePolicy().hasHeightForWidth());
        button->setSizePolicy(sizePolicy1);
        button->setFlat(true);

        gridLayout->addWidget(button, 0, 1, 1, 1);

        description = new QLabel(Popup);
        description->setObjectName(QStringLiteral("description"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy2);
        description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(description, 1, 0, 1, 2);


        retranslateUi(Popup);

        QMetaObject::connectSlotsByName(Popup);
    } // setupUi

    void retranslateUi(QDialog *Popup)
    {
        Popup->setWindowTitle(QApplication::translate("Popup", "Popup", Q_NULLPTR));
        title->setText(QApplication::translate("Popup", "Title", Q_NULLPTR));
        button->setText(QApplication::translate("Popup", "\303\227", Q_NULLPTR));
        description->setText(QApplication::translate("Popup", "Body", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Popup: public Ui_Popup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP_H
