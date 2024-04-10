#pragma once
#include <ld55/platform/window.h>
#include <memory>

namespace ld55 {
class ServiceLocator {
public:
  static inline const std::unique_ptr<Window> &GetWindow() { return window_; }
  static inline void Provide(Window *window) {
    if (window_ != nullptr)
      return;
    window_ = std::unique_ptr<Window>(window);
  }

private:
  static inline std::unique_ptr<Window> window_ = nullptr;
};
} // namespace ld55