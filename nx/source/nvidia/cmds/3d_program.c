#include <switch.h>
#include <string.h>

void vnBindProgram(Vn* vn, NvProgramStage stage, u32 offset, u8 num_gprs)
{
    if (!offset)
    {
        // Disable the shader stage
        vnAddCmd(
            vn,
            NvIncr(0, NvReg3D_ShaderProgramSelect(stage >> 4), stage));
        return;
    }

    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_ShaderProgramSelect(stage >> 4), stage | 1, // bit0 enables the shader stage
                                                           offset),
        NvIncr(0, NvReg3D_ShaderProgramGprAlloc(stage >> 4), num_gprs));
}
