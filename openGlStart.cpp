#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height) //This function will be called everytime a resize of a window happens
{
  glViewport(0, 0, width, height); //Specifies the area where to render openGL on the window, first two parameters tells the function where top left corner is, and the last two are width and height;
}

int main()
{
  glfwInit(); //Initialize glfw
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //Specify major version of OpenGl
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); //Specify minor version of OpenGl
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Specify which profile of OpenGl we are using

  GLFWwindow* window = glfwCreateWindow(800, 600, "First window", NULL, NULL); //Creating a window and storing it as a pointer with a name "window"
  //glfwCreateWindow function takes 5 params (width, height, name of window, should it open fullscreen, which window to share context with, it could be textures, vertex, element buffers, etc.)
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

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//This function adjusts the viewport everytime the window gets resized. It takes in two parameters, a GLFWwindow* and a function

  while(!glfwWindowShouldClose(window)) //glfwWindowShouldClose is true when an attempt of closing a window happens
  {
    glfwSwapBuffers(window); //Swaps the back buffer with the front buffer
    glfwPollEvents(); //Registers events like mouse clicks, keyboard inputs, etc.
  }

  glfwTerminate(); //Terminates all windows and frees allocated resources
  return 0; //Returns 0 stating everything went fine
}
