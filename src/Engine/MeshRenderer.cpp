#include "MeshRenderer.h"
#include "Core.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <fstream>

void MeshRenderer::init(const char* _objPath, const char* _texPath)
{
	const char* src =
		"#ifdef VERTEX                                 \n" \
		"                                              \n" \
		"attribute vec3 a_Position;                    \n" \
		"attribute vec2 a_TexCoord;                    \n" \
		"attribute vec3 a_Normal;                      \n" \
		"                                              \n" \
		"uniform mat4 u_Projection;                    \n" \
		"uniform mat4 u_Model;                         \n" \
		"                                              \n" \
		"varying vec3 v_Normal;                        \n" \
		"varying vec2 v_TexCoord;                      \n" \
		"                                              \n" \
		"void main()                                   \n" \
		"{                                             \n" \
		"  gl_Position = u_Projection *                \n" \
		"    u_Model * vec4(a_Position, 1);            \n" \
		"                                              \n" \
		"  v_Normal = a_Normal;                        \n" \
		"  v_TexCoord = a_TexCoord;                    \n" \
		"}                                             \n" \
		"                                              \n" \
		"#endif                                        \n" \
		"#ifdef FRAGMENT                               \n" \
		"                                              \n" \
		"uniform sampler2D u_Texture;                  \n" \
		"                                              \n" \
		"varying vec3 v_Normal;                        \n" \
		"varying vec2 v_TexCoord;                      \n" \
		"                                              \n" \
		"void main()                                   \n" \
		"{                                             \n" \
		"  gl_FragColor = texture2D(u_Texture, v_TexCoord);      \n" \
		"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;  \n" \
		"}                                             \n" \
		"                                              \n" \
		"#endif                                        \n";

	context = rend::Context::initialize();
	shader = context->createShader();
	shader->parse(src);
	mesh = context->createMesh();

	std::ifstream objFile(_objPath);

	if (!objFile.is_open())
		throw rend::Exception("Failed to open .obj file");

	std::string obj;
	std::string line;

	while (!objFile.eof())
	{
		std::getline(objFile, line);
		obj += line + "\n";
	}

	mesh->parse(obj);

	texture = context->createTexture();

	int w = 0, h = 0, comp = 0;

	unsigned char* tex = stbi_load(_texPath, &w, &h, &comp, 3);

	if (!tex)
		throw rend::Exception("Failed to open texture file");

	texture->setSize(w, h);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 3 + x * 3;

			texture->setPixel(x, y, glm::vec3(
				tex[r] / 255.0f,
				tex[r + 1] / 255.0f,
				tex[r + 2] / 255.0f));
		}
	}

	stbi_image_free(tex);

	mesh->setTexture("u_Texture", texture);
}

void MeshRenderer::onDraw()
{
	shader->setUniform("u_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f));
	shader->setUniform("u_Model",
		glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -20)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0, 1, 0))
	);

	angle += 1.0f;

	shader->setMesh(mesh);
	shader->render();
}
