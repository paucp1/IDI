TEMPLATE    = app
QT         += opengl 

INCLUDEPATH +=  /usr/include/glm /dades/IDI/Bloc2-Sessio2.1/model.cpp

FORMS += MyForm.ui

HEADERS += MyForm.h BL2GLWidget.h MyGLWidget.h

SOURCES += main.cpp MyForm.cpp \
        BL2GLWidget.cpp MyGLWidget.cpp /dades/IDI/Bloc2-Sessio2.1/model.cpp
