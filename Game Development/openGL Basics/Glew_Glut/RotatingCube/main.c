#include "Utils.h"

#define WINDOW_TITLE_PREFIX "Cube"

int CurrentWidth = 800, CurrentHeight = 600, WindowHandle = 0;

unsigned int FrameCount = 0;

GLuint
  ProjectionMatrixUniformLocation,
  ViewMatrixUniformLocation,
  ModelMatrixUniformLocation,
  BufferIds[3] = { 0 },
  ShaderIds[3] = { 0 };

Matrix
  ProjectionMatrix,
  ViewMatrix,
  ModelMatrix;

float CubeRotation = 0;
clock_t LastTime = 0;

void CreateCube(void);
void DestroyCube(void);
void DrawCube(void);

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


  glGetError();

  glClearColor(0.0f, 0.0f, 0.0f, 0.0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    ExitOnGLError("ERROR: Could not set OpenGL depth testing options");

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    ExitOnGLError("ERROR: Could not set OpenGL culling options");

    ModelMatrix = IDENTITY_MATRIX;
    ProjectionMatrix = IDENTITY_MATRIX;
    ViewMatrix = IDENTITY_MATRIX;
    TranslateMatrix(&ViewMatrix, 0, 0, -2);

    CreateCube();
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

  glutCloseFunc(DestroyCube);
}

void ResizeFunction(int Width, int Height)
{
  CurrentWidth = Width;
  CurrentHeight = Height;
  glViewport(0, 0, CurrentWidth, CurrentHeight);

  ProjectionMatrix = CreateProjectMatrix(
                                    60, 
                                    (float)CurrentWidth/CurrentHeight,
                                    1.0f,
                                    100.0f
  );

    glUseProgram(ShaderIds[0]);
    glUniformMatrix4fv(ProjectionMatrixUniformLocation, 1, GL_FALSE, ProjectionMatrix.m);
    glUseProgram(0);
}

void RenderFunction(void)
{
  ++FrameCount;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //cleans buffer
    //backbuffer cleared (GL_COLOR_BUFFER_BIT)
    //depth buffer also clear

  DrawCube();

  glutSwapBuffers();
  //glutPostRedisplay();
    //calls glutDisplayFunc for rerendering
}

void CreateCube(void)
{
    const Vertex VERTICES[8] =
    {
    { { -.5f, -.5f,  .5f, 1 }, { 0, 0, 1, 1 } },
    { { -.5f,  .5f,  .5f, 1 }, { 1, 0, 0, 1 } },
    { {  .5f,  .5f,  .5f, 1 }, { 0, 1, 0, 1 } },
    { {  .5f, -.5f,  .5f, 1 }, { 1, 1, 0, 1 } },
    { { -.5f, -.5f, -.5f, 1 }, { 1, 1, 1, 1 } },
    { { -.5f,  .5f, -.5f, 1 }, { 1, 0, 0, 1 } },
    { {  .5f,  .5f, -.5f, 1 }, { 1, 0, 1, 1 } },
    { {  .5f, -.5f, -.5f, 1 }, { 0, 0, 1, 1 } }
    };

    const GLuint INDICES[36] =
    {
        0,2,1,  0,3,2,
        4,3,0,  4,7,3,
        4,1,5,  4,0,1,
        3,6,2,  3,7,6,
        1,6,5,  1,2,6,
        7,5,6,  7,4,5
    };

    ShaderIds[0] = glCreateProgram();
    ExitOnGLError("ERROR: Could not create the shader program");

    ShaderIds[1] = LoadShader("SimpleShader.fragment.glsl", GL_FRAGMENT_SHADER);
    ShaderIds[2] = LoadShader("SimpleShader.vertex.glsl", GL_VERTEX_SHADER);
    glAttachShader(ShaderIds[0], ShaderIds[1]);
    glAttachShader(ShaderIds[0], ShaderIds[2]);

    glLinkProgram(ShaderIds[0]);
    ExitOnGLError("ERROR: Could not link the shader program");

    ModelMatrixUniformLocation = glGetUniformLocation(ShaderIds[0], "ModelMatrix");
    ViewMatrixUniformLocation = glGetUniformLocation(ShaderIds[0], "ViewMatrix");
    ProjectionMatrixUniformLocation = glGetUniformLocation(ShaderIds[0], "ProjectionMatrix");
    ExitOnGLError("ERROR: Could not get the shader uniform locations");

    glGenBuffers(2, &BufferIds[1]);
    ExitOnGLError("ERROR: Could not generate the buffer objects");

    glGenVertexArrays(1, &BufferIds[0]);
    ExitOnGLError("ERROR: Could not generate the VAO");
    glBindVertexArray(BufferIds[0]);
    ExitOnGLError("ERROR: Could not bind the VAO");

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    ExitOnGLError("ERROR: Could not enable vertex attributes");

    glBindBuffer(GL_ARRAY_BUFFER, BufferIds[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VERTICES), VERTICES, GL_STATIC_DRAW);
    ExitOnGLError("ERROR: Could not bind the VBO to the VAO");

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(VERTICES[0]), (GLvoid*)0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VERTICES[0]), (GLvoid*)sizeof(VERTICES[0].Position));
    ExitOnGLError("ERROR: Could not set VAO attributes");

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BufferIds[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_STATIC_DRAW);
    ExitOnGLError("ERROR: Could not bind the IBO to the VAO");

    glBindVertexArray(0);
}

void DestroyCube(void)
{
  glDetachShader(ShaderIds[0], ShaderIds[1]);
  glDetachShader(ShaderIds[0], ShaderIds[2]);
  glDeleteShader(ShaderIds[1]);
  glDeleteShader(ShaderIds[2]);
  glDeleteProgram(ShaderIds[0]);
  ExitOnGLError("ERROR: Could not destroy the shaders");

  glDeleteBuffers(2, &BufferIds[1]);
  glDeleteVertexArrays(1, &BufferIds[0]);
  ExitOnGLError("ERROR: Could not destroy the buffer objects");
}

void DrawCube(void)
{
    float CubeAngle;
    clock_t Now = clock();
    if (LastTime == 0)
        LastTime = Now;

    CubeRotation += 90.0f * ((float)(Now - LastTime) / CLOCKS_PER_SEC);
    CubeAngle = DegreesToRadians(CubeRotation);
    LastTime = Now;

    ModelMatrix = IDENTITY_MATRIX;
    RotateAboutY(&ModelMatrix, CubeAngle);
    RotateAboutX(&ModelMatrix, CubeAngle);

    glUseProgram(ShaderIds[0]);
    ExitOnGLError("ERROR: Could not use the shader program");

    glUniformMatrix4fv(ModelMatrixUniformLocation, 1, GL_FALSE, ModelMatrix.m);
    glUniformMatrix4fv(ViewMatrixUniformLocation, 1, GL_FALSE, ViewMatrix.m);
    ExitOnGLError("ERROR: Could not set the shader uniforms");

    glBindVertexArray(BufferIds[0]);
    ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (GLvoid*)0);
    ExitOnGLError("ERROR: Could not draw the cube");

    glBindVertexArray(0);
    glUseProgram(0);
}

void IdleFunction(void)
{
  glutPostRedisplay();
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


