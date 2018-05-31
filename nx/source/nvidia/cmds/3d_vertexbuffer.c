#include <switch.h>
#include <string.h>

void vnBindVertexBuffer(Vn* vn, u32 slot, iova_t start, size_t size)
{
    iova_t end = start + size - 1;

    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_VertexArrayStart(slot), vnSetAddr(start)),
        NvIncr(0, NvReg3D_VertexArrayEnd(slot), vnSetAddr(end)));
}
