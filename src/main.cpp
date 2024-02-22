#include <GLFW/glfw3.h>
#include <complex>
#include <cmath>
#include <iostream>

#define Y 450
#define X 800

void drawPixel(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void julia_point(float x, float y, int r, int depth, int max, std::complex<double> c, std::complex<double> z)
{
    if (std::abs(z) > r)
    {
        glColor3f(1.0f, 0.0f, 0.0f); // Red color
        drawPixel(x, y);
        depth = 0;
    }
    if (std::sqrt(std::pow((x - X / 2), 2) + std::pow((y - Y / 2), 2)) > Y / 2)
    {
        // Do nothing, pixel out of bounds
    }
    if (depth < max / 4)
    {
        return;
    }
    julia_point(x, y, r, depth - 1, max, c, std::pow(z, 2) + c);
}

void juliaset(int depth, std::complex<double> c, int r, int detail)
{
    for (float x = X / 2 - Y / 2; x < X / 2 + Y / 2; x += detail)
    {
        for (float y = 0; y < Y; y += detail)
        {
            julia_point(x, y, r, depth, depth, c, (2 * r * static_cast<double>(x - X / 2) / Y) + (2 * r * static_cast<double>(y - Y / 2) / Y) * std::complex<double>(0, 1));
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
        juliaset(1000, std::complex<double>(-0.128, 0.78), 2, 1);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
