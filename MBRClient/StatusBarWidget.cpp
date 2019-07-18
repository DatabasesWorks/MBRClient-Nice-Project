#include "StatusBarWidget.h"
#include <QDesktopServices>
#include <QUrl>

StatusBarWidget::StatusBarWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	InitUI();
	InitConnect();
}

StatusBarWidget::~StatusBarWidget()
{

}

void StatusBarWidget::InitUI()
{
	QString versionDescription = QStringLiteral("��ǰ�汾��");
	//versionDescription += USERCONFIG->getVersion();
	ui.lbl_version->setText(versionDescription);
	
	QString updateLink = QStringLiteral("<a href=1>������</a>");
	ui.lbl_update->setText(updateLink);
	ui.lbl_update->setToolTip(QStringLiteral("<font color=blue>�������</font>"));

	QString strUrl = "www.baidu.com";
	QString platformEntry = QStringLiteral("<a href=%1>�籣����ƽ̨���</a>").arg(strUrl);
	ui.lbl_platform->setText(platformEntry);
	ui.lbl_platform->setToolTip(strUrl);
}

void StatusBarWidget::InitConnect()
{
	connect(ui.lbl_update, SIGNAL(linkActivated(const QString &)), this, SLOT(SlotOnUpdate(const QString &)));
	connect(ui.lbl_platform, SIGNAL(linkActivated(const QString &)), this, SLOT(SlotOnOpenUrl(const QString &)));
}

void StatusBarWidget::SlotOnUpdate(const QString & linkUrl)
{
	Q_UNUSED(linkUrl)
}

void StatusBarWidget::SlotOnOpenUrl( const QString & linkUrl )
{
	QDesktopServices::openUrl(QUrl(linkUrl));
}
