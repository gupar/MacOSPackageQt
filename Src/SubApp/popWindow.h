#ifndef POPWINDOW_H
#define POPWINDOW_H

class cPopWindow;
extern cPopWindow *g_popWindow;

class cPopWindow : public QWidget {
    //Q_OBJECT

public:
	cPopWindow(QWebEngineProfile *profile);
	QWebEnginePage* page() const;

private slots:
	void setUrl(const QUrl &url);

private:
    class cWebView *m_view;

};

#endif //POPWINDOW_H