#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace sm {
    struct Camera {
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 5.0f);
        glm::vec3 target = glm::vec3(0.0f);

        float fov = 60.0f;
        float nearPlane = 0.01f;
        float farPlane = 100.0f;
        bool orthographic = false;
        float orthoHeight = 6.0f;
        float aspectRatio = 1.77f;

        inline glm::mat4 viewMatrix() const {
            return glm::lookAt(position, target, glm::vec3(0, 1, 0));
        }

        inline glm::mat4 projectionMatrix() const {
            if (orthographic) {
                return glm::ortho(orthoHeight, aspectRatio, nearPlane, farPlane);
            } else {
                return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
            }
        }
    };
}