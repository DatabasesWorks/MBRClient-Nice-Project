#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>

class AppManager : public QObject
{
	Q_OBJECT

public:
	AppManager(bool withParam = false, QObject *parent = 0);
	~AppManager();

	int startup(QString command = "");

public slots:
    void onOpenDatabaseFailed();

private:
	bool checkRunningEnv();
	int init(bool needUpdate = true);             // 0����¼��1��ע�᣻2���޷�ʹ��

private:
	bool m_withParam;
};

#endif // APPMANAGER_H
