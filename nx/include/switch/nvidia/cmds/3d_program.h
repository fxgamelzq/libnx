#pragma once

typedef enum {
    NvProgramStage_VP_A=0x00,
    NvProgramStage_VP_B=0x10,
    NvProgramStage_TCP=0x20,
    NvProgramStage_TEP=0x30,
    NvProgramStage_GP=0x40,
    NvProgramStage_FP=0x50,
} NvProgramStage;

void vnBindProgram(Vn* vn, NvProgramStage stage, u8 num_gprs, NvBuffer* buf);
