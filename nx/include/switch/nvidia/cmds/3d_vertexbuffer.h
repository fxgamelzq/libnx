#pragma once

typedef enum {
    NvPrimitiveMode_Points=0x00,
    NvPrimitiveMode_Lines=0x01,
    NvPrimitiveMode_Line_Loop=0x02,
    NvPrimitiveMode_Line_Strip=0x03,
    NvPrimitiveMode_Triangles=0x04,
    NvPrimitiveMode_Triangle_Strip=0x05,
    NvPrimitiveMode_Triangle_Fan=0x06,
    NvPrimitiveMode_Quads=0x07,
    NvPrimitiveMode_Quad_Strip=0x08,
    NvPrimitiveMode_Polygon=0x09,
    NvPrimitiveMode_Lines_Adjacency=0x0a,
    NvPrimitiveMode_Line_Strip_Adjacency=0x0b,
    NvPrimitiveMode_Triangles_Adjacency=0x0c,
    NvPrimitiveMode_Triangle_Strip_Adjacency=0x0d,
    NvPrimitiveMode_Patches=0x0e,
} NvPrimitiveMode;

void vnBindVertexBuffer(Vn* vn, u32 slot, iova_t start, size_t size);
void vnDrawArrays(Vn* vn, NvPrimitiveMode mode, u32 start, u32 count);
void vnBindVertexAttribState(Vn* vn, u32 count, u32* state);
void vnBindVertexStreamState(Vn* vn, u32 count, u32* state);
