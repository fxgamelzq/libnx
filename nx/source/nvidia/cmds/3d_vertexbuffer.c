#include <switch.h>
#include <string.h>
#include <assert.h>

void vnBindVertexBuffer(Vn* vn, u32 slot, iova_t start, size_t size)
{
    iova_t end = start + size - 1;

    vnAddCmd(
        vn,
        NvImm (0, NvReg3D_IndexBatchCount, 0),
        NvIncr(0, NvReg3D_VertexArrayStart(slot), vnSetAddr(start)),
        NvIncr(0, NvReg3D_VertexArrayEnd(slot), vnSetAddr(end)));
}

void vnDrawArrays(Vn* vn, NvPrimitiveMode mode, u32 start, u32 count)
{
    vnAddCmd(
        vn,
        NvImm (0, NvReg3D_VertexBeginGL, mode),
        NvIncr(0, NvReg3D_VertexBufferStart, start, count),
        NvImm (0, NvReg3D_VertexEndGL, 0));
}

void vnBindVertexAttribState(Vn* vn, u32 count, u32* state)
{
    // TODO: Support smaller attrib states
    assert(count < 16);

    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_VertexAttribFormat(0),
               state[0], state[1], state[2], state[3],
               state[4], state[5], state[6], state[7],
               state[8], state[9], state[10], state[11],
               state[12], state[13], state[14], state[15]));
}

void vnBindVertexStreamState(Vn* vn, u32 count, u32* state)
{
    for (int i = 0; i < count; i++)
    {
        vnAddCmd(
            vn,
            NvImm(0, NvReg3D_VertexArrayFetch(i), state[i]));
    }
}
