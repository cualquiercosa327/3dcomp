#include "gfx/detail/gfx_CommonHelper.hpp"

namespace nn {
    namespace gfx {
        namespace detail {
            int GetBlockWidth(ChannelFormat format) {
                switch (format) {
                case ChannelFormat_Pvrtc1_2Bpp:
                case ChannelFormat_Pvrtc1_Alpha_2Bpp:
                    return 16;
                case ChannelFormat_Pvrtc1_4Bpp:
                case ChannelFormat_Pvrtc1_Alpha_4Bpp:
                case ChannelFormat_Pvrtc2_Alpha_2Bpp:
                    return 8;
                case ChannelFormat_Astc_5x4:
                case ChannelFormat_Astc_5x5:
                    return 5;
                case ChannelFormat_Astc_6x5:
                case ChannelFormat_Astc_6x6:
                    return 6;
                case ChannelFormat_Astc_8x5:
                case ChannelFormat_Astc_8x6:
                case ChannelFormat_Astc_8x8:
                    return 8;
                case ChannelFormat_Astc_10x5:
                case ChannelFormat_Astc_10x6:
                case ChannelFormat_Astc_10x8:
                case ChannelFormat_Astc_10x10:
                    return 10;
                case ChannelFormat_Astc_12x10:
                case ChannelFormat_Astc_12x12:
                    return 12;
                default:
                    return 4;
                }
            }

            int GetBlockHeight(ChannelFormat format) {
                switch (format) {
                case ChannelFormat_Astc_5x5:
                case ChannelFormat_Astc_6x5:
                case ChannelFormat_Astc_8x5:
                case ChannelFormat_Astc_10x5:
                    return 5;
                case ChannelFormat_Astc_6x6:
                case ChannelFormat_Astc_8x6:
                case ChannelFormat_Astc_10x6:
                    return 6;
                case ChannelFormat_Pvrtc1_2Bpp:
                case ChannelFormat_Pvrtc1_Alpha_2Bpp:
                case ChannelFormat_Pvrtc1_4Bpp:
                case ChannelFormat_Pvrtc1_Alpha_4Bpp:
                case ChannelFormat_Astc_8x8:
                case ChannelFormat_Astc_10x8:
                    return 8;
                case ChannelFormat_Astc_10x10:
                case ChannelFormat_Astc_12x10:
                    return 10;
                case ChannelFormat_Astc_12x12:
                    return 12;
                default:
                    return 4;
                }
            }

            bool IsCompressedFormat(ChannelFormat format) {
                switch (format) {
                case ChannelFormat_Bc1:
                case ChannelFormat_Bc2:
                case ChannelFormat_Bc3:
                case ChannelFormat_Bc4:
                case ChannelFormat_Bc5:
                case ChannelFormat_Bc6:
                case ChannelFormat_Bc7:
                case ChannelFormat_Eac_R11:
                case ChannelFormat_Eac_R11_G11:
                case ChannelFormat_Etc1:
                case ChannelFormat_Etc2:
                case ChannelFormat_Etc2_Mask:
                case ChannelFormat_Etc2_Alpha:
                case ChannelFormat_Pvrtc1_2Bpp:
                case ChannelFormat_Pvrtc1_4Bpp:
                case ChannelFormat_Pvrtc1_Alpha_2Bpp:
                case ChannelFormat_Pvrtc1_Alpha_4Bpp:
                case ChannelFormat_Pvrtc2_Alpha_2Bpp:
                case ChannelFormat_Pvrtc2_Alpha_4Bpp:
                case ChannelFormat_Astc_4x4:
                case ChannelFormat_Astc_5x4:
                case ChannelFormat_Astc_5x5:
                case ChannelFormat_Astc_6x5:
                case ChannelFormat_Astc_6x6:
                case ChannelFormat_Astc_8x5:
                case ChannelFormat_Astc_8x6:
                case ChannelFormat_Astc_8x8:
                case ChannelFormat_Astc_10x5:
                case ChannelFormat_Astc_10x6:
                case ChannelFormat_Astc_10x8:
                case ChannelFormat_Astc_10x10:
                case ChannelFormat_Astc_12x10:
                case ChannelFormat_Astc_12x12:
                    return true;
                default:
                    return false;
                }
            }

