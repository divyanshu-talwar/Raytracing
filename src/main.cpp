#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>

#include <iostream>

#include <IL/il.h>

#include "camera.h"
#include "renderengine.h"
#include "world.h"
#include "material.h"
#include "object.h"
#include "sphere.h"
#include "triangle.h"
#include "cylinder.h"
#include "lightsource.h"
#include "pointlightsource.h"
#include "utility.hpp"

//Globals
GLFWwindow * mainWindow = nullptr;
GLuint program;
GLuint quadVao,quadVbo;
int screen_width = 800, screen_height = 600;
float quadVertices[] = {-1, -1,
                        1, -1,
                        1, 1,
                        -1, -1,
                        1, 1,
                        -1, 1};
GLuint texImage;
GLint uniform_texImage;

Camera *camera;
RenderEngine *engine;

int init_resources()
{

    auto vert(fileToCharArr("./Resources/vshader.vert"));
    auto frag(fileToCharArr("./Resources/fshader.frag"));



    //Create program
    program = makeProgram(compileShader(shDf(GL_VERTEX_SHADER,&vert[0],vert.size())),compileShader(shDf(GL_FRAGMENT_SHADER,&frag[0],frag.size())),true);



    //Initialize raytracer objects
    Vector3D camera_position(0, 0, 10);
    Vector3D camera_target(0, 0, 0); //Looking down -Z axis
    Vector3D camera_up(0, 1, 0);
    float camera_fovy =  45;
    camera = new Camera(camera_position, camera_target, camera_up, camera_fovy, screen_width, screen_height);
    //Create a world
    World *world = new World;
    world->setAmbient(Color(1));
    world->setBackground(Color(0.1, 0.3, 0.6));
    
    Material *m = new Material(world);
    m->color = Color(0.1, 0.7, 0.0);
    m->ka = 0.1;
    m->kd = 0.6;
    m->ks = 0.9;
    m->kr = 0.4;
    m->kt = 0.6;
    m->eta = 1.54;
    m->n = 128;

    // Object *cylinder = new Cylinder(Vector3D(5, 0, -10), 0.75, m);
    // world->addObject(cylinder);

    Object *sphere = new Sphere(Vector3D(2, 0, -10), 2.5, m);
    // Object *sphere = new Sphere(Vector3D(5, 0, -10), 3, m);
    world->addObject(sphere);

    // Object *triangle = new Triangle(Vector3D(-4, -2, -5), Vector3D(4, -2, -5), Vector3D(0, 5, -10), m);
    // world->addObject(triangle);
    Material *m2 = new Material(world);
    m2->color = Color(1.0, 0.6, 0.2);
    m2->ka = 0.1;
    m2->kd = 0.6;
    m2->ks = 0.9;
    m2->n = 164;

    Object *triangle = new Triangle(Vector3D(-9, -8, -12), Vector3D(10, -6, -20), Vector3D(-2, 12, -20), m2);
    // Object *triangle = new Triangle(Vector3D(1.5, -3, -10), Vector3D(-8.5, -3, -10), Vector3D(-3.5, 3, -10), m2);
    world->addObject(triangle);

    LightSource *light = new PointLightSource(world, Vector3D(7, 10, 10), Color(1, 1, 1));
    world->addLight(light);

    engine = new RenderEngine(world, camera);


    glGenVertexArrays(1, &quadVao);



    glGenBuffers(1, &quadVbo);
    glBindBuffer(GL_ARRAY_BUFFER, quadVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);



    glBindVertexArray(quadVao);
    glBindBuffer(GL_ARRAY_BUFFER,quadVbo);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2* sizeof(GLfloat),(GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);



    //Initialise texture
    glGenTextures(1, &texImage);
    glBindTexture(GL_TEXTURE_2D, texImage);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, screen_width, screen_height, 0, GL_RGB, GL_UNSIGNED_BYTE, camera->getBitmap());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    uniform_texImage = glGetUniformLocation(program, "texImage");
    if(uniform_texImage == -1)
    {
        fprintf(stderr, "Could not bind uniform: texImage\n");
        return 0;
    }
    return 1;
}

void SaveImage()
{
    ILuint imageID = ilGenImage();
    ilBindImage(imageID);
    ilTexImage(camera->getWidth(), camera->getHeight(), 1, 3, IL_RGB, IL_UNSIGNED_BYTE, camera->getBitmap());
    //ilEnable(IL_FILE_OVERWRITE);
    time_t rawtime;
    time (&rawtime);
    char time_str[26];
    ctime_r(&rawtime, time_str);
    time_str[strlen(time_str) - 1] =0;//Remove trailing return character.
    char imageName[256];
    sprintf(imageName, "Lumina %s.png", time_str);
    ilSave(IL_PNG, imageName);
    fprintf(stderr, "Image saved as: %s\n", imageName);
}

int main(int argc, char** argv) {
    fprintf(stderr, "Welcome to Lumina raytracer.\nPress S to save screenshot, and Esc to exit.\n");
    using namespace std;

    mainWindow = setupGlfw(screen_width,screen_height,"Lumina");

    #ifndef __APPLE__
    GLenum glew_status = glewInit();
    if(glew_status != GLEW_OK)
    {
    fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
    return EXIT_FAILURE;
    }
    #endif

    ilInit();

    if (1 != init_resources()) {
        exit(-1);
    }

    double last = 0,accumulator = 0;
    glfwSetTime(last);
    double delta = 0.0f;
    glfwSwapInterval(1);
    double last_save = glfwGetTime();

    bool done = false;
    while (!glfwWindowShouldClose(mainWindow)) {


        double curr = glfwGetTime();
        delta = curr-last;
        last = curr;
        glfwPollEvents();

        if(glfwGetKey(mainWindow,GLFW_KEY_S) == GLFW_PRESS){
            if(glfwGetTime() - last_save > 0.1){
                SaveImage();
                last_save = glfwGetTime();
            }
        }

        if(glfwGetKey(mainWindow,GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(mainWindow, GLFW_TRUE);
        }


        if(done)
            continue;
        if(engine->renderLoop())
        {
            done = true;
            cout << "Rendering complete" << endl;
        }

        //Update texture on GPU
        glBindTexture(GL_TEXTURE_2D, texImage);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, screen_width, screen_height, GL_RGB, GL_UNSIGNED_BYTE, camera->getBitmap());



        glClearColor(0.0, 0.0, 0.0, 0.0);

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texImage);
        glUniform1i(uniform_texImage, 0);


        glBindVertexArray(quadVao);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);

        glfwSwapBuffers(mainWindow);

    }


    glDeleteVertexArrays(1,&quadVao);
    glDeleteBuffers(1,&quadVbo);

    glDeleteProgram(program);
    glDeleteTextures(1, &texImage);
    return EXIT_SUCCESS;
}
