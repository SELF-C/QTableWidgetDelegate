#ifndef SPINBOXITEMDELEGATE_H
#define SPINBOXITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QSpinBox>

class SpinBoxItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    SpinBoxItemDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
};


#endif // SPINBOXITEMDELEGATE_H
