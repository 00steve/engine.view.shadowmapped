#include "shadowmappedview.h"

ShadowMappedView::ShadowMappedView(){
    depthMapShader = new Shader("shadowmap_pass1");
    cout << "build shadow map view\n";
}


void ShadowMappedView::OnSetSettings(){
    VarMap settings = Settings();
    if(settings.IsSet("camera")){
		cameraName = settings.get<string>("camera");
        GlobalRequest(cameraName);
    }
    View::OnSetSettings();
}

void ShadowMappedView::OnGlobalRequest(Node* globalNodeRef,string name){
	if(name == cameraName){
		camera = (Camera*)globalNodeRef;
		cout << "shadowmap view got camera\n";
        Link(globalNodeRef);
        return;
	}
	View::OnGlobalRequest(globalNodeRef,name);
}


void ShadowMappedView::Update(){
}

void ShadowMappedView::Draw(){

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glEnable(GL_SCISSOR_TEST);
	glScissor(bottomLeft.x,bottomLeft.y,dimensions.x,dimensions.y);
	glViewport(bottomLeft.x,bottomLeft.y,dimensions.x,dimensions.y);

    glClearColor(0,0,0,1);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        if(camera){
            camera->TranslateView();
        } else {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
        }
        glMatrixMode(GL_MODELVIEW);
        glEnable(GL_DEPTH_TEST);
        glCullFace(GL_BACK);
        glEnable(GL_CULL_FACE);
        glUseProgram(depthMapShader->Program());
        if(renderSubject) {
                renderSubject->Draw();
        }

    glPopMatrix();
    glPopAttrib();
}
