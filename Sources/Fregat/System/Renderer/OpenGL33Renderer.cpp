#include "OpenGL33Renderer.h"
#include <Fregat/System/Assets/Render/Components/RendererComponent.h>
#include <Fregat/System/Assets/Render/Material/SimpleMaterial.h>
#include <Fregat/System/Assets/Render/Shader/Shader.h>
#include <Fregat/System/Assets/Render/Mesh/MeshBase.h>
#include <Fregat/System/Core/Entity.h>
#include "ICamera.h"
#include <memory>
#include <GL/glew.h>
#include <SDL.h>

namespace Fregat
{
	namespace Render
	{
		OpenGL33Renderer::OpenGL33Renderer()
		{}

		OpenGL33Renderer::~OpenGL33Renderer()
		{}

		void OpenGL33Renderer::Render()
		{glEnable(GL_DEPTH_TEST);
			glClearColor(0.5, 0.5, 0.5, 1.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			
			for(auto rndr : m_renderers)
			{

				rndr->GetMaterial()->GetShader()->ActivateShader();
				Math::Mat4 proj;
				if (m_currentCamera != nullptr)
					proj = m_currentCamera->GetProjMatrix();
				//rndr->GetMaterial()->GetShader()->BindUniform4Mat(proj * rndr->GetParent()->GetTransform().GetGlobalTransformMatrix(), "modelViewProjectionMatrix");
				rndr->GetMaterial()->GetShader()->BindUniform4Mat(proj, "viewProjectionMatrix");
				
				rndr->GetMaterial()->GetShader()->BindUniform4Mat(m_currentCamera->GetMatrix(), "view");//(m_currentCamera->GetEntity()->GetTransform().GetGlobalTransformMatrix(), "view");
				rndr->GetMaterial()->GetShader()->BindUniform4Mat(rndr->GetEntity()->GetTransform().GetGlobalTransformMatrix(), "model");
				//ShowMat(m_currentCamera->GetMatrix());
				auto vec = m_currentCamera->GetPosition();
				//vec.SetZ(-vec.z);
				rndr->GetMaterial()->GetShader()->BindUniform3Vec(vec, "viewPos");
				
				//shaderProgram.BindUniform4Mat(projMat2, "modelViewProjectionMatrix");

				glBindVertexArray(rndr->GetMesh()->GetMeshPointer());//(colorPlane.GetVAO());
				glDrawElements(GL_TRIANGLES, rndr->GetMesh()->GetIndicesCount(), GL_UNSIGNED_INT, NULL);
			}
		}
	}
}