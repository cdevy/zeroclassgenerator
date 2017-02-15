#include "generatedwindow.h"

#include <QBoxLayout>

GeneratedWindow::GeneratedWindow(QString &code, QWidget *parent) : QDialog(parent) {
  setWindowTitle("Zero Class Generator");

  m_generatedCode = new QTextEdit();
  m_generatedCode->setPlainText(code);
  m_generatedCode->setReadOnly(true);
  m_generatedCode->setFont(QFont("Courier"));
  m_generatedCode->setLineWrapMode(QTextEdit::NoWrap);

  m_closeButton = new QPushButton("Close");
  m_closeButton->setFixedSize(80,30);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(m_generatedCode);
  layout->addWidget(m_closeButton);
  resize(500, 450);

  setLayout(layout);

  connect(m_closeButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

GeneratedWindow::~GeneratedWindow() {
  delete m_closeButton;
}
