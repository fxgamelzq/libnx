#include <switch.h>
#include <string.h>

void vnBindProgram(Vn* vn, NvProgramStage stage, u8 num_gprs, NvBuffer* buf)
{
    if (!buf)
    {
        // Disable the shader stage
        vnAddCmd(
            vn,
            NvIncr(0, NvReg3D_ShaderProgramSelect(stage >> 4), stage));
        return;
    }

    iova_t gpu_addr = nvBufferGetGpuAddr(buf);
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_ShaderProgramSelect(stage >> 4), stage | 1, // bit0 enables the shader stage
                                                           gpu_addr >> 32, gpu_addr),
        NvIncr(0, NvReg3D_ShaderProgramGprAlloc(stage >> 4), num_gprs));
}
