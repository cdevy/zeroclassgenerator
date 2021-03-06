#include "mainwindow.h"
#include "generatedwindow.h"

#include <QFormLayout>
#include <QBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow() {
  setWindowTitle("Zero Class Generator");

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
  m_addComments = new QGroupBox("Add comments");
  m_addComments->setCheckable(true);

  m_author = new QLineEdit;
  m_date = new QDateEdit(QDate::currentDate());
  m_role = new QTextEdit;

  QFormLayout *formLayout3 = new QFormLayout;
  formLayout3->addRow("Author:", m_author);
  formLayout3->addRow("Creation date:", m_date);
  formLayout3->addRow("Class role:", m_role);

  m_addComments->setLayout(formLayout3);

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
  layout->addWidget(m_addComments);
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
  delete m_addComments;
  delete m_generateButton;
  delete m_quitButton;
}

void MainWindow::generateCode() {
  if (m_name->text().isEmpty()) {
    QMessageBox::critical(this, "Error", "Please enter a class name");
    return;
  }

  QString code;

  if (m_addComments->isChecked()) {
    if (!m_author->text().isEmpty()) {
      code += "/*\nAuthor: " + m_author->text() + "\n";
    } else {
      code += "/*\nAuthor: unknown" + m_author->text() + "\n";
    }

    code += "Creation date: " + m_date->date().toString(Qt::ISODate) + "\n";

    if (!m_role->toPlainText().isEmpty()) {
      code += "Role:\n" + m_role->toPlainText() + "\n";
    }
    code += "*/\n\n";
  }

  if (m_protection->isChecked()) {
    code += "#ifndef " + m_name->text().toUpper() + "_H\n";
    code += "#define " + m_name->text().toUpper() + "_H\n\n";
  }

  code += "class " + m_name->text();

  if (!m_superclass->text().isEmpty()) {
    code += " : public " + m_superclass->text();
  }

  code += " {\n\n\tpublic:\n";

  if (m_generateConstructor->isChecked()) {
    code += "\t\t" + m_name->text() + "();\n";
  }

  if (m_generateDestructor->isChecked()) {
    code += "\t\t~" + m_name->text() + "();\n";
  }

  code += "\n\tprotected:\n";
  code += "\n\tprivate:\n";
  code += "\n};\n\n";

  if (m_protection->isChecked()) {
    code += "#endif\n";
  }

  GeneratedWindow *generatedWindow = new GeneratedWindow(code, this);
  generatedWindow->exec();
}
