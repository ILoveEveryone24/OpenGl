#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
  glfwInit(); //Initialize glfw
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //Specify major version of OpenGl
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); //Specify minor version of OpenGl
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Specify which profile of OpenGl we are using

  GLFWwindow* window = glfwCreateWindow(800, 600, "First window", glfwGetPrimaryMonitor(), NULL); //Creating a window and storing it as a pointer with a name "window"
  //glfwCreateWindow function takes 5 params (width, height, name of window, which monitor to make the window on, which window to share context with, it could be textures, vertex, element buffers, etc.)
  if(window == NULL) //Check if the function returned NULL
  {
    std::cout << "No window :c" << std::endl;//Print "No window :c"
    glfwTerminate();//Terminates all windows and frees allocated resources
    return -1;//Returns -1 indicating it's an error
  }
  glfwMakeContextCurrent(window);//Makes current context on current thread "window", only one context is allowed per thread

  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))//Initialize GLAD, we pass glfwGetProcAddress of a type GLADloadproc, it is a specific address that is different from OS to OS
  {
    std::cout << "RIP glad" << std::endl; //Print "RIP glad"
    return -1;//Return -1 indicating there's been an error
  }

  glViewport(0, 0, 800, 600); //Specifies the area where to render openGL on the window, first two parameters tells the function where top left corner is, and the last two are width and height;
}
