#include "stdafx.h"
#include "popWindow.h"
#include "WebPage.h"
#include "WebView.h"

cPopWindow *g_popWindow = nullptr;

cPopWindow::cPopWindow(QWebEngineProfile *profile)
	: m_view(new cWebView(this))
{
	m_view->setPage(new cWebPage(profile, m_view));
	QVBoxLayout *layout = new QVBoxLayout;
	layout->setMargin(0);
	setLayout(layout);
	layout->addWidget(m_view);
	//m_view->setFocus();

	connect(m_view, &QWebEngineView::urlChanged, this, &cPopWindow::setUrl);
}

QWebEnginePage* cPopWindow::page()const
{
	return m_view->page();
}

void cPopWindow::setUrl(const QUrl &url)
{
	qDebug() << "cPopWindow::setUrl" << url;
	g_WebView->setUrl(url);

	m_view->stop();

}
