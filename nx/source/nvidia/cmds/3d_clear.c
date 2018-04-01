#include <switch.h>
#include <string.h>

void nvVnClearBuffer(
    Vn* vn, NvBuffer* buf, u32 width, u32 height, float colors[4])
{
    VnCmd(vn, NvIncr(0, NvReg3D_ClearColor,
        f2i(colors[0]), f2i(colors[1]), f2i(colors[2]), f2i(colors[3])));
    VnCmd(vn, NvIncr(0, NvReg3D_ScreenScissorHorizontal,
        0 | (0x100 << 16), 0 | (0x100 << 16)));
    VnCmd(vn, NvImm(0, NvReg3D_RenderTargetControl, 1)); // bit0 probably enables RT #0

    iova_t gpu_addr = nvBufferGetGpuAddr(buf);
    VnCmd(vn,
        NvIncr(NvReg3D_RenderTargetNAddr + 0x10*0,
            gpu_addr >> 32, gpu_addr,
            width, height,
            0 /* Format */,
            0x1000 /* TileMode */,
            1 /* ArrayMode */,
            0 /* Stride */,
            0 /* BaseLayer */
        ));
    int z;
    for (z=0; z<32; z++)
        VnCmd(vn, NvImm(0, NvReg3D_ClearBufferTrigger, 0x3c | (z << 10)));
    /*
      TODO:
    IMMED_NVC0(push, NVC0_3D(ZETA_ENABLE), 0);
    IMMED_NVC0(push, NVC0_3D(MULTISAMPLE_MODE), 0);
    */    
}
