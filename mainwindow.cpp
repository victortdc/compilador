
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Lexico.h"
#include "Sintatico.h"
#include "Semantico.h"
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

using namespace std;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->compilar, SIGNAL(clicked(bool)),this,SLOT(compilar()));

    connect(ui->actionAbrir, SIGNAL(triggered(bool)),this,SLOT(abrir()));
    connect(ui->actionSalvar, SIGNAL(triggered(bool)),this,SLOT(salvar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::compilar()
{
    QString Text = ui->textEdit->toPlainText();
    string text = Text.toStdString();

    cout << text;

    Lexico * lex = new Lexico();
    Sintatico * sint = new Sintatico();
    Semantico * sem = new Semantico();

    lex->setInput(text.c_str());

    try {
        sint->parse(lex, sem);
        ui->setText->setText("Treino concluido!");
    }catch(LexicalError const msg){
        string erro = "Deu ruim no Lexico monstro: ";
        erro.append(msg.getMessage());
        ui->setText->setText(erro.c_str());
    } catch (SyntaticError const msg) {
        string erro = "Deu ruim no Sintatico monstro: ";
        erro.append(msg.getMessage());
        ui->setText->setText(erro.c_str());
    }catch(SemanticError const msg){
        string erro = "Deu ruim no Semantico monstro: ";
        erro.append(msg.getMessage());
        ui->setText->setText(erro.c_str());
    }
}

void MainWindow::abrir()
{
    QString fileContent;

    QString filename= QFileDialog::getOpenFileName(this, tr("Choose File"), "/home", tr("Notas(*.txt)"));

    if(filename.isEmpty())
       return;

    QFile file(filename);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QTextStream in(&file);

    fileContent= in.readAll();
    file.close();

    ui->textEdit->clear();
    ui->textEdit->setText(fileContent);
}

void MainWindow::salvar()
{
    //Save File

    QString filename= QFileDialog::getSaveFileName(this, "Salvar arquivo", "*.txt");

    if (filename.isEmpty())
        return;

    QFile file(filename);

    //Open the file
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);

    out << ui->textEdit->toPlainText() << "\n";

    file.close();
}

