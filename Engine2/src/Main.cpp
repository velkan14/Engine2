#include <vector>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>

#include "GL/glew.h"
#include "GL/freeglut.h"

#include "MatFactory.h"
#include "shaderManager.h"
#include "CameraManager.h"
#include "Mesh.h"
#include "MatrixStack.h"

#define CAPTION "Tangram 2D"

using namespace Engine2;

//640 x 480
int WinX = 640, WinY = 480;
int WindowHandle = 0;
unsigned int FrameCount = 0;

int lastTime = 0, elapsedTime = 0;

GLuint VertexShaderId, FragmentShaderId;

ShaderManager * shaderManager = new ShaderManager();
CameraManager * cameraManager = new CameraManager();
MatrixStack * ModelMatrixStack = new MatrixStack();

Mesh meshTriangle(shaderManager, ModelMatrixStack),
	 meshCube(shaderManager, ModelMatrixStack), 
	 meshParalelogram(shaderManager, ModelMatrixStack);

const vec3 X_AXIS(1.0f, 0.0f, 0.0f);
const vec3 Y_AXIS(0.0f, 1.0f, 0.0f);
const vec3 Z_AXIS(0.0f, 0.0f, 1.0f);

vec3 Position(0.0f, 0.0f, 0.0f);

bool isKeyDownW = false , isKeyDownS = false, isKeyDownA = false, isKeyDownD = false;

float t = -1.0f;
bool animationForward = false;

//////////////////////////////////////////////////////////////////////// POSITIONS AND ROTATIONS

vec3 initialPositionTriangleBig1(0.0f, 0.0f, 0.0f);
vec3 initialPositionTriangleBig2(0.0f, 0.0f, 0.0f);
vec3 initialPositionTriangleMedium(0.5f, -0.5f, 0.0f);
vec3 initialPositionTriangleSmall1(0.0f, 0.0f, 0.0f);
vec3 initialPositionTriangleSmall2(3.51f* M_UNITE, 3.51f* M_UNITE, 0.0f);
vec3 initialPositionParalelogram(0.0f, -7.0f * M_UNITE, 0.0f);
vec3 initialPositionSquare(0.0f, 0.0f, 0.0f);

vec3 secondPositionTriangleBig1(0.0f, 0.0f, 0.0f);
vec3 secondPositionTriangleBig2(0.0f, 0.0f, 0.2f);
vec3 secondPositionTriangleMedium(0.5f, -0.5f, 0.4f);
vec3 secondPositionTriangleSmall1(0.0f, 0.0f, 0.6f);
vec3 secondPositionTriangleSmall2(3.51f* M_UNITE, 3.51f* M_UNITE, 0.8f);
vec3 secondPositionParalelogram(0.0f, -8.0f * M_UNITE, 1.0f);
vec3 secondPositionSquare(0.0f, 0.0f, 1.2f);



vec3 thirdPositionTriangleBig1(2.0f * M_UNITE, 3.0f * M_UNITE, 0.0f);
vec3 thirdPositionTriangleBig2(9.0f* M_UNITE, -4.05f* M_UNITE, 0.2f);
vec3 thirdPositionTriangleMedium(-3.0f* M_UNITE, 13.0f* M_UNITE, 0.4f);
vec3 thirdPositionTriangleSmall1(-8.0f* M_UNITE, 3.0f* M_UNITE, 0.6f);
vec3 thirdPositionTriangleSmall2(2.0f* M_UNITE, -13.0f* M_UNITE, 0.8f);
vec3 thirdPositionParalelogram(5.5f* M_UNITE, -9.0f* M_UNITE, 1.0f);
vec3 thirdPositionSquare(-3.0f* M_UNITE, 3.0f* M_UNITE, 1.2f);

vec3 finalPositionSquare(-3.0f* M_UNITE, 3.0f* M_UNITE, 0.0f);
vec3 finalPositionParalelogram(11.4f* M_UNITE, -10.7f* M_UNITE, 0.0f);
vec3 finalPositionTriangleBig1(2.0f * M_UNITE, 3.0f * M_UNITE, 0.0f);
vec3 finalPositionTriangleBig2(9.0f* M_UNITE, -4.05f* M_UNITE, 0.0f);
vec3 finalPositionTriangleMedium(-3.0f* M_UNITE, 13.0f* M_UNITE, 0.0f);
vec3 finalPositionTriangleSmall1(-8.0f* M_UNITE, 3.0f* M_UNITE, 0.0f);
vec3 finalPositionTriangleSmall2(2.0f* M_UNITE, -13.0f* M_UNITE, 0.0f);

