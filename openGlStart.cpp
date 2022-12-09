#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
  glfwInit(); //Initialize glfw
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //Specify major version of OpenGl
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); //Specify minor version of OpenGl
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Specify which profile of OpenGl we are using
}
