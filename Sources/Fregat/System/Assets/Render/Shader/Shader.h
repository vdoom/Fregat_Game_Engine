//---------------------------------------------
// Shader class for material
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once

#include <GL/glew.h>// TODO: need to remove frome here
#include <map>
#include <memory>
#include <string>
#include <Fregat/MathLib/Mat4.h>
#include <Fregat/MathLib/Vec3.h>
#include <Fregat/System/Assets/AssetsManagement/AssetBase.h> // "../../AssetsManagement/AssetBase.h"

namespace Fregat
{
	namespace Render
	{
		enum class ShaderType
		{
			GLST_NONE,
			GLST_VERTEX_SHADER,
			GLST_FRAGMENT_SHADER,
			GLST_PROGRAM_SHADER
		};

		class Shader// : public System::AssetBase
		{			
		private:
			std::map<ShaderType, std::unique_ptr<Shader>> m_shadersPack;
			std::map<GLuint, std::string> m_attribLocks;
			std::string m_shaderText;
			std::string m_shaderCompileErrore;
			GLuint m_objectIndex;
			int m_isCompiled;
			ShaderType m_type;
			GLenum ConverShaderType(ShaderType);
			//char* filetobuf(char *file);
		public:
			Shader();
			//Shader(const Shader&);
			// no copy
			//Shader(const Shader&)// = delete;
			//{}
			// no assign
			//Shader& operator=(const Shader&);
			
			Shader(Shader&&);
			virtual ~Shader();
			//TODO: !!!! need to add operator = !!!!
			void SetShaderText(const std::string&, ShaderType);
			void SetShaderFile(const std::string&, ShaderType);
			void AddShader(std::unique_ptr<Shader>&, ShaderType);
			bool Compile();
			bool Link();
			
			void BindAttribLocation(GLuint, const char*);
			void BindUniform1Int(GLint, const char*);
			void BindUniform4Mat(const Math::Mat4&, const char*);
			void BindUniform3Vec(const Math::Vec3&, const char*);
			//TODO: need add method for optimized Uniform Update
			void ActivateShader();
			void DisactivateShader();
			//TODO: Need methods gor detaching and remmoving shaders

			static std::unique_ptr<Shader> CreateShader(const std::string&, const std::string&) noexcept;

			inline bool IsCompiled() const 
			{return 1 && m_isCompiled;}
			inline GLuint GetGLObject() const
			{return m_objectIndex;}
			inline std::string GetCompileError() const
			{return m_shaderCompileErrore;}
			inline ShaderType GetType()
			{return m_type;}
			
		};
	}
}