qtrn initialRotationTriangleBig1(Z_AXIS, -M_PI / 4.0f);
qtrn initialRotationTriangleBig2(Z_AXIS, -(3.0f / 4.0f) * M_PI);
qtrn initialRotationTriangleMedium(Z_AXIS, -M_PI / 2.0f);
qtrn initialRotationTriangleSmall1(Z_AXIS, (3.0f / 4.0f) * M_PI);
qtrn initialRotationTriangleSmall2(Z_AXIS, M_PI / 4.0f);
qtrn initialRotationParalelogram(Z_AXIS, 0.0f);
qtrn initialRotationSquare(Z_AXIS, M_PI / 4.0f);

qtrn finalRotationTriangleBig1(Z_AXIS, M_PI);
qtrn finalRotationTriangleBig2(Z_AXIS, -(3.0f / 4.0f) * M_PI);
qtrn finalRotationTriangleMedium(Z_AXIS, -(5.0f / 4.0f) * M_PI);
qtrn finalRotationTriangleSmall1(Z_AXIS, (3.0f / 4.0f) * M_PI);
qtrn finalRotationTriangleSmall2(Z_AXIS, -M_PI / 2.0f);
qtrn finalRotationParalelogram(Z_AXIS, (70.0f / 180.0f)*M_PI);
qtrn finalRotationSquare(Z_AXIS, 0.0f);

vec3 currentPositionTriangleBig1(0.0f, 0.0f, 0.0f);
vec3 currentPositionTriangleBig2(0.0f, 0.0f, 0.0f);
vec3 currentPositionTriangleMedium(0.5f, -0.5f, 0.0f);
vec3 currentPositionTriangleSmall1(0.0f, 0.0f, 0.0f);
vec3 currentPositionTriangleSmall2(3.51f* M_UNITE, 3.51f* M_UNITE, 0.0f);
vec3 currentPositionParalelogram(0.0f, -8.0f * M_UNITE, 0.1f);
vec3 currentPositionSquare(0.0f, 0.0f, 0.0f);

qtrn currentRotationTriangleBig1(Z_AXIS, -M_PI / 4.0f);
qtrn currentRotationTriangleBig2(Z_AXIS, -(3.0f / 4.0f) * M_PI);
qtrn currentRotationTriangleMedium(Z_AXIS, -M_PI / 2.0f);
qtrn currentRotationTriangleSmall1(Z_AXIS, (3.0f / 4.0f) * M_PI);
qtrn currentRotationTriangleSmall2(Z_AXIS, M_PI / 4.0f);
qtrn currentRotationParalelogram(Z_AXIS, 0.0f);
qtrn currentRotationSquare(Z_AXIS, M_PI / 4.0f);

/////////////////////////////////////////////////////////////////////// VAOs & VBOs

void createBufferObjects()
{
	meshCube.createBufferObjects();
	meshParalelogram.createBufferObjects();
	meshTriangle.createBufferObjects();

	ErrorManager::checkOpenGLError("ERROR: Could not create VAOs and VBOs.");
}

void destroyBufferObjects()
{
	meshTriangle.destroyBufferObjects();
	meshCube.destroyBufferObjects();
	meshParalelogram.destroyBufferObjects();

	ErrorManager::checkOpenGLError("ERROR: Could not destroy VAOs and VBOs.");
}

/////////////////////////////////////////////////////////////////////// SCENE

