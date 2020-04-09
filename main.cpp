#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

#include <iostream>
#include <unistd.h>

#define MS_PER_SECOND 16000

int main()
{
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow* window = glfwCreateWindow(1280, 720, "Vulkan Window", nullptr, nullptr);

  uint32_t extensionCount = 0;
  vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

  std::cout << extensionCount << " extension(s) supported" << std::endl;

  while (!glfwWindowShouldClose(window))
  {
    double start = glfwGetTime();
    glfwPollEvents();

    usleep(MS_PER_SECOND);
    printf("%.2f\r", 1.0 / (glfwGetTime() - start));
    fflush(stdout);
  }

  glfwDestroyWindow(window);

  glfwTerminate();
  return 0;
}
