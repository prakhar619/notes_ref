#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#define WINDOW_TITLE_PREFIX "Chapter 1"

int CurrentWidth = 800, CurrentHeight = 600, WindowHandle = 0;

unsigned int FrameCount = 0;

GLuint VertexShaderId, FragmentShaderId, ProgramId, VaoId, VboId, ColorBufferId;
const GLchar* VertexShader = 
{
  "#version 400\n"\

  "layout(location=0) in vec4 in_Position;\n"\
  "layout(location=1) in vec4 in_Color;\n"\
  "out vec4 ex_Color;\n"\

  "void main(void)\n"\
  "{\n"\
  "  gl_Position = in_Position;\n"\
  "  ex_Color = in_Color;\n"\
  "}\n"
};
const GLchar* FragmentShader =
{
  "#version 400\n"\

  "in vec4 ex_Color;\n"\
  "out vec4 out_Color;\n"\

  "void main(void)\n"\
  "{\n"\
  "  out_Color = ex_Color;\n"\
  "}\n"
};

void Initialize(int, char*[]);
void InitWindow(int, char*[]);
void ResizeFunction(int, int);
void RenderFunction(void);

void TimerFunction(int);
void IdleFunction(void);

void Cleanup(void);
void CreateVBO(void);
void DestroyVBO(void);
void CreateShaders(void);
void DestroyShaders(void);

int main(int argc, char* argv[])
{
  Initialize(argc, argv);

  glutMainLoop();
  
  exit(EXIT_SUCCESS);
}

void Initialize(int argc, char* argv[])
{
  GLenum GlewInitResult;

  InitWindow(argc, argv);
    //now we can call OpenGL functions
  
  GlewInitResult = glewInit();
    //after initializing opengl context
  if(GLEW_OK != GlewInitResult)
  {
    fprintf(stderr,
    "Error: %s\n", glewGetErrorString(GlewInitResult)
    );
    exit(EXIT_FAILURE);
  }

  fprintf(
    stdout,
    "INFO: OpenGL Version: %s\n",
    glGetString(GL_VERSION)
  );

  CreateShaders();
  CreateVBO();

  // glClearColor(0.2f, 0.0f, 0.0f, 0.0);
}

void InitWindow(int argc, char* argv[])
{
  //FreeGLUT
  glutInit(&argc, argv);
    //initializes glut
  glutInitContextVersion(4, 6);
  glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
  glutInitContextProfile(GLUT_CORE_PROFILE);
    //return a forward-compactible openGL 4.0 core profile context

  glutSetOption(
    GLUT_ACTION_ON_WINDOW_CLOSE,
    GLUT_ACTION_GLUTMAINLOOP_RETURNS
    // to make sure that the glutMainLoop function in main returns to the program and doesn't exit the program when it's done. The original GLUT library did not return to the program and after GLUT was done rendering it would end your program. 
  );
  
  glutInitWindowSize(CurrentWidth, CurrentHeight);
  // window size

  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  // BitMap properties (FrameBuffer)
  // Depth buffer : 3d graphics  (also called Z buffer)
  // Double Buffer: virtual buffer to edit and send only when complete
  // Color Composition

  WindowHandle = glutCreateWindow(WINDOW_TITLE_PREFIX);

  if(WindowHandle < 1) {
    fprintf(
      stderr,
      "ERROR: Could not create a new rendering window.\n"
    );
    exit(EXIT_FAILURE);
  }

  glutReshapeFunc(ResizeFunction);
  // The reshape function is called each time the window is resized, 
  glutDisplayFunc(RenderFunction);
  // the display function is called each time the scene is to be drawn to the screen. 

  glutIdleFunc(IdleFunction);

  glutTimerFunc(0,TimerFunction,0);
  // 3 param: millisecondDelayBeforeFUnctionIsCalled function valueToPassToFunction

  glutCloseFunc(Cleanup);
}

void ResizeFunction(int Width, int Height)
{
  CurrentWidth = Width;
  CurrentHeight = Height;
  glViewport(0, 0, CurrentWidth, CurrentHeight);
}

void RenderFunction(void)
{
  ++FrameCount;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //cleans buffer
    //backbuffer cleared (GL_COLOR_BUFFER_BIT)
    //depth buffer also clear

  glDrawArrays(GL_TRIANGLE_STRIP,0,4);

  glutSwapBuffers();
  //glutPostRedisplay();
    //calls glutDisplayFunc for rerendering
}

void IdleFunction(void)
{
  // glutPostRedisplay();
}

void TimerFunction(int value)
{
  //*********how is height width value updating ************** */
  if(0 != value)
  {
    char* tempString = (char*) malloc(512 + strlen(WINDOW_TITLE_PREFIX));
    sprintf(
      tempString,
      "%s:%d Frames per Second @ %d x %d",
      WINDOW_TITLE_PREFIX,
      FrameCount*4,
      CurrentWidth,
      CurrentHeight
    );
    glutSetWindowTitle(tempString);
    free(tempString);
  }
  
  FrameCount = 0;
  glutTimerFunc(250, TimerFunction, 1);

}

