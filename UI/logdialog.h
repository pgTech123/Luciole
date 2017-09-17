#ifndef LOGDIALOG_H
#define LOGDIALOG_H

#include <QDialog>
#include <QString>
#include <logs.h>

namespace Ui {
class LogDialog;
}

class LogDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogDialog(QWidget *parent = 0);
    ~LogDialog();

    void setLogMaster(Logs* logs);
    void refresh();

private slots:
    void refresh(bool);

private:
    Ui::LogDialog *ui;

    Logs *m_logs;
};

#endif // LOGDIALOG_H
