// MyGLWidget.h
#include "BL2GLWidget.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

  private:
    void ini_camera();
    void projectTransform();
    void viewTransform();
    void paintGL();
    void carregaShaders();
    int printOglError(const char file[], int line, const char func[]);

    // uniform locations
    GLuint projLoc, viewLoc;

    glm::vec3 OBS, VRP, up;
    float FOV, ra, znear, zfar;
};