void drawTangram()
{
	//Big Triangle 1
	ModelMatrixStack->pushMatrix();
	ModelMatrixStack->translate(currentPositionTriangleBig1);
	ModelMatrixStack->rotate(currentRotationTriangleBig1);
	ModelMatrixStack->scale(1.0f, 1.0f, 0.2f);
	meshTriangle.draw(VALUE_90, 0.0f, 0.0f);
	ModelMatrixStack->popMatrix();

	//Big Triangle 2
	ModelMatrixStack->pushMatrix();
	ModelMatrixStack->translate(currentPositionTriangleBig2);
	ModelMatrixStack->rotate(currentRotationTriangleBig2);
	ModelMatrixStack->scale(1.0f, 1.0f, 0.2f);
	meshTriangle.draw(0.0f, VALUE_90, 0.0f);
	ModelMatrixStack->popMatrix();

	//Medium Triangle
	ModelMatrixStack->pushMatrix();
	ModelMatrixStack->translate(currentPositionTriangleMedium);
	ModelMatrixStack->rotate(currentRotationTriangleMedium);
	ModelMatrixStack->scale(1.0f / M_SQRT2, 1.0f / M_SQRT2, 0.2f);
	meshTriangle.draw(0.0f, 0.0f, VALUE_90);
	ModelMatrixStack->popMatrix();

	//Small Triangle 1
	ModelMatrixStack->pushMatrix();
	ModelMatrixStack->translate(currentPositionTriangleSmall1);
	ModelMatrixStack->rotate(currentRotationTriangleSmall1);
	ModelMatrixStack->scale(1.0f / 2.0f, 1.0f / 2.0f,0.2f);
	meshTriangle.draw(VALUE_90, VALUE_90, 0.0f);
	ModelMatrixStack->popMatrix();

	//Small Triangle 2
	ModelMatrixStack->pushMatrix();
	ModelMatrixStack->translate(currentPositionTriangleSmall2);
	ModelMatrixStack->rotate(currentRotationTriangleSmall2);
	ModelMatrixStack->scale(0.5f, 0.5f, 0.2f);
	meshTriangle.draw(0.0f, VALUE_90, VALUE_90);
	ModelMatrixStack->popMatrix();

	//Paralelogram
	ModelMatrixStack->pushMatrix();
	ModelMatrixStack->translate(currentPositionParalelogram);
	ModelMatrixStack->rotate(currentRotationParalelogram);
	ModelMatrixStack->scale(2.0f, 2.0f, 0.4f);
	meshParalelogram.draw(VALUE_90, VALUE_90, VALUE_90);
	ModelMatrixStack->popMatrix();

	//Square
	ModelMatrixStack->pushMatrix();
	ModelMatrixStack->translate(currentPositionSquare);
	ModelMatrixStack->rotate(currentRotationSquare);
	ModelMatrixStack->scale(1.0f / (2.0f * M_SQRT2), 1.0f / (2.0f * M_SQRT2), 0.2f);
	meshCube.draw(VALUE_90, 0.0f,VALUE_90);
	ModelMatrixStack->popMatrix();
}
void drawScene()
{
	cameraManager->computeMatrix();

	ModelMatrixStack->loadIdentity();

	ModelMatrixStack->pushMatrix();
	ModelMatrixStack->translate(Position);
	ModelMatrixStack->pushMatrix();
		ModelMatrixStack->translate(0.0f, 0.0f, -0.2f);
		ModelMatrixStack->scale(5.0f, 5.0f, 0.1f);
		ModelMatrixStack->translate(-0.5f, -0.5f, 0.5f);
		meshCube.draw(VALUE_100, VALUE_90, VALUE_80);
		ModelMatrixStack->popMatrix();
		drawTangram();
	ModelMatrixStack->popMatrix();

}

/////////////////////////////////////////////////////////////////////// UPDATE

