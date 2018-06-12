#include <switch.h>
#include <string.h>

void vnSetViewport(Vn* vn, size_t index, VnViewportConfig* c) {
    vnAddCmd(
        vn,
        NvIncr(
            0,
            NvReg3D_ViewportScaleX(index),
            f2i(c->scale[0]), // ScaleX
            f2i(c->scale[1]), // ScaleY
            f2i(c->scale[2]), // ScaleZ
            f2i(c->translate[0]), // TranslateX
            f2i(c->translate[1]), // TranslateY
            f2i(c->translate[2]), // TranslateZ
            0, // Swizzles
            0  // SubpixelPrecisionBias
        ),
        NvIncr(
            0,
            NvReg3D_ViewportHorizontal(index),
            (c->window.w << 16) | c->window.x,
            (c->window.h << 16) | c->window.y,
            c->near,
            c->far
        )
    );
}
