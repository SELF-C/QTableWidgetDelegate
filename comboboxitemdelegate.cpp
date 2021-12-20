#include "comboboxitemdelegate.h"

ComboBoxItemDelegate::ComboBoxItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *ComboBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Create the combobox and populate it
    auto combobox = new QComboBox(parent);

    combobox->addItem(QString("one"));
    combobox->addItem(QString("two"));
    combobox->addItem(QString("three"));
    return combobox;
}


void ComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    auto combobox = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(combobox);

    const QString currentText = index.data(Qt::EditRole).toString();
    const int cbIndex = combobox->findText(currentText);

    if (cbIndex >= 0)
       combobox->setCurrentIndex(cbIndex);
}


void ComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *combobox = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(combobox);
    model->setData(index, combobox->currentText(), Qt::EditRole);
}
