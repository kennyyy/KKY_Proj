struct VS_IN {
    float3 p : POSITION;
    float2 t : TEXTURE;
};

struct VS_OUT {
    float4 p : SV_POSITION;
    float2 t : TEXTURE;
};


VS_OUT VS(VS_IN vin)
{
    VS_OUT vOut = (VS_OUT)0;
    vOut.p = float4(vin.p.x, vin.p.y, vin.p.z, 1);
    vOut.t = vin.t;
    return vOut;
}
