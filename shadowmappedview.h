#ifndef SHADOW_MAPPED_VIEW_H
#define SHADOW_MAPPED_VIEW_H

//#include <GL/gl.h>
//#include <engine/graphics/view.h>
//#define GLFW_INCLUDE_GLU
//#define GLFW_INCLUDE_GLCOREARB
//#define GL_GLEXT_PROTOTYPES
//#include <GLFW/glfw3.h>

#define GLFW_INCLUDE_GLU
#define GLFW_INCLUDE_GLCOREARB
#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h>

#include <engine/core/varmap.h>
#include <engine/core/node.h>
#include <engine/graphics/camera.h>
#include <engine/graphics/shader.h>
#include <engine/core/stringutil.h>
#include <engine/graphics/view.h>


class ShadowMappedView : public View{
private:
    Shader* depthMapShader;

    Camera* camera;
    string cameraName;

protected:
    virtual void OnSetSettings();
    virtual void OnGlobalRequest(Node* globalNodeRef,string name);

public:
    ShadowMappedView();
	virtual void Update();
    virtual void Draw();
};
#endif // SHADOW_MAPPED_VIEW_H
