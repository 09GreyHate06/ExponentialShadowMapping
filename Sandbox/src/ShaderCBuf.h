#pragma once
#include <DirectXMath.h>

namespace ESM
{
	namespace PhongCBuf
	{
		struct VSSystem
		{
			DirectX::XMFLOAT4X4 viewProjection;
			DirectX::XMFLOAT3 viewPos; // camera pos
			float p0;
		};

		struct VSEntity
		{
			DirectX::XMFLOAT4X4 transform;
			DirectX::XMFLOAT4X4 normalMatrix;
		};

		struct PSSystem
		{
			struct DirectionalLight
			{
				DirectX::XMFLOAT3 color;
				float ambientIntensity;
				DirectX::XMFLOAT3 direction;
				float intensity;
				DirectX::XMFLOAT4X4 lightSpace;
			} dirLight;

			struct BasicSMapControl
			{
				uint32_t pcfLevel;
				DirectX::XMFLOAT3 p0;
			} basicSMapControl;

			struct ESMControl
			{
				BOOL useESM;
				BOOL linearizeDepth;
				float nearZ; // light space near
				float farZ; // light space near
				float expScalarC;
				DirectX::XMFLOAT3 p0;
			} esmControl;
		};

		struct PSEntity
		{
			struct Material
			{
				DirectX::XMFLOAT4 color;
				DirectX::XMFLOAT2 tiling;
				float shininess;
				BOOL enableNormalMapping;
				BOOL enableParallaxMapping;
				float depthMapScale;
				int p0;
				int p1;
			} mat;
		};
	}

	namespace BlurCBuf
	{
		struct PSKernel
		{
			uint32_t nTaps;
			DirectX::XMUINT3 p0;
			DirectX::XMFLOAT4 coefficients[35];
		};

		struct PSControl
		{
			DirectX::XMFLOAT2 texelStep;
			DirectX::XMFLOAT2 p1;
		};
	}

	namespace ESMCBuf
	{
		struct PSSystem
		{
			BOOL linearizeDepth;
			float nearZ; // light space near
			float farZ; // light space near
			float expScalarC;
		};
	}
}