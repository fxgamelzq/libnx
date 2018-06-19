#include <switch.h>
#include <string.h>

static void _vnInitMacros(Vn* vn) {
    // BeginTransformFeedback
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 0, 0),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0,
            0x4744351, 0x708215, 0x4041, 0x20390021, 0x41, 0x41, 0x41, 0x41,
            0x4180021, 0x10041, 0x4041, 0x841, 0x1841, 0x41B0021, 0x40440C1,
            0x1041)
    );

    // ClearColor
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 1, 0x10),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x10,
            0x210C4212, 0x819215, 0x19027, 0x19D0021, 0xFFFFD211, 0x841,
            0xFFFF5097, 0x1000911, 0x91, 0x11)
    );

    // BufferClearDepthStencil
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 2, 0x1A),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x1A,
            0x1230215, 0x19027, 0x19D0021, 0xFFFFD211, 0x841, 0xFFFF5097,
            0x1000911, 0x91, 0x11)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 3, 0x23),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x23,
            0x34A4215, 0x45210, 0x11027, 0x652C8071, 0x34A40A1, 0x841,
            0x91, 0x11)
    );

    // DrawArraysIndirect/Instanced
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 4, 0x2B),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x2B,
            0x501, 0x346C215, 0x401, 0xD74061, 0x1438351, 0x1841, 0x638C021,
            0x151410, 0x1910041, 0x2E007, 0x1841, 0x1618021, 0x841, 0xD78021,
            0x2841, 0x1614071, 0xFFFFE411, 0x4211, 0xFFFE6017, 0xD0808912,
            0x1438071, 0x638C021, 0x19100C1, 0x41)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 5, 0x43),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x43,
            0x346C215, 0x401, 0x301, 0x14D310, 0xD74061, 0x2D807,
            0x1438061, 0x1618021, 0x841, 0xD78021, 0x2041, 0x1614071,
            0xFFFFDB11, 0x4211, 0xFFFE5817, 0xD0808912, 0x14380F1, 0x11)
    );

    // DrawElementsIndirect/Instanced
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 6, 0x55),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x55,
            0x601, 0x501, 0x346C215, 0x17DC061, 0x1118451, 0x2041,
            0x5434021, 0x2331, 0x1841, 0x638C021, 0x1900041, 0x155510,
            0x2041, 0x2E807, 0x1841, 0x1618021, 0x841, 0x17E0021, 0x3041,
            0x1614071, 0xFFFFED11, 0x4211, 0xFFFE6817, 0xD0808912, 0x1118071,
            0x1434071, 0x1438071, 0x638C021, 0x1900041, 0xC1, 0x41)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 7, 0x74),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x74,
            0x501, 0x346C215, 0x401, 0x17DC061, 0x1118351, 0x1841,
            0x5434021, 0x151410, 0x1A31, 0x2E007, 0x1041, 0x1618021,
            0x841, 0x17E0021, 0x2841, 0x1614071, 0xFFFFE411, 0x4211,
            0xFFFE6017, 0xD0808912, 0x1118071, 0x14340F1, 0x1438071)
    );

    // DrawTransformFeedback
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 8, 0x8B),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x8B,
            0x5618021, 0x841, 0x5318061, 0x523C061, 0x16140A1, 0x41)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 9, 0x91),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x91,
            0x346C215, 0xE11, 0x501, 0x101, 0x3420021, 0x841, 0x401,
            0x11017, 0x701, 0xF0007, 0x5AD10, 0x5EA10, 0xF87E8212,
            0x9027, 0x2F11, 0x5F210, 0xF87E8212, 0xCD027, 0x3420115,
            0x5ED10, 0x4211, 0x3424021, 0xD0808912, 0x841, 0x5F210,
            0x91027, 0x301, 0x201, 0xD74061, 0x1438151, 0x841, 0x638C021,
            0x1910041, 0x841, 0x49007, 0x3041, 0x3420115, 0x1618021, 0x841,
            0xD78021, 0xFFFFD211, 0x1841, 0x29007, 0x1614071, 0x3424115,
            0x1618021, 0x841, 0xD78021, 0xFFFFD211, 0x1841, 0xFFFE9017,
            0x1614071, 0xFFF92007, 0x7611, 0x5F210, 0xFFF85027, 0x2211,
            0xFFFFD211, 0xFFFFD017, 0x101, 0xFFF70027, 0x22027, 0x1E827,
            0x2211, 0xFFFFD211, 0xFFFFD017, 0x101, 0x8027, 0x5AD10,
            0x36827, 0x101, 0x101, 0x101, 0xFFFFED11, 0x1E007, 0x101,
            0x16827, 0x2211, 0xFFFFD211, 0xFFFFD017, 0x101, 0xFFFD6837,
            0x1438071, 0x638C021, 0x1910041, 0xC1, 0x41)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 10, 0xE8),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0xE8,
            0x346C315, 0x501, 0x201, 0x3420021, 0x1041, 0x401, 0x201,
            0x3428021, 0x11817, 0x1041, 0x11C007, 0x46D10, 0x3428215, 0x4AB10,
            0xF87EC312, 0x11827, 0x2A11, 0x3428021, 0x1041, 0x3428215, 0x48B10,
            0xF87EC312, 0xE9827, 0x3428215, 0x4311, 0x4AD10, 0x3420215,
            0x3424021, 0xD080D212, 0x1041, 0x3428215, 0x48B10, 0xA5827, 0x601,
            0x301, 0x17DC061, 0x1118751, 0x3841, 0x5434021, 0x3A31, 0x1041,
            0x638C021, 0x1900041, 0x3841, 0x1041, 0x49807, 0x841, 0x3420215,
            0x1618021, 0x1041, 0x17E0021, 0xFFFFDB11, 0x3041, 0x29807,
            0x1614071, 0x3424215, 0x1618021, 0x1041, 0x17E0021, 0xFFFFDB11,
            0x3041, 0xFFFE9817, 0x1614071, 0xFFF7E007, 0x4911, 0x3428215,
            0x48B10, 0xFFF6D827, 0x2311, 0xFFFFDB11, 0xFFFFD817, 0x201,
            0xFFF58027, 0x22027, 0x1E827, 0x2311, 0xFFFFDB11, 0xFFFFD817, 0x201,
            0x8027, 0x46D10, 0x3A827, 0x201, 0x201, 0x201, 0x201, 0xFFFFED11,
            0x1E007, 0x201, 0x16827, 0x2311, 0xFFFFDB11, 0xFFFFD817, 0x201,
            0xFFFD2837, 0x1118071, 0x1434071, 0x1438071, 0x638C021, 0x1900041,
            0x41, 0xC1, 0x41)
    );

    // SetConservativeRasterDilate
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 11, 0x14F),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x14F,
            0x110071, 0x7400451, 0x301, 0x41, 0x2041, 0x1841, 0x2310021,
            0x841, 0x3468115, 0x2004112, 0xFFFF8911, 0x24827, 0x3400115,
            0x4211, 0x48910, 0x24827, 0x100071, 0xFFFF4007, 0x3400195,
            0x11, 0x28211, 0xFFFFD211, 0xFFFFD097, 0x100071, 0x91, 0x11)
    );

    // DrawTexture/TiledDownsample
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 12, 0x169),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x169,
            0x3488B15, 0x2004211, 0x21005112, 0x618008A2, 0x1841)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 13, 0x16E),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x16E,
            0x34A8B15, 0x6380021, 0x34BC915, 0x230C212, 0x4600C312,
            0x841, 0x10C1, 0x1841)
    );

    // BindColorState
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 14, 0x176),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x176,
            0x19C4071, 0x5360021, 0x504042, 0x524042, 0x544042,
            0x564042, 0x584042, 0x5A4042, 0x5C40C2, 0x5E4042)
    );

    // BindChannelMaskState
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 15, 0x180),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x180,
            0x5A00021, 0x3404042, 0x3604132, 0x3404042, 0x3604132,
            0x3404042, 0x3604132, 0x34040C2, 0x3604042)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 16, 0x189),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x189,
            0x6380021, 0x931, 0x9B1, 0x841)
    );

    // Duplicate macro, never used
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 17, 0x18D),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x18D,
            0x6380021, 0x931, 0x9B1, 0x841)
    );

    // SetShaders
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 18, 0x191),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x191,
            0x3470A15, 0x401, 0x4A210, 0x55007, 0x301, 0x2004211,
            0x21005212, 0x61801022, 0x1841, 0x3470A11, 0x61801022,
            0x2041, 0x3488A11, 0x61801022, 0x1A31, 0x6380151,
            0x40000041, 0x2304042, 0x46004042, 0x19C08112,
            0x2410911, 0x618008A2, 0x44041, 0x11, 0x281, 0x101,
            0x91, 0x11)
    );

    // BindDepthStencilState
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 19, 0x1AD),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x1AD,
            0x5380071, 0x5384021, 0x1084042, 0x1184042, 0x1104042,
            0x1004042, 0x5598021, 0x1284042, 0x1384042, 0x13040C2,
            0x1204042)
    );

    // ClearTexture/TiledDownsample
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 20, 0x1B8),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x1B8,
            0x3EB0211, 0x84008212, 0x121C021, 0x1A205041, 0x3FFFC211,
            0x1538071, 0x4800021, 0x2304042, 0x46004112, 0xC31, 0x2331,
            0x1931, 0x2304042, 0x6004042, 0x4041, 0x41, 0x4FF4021,
            0x84010042, 0x8400C042, 0x1534071, 0x15D0071, 0x4754071,
            0xE00071, 0x4C00021, 0x84008042, 0x3FFFC211, 0x84008042,
            0xFE00211, 0x41, 0x84008042, 0xE2220211, 0x84008212,
            0x22221211, 0x192C071, 0x193C021, 0x3070041, 0x5944071,
            0x437C071, 0xD68071, 0x12CC071, 0x19BC071, 0x1380071,
            0x12EC071, 0x1360071, 0x19C4071, 0x1A00021, 0x4444041,
            0x210071, 0x153C071, 0x4FBC021, 0x3FFFC041, 0x3FFFC041,
            0x3FFFC041, 0x3FFFC041, 0x4DAC021, 0x6C08041, 0x6C08041,
            0xDC8071, 0x1918071, 0x82080071, 0xC20C0071, 0x2100021,
            0x100041, 0x744071, 0xF40071, 0x1224071, 0x1148071,
            0xFB4071, 0xDD0071, 0xA18021, 0x19080041, 0x11F8071,
            0xF1C071, 0x51E0021, 0x1041, 0x1041, 0x10C1, 0x1041)
    );

    // BindStorageBuffer (and every draw function)
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 21, 0x206),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x206,
            0x3460215, 0x6380021, 0x17C00041, 0x2308042, 0x460080C2,
            0x17804042)
    );

    // SetConservativeRasterDilate
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 22, 0x20C),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x20C,
            0x1148315, 0x34D0215, 0x111, 0x2EC021, 0x149A90,
            0x22008842)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 23, 0x212),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x212,
            0x3470C15, 0x200C211, 0x501, 0x301, 0x21005112,
            0x52A10, 0xD037, 0x618008A2, 0x1841, 0x91, 0x11)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 24, 0x21D),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x21D,
            0x34A0215, 0xFFFFD211, 0x15037, 0x42FC071, 0x436C071,
            0x95300F1, 0x36C071, 0x91, 0x11)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 25, 0x226),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x226,
            0x301, 0x4180251, 0x1041, 0x4041, 0x841, 0x1841,
            0x41B0021, 0x4044041, 0x21007, 0x1B4021, 0x41, 0x41,
            0xFFFC1211, 0x41, 0xFFFF1097, 0x41, 0x91, 0x11)
    );

    // ???
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeStartAddressRamPointer, 26, 0x238),
        NvIncrOnce(0, NvReg3D_MmeInstructionRamPointer, 0x238,
            0x6380021, 0x17C00041, 0x931, 0x841, 0x131, 0x20807,
            0x2390021, 0x41, 0x41, 0xFFFFC911, 0x41, 0xFFFF0897,
            0x41, 0x91, 0x11)
    );
}

