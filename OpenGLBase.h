#ifndef OPENGLBASE_H
#define OPENGLBASE_H

#include <QWindow>
#include <QOpenGLContext>
#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLPaintDevice>
#include <QScreen>
#include "BaseScene.h"



class OpenGLBase : public QWindow, public QOpenGLFunctions
{
    Q_OBJECT
    
public:
    
    explicit OpenGLBase(QWidget *pParent = nullptr);
    ~OpenGLBase();
    
    // Helper function
    void setupContext();
    
    // Rendering related
    void setScene(BaseScene *pScene);
    void drawScene();
    
private:
    
    // OpenGL window stuff
    QOpenGLContext     * m_pContext;
    QOpenGLPaintDevice * m_pPainter;
    
    // The scene to be renderered
    BaseScene          * m_pScene;
    
};

#endif // OPENGLBASE_H
