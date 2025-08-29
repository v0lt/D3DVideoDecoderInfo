#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>

#define __WRL_NO_DEFAULT_LIB__
#define __WRL_CLASSIC_COM_STRICT__
#include <wrl/client.h>

#include <initguid.h>
#include <d3d11_1.h>
#include <d3d12video.h>
#include <dxgi1_4.h>

// {9947EC6F-689B-11DC-A320-0019DBBC4184}
DEFINE_GUID(DXVA2_MPEG4pt2_VLD_AdvSimple_Nvidia, 0x9947EC6F, 0x689B, 0x11DC, 0xA3, 0x20, 0x00, 0x19, 0xDB, 0xBC, 0x41, 0x84);

// {33FCFE41-DE46-4A49-861B-AC71110649D5}
DEFINE_GUID(DXVA2_MJPEG_VLD_Nvidia, 0x33FCFE41, 0xDE46, 0x4A49, 0x86, 0x1B, 0xAC, 0x71, 0x11, 0x06, 0x49, 0xD5);

// {7C74ADC6-E2BA-4ADE-86DE-30BEABB40CC1}
DEFINE_GUID(DXVA2_MPEG4pt2_VLD_AdvSimple_AMD, 0x7C74ADC6, 0xE2BA, 0x4ADE, 0x86, 0xDE, 0x30, 0xBE, 0xAB, 0xB4, 0x0C, 0xC1);

// {D1C20509-AE7B-4E72-AE3B-49F88D58992F}
DEFINE_GUID(DXVA2_MJPEG_VLD_AMD, 0xD1C20509, 0xAE7B, 0x4E72, 0xAE, 0x3B, 0x49, 0xF8, 0x8D, 0x58, 0x99, 0x2F);

// {4245F676-2BBC-4166-A0BB-54E7B849C380}
DEFINE_GUID(DXVA2_H264_VLD_NoFGT_AMD, 0x4245F676, 0x2BBC, 0x4166, 0xA0, 0xBB, 0x54, 0xE7, 0xB8, 0x49, 0xC3, 0x80);

// {9901CCD3-CA12-4B7E-867A-E2223D9255C3}
DEFINE_GUID(DXVA2_H264_VLD_Multiview_AMD, 0x9901CCD3, 0xCA12, 0x4B7E, 0x86, 0x7A, 0xE2, 0x22, 0x3D, 0x92, 0x55, 0xC3);

// {BCC5DB6D-A2B6-4AF0-ACE4-ADB1F787BC89}
DEFINE_GUID(DXVA2_VC1_VLD_Intel, 0xBCC5DB6D, 0xA2B6, 0x4AF0, 0xAC, 0xE4, 0xAD, 0xB1, 0xF7, 0x87, 0xBC, 0x89);

// {E07EC519-E651-4CD6-AC84-1370CCEEC851}
DEFINE_GUID(DXVA2_VC1_VLD_2_Intel, 0xE07EC519, 0xE651, 0x4CD6, 0xAC, 0x84, 0x13, 0x70, 0xCC, 0xEE, 0xC8, 0x51);

// {604F8E68-4951-4C54-88FE-ABD25C15B3D6}
DEFINE_GUID(DXVA2_H264_VLD_Intel, 0x604F8E68, 0x4951, 0x4C54, 0x88, 0xFE, 0xAB, 0xD2, 0x5C, 0x15, 0xB3, 0xD6);

// {76988A52-DF13-419A-8E64-FFCF4A336CF5}
DEFINE_GUID(DXVA2_VP9_VLD_Intel, 0x76988A52, 0xDF13, 0x419A, 0x8E, 0x64, 0xFF, 0xCF, 0x4A, 0x33, 0x6C, 0xF5);

// {8C56EB1E-2B47-466F-8D33-7DBCD63F3DF2}
DEFINE_GUID(DXVA2_HEVC_VLD_Main_Intel, 0x8C56EB1E, 0x2B47, 0x466F, 0x8D, 0x33, 0x7D, 0xBC, 0xD6, 0x3F, 0x3D, 0xF2);

