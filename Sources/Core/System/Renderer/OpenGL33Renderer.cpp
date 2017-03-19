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
				//rndr->
				//TODO: perhaps need methods for preparing shaders
				//Transform& trnc = rndr->GetParent()->GetTransform();
				rndr->GetMaterial()->GetShader()->ActivateShader();
				Math::Mat4 proj;
				if(m_currentCamera != nullptr)
					proj = m_currentCamera->GetProjMatrix();
				rndr->GetMaterial()->GetShader()->BindUniform4Mat(proj * rndr->GetParent()->GetTransform().GetGlobalTransformMatrix(), "modelViewProjectionMatrix");
				
				//shaderProgram.BindUniform4Mat(projMat2, "modelViewProjectionMatrix");

				glBindVertexArray(rndr->GetMesh()->GetMeshPointer());//(colorPlane.GetVAO());
				/* Invoke glDrawArrays telling that our data is a line loop and we want to draw 2-4 vertexes */
				//glDrawArrays(GL_TRIANGLE_FAN, 0, 4);//GL_POINTS//GL_TRIANGLE_FAN
				glDrawElements(GL_TRIANGLES, rndr->GetMesh()->GetIndicesCount(), GL_UNSIGNED_INT, NULL);
			}
		}
	}
}