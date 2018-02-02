#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QWebEnginePage>

class cWebPage : public QWebEnginePage
{
    Q_OBJECT

public:
	explicit cWebPage(QObject *parent = nullptr);
	cWebPage(QWebEngineProfile *profile, QObject *parent = nullptr);
	void setUrl(const QUrl &url);
	QWebEnginePage *createWindow(QWebEnginePage::WebWindowType type) Q_DECL_OVERRIDE;
	virtual void triggerAction(WebAction action, bool checked = false);
	virtual bool event(QEvent* event);
};

#endif // WEBPAGE_H
