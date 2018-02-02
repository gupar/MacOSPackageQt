
#include "stdafx.h"
#include "webpage.h"
#include "webview.h"


cWebView *g_WebView = nullptr;

cWebView::cWebView(QWidget *parent)
    : QWebEngineView(parent)
{

}

cWebView::~cWebView()
{

}

//void cWebView::setPage(cWebPage *page)
//{
//    QWebEngineView::setPage(page);
//}


QWebEngineView *cWebView::createWindow(QWebEnginePage::WebWindowType type)
{
	return QWebEngineView::createWindow(type);
}

bool cWebView::event(QEvent* event)
{
	return QWebEngineView::event(event);
}

void cWebView::contextMenuEvent(QContextMenuEvent *event)
{
	const QList<QAction*> actions = page()->createStandardContextMenu()->actions();
	QMenu *menu = new QMenu(this);
	switch (actions.size())
	{
	case 3:
		break;
	case 6:
		auto it = std::find(actions.cbegin(), actions.cend(), page()->action(QWebEnginePage::CopyImageToClipboard));
		if (it != actions.cend())
		{
			QAction *downloadImage = page()->action(QWebEnginePage::DownloadImageToDisk);
			QAction *copyImage = page()->action(QWebEnginePage::CopyImageToClipboard);
			QAction *copyImageUrl = page()->action(QWebEnginePage::CopyImageUrlToClipboard);

			downloadImage->setText(tr("downloadImage"));
			copyImage->setText(tr("copyImage"));
			copyImageUrl->setText(tr("copyImageUrl"));

			menu->addAction(downloadImage);
			menu->addAction(copyImage);
			menu->addAction(copyImageUrl);
		}
		else
		{
			QAction *openLink = page()->action(QWebEnginePage::OpenLinkInThisWindow);
			QAction *copyLink = page()->action(QWebEnginePage::CopyLinkToClipboard);

			openLink->setText(tr("openLink"));
			copyLink->setText(tr("copyLink"));

			menu->addAction(openLink);
			menu->addAction(copyLink);
		}
		break;
	}

	if (menu->actions().size() != 0)
	{
		connect(menu, &QMenu::aboutToHide, menu, &QObject::deleteLater);
		menu->popup(event->globalPos());
	}
}

