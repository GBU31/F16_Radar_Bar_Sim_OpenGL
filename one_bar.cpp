#include <GL/glut.h>


const float radarSize = 200.0f;
const float barWidth = 300.0f;
const float barMaxHeight = 100.0f;
const float barMaxIntensity = 1.0f;
const float barSpeed = 0.5f;
const float barMinHeight = 10.0f;


float barHeight = barMinHeight;
bool barGrowing = true;

void updateBarHeight()
{
    if (barGrowing)
    {
        barHeight += barSpeed;
        if (barHeight >= barMaxHeight)
        {
            barHeight = barMaxHeight;
            barGrowing = false;
        }
    }
    else
    {
        barHeight -= barSpeed;
        if (barHeight <= barMinHeight)
        {
            barHeight = barMinHeight;
            barGrowing = true;
        }
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, radarSize, 0, barMaxHeight);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

   
    float barY = (barMaxHeight ) / 2.0f;
    glRectf(0, barY, barWidth, barY + barHeight);

    glutSwapBuffers();
}

void update(int value)
{
    updateBarHeight();
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 300);
    glutCreateWindow("1 B Sim");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}
