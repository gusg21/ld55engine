#include "ld55/engine.h"

#include <cstdio>

#include <ld55/service_locator.h>

#include "platform/sdl_window.h"

using namespace ld55;

void Engine::Init() { 
    printf("Creating window...");
    ServiceLocator::Provide(new SDLWindow());
 }