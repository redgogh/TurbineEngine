/* ======================================================================== */
/* renderer.cpp                                                             */
/* ======================================================================== */
/*                        This file is part of:                             */
/*                           COPILOT ENGINE                                 */
/* ======================================================================== */
/*                                                                          */
/* Copyright (C) 2022 Vcredent All rights reserved.                         */
/*                                                                          */
/* Licensed under the Apache License, Version 2.0 (the "License");          */
/* you may not use this file except in compliance with the License.         */
/*                                                                          */
/* You may obtain a copy of the License at                                  */
/*     http://www.apache.org/licenses/LICENSE-2.0                           */
/*                                                                          */
/* Unless required by applicable law or agreed to in writing, software      */
/* distributed under the License is distributed on an "AS IS" BASIS,        */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, e1ither express or implied */
/* See the License for the specific language governing permissions and      */
/* limitations under the License.                                           */
/*                                                                          */
/* ======================================================================== */
#include "renderer.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "NullDereference"

RenderDevice *Renderer::rd = NULL;
RendererScene *Renderer::scene = NULL;

#define _CHECK_RENDERER_INIT() do {                                                                          \
    EXIT_FAIL_COND_V(rd, "-engine error: the renderer is not initialized! call Renderer::Initialize(rd)");   \
} while(0)

void Renderer::Initialize(RenderDevice *v_rd)
{
    rd = v_rd;
    // initialize
    scene = memnew(RendererScene, rd);
}

void Renderer::Destroy()
{
    _CHECK_RENDERER_INIT();
    memdel(scene);
}

void Renderer::PushSceneRenderObject(RenderObject *v_object)
{
    _CHECK_RENDERER_INIT();
    scene->push_render_object(v_object);
}

void Renderer::BeginScene(Camera *v_camera, uint32_t v_width, uint32_t v_height)
{
    _CHECK_RENDERER_INIT();
    scene->cmd_begin_scene_renderer(v_camera, v_width, v_height);
}

void Renderer::EndScene(RenderDevice::Texture2D **texture, RenderDevice::Texture2D **depth)
{
    _CHECK_RENDERER_INIT();
    scene->cmd_end_scene_renderer(texture, depth);
}
#pragma clang diagnostic pop