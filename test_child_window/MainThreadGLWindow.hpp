﻿#pragma once

#include <array>
#include <QtGui/qwindow.h>
 
class QOpenGLContext;

class MainThreadGLWindow : public QWindow {
    Q_OBJECT
public:
    MainThreadGLWindow();
    ~MainThreadGLWindow();

    inline void setCleanColor(float r,float g,float b,float a=1.0f);
    inline void setCleanColor(const std::array<float,4> &);
    std::array<float,4> getCleanColor() const{ return mmm_CleanColor; }
    void setContent(QWindow *);
    QWindow * getContent() const {
        return mmm_Content;
    }
public:
    Q_SLOT void update();
protected:
    bool event(QEvent *event) override ;
    void exposeEvent(QExposeEvent *event) override ;
private:
    void init_and_repaint();
protected:
    void resizeEvent(QResizeEvent *ev) override;
    void showEvent(QShowEvent *ev) override;
    void hideEvent(QHideEvent *ev) override;
private:
    std::array<float,4> mmm_CleanColor{0,0,0,1};
    using Super = QWindow ;
    QOpenGLContext * mmm_Contex{nullptr};
    QWindow * mmm_Content{nullptr};
};

inline void MainThreadGLWindow::setCleanColor(float r,float g,float b,float a){
    mmm_CleanColor[0]=r;
    mmm_CleanColor[1]=g;
    mmm_CleanColor[2]=b;
    mmm_CleanColor[3]=a;
    this->update();
}

inline void MainThreadGLWindow::setCleanColor(const std::array<float,4> & arg){
    mmm_CleanColor=arg;
    this->update();
}




