#include "mainwindow.h"

#include <QGroupBox>
#include <QFormLayout>
#include <QBoxLayout>

MainWindow::MainWindow() {
  // Creation of the class definition box
  QGroupBox *classDefinition = new QGroupBox("Class definition");
  m_name = new QLineEdit;
  m_superclass = new QLineEdit;

  QFormLayout *formLayout1 = new QFormLayout;
  formLayout1->addRow("Name:", m_name);
  formLayout1->addRow("Superclass:", m_superclass);

  classDefinition->setLayout(formLayout1);

  // Creation of the options box
  QGroupBox *options = new QGroupBox("Options");
  m_protection = new QCheckBox;
  m_protection->setChecked(true);
  m_generateConstructor = new QCheckBox;
  m_generateConstructor->setChecked(true);
  m_generateDestructor = new QCheckBox;

  QFormLayout *formLayout2 = new QFormLayout;
  formLayout2->addRow("Protect the header from multiple inclusions", m_protection);
  formLayout2->addRow("Generate a default constructor", m_generateConstructor);
  formLayout2->addRow("Generate a destructor", m_generateDestructor);

  options->setLayout(formLayout2);

  // Creation of the comments box which is facultative
  QGroupBox *comments = new QGroupBox("Add comments");
  comments->setCheckable(true);

  m_author = new QLineEdit;
  m_date = new QDateEdit(QDate::currentDate());
  m_role = new QTextEdit;

  QFormLayout *formLayout3 = new QFormLayout;
  formLayout3->addRow("Author:", m_author);
  formLayout3->addRow("Creation date:", m_date);
  formLayout3->addRow("Class role:", m_role);

  comments->setLayout(formLayout3);


  // Creation of quit and generate buttons
  m_generateButton = new QPushButton("Generate");
  m_generateButton->setFixedSize(80,30);
  m_quitButton = new QPushButton("Quit");
  m_quitButton->setFixedSize(80,30);

  QHBoxLayout *layout4 = new QHBoxLayout;
  layout4->addStretch(1);
  layout4->addWidget(m_generateButton);
  layout4->addWidget(m_quitButton);

  // Bind all widgets
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(classDefinition);
  layout->addWidget(options);
  layout->addWidget(comments);
  layout->addLayout(layout4, Qt::AlignCenter);

  setLayout(layout);

  connect(m_generateButton, SIGNAL(clicked()), this, SLOT(generateCode()));
  connect(m_quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

MainWindow::~MainWindow() {
  delete m_name;
  delete m_superclass;
  delete m_protection;
  delete m_generateConstructor;
  delete m_generateDestructor;
  delete m_author;
  delete m_date;
  delete m_role;
  delete m_generateButton;
  delete m_quitButton;
}

void MainWindow::generateCode() {

}
