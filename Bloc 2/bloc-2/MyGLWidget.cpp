// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

void MyGLWidget::ini_camera()
{
	OBS = glm::vec3(0,0,1);
	VRP = glm::vec3(0,0,0);
	up = glm::vec3(1,0,0);
	viewTransform();
	
	FOV = float(M_PI)/2.0f;
	ra = 1.0f;
	znear = 0.4f;
	zfar = 3.0f;
	projectTransform();
}

void MyGLWidget::projectTransform()
{
	glm::mat4 Proj = glm::perspective(FOV, ra, znear, zfar);
	glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]); 
}

void MyGLWidget::viewTransform()
{
	glm::mat4 View = glm::lookAt(OBS, VRP, up);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::paintGL () 
{
// En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
// useu els paràmetres que considereu (els que hi ha són els de per defecte)
//  glViewport (0, 0, ample, alt);
  
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT);

  // Carreguem la transformació de model
  modelTransform ();
  
  /*//transformacio de punt de vista
  viewTransform();

  //tranformacio de projeccio
  projectTransform();*/

  //inicialitzem els paràmetres de view matrix i project matrix
  ini_camera();

  // Activem el VAO per a pintar la caseta 
  glBindVertexArray (VAO_Casa);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, 9);

  glBindVertexArray (0);
}

void MyGLWidget::carregaShaders()
{
BL2GLWidget::carregaShaders();
projLoc = glGetUniformLocation(program->programId(), "proj");
viewLoc = glGetUniformLocation(program->programId(), "view");
}

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {
}