// {75FC75F7-C589-4A07-A25B-72E03B0383B3}
DEFINE_GUID(DXVA2_HEVC_VLD_Main10_Intel, 0x75FC75F7, 0xC589, 0x4A07, 0xA2, 0x5B, 0x72, 0xE0, 0x3B, 0x03, 0x83, 0xB3);

// {8FF8A3AA-C456-4132-B6EF-69D9DD72571D}
DEFINE_GUID(DXVA2_HEVC_VLD_Main12_Intel, 0x8FF8A3AA, 0xC456, 0x4132, 0xB6, 0xEF, 0x69, 0xD9, 0xDD, 0x72, 0x57, 0x1D);

// {E484DCB8-CAC9-4859-99F5-5C0D45069089}
DEFINE_GUID(DXVA2_HEVC_VLD_Main422_10_Intel, 0xE484DCB8, 0xCAC9, 0x4859, 0x99, 0xF5, 0x5C, 0x0D, 0x45, 0x06, 0x90, 0x89);

// {C23DD857-874B-423C-B6E0-82CEAA9B118A}
DEFINE_GUID(DXVA2_HEVC_VLD_Main422_12_Intel, 0xC23DD857, 0x874B, 0x423C, 0xB6, 0xE0, 0x82, 0xCE, 0xAA, 0x9B, 0x11, 0x8A);

// {41A5AF96-E415-4B0C-9D03-907858E23E78}
DEFINE_GUID(DXVA2_HEVC_VLD_Main444_Intel, 0x41A5AF96, 0xE415, 0x4B0C, 0x9D, 0x03, 0x90, 0x78, 0x58, 0xE2, 0x3E, 0x78);

// {6A6A81BA-912A-485D-B57F-CCD2D37B8D94}
DEFINE_GUID(DXVA2_HEVC_VLD_Main444_10_Intel, 0x6A6A81BA, 0x912A, 0x485D, 0xB5, 0x7F, 0xCC, 0xD2, 0xD3, 0x7B, 0x8D, 0x94);

// {5B08E35D-0C66-4C51-A6F1-89D00CB2C197}
DEFINE_GUID(DXVA2_HEVC_VLD_Main444_12_Intel, 0x5B08E35D, 0x0C66, 0x4C51, 0xA6, 0xF1, 0x89, 0xD0, 0x0C, 0xB2, 0xC1, 0x97);

#if !defined(NTDDI_WIN11_GE)
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_HEVC_MONOCHROME,   0x0685b993, 0x3d8c, 0x43a0, 0x8b, 0x28, 0xd7, 0x4c, 0x2d, 0x68, 0x99, 0xa4);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_HEVC_MONOCHROME10, 0x142a1d0f, 0x69dd, 0x4ec9, 0x85, 0x91, 0xb1, 0x2f, 0xfc, 0xb9, 0x1a, 0x29);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN12,       0x1a72925f, 0x0c2c, 0x4f15, 0x96, 0xfb, 0xb1, 0x7d, 0x14, 0x73, 0x60, 0x3f);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN10_422,   0x0bac4fe5, 0x1532, 0x4429, 0xa8, 0x54, 0xf8, 0x4d, 0xe0, 0x49, 0x53, 0xdb);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN12_422,   0x55bcac81, 0xf311, 0x4093, 0xa7, 0xd0, 0x1c, 0xbc, 0x0b, 0x84, 0x9b, 0xee);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN_444,     0x4008018f, 0xf537, 0x4b36, 0x98, 0xcf, 0x61, 0xaf, 0x8a, 0x2c, 0x1a, 0x33);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN10_EXT,   0x9cc55490, 0xe37c, 0x4932, 0x86, 0x84, 0x49, 0x20, 0xf9, 0xf6, 0x40, 0x9c);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN10_444,   0x0dabeffa, 0x4458, 0x4602, 0xbc, 0x03, 0x07, 0x95, 0x65, 0x9d, 0x61, 0x7c);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN12_444,   0x9798634d, 0xfe9d, 0x48e5, 0xb4, 0xda, 0xdb, 0xec, 0x45, 0xb3, 0xdf, 0x01);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN16,       0xa4fbdbb0, 0xa113, 0x482b, 0xa2, 0x32, 0x63, 0x5c, 0xc0, 0x69, 0x7f, 0x6d);

DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_MJPEG_VLD_420,     0x725cb506, 0x0c29, 0x43c4, 0x94, 0x40, 0x8e, 0x93, 0x97, 0x90, 0x3a, 0x04);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_MJPEG_VLD_422,     0x5b77b9cd, 0x1a35, 0x4c30, 0x9f, 0xd8, 0xef, 0x4b, 0x60, 0xc0, 0x35, 0xdd);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_MJPEG_VLD_444,     0xd95161f9, 0x0d44, 0x47e6, 0xbc, 0xf5, 0x1b, 0xfb, 0xfb, 0x26, 0x8f, 0x97);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_MJPEG_VLD_4444,    0xc91748d5, 0xfd18, 0x4aca, 0x9d, 0xb3, 0x3a, 0x66, 0x34, 0xab, 0x54, 0x7d);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_JPEG_VLD_420,      0xcf782c83, 0xbef5, 0x4a2c, 0x87, 0xcb, 0x60, 0x19, 0xe7, 0xb1, 0x75, 0xac);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_JPEG_VLD_422,      0xf04df417, 0xeee2, 0x4067, 0xa7, 0x78, 0xf3, 0x5c, 0x15, 0xab, 0x97, 0x21);
DEFINE_GUID(D3D12_VIDEO_DECODE_PROFILE_JPEG_VLD_444,      0x4cd00e17, 0x89ba, 0x48ef, 0xb9, 0xf9, 0xed, 0xcb, 0x82, 0x71, 0x3f, 0x65);
#endif

inline std::wstring GUIDtoWString(const GUID& guid)
{
	std::wstring str(39, 0);
	int ret = StringFromGUID2(guid, &str[0], 39);
	if (ret) {
		str.resize(ret - 1);
	}
	else {
		str.clear();
	}
	return str;
}

const wchar_t* DXGIFormatToString(const DXGI_FORMAT format)
{
	switch (format) {
	case DXGI_FORMAT_R16G16B16A16_FLOAT:         return L"R16G16B16A16_FLOAT";
	case DXGI_FORMAT_R16G16B16A16_UNORM:         return L"R16G16B16A16_UNORM";
	case DXGI_FORMAT_R10G10B10A2_UNORM:          return L"R10G10B10A2_UNORM";
	case DXGI_FORMAT_R8G8B8A8_UNORM:             return L"R8G8B8A8_UNORM";
	case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:        return L"R8G8B8A8_UNORM_SRGB";
	case DXGI_FORMAT_R16G16_UNORM:               return L"R16G16_UNORM";
	case DXGI_FORMAT_R8G8_UNORM:                 return L"R8G8_UNORM";
	case DXGI_FORMAT_R16_TYPELESS:               return L"R16_TYPELESS";
	case DXGI_FORMAT_R16_UNORM:                  return L"R16_UNORM";
	case DXGI_FORMAT_R8_TYPELESS:                return L"R8_TYPELES";
	case DXGI_FORMAT_R8_UNORM:                   return L"R8_UNORM";
	case DXGI_FORMAT_B8G8R8A8_UNORM:             return L"B8G8R8A8_UNORM";
	case DXGI_FORMAT_B8G8R8X8_UNORM:             return L"B8G8R8X8_UNORM";
	case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM: return L"R10G10B10_XR_BIAS_A2_UNORM";
	case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:        return L"B8G8R8A8_UNORM_SRGB";
	case DXGI_FORMAT_AYUV:                       return L"AYUV";
	case DXGI_FORMAT_Y410:                       return L"Y410";
	case DXGI_FORMAT_Y416:                       return L"Y416";
	case DXGI_FORMAT_NV12:                       return L"NV12";
	case DXGI_FORMAT_P010:                       return L"P010";
	case DXGI_FORMAT_P016:                       return L"P016";
	case DXGI_FORMAT_420_OPAQUE:                 return L"420_OPAQUE";
	case DXGI_FORMAT_YUY2:                       return L"YUY2";
	case DXGI_FORMAT_Y210:                       return L"Y210";
	case DXGI_FORMAT_Y216:                       return L"Y216";
	case DXGI_FORMAT_AI44:                       return L"AI44";
	case DXGI_FORMAT_IA44:                       return L"IA44";
	case DXGI_FORMAT_P8:                         return L"P8";
	case DXGI_FORMAT_A8P8:                       return L"A8P8";
	};

	return L"UNKNOWN";
}

