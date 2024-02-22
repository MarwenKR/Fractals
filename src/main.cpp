#include <GLFW/glfw3.h>
#include <complex>
#include <cmath>
#include <iostream>

#include "include/utils.hpp"

void colot_template(double t, double& r, double& g,  double& b){
r = -std::log(t);
g = std::min(1-t*t,0.5);
b = 1+std::log((t));
}
void drawPixel(double x, double y, double r, double g, double b)
{
    glBegin(GL_POINTS);
    glColor3d(r,g,b);
    glVertex2d(x, y);
    glEnd();
}


void julia_point(double x, double y, int r, int depth,int p, int max, std::complex<double> c, std::complex<double> z)
{
    if (std::abs(z) > r)
    {
        double t = depth<=max?(double)depth/max:0.1;
        double r,g,b;
        colot_template(t,r,g,b);
        drawPixel(x, y,r,g,b);
        depth = 1;
    }
    if (std::sqrt(std::pow((x - X / 2), p) + std::pow((y - Y / 2), p)) > Y / 2)
    {
        // Do nothing, pixel out of bounds
    }
    if (depth < max / 4)
    {
        return;
    }
    julia_point(x, y, r, depth - 1,p, max, c, std::pow(z, p) + c);
}

void juliaset(int depth,int p, std::complex<double> c, int r, int detail)
{
    for (double x = X / 2 - Y / 2; x < X / 2 + Y / 2; x += detail)
    {
        for (double y = 0; y < Y; y += detail)
        {
            double zx = 2 * r * static_cast<double>(x - X / 2) / Y ; // real part of z
            double zy = 2 * r * static_cast<double>(y - Y / 2) / Y ; // imaginary part of z

            julia_point(x, y, r, depth, p,depth, c, zx+ zy* std::complex<double>(0, 1));
        }
    }
}

int main()
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(X, Y, "Julia Set", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Set up OpenGL for drawing
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, X, Y, 0, 1, -1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Draw the Julia set
        juliaset(32, 2,std::complex<double>(-0.67, 0.015),2,1);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
