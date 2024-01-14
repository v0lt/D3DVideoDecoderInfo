#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")

#include <iostream>
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
	// obsolete incomplete decoders (MOCOMP, IDCT, POSTPROC)
	{ D3D11_DECODER_PROFILE_MPEG2_MOCOMP,      L"" },
	{ D3D11_DECODER_PROFILE_MPEG2_IDCT,        L"" },
	{ D3D11_DECODER_PROFILE_H264_MOCOMP_NOFGT, L"" },
	{ D3D11_DECODER_PROFILE_H264_MOCOMP_FGT,   L"" },
	{ D3D11_DECODER_PROFILE_H264_IDCT_NOFGT,   L"" },
	{ D3D11_DECODER_PROFILE_H264_IDCT_FGT,     L"" },
	{ D3D11_DECODER_PROFILE_WMV8_POSTPROC,     L"" },
	{ D3D11_DECODER_PROFILE_WMV8_MOCOMP,       L"" },
	{ D3D11_DECODER_PROFILE_WMV9_POSTPROC,     L"" },
	{ D3D11_DECODER_PROFILE_WMV9_MOCOMP,       L"" },
	{ D3D11_DECODER_PROFILE_WMV9_IDCT,         L"" },
	{ D3D11_DECODER_PROFILE_VC1_POSTPROC,      L"" },
	{ D3D11_DECODER_PROFILE_VC1_MOCOMP,        L"" },
	{ D3D11_DECODER_PROFILE_VC1_IDCT,          L"" },
	// D3D11 decoders (VLD)
	{ D3D11_DECODER_PROFILE_MPEG2_VLD,                         L"MPEG2" },
	{ D3D11_DECODER_PROFILE_MPEG1_VLD,                         L"MPEG1" },
	{ D3D11_DECODER_PROFILE_MPEG2and1_VLD,                     L"MPEG2and1" },
	{ D3D11_DECODER_PROFILE_H264_VLD_NOFGT,                    L"H264_NOFGT" },
	{ D3D11_DECODER_PROFILE_H264_VLD_FGT,                      L"H264_FGT" },
	{ D3D11_DECODER_PROFILE_H264_VLD_WITHFMOASO_NOFGT,         L"H264_WITHFMOASO_NOFGT" },
	{ D3D11_DECODER_PROFILE_H264_VLD_STEREO_PROGRESSIVE_NOFGT, L"H264_STEREO_PROGRESSIVE_NOFGT" },
	{ D3D11_DECODER_PROFILE_H264_VLD_STEREO_NOFGT,             L"H264_STEREO_NOFG" },
	{ D3D11_DECODER_PROFILE_H264_VLD_MULTIVIEW_NOFGT,          L"H264_MULTIVIEW_NOFGT" },
	{ D3D11_DECODER_PROFILE_VC1_VLD,                           L"VC1" },
	{ D3D11_DECODER_PROFILE_VC1_D2010,                         L"VC1_2010" },
	{ D3D11_DECODER_PROFILE_MPEG4PT2_VLD_SIMPLE,               L"MPEG4PT2_SIMPLE" },
	{ D3D11_DECODER_PROFILE_MPEG4PT2_VLD_ADVSIMPLE_NOGMC,      L"MPEG4PT2_ADVSIMPLE_NOGMC" },
	{ D3D11_DECODER_PROFILE_MPEG4PT2_VLD_ADVSIMPLE_GMC,        L"MPEG4PT2_ADVSIMPLE_GMC" },
	{ D3D11_DECODER_PROFILE_HEVC_VLD_MAIN,                     L"HEVC_MAIN" },
	{ D3D11_DECODER_PROFILE_HEVC_VLD_MAIN10,                   L"HEVC_MAIN10" },
	{ D3D11_DECODER_PROFILE_VP9_VLD_PROFILE0,                  L"VP9_PROFILE0" },
	{ D3D11_DECODER_PROFILE_VP9_VLD_10BIT_PROFILE2,            L"VP9_10BIT_PROFILE2" },
	{ D3D11_DECODER_PROFILE_VP8_VLD,                           L"VP8" },
	// D3D11/D3D12 decoders
	{ D3D12_VIDEO_DECODE_PROFILE_AV1_PROFILE0,                 L"AV1_PROFILE0" },
	{ D3D12_VIDEO_DECODE_PROFILE_AV1_PROFILE1,                 L"AV1_PROFILE1" },
	{ D3D12_VIDEO_DECODE_PROFILE_AV1_PROFILE2,                 L"AV1_PROFILE2" },
	{ D3D12_VIDEO_DECODE_PROFILE_AV1_12BIT_PROFILE2,           L"AV1_12BIT_PROFILE2" },
	{ D3D12_VIDEO_DECODE_PROFILE_AV1_12BIT_PROFILE2_420,       L"AV1_12BIT_PROFILE2_420" },
	// Nvidia decoders
	{ DXVA2_MPEG4pt2_VLD_AdvSimple_Nvidia,                     L"MPEG4pt2_AdvSimple_Nvidia" },
	{ DXVA2_MJPEG_VLD_Nvidia,                                  L"MJPEG_Nvidia" },
	// AMD decoders
	{ DXVA2_MPEG4pt2_VLD_AdvSimple_AMD,                        L"MPEG4pt2_AdvSimple_AMD" },
	{ DXVA2_MJPEG_VLD_AMD,                                     L"MJPEG_AMD" },
	{ DXVA2_H264_VLD_NoFGT_AMD,                                L"H264_NoFGT_AMD" },
	{ DXVA2_H264_VLD_Multiview_AMD,                            L"H264_Multiview_AMD" },
	// Intel decoders
	{ DXVA2_VC1_VLD_Intel,                                     L"VC1_Intel" },
	{ DXVA2_VC1_VLD_2_Intel,                                   L"VC1_2_Intel" },
	{ DXVA2_VP9_VLD_Intel,                                     L"VP9_Intel" },
	{ DXVA2_HEVC_VLD_Main_Intel,                               L"HEVC_Main_Intel" },
	{ DXVA2_HEVC_VLD_Main10_Intel,                             L"HEVC_Main10_Intel" },
	{ DXVA2_HEVC_VLD_Main12_Intel,                             L"HEVC_Main12_Intel" },
	{ DXVA2_HEVC_VLD_Main422_10_Intel,                         L"HEVC_Main422_10_Intel" },
	{ DXVA2_HEVC_VLD_Main422_12_Intel,                         L"HEVC_Main422_12_Intel" },
	{ DXVA2_HEVC_VLD_Main444_Intel,                            L"HEVC_Main444_Intel" },
	{ DXVA2_HEVC_VLD_Main444_10_Intel,                         L"HEVC_Main444_10_Intel" },
	{ DXVA2_HEVC_VLD_Main444_12_Intel,                         L"HEVC_Main444_12_Intel" },
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
				std::wcout << std::endl << "  " << str;
			}
#if 0
			else {
				std::wcout << std::endl << "  " << GUIDtoWString(decoderProfile);
			}
#endif
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
				std::wcout << str;
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

			std::wcout << L"  (";
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
