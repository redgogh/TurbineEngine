/* ======================================================================== */
/* CoordinateAxisRender.h                                                   */
/* ======================================================================== */
/*                        This file is part of:                             */
/*                            BRIGHT ENGINE                                 */
/* ======================================================================== */
/*                                                                          */
/* Copyright (C) 2022 TheSampson All rights reserved.                       */
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
#ifndef _RENDERER_AXIS_LINE_H_
#define _RENDERER_AXIS_LINE_H_

#include "Drivers/RenderDevice.h"
#include <Turbine/Math.h>

class CoordinateAxisRender {
public:
    U_MEMNEW_ONLY CoordinateAxisRender(RenderDevice *v_RenderDevice, VkRenderPass v_RenderPass);
    ~CoordinateAxisRender();

    void SetViewUniformBuffer(Matrix4 view, Matrix4 projection);
    void CmdDrawCoordinateAxisRendering(VkCommandBuffer cmdBuffer, uint32_t w, uint32_t h);

private:
    struct ViewUniformBuffer
    {
        Matrix4 viewMatrix;
        Matrix4 projectionMatrix;
    };

    ViewUniformBuffer viewUniformBuffer;

    RenderDevice *rd;
    RenderDevice::Buffer *uniformBuffer;
    VkDescriptorSetLayout descriptor_set_layout;
    VkDescriptorSet descriptor_set;
    RenderDevice::Pipeline *pipeline;
};

#endif /* _RENDERER_AXIS_LINE_H_ */