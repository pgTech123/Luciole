#include "logdialog.h"
#include "ui_logdialog.h"

LogDialog::LogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogDialog)
{
    ui->setupUi(this);
    connect(ui->pushButtonRefresh, SIGNAL(clicked(bool)), this, SLOT(refresh(bool)));
}

LogDialog::~LogDialog()
{
    delete ui;
}

void LogDialog::setLogMaster(Logs* logs)
{
    m_logs = logs;
}

// Assuming that m_logs is always set before this call.
void LogDialog::refresh()
{
    ui->textBrowser->clear();
    QString logs = m_logs->getText();
    ui->textBrowser->setText(logs);
}

void LogDialog::refresh(bool)
{
    refresh();
}
