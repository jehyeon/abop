#pragma once

class ModelClass : public AlignedAllocationPolicy<16>
{
protected:
    struct VertexType
    {
        DirectX::XMFLOAT3 position;
        DirectX::XMFLOAT4 color;
    };

public:
    ModelClass();
    ModelClass(const ModelClass&);
    ~ModelClass();

    bool Initialize(ID3D11Device*, float* = nullptr);
    void Shutdown();
    void Render(ID3D11DeviceContext*);

    void SetPosition(const float&, const float&, const float&);

    int GetIndexCount();

protected:
    // ModelClass 자식 모델 오버라이드
    bool InitializeBuffers(ID3D11Device*);
    bool InitializeBuffers(ID3D11Device*, float*);
    void ShutdownBuffers();
    void RenderBuffers(ID3D11DeviceContext*);

protected:
    ID3D11Buffer* vertexBuffer_ = nullptr;
    ID3D11Buffer* indexBuffer_ = nullptr;
    int vertexCount_ = 0;
    int indexCount_ = 0;

    Vector3 position_ = { 0, 0, 0 };
    DirectX::XMFLOAT4 color_ = { 0, 0, 0, 0 };
};