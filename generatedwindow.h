#ifndef GENERATEDWINDOW_H
#define  GENERATEDWINDOW_H

#include <QApplication>
#include <QDialog>
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

class GeneratedWindow : public QDialog {

  Q_OBJECT

  public:
    GeneratedWindow(QString &code, QWidget *parent);
    ~GeneratedWindow();

  private:
    QTextEdit *m_generatedCode;
    QPushButton *m_closeButton;

};

#endif