void updateAnimation()
{
	float vstep = 0.0005f * elapsedTime;

	if (animationForward) {
		t = t + 1.0f * vstep;
		if (t > 3.0f) t = 3.0f;
	}
	else
	{
		t = t - 1.0f * vstep;
		if (t < 0.0f) t = 0.0f;
	}

	if(t < 1.0f)
	{
		currentPositionTriangleBig1 = lerp(initialPositionTriangleBig1, secondPositionTriangleBig1, t);
		currentPositionTriangleBig2 = lerp(initialPositionTriangleBig2, secondPositionTriangleBig2, t);
		currentPositionTriangleMedium = lerp(initialPositionTriangleMedium, secondPositionTriangleMedium, t);
		currentPositionTriangleSmall1 = lerp(initialPositionTriangleSmall1, secondPositionTriangleSmall1, t);
		currentPositionTriangleSmall2 = lerp(initialPositionTriangleSmall2, secondPositionTriangleSmall2, t);
		currentPositionParalelogram = lerp(initialPositionParalelogram, secondPositionParalelogram, t);
		currentPositionSquare = lerp(initialPositionSquare, secondPositionSquare, t);
	} else if(t < 2.0f)
	{

		currentPositionTriangleBig1 = lerp(secondPositionTriangleBig1, thirdPositionTriangleBig1, t - 1.0f);
		currentPositionTriangleBig2 = lerp(secondPositionTriangleBig2, thirdPositionTriangleBig2, t - 1.0f);
		currentPositionTriangleMedium = lerp(secondPositionTriangleMedium, thirdPositionTriangleMedium, t - 1.0f);
		currentPositionTriangleSmall1 = lerp(secondPositionTriangleSmall1, thirdPositionTriangleSmall1, t - 1.0f);
		currentPositionTriangleSmall2 = lerp(secondPositionTriangleSmall2, thirdPositionTriangleSmall2, t - 1.0f);
		currentPositionParalelogram = lerp(secondPositionParalelogram, thirdPositionParalelogram, t - 1.0f);
		currentPositionSquare = lerp(secondPositionSquare, thirdPositionSquare, t - 1.0f);

		currentRotationTriangleBig1 = slerp(initialRotationTriangleBig1, finalRotationTriangleBig1, t - 1.0f);
		currentRotationTriangleBig2 = slerp(initialRotationTriangleBig2, finalRotationTriangleBig2, t - 1.0f);
		currentRotationTriangleMedium = slerp(initialRotationTriangleMedium, finalRotationTriangleMedium, t - 1.0f);
		currentRotationTriangleSmall1 = slerp(initialRotationTriangleSmall1, finalRotationTriangleSmall1, t - 1.0f);
		currentRotationTriangleSmall2 = slerp(initialRotationTriangleSmall2, finalRotationTriangleSmall2, t - 1.0f);
		currentRotationParalelogram = slerp(initialRotationParalelogram, finalRotationParalelogram, t - 1.0f);
		currentRotationSquare = slerp(initialRotationSquare, finalRotationSquare, t - 1.0f);

	} else if(t <= 3.0f)
	{
		currentPositionTriangleBig1 = lerp(thirdPositionTriangleBig1, finalPositionTriangleBig1, t-2.0f);
		currentPositionTriangleBig2 = lerp(thirdPositionTriangleBig2, finalPositionTriangleBig2, t-2.0f);
		currentPositionTriangleMedium = lerp(thirdPositionTriangleMedium, finalPositionTriangleMedium, t - 2.0f);
		currentPositionTriangleSmall1 = lerp(thirdPositionTriangleSmall1, finalPositionTriangleSmall1, t - 2.0f);
		currentPositionTriangleSmall2 = lerp(thirdPositionTriangleSmall2, finalPositionTriangleSmall2, t - 2.0f);
		currentPositionParalelogram = lerp(thirdPositionParalelogram, finalPositionParalelogram, t - 2.0f);
		currentPositionSquare = lerp(thirdPositionSquare, finalPositionSquare, t - 2.0f);
	}

}

void update()
{
	float vstep = 0.0025f * elapsedTime;

	if (isKeyDownW)	Position = Position + vec3(0.0f, 1.0f, 0.0f) * vstep;
	if (isKeyDownS)	Position = Position + vec3(0.0f, -1.0f, 0.0f) * vstep;
	if (isKeyDownA) Position = Position + vec3(-1.0f, 0.0f, 0.0f) * vstep;
	if (isKeyDownD) Position = Position + vec3(1.0f, 0.0f, 0.0f) * vstep;

	updateAnimation();

	cameraManager->update();
}

/////////////////////////////////////////////////////////////////////// CALLBACKS

void cleanup()
{
	shaderManager->destroyShaderProgram();
	destroyBufferObjects();
}

void display()
{
	++FrameCount;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawScene();
	glutSwapBuffers();
}

