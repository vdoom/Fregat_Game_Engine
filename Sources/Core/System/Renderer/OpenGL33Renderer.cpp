#include "OpenGL33Renderer.h"
#include "../../Assets/Render/Components/RendererComponent.h"
#include "../../Assets/Render/Material/SimpleMaterial.h"
#include "../../Assets/Render/Shader/Shader.h"
#include "../../Assets/Render/Mesh/MeshBase.h"
#include "../../Entity.h"
#include "Camera.h"
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
		{
			for(auto rndr : m_renderers)
			{

				rndr->GetMaterial()->GetShader()->ActivateShader();
				Math::Mat4 proj;
				if (m_currentCamera != nullptr)
					proj = m_currentCamera->GetProjMatrix();
				//rndr->GetMaterial()->GetShader()->BindUniform4Mat(proj * rndr->GetParent()->GetTransform().GetGlobalTransformMatrix(), "modelViewProjectionMatrix");
				rndr->GetMaterial()->GetShader()->BindUniform4Mat(proj, "viewProjectionMatrix");
				
				rndr->GetMaterial()->GetShader()->BindUniform4Mat(m_currentCamera->GetEntity()->GetTransform().GetGlobalTransformMatrix(), "view");
				rndr->GetMaterial()->GetShader()->BindUniform4Mat(rndr->GetEntity()->GetTransform().GetGlobalTransformMatrix(), "model");
				ShowMat(m_currentCamera->GetEntity()->GetTransform().GetGlobalTransformMatrix());
				auto vec = m_currentCamera->GetPos();
				vec.SetZ(-vec.z);
				rndr->GetMaterial()->GetShader()->BindUniform3Vec(vec, "viewPos");
				
				//shaderProgram.BindUniform4Mat(projMat2, "modelViewProjectionMatrix");

				glBindVertexArray(rndr->GetMesh()->GetMeshPointer());//(colorPlane.GetVAO());
				glDrawElements(GL_TRIANGLES, rndr->GetMesh()->GetIndicesCount(), GL_UNSIGNED_INT, NULL);
			}
		}
	}
}