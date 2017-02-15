#ifndef MAINWINDOW_H
#define  MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QGroupBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>

class MainWindow : public QWidget {

  Q_OBJECT

  public:
    MainWindow();
    ~MainWindow();

  private slots:
    void generateCode();

  private:
    QLineEdit *m_name;
    QLineEdit *m_superclass;
    QCheckBox *m_protection;
    QCheckBox *m_generateConstructor;
    QCheckBox *m_generateDestructor;
    QGroupBox *m_addComments;
    QLineEdit *m_author;
    QDateEdit *m_date;
    QTextEdit *m_role;
    QPushButton *m_generateButton;
    QPushButton *m_quitButton;

};

#endif
