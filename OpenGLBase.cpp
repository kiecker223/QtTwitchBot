#include "OpenGLBase.h"

OpenGLBase::OpenGLBase(QWindow *pParent) : QWindow(pParent)
{
    
}

OpenGLBase::~OpenGLBase()
{
    
}

void OpenGLBase::setupContext()
{
    if (!m_pContext)
        m_pContext = new QOpenGLContext(this);
    
    if (!m_pPainter)
        m_pPainter = new QOpenGLPaintDevice(this->size());
    
    
}

void OpenGLBase::setScene(BaseScene *pScene)
{
    
}

void OpenGLBase::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClearColor();
}
