#include "xlsemployeelistmodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>

#include "dbmanager.h"

XlsEmployeeListModel::XlsEmployeeListModel(QSqlDatabase* db, QWidget *parent)
    : QStandardItemModel(parent),
      connection(db)
{
    dbModel = new QSqlQueryModel(this);
    query = new QSqlQuery(DBManager::getInstance()->connection);
    query->exec(QString("SELECT * FROM ul_employees"));
}

XlsEmployeeListModel::~XlsEmployeeListModel()
{

}

int XlsEmployeeListModel::rowCount(const QModelIndex &parent) const {
    return QStandardItemModel::rowCount(parent);
}
int XlsEmployeeListModel::columnCount(const QModelIndex &parent) const {
    return QStandardItemModel::columnCount(parent);
}

QVariant XlsEmployeeListModel::data(const QModelIndex & index, int role) const {
    qDebug() << "data (" << index.row() << "," << index.column() << ")";

    if (!index.isValid()) {
        return QVariant();
    }
    switch(role) {
    case Qt::BackgroundColorRole:
    {
        return this->identifyBrush(index);
    }
    default:
        return QStandardItemModel::data(index, role);
    }
}

QBrush XlsEmployeeListModel::identifyBrush(const QModelIndex& index) const{
    QString xls_value = index.model()->data(index).toString();
    QModelIndex xls_code_index = index.model()->index(index.row(),5);
    QString xls_code = index.model()->data(xls_code_index).toString();

    query->first();
    int db_code_index = query->record().indexOf("code");
    bool found = false;
    do {
        QSqlRecord rec = query->record();
        QString db_code = rec.value(db_code_index).toString();
        if (db_code.compare(xls_code) == 0) {
            QString db_value = rec.value(index.column()+1).toString();
            found = true;
            if(db_value.compare(xls_value)) {
                return QBrush(Qt::gray);
            }
            break;
        }
    } while (query->next());

    return QBrush(Qt::white);
}

