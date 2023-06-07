#include <GL/glut.h>

const int scanningAreaWidth = 400;
const int scanningAreaHeight = 300; 
const int radarSpeed = 2; 

int dotX = 0; 
int dotY = 0; 
bool isMovingRight = true; 
bool isMovingUp = false; 
bool isCycleComplete = false;

void drawDot()
{
    glColor3f(1.0f, 1.0f, 1.0f); 

   
    glBegin(GL_QUADS);
    glVertex2i(dotX, dotY);
    glVertex2i(dotX + 10, dotY);
    glVertex2i(dotX + 10, dotY + 10);
    glVertex2i(dotX, dotY + 10);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawDot();
    glutSwapBuffers();
}

void update(int value)
{
    
    if (!isCycleComplete)
    {
        if (isMovingRight)
        {
            dotX += radarSpeed;
            if (dotX >= scanningAreaWidth)
            {
              
                dotX = scanningAreaWidth;
                isMovingRight = false;
                isMovingUp = false;
            }
        }
        else
        {
            if (!isMovingUp)
            {
                dotY += radarSpeed;
                if (dotY >= scanningAreaHeight)
                {
                  
                    dotY = scanningAreaHeight;
                    isMovingRight = false;
                    isMovingUp = true;
                }
            }
            else
            {
                dotX -= radarSpeed;
                if (dotX <= 0)
                {
                    
                    dotX = 0;
                    isMovingRight = true;
                    isMovingUp = true;
                    isCycleComplete = true;
                }
            }
        }
    }

    glutPostRedisplay();

    if (!isCycleComplete)
        glutTimerFunc(16, update, 0); 
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("4 B Sim");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}
