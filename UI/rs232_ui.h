#ifndef RS232_UI_H
#define RS232_UI_H

#include <QDialog>

namespace Ui {
class Rs232_ui;
}

class Rs232_ui : public QDialog
{
    Q_OBJECT

public:
    explicit Rs232_ui(QWidget *parent = 0);
    ~Rs232_ui();

private:
    Ui::Rs232_ui *ui;
};

#endif // RS232_UI_H
