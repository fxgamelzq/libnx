#pragma once

typedef struct {
    iova_t gpu_addr;
    u32 width;
    u32 height;
    u32 format;
    u32 tile_mode;
} VnRenderTargetConfig;

static inline void vnRenderTargetSetColorBuffer(VnRenderTargetConfig* c, iova_t gpu_addr) {
    c->gpu_addr = gpu_addr;
}

static inline void vnRenderTargetSetDimensions(VnRenderTargetConfig* c, size_t width, size_t height) {
    c->width = width;
    c->height = height;
    // TODO: Support tile modes for small/linear render targets
    c->tile_mode = 0x040;
}

static inline void vnRenderTargetSetFormat(VnRenderTargetConfig* c, u32 format) {
    c->format = format;
}

void vnSetRenderTargets(Vn* vn, VnRenderTargetConfig* targets, u32 num_targets);
