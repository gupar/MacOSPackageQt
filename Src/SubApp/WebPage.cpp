
#include "stdafx.h"
#include "WebPage.h"
#include "WebView.h"
#include "popWindow.h"

QWebEnginePage *myCreateWindow(QWebEnginePage*page, QWebEnginePage::WebWindowType)
{
	qDebug() << "MyQWebEnginePage::createWindow";

	/*gWebView->setPage(new MyQWebEnginePage(page->profile(), gWebView));
	return gWebView->page();*/

	if (g_popWindow == nullptr){
		cPopWindow *PopWindow = new cPopWindow(page->profile());
		PopWindow->setAttribute(Qt::WA_DeleteOnClose);
		//PopWindow->show();
		g_popWindow = PopWindow;
		return PopWindow->page();
	}
	else{
		return g_popWindow->page();
	}

	//page->view();

	// return page;

	// return QWebEnginePage::createWindow(type);
}

cWebPage::cWebPage(QObject *parent)
	: QWebEnginePage(parent)
{

}

cWebPage::cWebPage(QWebEngineProfile *profile, QObject *parent)
    : QWebEnginePage(profile, parent)
{

}
void cWebPage::setUrl(const QUrl &url)
{
	QWebEnginePage::setUrl(url);
}

QWebEnginePage *cWebPage::createWindow(QWebEnginePage::WebWindowType type)
{
	return myCreateWindow(this, type);
}

void cWebPage::triggerAction(WebAction action, bool checked)
{
	if (action == WebAction::OpenLinkInNewTab){
		qDebug() << "WebAction::OpenLinkInNewTab";
	}

	qDebug() << action;

	QWebEnginePage::triggerAction(action, checked);
}

bool cWebPage::event(QEvent* event)
{
	qDebug() << "cWebPage::" << event->type();

	return QWebEnginePage::event(event);
}