void Cleanup(void)
{
  DestroyShaders();
  DestroyVBO();
}

void CreateVBO(void)
{
  //Middle of Screen 0,0
  //   --------> x Inc
  //   ^
  //   |
  //   |  y inc

  // LeftTop -1,1
  // RightTop 1,1
  // LeftBottom -1,-1
  // RightBottom 1,-1
  // GLfloat Vertices[] = {
  // -0.8f,  0.8f, 0.0f, 1.0f,
  //  0.8f,  0.8f, 0.0f, 1.0f,
  // -0.8f, -0.8f, 0.0f, 1.0f,

  // -0.8f, -0.8f, 0.0f, 1.0f,
  //  0.8f,  0.8f, 0.0f, 1.0f,
  //  0.8f, -0.8f, 0.0f, 1.0f

  // };
  GLfloat Vertices[] = {
  -0.8f,  0.8f, 0.0f, 1.0f,
   0.8f,  0.8f, 0.0f, 1.0f,
  -0.8f, -0.8f, 0.0f, 1.0f,
   0.8f, -0.8f, 0.0f, 1.0f
};

  // GLfloat Colors[] = {
  // 1.0f, 0.0f, 0.0f, 1.0f,
  // 0.0f, 1.0f, 0.0f, 1.0f,
  // 0.0f, 0.0f, 1.0f, 1.0f,

  // 0.0f, 0.0f, 1.0f, 1.0f,
  // 0.0f, 1.0f, 0.0f, 1.0f,
  // 1.0f, 1.0f, 1.0f, 1.0f
  // };

  GLfloat Colors[] = {
  1.0f, 0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f, 1.0f,
  1.0f, 1.0f, 1.0f, 1.0f
};

  GLenum ErrorCheckValue = glGetError();

  glGenVertexArrays(1, &VaoId);
  glBindVertexArray(VaoId);



  glGenBuffers(1, &VboId);
  glBindBuffer(GL_ARRAY_BUFFER, VboId);
  
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);



  glGenBuffers(1, &ColorBufferId);
  glBindBuffer(GL_ARRAY_BUFFER, ColorBufferId);
  
  glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
  
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(1);



  ErrorCheckValue = glGetError();
  if (ErrorCheckValue != GL_NO_ERROR)
  {
    fprintf(
      stderr,
      "ERROR: Could not create a VBO: %s \n",
      gluErrorString(ErrorCheckValue)
    );

    exit(-1);
  }
}

void DestroyVBO(void)
{
  GLenum ErrorCheckValue = glGetError();
  
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(0);


  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glDeleteBuffers(1, &ColorBufferId);
  glDeleteBuffers(1, &VboId);


  glBindVertexArray(0);
  glDeleteVertexArrays(1, &VaoId);

  ErrorCheckValue = glGetError();
  if (ErrorCheckValue != GL_NO_ERROR)
  {
    fprintf(
      stderr,
      "ERROR: Could not destroy the VBO: %s \n",
      gluErrorString(ErrorCheckValue)
    );

    exit(-1);
  }

}

void CreateShaders(void)
{
 GLenum ErrorCheckValue = glGetError();

  VertexShaderId = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(VertexShaderId, 1, &VertexShader, NULL);
  glCompileShader(VertexShaderId);

  FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(FragmentShaderId, 1, &FragmentShader, NULL);
  glCompileShader(FragmentShaderId);

  ProgramId = glCreateProgram();
    glAttachShader(ProgramId, VertexShaderId);
    glAttachShader(ProgramId, FragmentShaderId);
  glLinkProgram(ProgramId);


  glUseProgram(ProgramId);

  glEnableVertexAttribArray(1);
  ErrorCheckValue = glGetError();
  if (ErrorCheckValue != GL_NO_ERROR)
  {
    fprintf(
      stderr,
      "ERROR: Could not create the shaders: %s \n",
      gluErrorString(ErrorCheckValue)
    );

    exit(-1);
  }
}

void DestroyShaders(void)
{
  GLenum ErrorCheckValue = glGetError();

  glUseProgram(0);

  glDetachShader(ProgramId, VertexShaderId);
  glDetachShader(ProgramId, FragmentShaderId);

  glDeleteShader(FragmentShaderId);
  glDeleteShader(VertexShaderId);

  glDeleteProgram(ProgramId);

  ErrorCheckValue = glGetError();
  if (ErrorCheckValue != GL_NO_ERROR)
  {
    fprintf(
      stderr,
      "ERROR: Could not destroy the shaders: %s \n",
      gluErrorString(ErrorCheckValue)
    );

    exit(-1);
  }
}