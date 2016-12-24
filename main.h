#ifndef __MAIN_H__
#define __MAIN_H__

#define GLFW_INCLUDE_GLU
#define GLFW_INCLUDE_GLCOREARB
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include "shadowmappedview.h"
#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

    DLL_EXPORT View* Build();

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
