#ifndef L1_H
#define L1_H

#include <QMainWindow>
#include <QTreeWidgetItem>

namespace Ui {
class L1;
}

class L1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit L1(QWidget *parent = nullptr);
    ~L1();

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_2_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::L1 *ui;
};

#endif // L1_H
