#include <switch.h>
#include <string.h>

void vnSetRenderTargets(Vn* vn, VnRenderTargetConfig* targets, u32 num_targets) {
    size_t i;

    vnAddCmd(vn,
        NvIncr(0, NvReg3D_ScreenScissorHorizontal, 0 | (targets[0].width << 16), 0 | (targets[0].height << 16)),
        NvIncr(0, NvReg3D_RenderTargetControl, (076543210 << 4) | num_targets));

    for (i=0; i<num_targets; i++) {
        vnAddCmd(
            vn,
            NvIncr(0,
                NvReg3D_RenderTargetAddr(i),
                targets[i].gpu_addr >> 32,
                targets[i].gpu_addr,
                targets[i].width,
                targets[i].height,
                targets[i].format,
                targets[i].tile_mode,
                1, // TODO: Array support
                0, // TODO: Layer stride
                0  // TODO: First layer
            )
        );
    }
}
