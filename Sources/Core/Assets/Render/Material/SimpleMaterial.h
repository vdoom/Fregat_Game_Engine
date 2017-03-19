//---------------------------------------------
// Simple material for 2D texture and simple shader
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include "MaterialBase.h"
#include <memory>

namespace Fregat
{
	namespace Render
	{
		class Shader;
		class TextureBase;

		class SimpleMaterial : public MaterialBase
		{
		private:
			std::shared_ptr<Shader> m_shader;
			std::shared_ptr<TextureBase> m_texture;
		public:
			SimpleMaterial();
			virtual ~SimpleMaterial();
			void InitMaterial(std::shared_ptr<Shader>, std::shared_ptr<TextureBase>);
			static SimpleMaterial CreateMaterial(std::shared_ptr<Shader>, std::shared_ptr<TextureBase>);

			inline Shader* GetShader(){return m_shader.get();}
			inline TextureBase* GetTexture(){return m_texture.get();}
		};
	}
}