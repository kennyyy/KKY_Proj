struct VS_IN {
    float3 p : POSITION;
    float2 t : TEXTURE;
};

struct VS_OUT {
    float4 p : SV_POSITION;
    float2 t : TEXTURE;
};

cbuffer cb0 {
    matrix g_mtxWorld :  packoffset(c0);
    matrix g_mtxView:  packoffset(c4);
    matrix g_mtxProj : packoffset(c8);
};


VS_OUT VS(VS_IN vin)
{
    VS_OUT vOut = (VS_OUT)0;
    vOut.p = mul(float4(vin.p, 1.0f),    g_mtxWorld);
    vOut.p = mul(vOut.p,    g_mtxView);
    vOut.p = mul(vOut.p,    g_mtxProj);
   // vOut.p = float4(vin.p.x, vin.p.y, vin.p.z, 1);
    vOut.t = vin.t;
    return vOut;
}

Texture2D g_txDiffuse1 : register(t0);
Texture2D g_txDiffuseMask1 : register(t1);
SamplerState sample0 : register(s0);

struct PS_IN {
	float4 p : SV_POSITION;
	float2 t : TEXTURE;
};

float4 PS(PS_IN vIn) : SV_Target
{
    float4 color = g_txDiffuse1.Sample(sample0, vIn.t);
    color.a = 1.0f - g_txDiffuseMask1.Sample(sample0, vIn.t).r;
    return color;
}