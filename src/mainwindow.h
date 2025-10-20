#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
Q_OBJECT


public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();


private slots:
void onCategorySelected();
void onClearCategory();
void onSearchClicked();


private:
Ui::MainWindow *ui;


// Helper
void populateCategories();
void populatePackages();
void filterPackagesByCategory(const QString &category);
};


#endif // MAINWINDOW_H