            bool IsSrgbFormat(TypeFormat format) {
                return format == TypeFormat_UnormSrgb;
            }

            int GetBytePerPixel(ChannelFormat format) {
                switch (format) {
                case ChannelFormat_Bc1:
                case ChannelFormat_Bc4:
                case ChannelFormat_Eac_R11:
                case ChannelFormat_Etc1:
                case ChannelFormat_Etc2:
                case ChannelFormat_Etc2_Mask:
                case ChannelFormat_Pvrtc2_Alpha_2Bpp:
                case ChannelFormat_Pvrtc2_Alpha_4Bpp:
                    return 8;
                case ChannelFormat_Bc2:
                case ChannelFormat_Bc3:
                case ChannelFormat_Bc5:
                case ChannelFormat_Bc6:
                case ChannelFormat_Bc7:
                case ChannelFormat_Eac_R11_G11:
                case ChannelFormat_Etc2_Alpha:
                case ChannelFormat_Astc_4x4:
                case ChannelFormat_Astc_5x4:
                case ChannelFormat_Astc_5x5:
                case ChannelFormat_Astc_6x5:
                case ChannelFormat_Astc_6x6:
                case ChannelFormat_Astc_8x5:
                case ChannelFormat_Astc_8x6:
                case ChannelFormat_Astc_8x8:
                case ChannelFormat_Astc_10x5:
                case ChannelFormat_Astc_10x6:
                case ChannelFormat_Astc_10x8:
                case ChannelFormat_Astc_10x10:
                case ChannelFormat_Astc_12x10:
                case ChannelFormat_Astc_12x12:
                    return 16;
                case ChannelFormat_Pvrtc1_2Bpp:
                case ChannelFormat_Pvrtc1_4Bpp:
                case ChannelFormat_Pvrtc1_Alpha_2Bpp:
                case ChannelFormat_Pvrtc1_Alpha_4Bpp:
                    return 32;
                case ChannelFormat_B5_G5_R5_A1:
                    return 2;
                default: {
                    if (format <= ChannelFormat_R8) {
                        return 1;
                    }
                    if (format <= ChannelFormat_R16) {
                        return 2;
                    }
                    if (format <= ChannelFormat_R32) {
                        return 4;
                    }
                    if (format <= ChannelFormat_R32_G32) {
                        return 8;
                    }
                    if (format <= ChannelFormat_R32_G32_B32) {
                        return 12;
                    }
                }
                    return 16;
                }
            }

            size_t CalculateImageSize(ChannelFormat format, uint32_t width, uint32_t height,
                                      uint32_t depth) {
                if (IsCompressedFormat(format)) {
                    int blockWidth = GetBlockWidth(format);
                    int blockHeight = GetBlockHeight(format);
                    width = (width + blockWidth - 1) / blockWidth;
                    height = (height + blockHeight - 1) / blockHeight;
                }

                return width * height * depth * GetBytePerPixel(format);
            }

            int GetChannelCount(ChannelFormat format) {
                static const int s_ChannelCountTable[] = {
                    0, 2, 1, 4, 4, 4, 4, 3, 3, 2, 1, 4, 4, 4, 4, 3, 3, 3, 2, 2,
                    1, 4, 2, 2, 3, 4, 4, 4, 4, 1, 2, 3, 4, 1, 2, 3, 3, 4, 4, 3,
                    3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
                return s_ChannelCountTable[format];
            }

            size_t CalculateRowSize(uint32_t width, ChannelFormat format) {
                if (IsCompressedFormat(format)) {
                    int blockWidth = GetBlockWidth(format);
                    width = (width + blockWidth - 1) / blockWidth;
                }

                return width * GetBytePerPixel(format);
            }

        };  // namespace detail
    };  // namespace gfx
};  // namespace nn
