#include "shadow_mapping.hlsli"

cbuffer SystemCBuf : register(b0)
{
    bool linearizeDepth;
    float nearZ; // light space near
    float farZ; // light space far
    float expScalarC;
};

float4 main(float4 position : SV_Position) : SV_Target
{
    const float z = linearizeDepth ? LinearizeDepth(position.z, nearZ, farZ) : position.z;
    const float e_cz = exp(expScalarC * z);
    return float4(e_cz, 0.0f, 0.0f, 0.0f);
}