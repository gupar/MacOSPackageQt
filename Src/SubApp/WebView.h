#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebEngineView>

class cWebView;
extern cWebView *g_WebView;

class cWebView : public QWebEngineView
{
    Q_OBJECT

public:
	explicit cWebView(QWidget* parent = nullptr);

	virtual ~cWebView();
    //void setPage(cWebPage *page);

    //int loadProgress() const;

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
	virtual QWebEngineView *createWindow(QWebEnginePage::WebWindowType type);
	virtual bool event(QEvent* event) override;

private:
    //int m_loadProgress;
};

#endif //WEBVIEW_H

