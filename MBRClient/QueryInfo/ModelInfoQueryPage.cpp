#include "ModelInfoQueryPage.h"
#include <QStandardItemModel>

ModelInfoQueryPage::ModelInfoQueryPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QString strText = QStringLiteral("���� <font color=green>");
	strText += QStringLiteral("%1</font> ����¼���� <font color=green>%2/%3</font> ҳ��ʾ��ÿҳ��ʾ <font color=green>%4</font> ��").arg(0).arg(0).arg(0).arg(0);
	ui.lbl_ct->setText(strText);

	QFont font;
	font.setPixelSize(12);
	ui.tableView->horizontalHeader()->setSectionsMovable(false);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableView->setFont(font);

	font.setPixelSize(14);
	font.setBold(true);
	QHeaderView *headerView = ui.tableView->horizontalHeader();
	headerView->setSortIndicatorShown(true);
	headerView->setStyleSheet("QHeaderView::section { padding-left: 1px; border: 1px solid #B0B0B0; }");
	headerView->setFont(font);

	QStandardItemModel *model = new QStandardItemModel(this);

	QStringList headList;
	headList << QStringLiteral("�豸����") 
		<< QStringLiteral("��������") 
		<< QStringLiteral("ģ������") 
		<< QStringLiteral("�ɼ�ʱ��")  
		<< QStringLiteral("�ɼ�������") 
		<< QStringLiteral("���");
	model->setHorizontalHeaderLabels(headList);
	ui.tableView->setModel(model);
}

ModelInfoQueryPage::~ModelInfoQueryPage()
{

}
