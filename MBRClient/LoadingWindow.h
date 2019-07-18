#ifndef LOADINGWINDOW_H
#define LOADINGWINDOW_H

#include <QWidget>

class QLabel;
class QTimer;
class QProgressIndicator;
class LoadingWindow : public QWidget
{
	Q_OBJECT

public:
	explicit LoadingWindow(int width = 0, int height = 0, QWidget *parent = 0);
	virtual ~LoadingWindow();

public:
	void setTimeOut(int mesc);
	void start(int mesc = 0);
	void stop();
	void setLoadingText(QString strPrompt);

protected:
	void paintEvent(QPaintEvent *);

private:
	void createUI();

private slots:
	void updateHint();

signals:
	void timeOut();

private:
	QTimer* m_timer;                  /*! ��ʱ��ʱ��*/
	QLabel* m_loadingGifLabel;         /*! ����gif*/
	QLabel* m_loadingTextLabel;        /*! ����gif��ǩ*/
	QProgressIndicator* m_proIndicator; /*! Loadingͼ��*/

	int m_timeMesc;                    /*! ��ʱʱ��*/
	unsigned int m_screenWidth;        /*! ��ʾҳ����*/
	unsigned int m_screenheight;        /*! ��ʾҳ��߶�*/
};

#endif // LOADINGWINDOW_H
