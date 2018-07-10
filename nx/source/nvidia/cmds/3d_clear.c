#include <switch.h>
#include <string.h>

void vnClearBuffer(Vn* vn, u32 width, u32 height, const float colors[4])
{
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_ClearColor, f2i(colors[0]), f2i(colors[1]), f2i(colors[2]), f2i(colors[3])),
        NvImm(0, 0x54E, 0), NvImm(0, 0x54D, 0)); // Disable zeta + multisample

    // Only layer 0.
    int z;
    for (z=0; z<1; z++)
        vnAddCmd(vn, NvImm(0, NvReg3D_ClearBufferTrigger, 0x3c | (z << 10)));
}
