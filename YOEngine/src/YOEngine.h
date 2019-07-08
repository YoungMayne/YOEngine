#pragma once

#include "items/Utils.h"
#include "items/Types.h"
#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"
#include "math/mat4.h"
#include "input/Event.h"
#include "graphics/Mesh.h"
#include "graphics/Shader.h"
#include "graphics/Window.h"
#include "graphics/Camera.h"
#include "graphics/Vertex.h"
#include "graphics/Texture.h"
#include "graphics/Transform.h"


#ifdef _DEBUG

#define STARTENGINE main

#else

#define STARTENGINE WinMain

#endif 
