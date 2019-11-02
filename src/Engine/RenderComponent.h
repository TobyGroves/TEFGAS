#ifndef TEFGAS_RENDERCOMPONENT_H
#define TEFGAS_RENDERCOMPONENT_H
#include "Component.h"

namespace TEFGAS{

class RenderComponent : public Component
{
    public:
        RenderComponent();

        void onDisplay() override;

    private:
        unsigned int programId;
        unsigned int vaoId;
};
}

#endif