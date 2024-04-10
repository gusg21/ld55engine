#pragma once

#include <string>
#include <vector>
#include "mesh.h"

namespace ld55 {
    class Model {
    public:
        Model(const std::string& filePath);
        void draw();
    private:
        std::vector<ld55::Mesh> m_meshes;
    };
};