const struct {
	const GUID guid;
	const wchar_t* str;
}
g_D3D11DecoderProfileInfos[] = {
	// D3D12 (D3D11) decoders "3d12video.h"
	{ D3D12_VIDEO_DECODE_PROFILE_MPEG2,                     L"MPEG2" },
	{ D3D12_VIDEO_DECODE_PROFILE_MPEG1_AND_MPEG2,           L"MPEG1_AND_MPEG2" },
	{ D3D12_VIDEO_DECODE_PROFILE_H264,                      L"H264" },
	{ D3D12_VIDEO_DECODE_PROFILE_H264_STEREO_PROGRESSIVE,   L"H264_STEREO_PROGRESSIVE" },
	{ D3D12_VIDEO_DECODE_PROFILE_H264_STEREO,               L"H264_STEREO" },
	{ D3D12_VIDEO_DECODE_PROFILE_H264_MULTIVIEW,            L"H264_MULTIVIEW" },
	{ D3D12_VIDEO_DECODE_PROFILE_VC1,                       L"VC1" },
	{ D3D12_VIDEO_DECODE_PROFILE_VC1_D2010,                 L"VC1_D2010" },
	{ D3D12_VIDEO_DECODE_PROFILE_MPEG4PT2_SIMPLE,           L"MPEG4PT2_SIMPLE" },
	{ D3D12_VIDEO_DECODE_PROFILE_MPEG4PT2_ADVSIMPLE_NOGMC,  L"MPEG4PT2_ADVSIMPLE_NOGMC" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN,                 L"HEVC_MAIN" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN10,               L"HEVC_MAIN10" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MONOCHROME,           L"HEVC_MONOCHROME" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MONOCHROME10,         L"HEVC_MONOCHROME10" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN12,               L"HEVC_MAIN12" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN10_422,           L"HEVC_MAIN10_422" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN12_422,           L"HEVC_MAIN12_422" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN_444,             L"HEVC_MAIN_444" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN10_EXT,           L"HEVC_MAIN10_EXT" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN10_444,           L"HEVC_MAIN10_444" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN12_444,           L"HEVC_MAIN12_444" },
	{ D3D12_VIDEO_DECODE_PROFILE_HEVC_MAIN16,               L"HEVC_MAIN16" },
	{ D3D12_VIDEO_DECODE_PROFILE_VP9,                       L"VP9" },
	{ D3D12_VIDEO_DECODE_PROFILE_VP9_10BIT_PROFILE2,        L"VP9_10BIT_PROFILE2" },
	{ D3D12_VIDEO_DECODE_PROFILE_VP8,                       L"VP8" },
	{ D3D12_VIDEO_DECODE_PROFILE_AV1_PROFILE0,              L"AV1_PROFILE0" },
	{ D3D12_VIDEO_DECODE_PROFILE_AV1_PROFILE1,              L"AV1_PROFILE1" },
	{ D3D12_VIDEO_DECODE_PROFILE_AV1_PROFILE2,              L"AV1_PROFILE2" },
	{ D3D12_VIDEO_DECODE_PROFILE_AV1_12BIT_PROFILE2,        L"AV1_12BIT_PROFILE2" },
	{ D3D12_VIDEO_DECODE_PROFILE_AV1_12BIT_PROFILE2_420,    L"AV1_12BIT_PROFILE2_420" },
	{ D3D12_VIDEO_DECODE_PROFILE_MJPEG_VLD_420,             L"MJPEG_420" },
	{ D3D12_VIDEO_DECODE_PROFILE_MJPEG_VLD_422,             L"MJPEG_422" },
	{ D3D12_VIDEO_DECODE_PROFILE_MJPEG_VLD_444,             L"MJPEG_444" },
	{ D3D12_VIDEO_DECODE_PROFILE_MJPEG_VLD_4444,            L"MJPEG_4444" },
	{ D3D12_VIDEO_DECODE_PROFILE_JPEG_VLD_420,              L"JPEG_420" },
	{ D3D12_VIDEO_DECODE_PROFILE_JPEG_VLD_422,              L"JPEG_422" },
	{ D3D12_VIDEO_DECODE_PROFILE_JPEG_VLD_444,              L"JPEG_444" },
	// additional D3D11 decoders (VLD) "d3d11.h"
	{ D3D11_DECODER_PROFILE_MPEG1_VLD,                      L"MPEG1" },
	{ D3D11_DECODER_PROFILE_H264_VLD_FGT,                   L"H264_FGT" },
	{ D3D11_DECODER_PROFILE_H264_VLD_WITHFMOASO_NOFGT,      L"H264_WITHFMOASO_NOFGT" },
	{ D3D11_DECODER_PROFILE_MPEG4PT2_VLD_ADVSIMPLE_GMC,     L"MPEG4PT2_ADVSIMPLE_GMC" },
	// obsolete incomplete decoders (MOCOMP, IDCT, POSTPROC)
	{ D3D11_DECODER_PROFILE_MPEG2_MOCOMP,                   L"" },
	{ D3D11_DECODER_PROFILE_MPEG2_IDCT,                     L"" },
	{ D3D11_DECODER_PROFILE_H264_MOCOMP_NOFGT,              L"" },
	{ D3D11_DECODER_PROFILE_H264_MOCOMP_FGT,                L"" },
	{ D3D11_DECODER_PROFILE_H264_IDCT_NOFGT,                L"" },
	{ D3D11_DECODER_PROFILE_H264_IDCT_FGT,                  L"" },
	{ D3D11_DECODER_PROFILE_WMV8_POSTPROC,                  L"" },
	{ D3D11_DECODER_PROFILE_WMV8_MOCOMP,                    L"" },
	{ D3D11_DECODER_PROFILE_WMV9_POSTPROC,                  L"" },
	{ D3D11_DECODER_PROFILE_WMV9_MOCOMP,                    L"" },
	{ D3D11_DECODER_PROFILE_WMV9_IDCT,                      L"" },
	{ D3D11_DECODER_PROFILE_VC1_POSTPROC,                   L"" },
	{ D3D11_DECODER_PROFILE_VC1_MOCOMP,                     L"" },
	{ D3D11_DECODER_PROFILE_VC1_IDCT,                       L"" },
	// Nvidia decoders
	{ DXVA2_MPEG4pt2_VLD_AdvSimple_Nvidia,                  L"MPEG4pt2_AdvSimple_Nvidia" },
	{ DXVA2_MJPEG_VLD_Nvidia,                               L"MJPEG_Nvidia" },
	// AMD decoders
	{ DXVA2_MPEG4pt2_VLD_AdvSimple_AMD,                     L"MPEG4pt2_AdvSimple_AMD" },
	{ DXVA2_MJPEG_VLD_AMD,                                  L"MJPEG_AMD" },
	{ DXVA2_H264_VLD_NoFGT_AMD,                             L"H264_NoFGT_AMD" },
	{ DXVA2_H264_VLD_Multiview_AMD,                         L"H264_Multiview_AMD" },
	// Intel decoders
	{ DXVA2_VC1_VLD_Intel,                                  L"VC1_Intel" },
	{ DXVA2_VC1_VLD_2_Intel,                                L"VC1_2_Intel" },
	{ DXVA2_VP9_VLD_Intel,                                  L"VP9_Intel" },
	{ DXVA2_HEVC_VLD_Main_Intel,                            L"HEVC_Main_Intel" },
	{ DXVA2_HEVC_VLD_Main10_Intel,                          L"HEVC_Main10_Intel" },
	{ DXVA2_HEVC_VLD_Main12_Intel,                          L"HEVC_Main12_Intel" },
	{ DXVA2_HEVC_VLD_Main422_10_Intel,                      L"HEVC_Main422_10_Intel" },
	{ DXVA2_HEVC_VLD_Main422_12_Intel,                      L"HEVC_Main422_12_Intel" },
	{ DXVA2_HEVC_VLD_Main444_Intel,                         L"HEVC_Main444_Intel" },
	{ DXVA2_HEVC_VLD_Main444_10_Intel,                      L"HEVC_Main444_10_Intel" },
	{ DXVA2_HEVC_VLD_Main444_12_Intel,                      L"HEVC_Main444_12_Intel" },
};

