#include"Component.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>


namespace TEFGAS
{

class Transform : public Component
{
public:
    Transform();
    Transform(glm::vec3 _position,glm::vec3 _rotation,glm::vec3 _scale);

    glm::vec3 getPosition(){return position;}
    glm::vec3 getRotation(){return rotation;}
    glm::vec3 getScale(){return scale;}

    void setPosition(glm::vec3 _position){position = _position;}
    void setRotation(glm::vec3 _rotation){rotation = _rotation;}
    void setScale(glm::vec3 _scale){scale =_scale;}

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;


};

}