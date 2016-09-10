#ifndef USERDATA_H
#define USERDATA_H

#include <QDialog>

namespace Ui 
{
class UserData;
}

class UserData : public QDialog
{
    Q_OBJECT
    
public:
    explicit UserData(QWidget *parent = 0);
    ~UserData();
    
private slots:
    void on_buttonBox_accepted();
    
private:
    Ui::UserData *ui;
};

#endif // USERDATA_H
