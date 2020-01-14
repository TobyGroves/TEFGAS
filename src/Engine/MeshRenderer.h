#ifndef _MESHRENDERER_H_
#define _MESHRENDERER_H_

#include "rend.h"
#include "Component.h"

class MeshRenderer : public Component
{
private:
	std::sr1::shared_ptr<rend::Context> context;
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Mesh> mesh;
	std::sr1::shared_ptr<rend::Texture> texture;

	void onStart() {}
	void onUpdate() {}
	void onDraw();

	float angle = 0.0f;

public:
	void init(const char* _objPath, const char* _texPath);
};

#endif