void idle()
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);	
	elapsedTime = currentTime - lastTime;
	lastTime = currentTime;

	update();
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	WinX = w;
	WinY = h;
	cameraManager->reshape(w, h);
	glViewport(0, 0, WinX, WinY);
}

void timer(int value)
{
	std::ostringstream oss;
	oss << CAPTION << ": " << FrameCount << " FPS @ (" << WinX << "x" << WinY << ")";
	std::string s = oss.str();
	glutSetWindow(WindowHandle);
	glutSetWindowTitle(s.c_str());
	FrameCount = 0;
	glutTimerFunc(1000, timer, 0);
}

/////////////////////////////////////////////////////////////////////// KEYBOARD

void keyUp(unsigned char key, int xx, int yy) {

	switch (key) {
	case 'w':
		isKeyDownW = false;
		break;
	case 's':
		isKeyDownS = false;
		break;
	case 'a':
		isKeyDownA = false;
		break;
	case 'd':
		isKeyDownD = false;
		break;
	}

}

void processKeys(unsigned char key, int xx, int yy)
{
	switch (key) {
	case 27:
		glutLeaveMainLoop();
		break;
	case 'p':
		cameraManager->changeCamera();
		break;
	case 'g':
		cameraManager->changeRotation();
		break;
	case 'w':
		isKeyDownW = true;
		break;
	case 's':
		isKeyDownS = true;
		break;
	case 'a':
		isKeyDownA = true;
		break;
	case 'd':
		isKeyDownD = true;
		break;
	case 'q':
		animationForward = !animationForward;
		break;
	}
}

/////////////////////////////////////////////////////////////////////// MOUSE

void processMouseButtons(int button, int state, int xx, int yy)
{
	cameraManager->mouse(button, state, xx, yy);
}


void processMouseMotion(int xx, int yy)
{
	cameraManager->mouseMotion(xx, yy);
}

void mouseWheel(int wheel, int direction, int x, int y)
{
	cameraManager->mouseWheel(wheel, direction, x, y);
}

/////////////////////////////////////////////////////////////////////// SETUP

void setupCallbacks()
{
	glutCloseFunc(cleanup);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);

	glutKeyboardUpFunc(keyUp);
	glutKeyboardFunc(processKeys);
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);
	glutMouseWheelFunc(mouseWheel);

	glutTimerFunc(0, timer, 0);
}

void checkOpenGLInfo()
{
	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *version = glGetString(GL_VERSION);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	std::cerr << "OpenGL Renderer: " << renderer << " (" << vendor << ")" << std::endl;
	std::cerr << "OpenGL version " << version << std::endl;
	std::cerr << "GLSL version " << glslVersion << std::endl;
}

void setupOpenGL()
{
	checkOpenGLInfo();
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);
	glDepthRange(0.0, 1.0);
	glClearDepth(1.0);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
}

void setupGLEW()
{
	glewExperimental = GL_TRUE;
	GLenum result = glewInit();
	if (result != GLEW_OK) {
		std::cerr << "ERROR glewInit: " << glewGetString(result) << std::endl;
		exit(EXIT_FAILURE);
	}
	GLenum err_code = glGetError();
}

void setupGLUT(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitContextVersion(3, 3);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutInitWindowSize(WinX, WinY);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	WindowHandle = glutCreateWindow(CAPTION);
	if (WindowHandle < 1) {
		std::cerr << "ERROR: Could not create a new rendering window." << std::endl;
		exit(EXIT_FAILURE);
	}

}

void init(int argc, char* argv[])
{
	setupGLUT(argc, argv);
	setupGLEW();
	setupOpenGL();

	meshTriangle.createMesh(std::string("models/triangle.obj"));
	meshCube.createMesh(std::string("models/cube.obj"));
	meshParalelogram.createMesh(std::string("models/paralelogram.obj"));
	shaderManager->createShaderProgram(std::string("shader/BasicShader.vert"), 
									std::string("shader/BasicShader.frag"));
	createBufferObjects();
	cameraManager->init(shaderManager, meshCube.VaoId);

	setupCallbacks();
}

int main(int argc, char* argv[])
{
	init(argc, argv);
	glutMainLoop();
	exit(EXIT_SUCCESS);
}

///////////////////////////////////////////////////////////////////////