Result vnInit3D(Vn* vn) {
    Result rc;

    _vnInitMacros(vn);

    vnAddCmd(
        vn,
        // ???
        NvIncr(0, NvReg3D_MmeShadowScratch(0x1A), 0, 0xffffffff),
        NvImm(0, NvReg3D_MmeShadowScratch(0x19), 0),
        //
        NvImm(0, NvReg3D_MultisampleEnable, 0),
        NvImm(0, NvReg3D_MultisampleCsaaEnable, 0),
        NvImm(0, NvReg3D_MultisampleMode, 0),
        NvImm(0, NvReg3D_MultisampleControl, 0),
        // ???
        NvIncr(0, 0x433, 0),
        NvIncr(0, 0x438, 0),
        NvIncr(0, 0x439, 0),
        NvIncr(0, 0x43b, 0),
        NvIncr(0, 0x43c, 0),
        NvIncr(0, 0x1d3, 0),
        //
        NvIncr(0, NvReg3D_WindowNHorizontal,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        NvImm(0, NvReg3D_ClearFlags, 0x101)
    );

    size_t i;
    for (i=0; i<16; i++) {
        vnAddCmd(vn, NvImm(0, NvReg3D_ScissorEnable(i), 1));
    }

    vnAddCmd(
        vn,
        // ???
        NvIncr(0, 0x5AA, 0x30003),
        NvIncr(0, 0x5E5, 0x20002),
        //
        NvImm(0, NvReg3D_PrimRestartWithDrawArrays, 1),
        NvImm(0, NvReg3D_PointRasterRules, 0),
        NvImm(0, NvReg3D_LinkedTsc, 0),
        NvImm(0, NvReg3D_ProvokingVertexLast, 1),
        // ???
        NvImm(0, 0x54a, 0),
        NvImm(0, 0x400, 0),
        NvImm(0, 0x86, 0),
        NvImm(0, 0x43f, 0),
        NvImm(0, 0x4a4, 0),
        NvImm(0, 0x4b6, 0),
        NvImm(0, 0x4b7, 0),
        //
        NvImm(0, NvReg3D_CallLimitLog, 8),
        // ???
        NvImm(0, 0x450, 0x10),
        NvImm(0, 0x584, 0xe)
    );

    for (i=0; i<16; i++) {
        vnAddCmd(vn, NvImm(0, NvReg3D_VertexStreamEnableDivisor(i), 0));
    }

    vnAddCmd(
        vn,
        NvImm(0, NvReg3D_VertexIdGenMode, 0x1000),
        NvImm(0, NvReg3D_ZcullStatCtrsEnable, 1),
        NvImm(0, NvReg3D_LineWidthSeparate, 1),
        // ???
        NvImm(0, 0xc3, 0),
        NvImm(0, 0xc0, 3),
        NvImm(0, 0x3f7, 1),
        NvImm(0, 0x670, 1),
        NvImm(0, 0x3e3, 0),
        NvImm(0, NvReg3D_StencilTwoSideEnable, 1),
        NvImm(0, NvReg3D_TextureConstantBufferIndex, 2),
        NvImm(0, 0xc4, 0x503),
        NvIncr(0, NvReg3D_LocalBase, 0x01000000),
        NvImm(0, 0x44c, 0x13),
        NvImm(0, 0xdd, 0),
        NvIncr(0, NvReg3D_Layer, 0x10000),
        NvImm(0, 0x488, 0),
        NvIncr(0, 0x514, 0x00800008),
    );

    // Initializes some 2D things..
    vnAddCmd(
        vn,
        NvImm(3, 0xab, 3), // SetOperation?
        NvImm(3, 0xa4, 0), // SetClipEnable
        NvImm(3, 0x221, 0x3f)
    );

    vnAddCmd(
        vn,
        NvIncrOnce(0, NvReg3D_MmeMacroCall(11), 0x00418800, 1, 1),
        NvIncrOnce(0, NvReg3D_MmeMacroCall(11), 0x419A08, 0, 0x10),
        NvIncrOnce(0, NvReg3D_MmeMacroCall(11), 0x00419f78, 0, 8),
        NvIncrOnce(0, NvReg3D_MmeMacroCall(11), 0x00404468, 0x07ffffff, 0x3fffffff),
        //NvIncrOnce(0, NvReg3D_MmeMacroCall(11), 0x00419a04, 1, 1),
        //NvIncrOnce(0, NvReg3D_MmeMacroCall(11), 0x00419a04, 2, 2)
    );

    vnAddCmd(
        vn,
        // Reset Zcull.
        NvImm(0, 0x65a, 0x11),
        NvImm(0, NvReg3D_ZcullTestMask, 0),
        NvImm(0, NvReg3D_ZcullRegion, 0),
        NvIncr(0, 0x054, 0x49000000, 0x49000001),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x18), 0x1106500),
    );

    // TODO: Of what size is this buffer actually supposed to be?
    rc = nvBufferCreateRw(
        &vn->vertex_runout, 0x10000, 0x1000, 0, &vn->parent->addr_space);

    if (R_FAILED(rc))
        return rc;

    iova_t gpu_addr = nvBufferGetGpuAddr(&vn->vertex_runout);
    vnAddCmd(vn, NvIncr(0, NvReg3D_VertexRunoutAddr, gpu_addr >> 32, gpu_addr));

    // Bind all const buffers index 0 to same buffer (of size 0x5f00).
    rc = nvBufferCreateRw(
        &vn->const_buffer0, 0x5f00 + 10*0x200, 0x1000, 0, &vn->parent->addr_space);

    if (R_FAILED(rc))
        return rc;

    gpu_addr = nvBufferGetGpuAddr(&vn->const_buffer0);

    // FIXME: Breaks rendering