const wchar_t* DecoderProfileToString(const GUID decoder_profile)
{
	for (const auto& decoderProfileInfo : g_D3D11DecoderProfileInfos) {
		if (decoder_profile == decoderProfileInfo.guid) {
			return decoderProfileInfo.str;
		}
	}

	return nullptr;
}
using Microsoft::WRL::ComPtr;

void TestDecoder_D3D11()
{
	HRESULT hr = S_OK;
	std::wcout << "=== Direct3D 11 ===" << std::endl;

	ComPtr<IDXGIFactory1> pDxgiFactory;
	hr = CreateDXGIFactory1(IID_PPV_ARGS(pDxgiFactory.GetAddressOf()));
	if (FAILED(hr)) {
		std::wcout << "ERROR: Failed to create IDXGIFactory1." << std::endl;
		return;
	}

	ComPtr<IDXGIAdapter1> pDxgiAdapter;
	UINT uAdapter = 0;
	while (SUCCEEDED(pDxgiFactory->EnumAdapters1(uAdapter++, pDxgiAdapter.GetAddressOf()))) {
		std::wcout << std::endl;
		std::wcout << "Graphics adapter " << (uAdapter - 1) << L": ";
		DXGI_ADAPTER_DESC1 desc = {};
		hr = pDxgiAdapter->GetDesc1(&desc);
		if (FAILED(hr)) {
			std::wcout << "ERROR: Failed to get description." << std::endl;
			pDxgiAdapter->Release();
			continue;
		}
		std::wcout << desc.Description << std::endl;

		D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_1 };
		D3D_FEATURE_LEVEL featurelevel = (D3D_FEATURE_LEVEL)0;

		ComPtr<ID3D11Device> pDevice;
		hr = D3D11CreateDevice(
			pDxgiAdapter.Get(),
			D3D_DRIVER_TYPE_UNKNOWN,
			nullptr,
#ifdef _DEBUG
			D3D11_CREATE_DEVICE_DEBUG,
#else
			0,
#endif
			featureLevels,
			(UINT)std::size(featureLevels),
			D3D11_SDK_VERSION,
			pDevice.GetAddressOf(),
			&featurelevel,
			nullptr
		);
		pDxgiAdapter->Release();
		if (FAILED(hr)) {
			std::wcout << "ERROR: Failed to create device D3D11." << std::endl;
			continue;
		}

		ComPtr<ID3D11VideoDevice> pVideoDevice;
		hr = pDevice.As(&pVideoDevice);
		if (FAILED(hr)) {
			std::wcout << "ERROR: Failed to get ID3D11VideoDevice." << std::endl;
			continue;
		}

		const UINT decoderProfileCount = pVideoDevice->GetVideoDecoderProfileCount();
		if (!decoderProfileCount) {
			std::wcout << "ERROR: Failed to DecoderProfileCount." << std::endl;
			continue;
		}

		std::wcout << "D3D11 video decoders [" << decoderProfileCount << L"]:";

		for (UINT index = 0; index < decoderProfileCount; index++) {
			GUID decoderProfile = {};
			hr = pVideoDevice->GetVideoDecoderProfile(index, &decoderProfile);
			if (FAILED(hr)) {
				continue;
			}

			auto str = DecoderProfileToString(decoderProfile);
			if (str && str[0]) {
				std::wcout << std::endl << "  " << std::left << std::setw(30) << str;
			}
			else {
#if 0
				std::wcout << std::endl << "  " << GUIDtoWString(decoderProfile);
#endif
				continue;
			}

			std::vector<DXGI_FORMAT> decodeFormats;

			for (UINT format = 1; format <= 190; format++) {
				BOOL supported = FALSE;
				hr = pVideoDevice->CheckVideoDecoderFormat(&decoderProfile, (DXGI_FORMAT)format, &supported);
				if (FAILED(hr)) {
					continue;
				}
				if (supported) {
					decodeFormats.emplace_back((DXGI_FORMAT)format);
				}
			}

			if (decodeFormats.size()) {
				std::wcout << L"(";
				for (size_t j = 0; j < decodeFormats.size(); j++) {
					if (j) {
						std::wcout << L", ";
					}
					std::wcout << DXGIFormatToString(decodeFormats[j]);
				}
				std::wcout << L")";
			}
		}
		std::wcout << std::endl;
	}
}

