#include <GL/glut.h>


const float boxSize = 200.0f;
const float dotRadius = 5.0f;
const float dotSpeed = 3.0f;


float dotX = -boxSize / 2 + dotRadius;
float dotY = -boxSize / 2 + dotRadius; 
int dotDirection = 3; 

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-boxSize / 2, boxSize / 2, -boxSize / 2, boxSize / 2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-boxSize / 2, -boxSize / 2);
    glVertex2f(boxSize / 2, -boxSize / 2);
    glVertex2f(boxSize / 2, boxSize / 2);
    glVertex2f(-boxSize / 2, boxSize / 2);
    glEnd();

  
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(dotX - dotRadius, dotY - dotRadius);
    glVertex2f(dotX + dotRadius, dotY - dotRadius);
    glVertex2f(dotX + dotRadius, dotY + dotRadius);
    glVertex2f(dotX - dotRadius, dotY + dotRadius);
    glEnd();

    glutSwapBuffers();
}

void update(int value)
{
    
    switch (dotDirection)
    {
        case 0: 
            dotX += dotSpeed;
            if (dotX >= boxSize / 2 - dotRadius)
            {
                dotX = boxSize / 2 - dotRadius;
                dotDirection = 1; 
            }
            break;
        case 1: 
            dotY -= dotSpeed;
            if (dotY <= -boxSize / 2 + dotRadius)
            {
                dotY = -boxSize / 2 + dotRadius;
                dotDirection = 2;
            }
            break;
        case 2: 
            dotX -= dotSpeed;
            if (dotX <= -boxSize / 2 + dotRadius)
            {
                dotX = -boxSize / 2 + dotRadius;
                dotDirection = 3; 
            }
            break;
        case 3: 
            dotY += dotSpeed;
            if (dotY >= boxSize / 2 - dotRadius)
            {
                dotY = boxSize / 2 - dotRadius;
                dotDirection = 0;
            }
            break;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("1 Sim B");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}
