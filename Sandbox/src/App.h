#pragma once
#include <GDX11.h>
#include <GDX11/Utils/ResourceLibrary.h>
#include <GDX11/Utils/Time.h>
#include "Rendering/Camera.h"
#include "Rendering/EditorCameraController.h"
#include "Rendering/Mesh.h"
#include "Rendering/Model.h"
#include "Rendering/Light.h"
#include "ImGui/ImGuiManager.h"

namespace ESM
{
	class App
	{
	public:
		App();

		void Run();

	private:
		void OnEvent(GDX11::Event& event);
		void OnUpdate();
		void OnRender();
		void OnImGuiRender();

		void BasicSMapPass();
		void ESMPass();
		void ESMBlurPass();
		void RenderPass();
		void GammaCorrectionPass();

		bool OnWindowResizedEvent(GDX11::WindowResizeEvent& event);


		
		void ResizeViews(uint32_t width, uint32_t height);
		void SetShaders();
		void SetStates();
		void SetBuffers();
		void SetTextures();
		void SetSwapChain();
		void SetESMBlurKernel(int radius, float sigma);
		void ResizeBasicSMap(uint32_t width, uint32_t height);
		void ResizeESM(uint32_t width, uint32_t height);
		void ResizeESMMS(uint32_t width, uint32_t height, int samples);




		std::unique_ptr<GDX11::Window> m_window;
		std::unique_ptr<GDX11::GDX11Context> m_context;
		GDX11::Utils::ResourceLibrary m_resLib;
		ImGuiManager m_imguiManager;

		Camera m_camera;
		EditorCameraController m_cameraController;

		GDX11::Utils::Time m_time;

		DirectionalLight m_dirLight;
		Mesh m_cube;
		Mesh m_plane;
		std::unique_ptr<Model> m_model;

		// controls
		bool m_drawDirLightFrustum = false;

		bool m_useESM = false;
		bool m_blurESM = false;
		DirectX::XMUINT2 m_esmSize = { 512, 512 };
		bool m_esmlinearizeDepth = false;
		float m_esmExpScalarC = 80.0f;
		int m_esmGaussBlurRadius = 4;
		float m_esmGaussBlurSigma = 1.5f;
		int m_esmSamplesArrayIndex = 0;
		int m_esmSamples = 2;
		int m_esmSamplerArrayIndex = 2;
		std::string m_esmSampler;

		DirectX::XMUINT2 m_basicSMapSize = { 512, 512 };
		int m_basicSMapPCF = 4;
	};
}