void TestDecoder_D3D12()
{
	HRESULT hr = S_OK;
	std::wcout << "=== Direct3D 12 ===" << std::endl;

#ifdef _DEBUG
	{
		// Enable the debug layer.
		ComPtr<ID3D12Debug> debugController;
		if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(debugController.GetAddressOf())))) {
			debugController->EnableDebugLayer();
		}
	}
#endif

	ComPtr<IDXGIFactory4> pDxgiFactory;
	hr = CreateDXGIFactory1(IID_PPV_ARGS(pDxgiFactory.GetAddressOf()));
	if (FAILED(hr)) {
		std::wcout << "ERROR: Failed to create IDXGIFactory4." << std::endl;
		return;
	}

	ComPtr<IDXGIAdapter1> pDxgiAdapter;
	UINT uAdapter = 0;
	while (SUCCEEDED(pDxgiFactory->EnumAdapters1(uAdapter++, pDxgiAdapter.GetAddressOf()))) {
		std::wcout << std::endl;
		std::wcout << "Graphics adapter " << (uAdapter - 1) << L": ";
		DXGI_ADAPTER_DESC1 desc = {};
		hr = pDxgiAdapter->GetDesc1(&desc);
		if (FAILED(hr)) {
			std::wcout << "ERROR: Failed to get description." << std::endl;
			pDxgiAdapter->Release();
			continue;
		}
		std::wcout << desc.Description << std::endl;

		ComPtr<ID3D12Device> pDevice;
		hr = D3D12CreateDevice(
			pDxgiAdapter.Get(),
			D3D_FEATURE_LEVEL_12_0,
			IID_PPV_ARGS(pDevice.GetAddressOf())
		);
		pDxgiAdapter->Release();
		if (FAILED(hr)) {
			std::wcout << "ERROR: Failed to create device D3D12." << std::endl;
			continue;
		}

		ComPtr<ID3D12VideoDevice> pVideoDevice;
		hr = pDevice.As(&pVideoDevice);
		if (FAILED(hr)) {
			std::wcout << "ERROR: Failed to get ID3D12VideoDevice." << std::endl;
			continue;
		}

		D3D12_FEATURE_DATA_VIDEO_DECODE_PROFILE_COUNT decodeProfileCountData = { 0, 0 };
		hr = pVideoDevice->CheckFeatureSupport(D3D12_FEATURE_VIDEO_DECODE_PROFILE_COUNT, &decodeProfileCountData, sizeof(decodeProfileCountData));
		if (FAILED(hr) || !decodeProfileCountData.ProfileCount) {
			std::wcout << "ERROR: Failed to get D3D12_FEATURE_VIDEO_DECODE_PROFILE_COUNT." << std::endl;
			continue;
		}

		std::vector<GUID> decodeProfiles(decodeProfileCountData.ProfileCount);
		D3D12_FEATURE_DATA_VIDEO_DECODE_PROFILES decoderProfilesData = {
			decodeProfileCountData.NodeIndex,
			decodeProfileCountData.ProfileCount,
			decodeProfiles.data()
		};
		hr = pVideoDevice->CheckFeatureSupport(D3D12_FEATURE_VIDEO_DECODE_PROFILES, &decoderProfilesData, sizeof(decoderProfilesData));
		if (FAILED(hr)) {
			std::wcout << "ERROR: Failed to get D3D12_FEATURE_VIDEO_DECODE_PROFILES." << std::endl;
			continue;
		}

		std::wcout << "D3D12 video decoders [" << decodeProfileCountData.ProfileCount << L"]:";
		for (const auto& decodeProfile : decodeProfiles) {
			std::wcout << std::endl << "  ";
			auto str = DecoderProfileToString(decodeProfile);
			if (str) {
				std::wcout << std::left << std::setw(30) << str;
			}
			else {
				std::wcout << GUIDtoWString(decodeProfile);
			}

			const D3D12_VIDEO_DECODE_CONFIGURATION decodeConfig = {
				decodeProfile,
				D3D12_BITSTREAM_ENCRYPTION_TYPE_NONE,
				D3D12_VIDEO_FRAME_CODED_INTERLACE_TYPE_NONE
			};
			D3D12_FEATURE_DATA_VIDEO_DECODE_FORMAT_COUNT decodeFormatCountData = {
				decodeProfileCountData.NodeIndex,
				decodeConfig,
				0
			};
			hr = pVideoDevice->CheckFeatureSupport(D3D12_FEATURE_VIDEO_DECODE_FORMAT_COUNT, &decodeFormatCountData, sizeof(decodeFormatCountData));
			if (FAILED(hr) || !decodeFormatCountData.FormatCount) {
				continue;
			}

			std::vector<DXGI_FORMAT> decodeFormats(decodeFormatCountData.FormatCount);
			D3D12_FEATURE_DATA_VIDEO_DECODE_FORMATS decodeFormatsData = {
				decodeProfileCountData.NodeIndex,
				decodeConfig,
				decodeFormatCountData.FormatCount,
				decodeFormats.data()
			};

			hr = pVideoDevice->CheckFeatureSupport(D3D12_FEATURE_VIDEO_DECODE_FORMATS, &decodeFormatsData, sizeof(decodeFormatsData));
			if (FAILED(hr)) {
				continue;
			}

			std::wcout << L"(";
			for (size_t j = 0; j < decodeFormats.size(); j++) {
				if (j) {
					std::wcout << L", ";
				}
				std::wcout << DXGIFormatToString(decodeFormats[j]);
			}
			std::wcout << L")";

			D3D12_FEATURE_DATA_VIDEO_DECODE_SUPPORT decodeFeature = {
				decodeProfileCountData.NodeIndex,
				decodeConfig,
				1920, 1080,
				decodeFormats[0],
				{ 30000 , 1001 },
				40 * 1000 * 1000,
				D3D12_VIDEO_DECODE_SUPPORT_FLAG_NONE,
				D3D12_VIDEO_DECODE_CONFIGURATION_FLAG_NONE,
				D3D12_VIDEO_DECODE_TIER_NOT_SUPPORTED
			};
			hr = pVideoDevice->CheckFeatureSupport(D3D12_FEATURE_VIDEO_DECODE_SUPPORT, &decodeFeature, sizeof(decodeFeature));
			if (SUCCEEDED(hr)) {
				const D3D12_VIDEO_DECODER_DESC decoderDesc = { 0, decodeConfig };
				ComPtr<ID3D12VideoDecoder> pVideoDecoder;
				hr = pVideoDevice->CreateVideoDecoder(&decoderDesc, IID_PPV_ARGS(pVideoDecoder.GetAddressOf()));
				if (SUCCEEDED(hr)) {
					const D3D12_VIDEO_DECODER_HEAP_DESC decoderHeapDesc = {
						0,
						decodeConfig,
						1920, 1080,
						decodeFormats[0],
						{ 30000 , 1001 },
						40 * 1000 * 1000,
						4
					};
					ComPtr<ID3D12VideoDecoderHeap> pVideoDecoderHeap;
					hr = pVideoDevice->CreateVideoDecoderHeap(&decoderHeapDesc, IID_PPV_ARGS(pVideoDecoderHeap.GetAddressOf()));
				}
			}
			std::wcout << L"  ";
			if (SUCCEEDED(hr) && decodeFeature.DecodeTier > 0) {
				std::wcout << L"Tier " << decodeFeature.DecodeTier;
			} else {
				std::wcout << L"broken";
			}
		}
		std::wcout << std::endl;
	}
}

/////////////////////////////

int wmain()
{
	TestDecoder_D3D11();

	std::wcout << std::endl;

	TestDecoder_D3D12();

	return 0;
}
