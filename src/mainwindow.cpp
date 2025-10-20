#include "mainwindow.h"
for (int i = 0; i < ui->pkgTree->topLevelItemCount(); ++i) {
ui->pkgTree->topLevelItem(i)->setHidden(false);
}
return;
}


for (int i = 0; i < ui->pkgTree->topLevelItemCount(); ++i) {
QTreeWidgetItem *it = ui->pkgTree->topLevelItem(i);
QString cat = it->data(0, Qt::UserRole).toString();
bool match = cat.compare(category, Qt::CaseInsensitive) == 0;
it->setHidden(!match);
}
}


void MainWindow::onCategorySelected()
{
QList<QListWidgetItem*> sel = ui->categoryList->selectedItems();
if (sel.isEmpty()) {
filterPackagesByCategory("All");
return;
}
QString cat = sel.first()->text();
filterPackagesByCategory(cat);
}


void MainWindow::onClearCategory()
{
ui->categoryList->clearSelection();
ui->categoryList->setCurrentRow(0);
filterPackagesByCategory("All");
}


void MainWindow::onSearchClicked()
{
QString term = ui->searchEdit->text().trimmed();
if (term.isEmpty()) {
// if no term, show according to selected category
onCategorySelected();
return;
}


// simple search: show only items matching the search term in the name or version
for (int i = 0; i < ui->pkgTree->topLevelItemCount(); ++i) {
QTreeWidgetItem *it = ui->pkgTree->topLevelItem(i);
const QString name = it->text(0);
const QString ver = it->text(1);
bool match = name.contains(term, Qt::CaseInsensitive) || ver.contains(term, Qt::CaseInsensitive);
it->setHidden(!match);
}
}
