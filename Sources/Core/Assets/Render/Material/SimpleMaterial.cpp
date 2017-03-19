#include "SimpleMaterial.h"
#include "../Shader/Shader.h"
#include "../Texture/Texture2D.h"

namespace Fregat
{
	namespace Render
	{
		SimpleMaterial::SimpleMaterial()
		{}

		SimpleMaterial::~SimpleMaterial()
		{
			//TODO: need releas all generated content
		}

		void SimpleMaterial::InitMaterial(std::shared_ptr<Shader> t_shader, std::shared_ptr<TextureBase> t_texture)
		{
			m_shader = t_shader;
			m_texture = t_texture;
			m_shader->ActivateShader();
			
			m_shader->BindUniform1Int(0, "colorTexture");
		}

		SimpleMaterial SimpleMaterial::CreateMaterial(std::shared_ptr<Shader> t_shader, std::shared_ptr<TextureBase> t_texture)
		{
			SimpleMaterial tmp;
			tmp.InitMaterial(t_shader, t_texture);
			return tmp;
			//
		}
	}
}