#if 0
    iova_t start = gpu_addr + 0x6900;
    iova_t end = gpu_addr + 0x6A00;

    vnAddCmd(
        vn,
        NvIncrOnce(0, NvReg3D_MmeMacroCall(26), gpu_addr >> 32, gpu_addr, 0x67),
        NvImm(0, NvReg3D_MmeMacroCall(21), 0x194),
        NvIncr(0, NvReg3D_ConstantBufferLoad(0), end, end >> 32, 0, 0),
        NvIncrOnce(0, NvReg3D_MmeMacroCall(25), start >> 32, start, 0x100),
        NvIncrOnce(0, NvReg3D_MmeMacroCall(25), end >> 32, end, 0x400)
    );
#endif

    vnAddCmd(
        vn,
        NvIncr(
            0, NvReg3D_ConstantBufferSize,
            0x5f00,
            gpu_addr >> 32, gpu_addr
        )
    );
    gpu_addr += 0x5f00;

    for (i=0; i<5; i++) {
        vnAddCmd(vn, NvImm(0, NvReg3D_ConstantBufferBind(i), 1));
    }

    // Bind const buffer index 2 to different buffers (each of size 0x200).
    for (i=0; i<5; i++) {
        vnAddCmd(
            vn,
            NvIncr(0,
                NvReg3D_ConstantBufferSize,
                0x200, // Size
                gpu_addr >> 32, gpu_addr // Addr
            ),
            NvImm(0, NvReg3D_ConstantBufferBind(i), 0x21),
            NvIncrOnce(
                0, NvReg3D_ConstantBufferLoadOffset, 0,
                0,1,2,3,4,5,6,7
            )
        );
        gpu_addr += 0x200;
    }

    vnAddCmd(
        vn,
        NvImm(0, NvReg3D_BlendIndependent, 1),
        NvImm(0, NvReg3D_EdgeFlag, 1),
        NvImm(0, NvReg3D_ViewportTransformEnable, 1),
        NvIncr(0, NvReg3D_ViewportControl, 0x181d), // ???
        NvImm(0, NvReg3D_DepthClipAllowNegativeZ, 0)
    );

    // Now that negative-z is disabled we need to change the viewports.
    // Put both Z scaling and translate to 0.5: (-1..1) * 0.5 + 0.5 = 0..1
    for (i=0; i<16; i++) {
        vnAddCmd(
            vn,
            NvIncr(0, NvReg3D_ViewportScaleZ(i), f2i(0.5)),
            NvIncr(0, NvReg3D_ViewportTranslateZ(i), f2i(0.5)),
        );
    }

    vnAddCmd(
        vn,
        NvImm(0, NvReg3D_ScreenVerticalControl, 0x10)
    );

    for (i=0; i<16; i++) {
        vnAddCmd(
            vn,
            NvIncr(0, NvReg3D_ViewportScaleX(i), f2i(0.5), f2i(0.5)),
            NvIncr(0, NvReg3D_ViewportTranslateX(i), f2i(0.5), f2i(0.5)),
            NvIncr(0, NvReg3D_ViewportHorizontal(i),
                0 | (1<<16), /* Horizontal */
                0 | (1<<16)  /* Vertical */
            )
        );
    }

    vnAddCmd(
        vn,
        NvImm(0, NvReg3D_MmeShadowRamControl, 0)
    );

    // Reset all the scissors.
    for (i=0; i<16; i++) {
        vnAddCmd(
            vn,
            NvIncr(0, NvReg3D_ScissorHorizontal(i),
                (0xffff << 16) | 0, /* Horizontal */
                (0xffff << 16) | 0  /* Vertical */
            )
        );
    }

    // Setup RAM for macros.
    vnAddCmd(
        vn,
        NvImm(0, NvReg3D_MmeShadowRamControl, 1),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x1c),
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xffffffff)
    );

    // Reset IndexArrayLimit.
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_IndexArrayLimit, 0xFF, 0xFFFFFFFF),
        NvImm(0, NvReg3D_PrimRestartWithDrawArrays, 0)
    );

    // More RAM setup.
    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_MmeShadowScratch(0x2a), 0x110655F),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x2f), 0x200),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x2b), 0x1106561),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x30), 0x200),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x2c), 0x1106563),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x31), 0x200),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x2d), 0x1106565),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x32), 0x200),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x2e), 0x1106567),
        NvIncr(0, NvReg3D_MmeShadowScratch(0x33), 0x200)
    );

    vnAddCmd(
        vn,
        NvIncr(0, NvReg3D_SampleCountEnable, 1),
        NvIncr(0, NvReg3D_ClipDistanceEnable, 0xff),
        NvIncr(0, NvReg3D_MsaaMask, 0xffff, 0xffff, 0xffff, 0xffff),
        NvImm(0, 0x367, 0),
        NvImm(0, NvReg3D_PointSpriteEnable, 1),
        NvImm(0, NvReg3D_PointCoordReplace, 4),
        NvImm(0, NvReg3D_VpPointSize, 1),
        NvImm(0, 0x68b, 0),
        NvImm(0, NvReg3D_StencilTwoSideEnable, 1),
        NvImm(0, NvReg3D_MmeMacroCall(21), 0x184)
    );

    //vnAddCmd(vn, NvIncr(0, NvReg3D_ConstantBufferLoad(0), 0x44fffe00));

    vnAddCmd(
        vn,
        NvImm(0, NvReg3D_ZetaArrayMode, 1),
        NvImm(0, NvReg3D_ConservativeRaster, 0),
        NvIncrOnce(0, NvReg3D_MmeMacroCall(11), 0x418800, 0, 0x1800000),
        NvImm(0, NvReg3D_MmeShadowScratch(0x34), 0),
        NvImm(0, 0xbb, 0),
        NvImm(0, NvReg3D_MultisampleRasterEnable, 0),
        NvImm(0, NvReg3D_CoverageModulationEnable, 0),
        NvImm(0, 0x44c, 0x13), // not in fermi ?
        NvImm(0, NvReg3D_MultisampleCoverageToColor, 0)
    );

    rc = nvBufferCreateRw(
        &vn->code_segment, 1 << 19, 1 << 17, 0, &vn->parent->addr_space);
    if (R_FAILED(rc))
        return rc;
    gpu_addr = nvBufferGetGpuAddr(&vn->code_segment);
    vnAddCmd(vn, NvIncr(0, NvReg3D_CodeAddr, gpu_addr >> 32, gpu_addr));

    vnAddCmd(
        vn,
        NvImm(0, NvReg3D_MmeShadowScratch(0x27), 0x230),
        NvImm(0, NvReg3D_MmeShadowScratch(0x23), 0x430),
        NvImm(0, 0x5ad, 0),
        NvIncrOnce(0, NvReg3D_MmeMacroCall(11), 0x418E00, 2, 2),
        NvImm(1, 0x54a, 0),
        NvImm(1, NvReg3D_TextureConstantBufferIndex, 2),
        NvIncr(1, NvReg3D_LocalBase, 0x1000000),
        NvIncr(1, 0x85, 0x3000000),
        NvIncr(1, NvReg3D_CodeAddr, gpu_addr >> 32, gpu_addr),
        NvImm(1, 0xC4, 0x503),
        NvIncr(6, 0xB, 0x80000000),
        NvImm(0, NvReg3D_InvalidateTextureDataNoWfi, 0),
        NvImm(0, 0x369, 0x1011),
        NvImm(0, NvReg3D_TicFlush, 0),
        NvImm(0, NvReg3D_TscFlush, 0),
    );

    // Setting up TiledCache and other stuff.
    /*vnAddCmd(
        vn,
        NvImm(0, 0x3d8, 0),
        NvIncr(0, 0x3d9, 0x00800080),
        NvIncr(0, 0x3da, 0x1109),
        NvIncr(0, 0x3db, 0x08080202),
        NvImm(0, 0x442, 0x1f),
        NvIncr(0, 0x3dc, 0x00080001),
        NvImm(0, 0x44d, 0),
    );*/

    // TODO: Subchannel 1:
    /*
      NvImm(0, 0x54a, 0),
      NvImm(0, 0x982, 2),
      NvIncr(0, NvReg3D_LocalBase, 0x01000000),
      NvIncr(0, 0x85, 0x03000000),
      NvIncr(0, NvReg3D_CodeAddr, 4, 0x00000000),
      NvImm(0xc4, 0x503),
    */

    // TODO: Subchannel 6:
    /*
      2001c00b type: 1, subchannel: 6
      UNKNOWN (0x00b) <- 0x80000000
      2001c00b type: 1, subchannel: 6
      UNKNOWN (0x00b) <- 0x70000000
    */

    // Flush texture info cache.
    /*vnAddCmd(
        vn,
        NvImm(0, 0x4a2, 0),
        NvImm(0, 0x369, 0x11),
        NvImm(0, 0x50a, 0),
        NvImm(0, 0x509, 0)
    );*/

    vnAddCmd(
        vn,
        NvIncr(0, 0x1e9, 0x7ff8),
        NvIncr(0, 0x1ea, 0x7ffc)
    );

    return 0;
}
