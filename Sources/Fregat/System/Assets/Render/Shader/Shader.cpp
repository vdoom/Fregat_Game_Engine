#include "Shader.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <assert.h>
#include <memory>

namespace Fregat
{
	namespace Render
	{
		char* filetobuf(const char *file)
		{
		    FILE *fptr;
		    long length;
		    char *buf;
		
		    fptr = fopen(file, "rb"); /* Open file for reading */
		    if (!fptr) /* Return NULL on failure */
		        return NULL;
		    fseek(fptr, 0, SEEK_END); /* Seek to the end of the file */
		    length = ftell(fptr); /* Find out how many bytes into the file we are */
		    buf = (char*)malloc(length+1); /* Allocate a buffer for the entire length of the file and a null terminator */
		    fseek(fptr, 0, SEEK_SET); /* Go back to the beginning of the file */
		    fread(buf, length, 1, fptr); /* Read the contents of the file in to the buffer */
		    fclose(fptr); /* Close the file */
		    buf[length] = 0; /* Null terminator */
		
		    return buf; /* Return the buffer */
		}

		Shader::Shader()
		{
			m_objectIndex = -1;
			m_isCompiled = -1;
			m_type = ShaderType::GLST_NONE;
		}

		//Shader::Shader(const Shader& t_shdr)
		//{
		//	//TODO:should be removed
		//}

		//Shader::Shader(const Shader&) = delete;
			// no assign
		//Shader& Shader::operator=(const Shader&) = delete;

		Shader::Shader(Shader&& t_shdr)
		{
			m_objectIndex = t_shdr.m_objectIndex;
			t_shdr.m_objectIndex = -1;
			m_isCompiled = t_shdr.m_isCompiled;
			t_shdr.m_isCompiled = false;
			m_type = t_shdr.m_type;
			t_shdr.m_type = ShaderType::GLST_NONE;
			/*std::map<ShaderType, Shader> m_shadersPack;
			std::map<GLuint, std::string> m_attribLocks;
			std::string m_shaderText;
			std::string m_shaderCompileErrore;*/
			m_shaderCompileErrore = t_shdr.m_shaderCompileErrore;
			m_shaderText = t_shdr.m_shaderText;
			m_shadersPack = std::move(t_shdr.m_shadersPack);
			m_attribLocks = std::move(t_shdr.m_attribLocks);
		}

		Shader::~Shader()
		{
			//DisactivateShader();

			if(m_type == ShaderType::GLST_PROGRAM_SHADER)
			{
				glDisableVertexAttribArray(0);
				glDisableVertexAttribArray(1);
				glDetachShader(GetGLObject(), m_shadersPack[ShaderType::GLST_VERTEX_SHADER]->GetGLObject());
				glDetachShader(GetGLObject(), m_shadersPack[ShaderType::GLST_FRAGMENT_SHADER]->GetGLObject());
				glDeleteProgram(GetGLObject());
			}
			else if(m_type == ShaderType::GLST_FRAGMENT_SHADER ||
				m_type == ShaderType::GLST_VERTEX_SHADER)
			{
				glDeleteShader(this->GetGLObject());
			}
			//TODO: need to remove all data and free memory

				//shaderProgram.DisactivateShader();
	//glDisableVertexAttribArray(0);
 //   glDisableVertexAttribArray(1);
	//glDetachShader(shaderProgram.GetGLObject(), vertShader.GetGLObject());
	//glDetachShader(shaderProgram.GetGLObject(), fragShader.GetGLObject());
    //glDeleteProgram(shaderProgram.GetGLObject());
   // glDeleteShader(vertShader.GetGLObject());
    //glDeleteShader(fragShader.GetGLObject());
		}

		void Shader::SetShaderText(const std::string& t_sourceCode, ShaderType t_shaderType)
		{
			m_objectIndex = glCreateShader(ConverShaderType(t_shaderType));
			m_type = t_shaderType;
			const char* str = t_sourceCode.c_str();
			glShaderSource(m_objectIndex, 1, (const GLchar**)&str, 0);
		}
		void Shader::SetShaderFile(const std::string&, ShaderType t_shaderType)
		{}

		void Shader::AddShader(std::unique_ptr<Shader>& t_shader, ShaderType t_type)
		{m_shadersPack[t_type] = std::move(t_shader);}

		bool Shader::Compile()
		{
			assert(m_objectIndex!=-1);
			glCompileShader(m_objectIndex);

			glGetShaderiv(m_objectIndex, GL_COMPILE_STATUS, &m_isCompiled);
			if(m_isCompiled == 0)
			{
				char *infoLog;
				int maxLength;
				glGetShaderiv(m_objectIndex, GL_INFO_LOG_LENGTH, &maxLength);
				infoLog = (char *)malloc(maxLength);
				glGetShaderInfoLog(m_objectIndex, maxLength, &maxLength, infoLog);
				m_shaderCompileErrore = std::string(infoLog);
				std::cout<<infoLog<<std::endl;
				free(infoLog);
				return false;
			}
			return true;
		}

		bool Shader::Link()
		{
			std::cout<<"Link shader"<<std::endl;
			//TODO: need implement
			m_objectIndex = glCreateProgram();

			/* Attach our shaders to our program */
			auto vertexShader = m_shadersPack.find(ShaderType::GLST_VERTEX_SHADER);
			assert(vertexShader != m_shadersPack.end() && vertexShader->second->IsCompiled());
			auto fragmentShader = m_shadersPack.find(ShaderType::GLST_FRAGMENT_SHADER);
			assert(fragmentShader != m_shadersPack.end() && fragmentShader->second->IsCompiled());
			std::cout<<vertexShader->second->GetGLObject()<<" "<<fragmentShader->second->GetGLObject()<<std::endl;
			glAttachShader(m_objectIndex, vertexShader->second->GetGLObject());
			glAttachShader(m_objectIndex, fragmentShader->second->GetGLObject());

			for(auto attrib : m_attribLocks)
			{
				std::cout<<attrib.first<<" "<<attrib.second.c_str()<<std::endl;
				glBindAttribLocation(m_objectIndex, attrib.first, attrib.second.c_str());
			}

			glLinkProgram(m_objectIndex);

			glGetProgramiv(m_objectIndex, GL_LINK_STATUS, (int *)&m_isCompiled);
			if(m_isCompiled == 0)
			{
				char *infoLog;
				int maxLength;
				/* Noticed that glGetProgramiv is used to get the length for a shader program, not glGetShaderiv. */
				glGetProgramiv(m_objectIndex, GL_INFO_LOG_LENGTH, &maxLength);

				/* The maxLength includes the NULL character */
				infoLog = (char *)malloc(maxLength);

				/* Notice that glGetProgramInfoLog, not glGetShaderInfoLog. */
				glGetProgramInfoLog(m_objectIndex, maxLength, &maxLength, infoLog);

				/* Handle the error in an appropriate way such as displaying a message or writing to a log file. */
				/* In this simple program, we'll just leave */
				m_shaderCompileErrore = std::string(infoLog);
				std::cout<<infoLog<<std::endl;
				free(infoLog);
				return false;
			}
			//glUseProgram(m_objectIndex);
			//auto colorTextureLocation = glGetUniformLocation(m_objectIndex, "colorTexture");
			//if ((colorTextureLocation) != -1)
				//glUniform1i(colorTextureLocation, 0);
			//glUniform1i(2, 0);
			return true;
		}
		
		void Shader::BindAttribLocation(GLuint t_location, const char* t_name)
		{
			std::cout<<t_location<<" "<<t_name<<std::endl;
			m_attribLocks[t_location] = t_name;
		}

		void Shader::BindUniform1Int(GLint t_index, const char* t_name)
		{
			auto colorTextureLocation = glGetUniformLocation(m_objectIndex, t_name);
			if ((colorTextureLocation) != -1)
				glUniform1i(colorTextureLocation, t_index);
		}

		void Shader::BindUniform4Mat(const Math::Mat4& t_mat, const char* t_name)
		{
			auto matrixLocation = glGetUniformLocation(m_objectIndex, t_name);//TODO: perhaps need to thik about caching this data
			glUniformMatrix4fv(matrixLocation, 1, GL_TRUE, t_mat.m);
		}

		void Shader::BindUniform3Vec(const Math::Vec3& t_vec, const char* t_name)
		{
			auto vectorLocation = glGetUniformLocation(m_objectIndex, t_name);
			glUniform3fv(vectorLocation, 1, t_vec.v);
		}
		
		void Shader::ActivateShader()
		{
			glUseProgram(m_objectIndex);
		}

		void Shader::DisactivateShader()
		{
			glUseProgram(0);
		}

		GLenum Shader::ConverShaderType(ShaderType t_type)
		{
			assert(t_type != ShaderType::GLST_NONE);
			switch(t_type)
			{
			case ShaderType::GLST_FRAGMENT_SHADER:
				return GL_FRAGMENT_SHADER;
			case ShaderType::GLST_VERTEX_SHADER:
				return GL_VERTEX_SHADER;
			default:
				return -1;
			}
		}

		std::unique_ptr<Shader> Shader::CreateShader(const std::string& t_vertexShaderPath, const std::string& t_fragmentShaderPath) noexcept
		{
			GLchar *vertexsource, *fragmentsource;
			vertexsource = filetobuf(t_vertexShaderPath.c_str());
			fragmentsource = filetobuf(t_fragmentShaderPath.c_str());
			//tmpClass ttt;
			std::unique_ptr<Shader> vertShader(new Shader());
			vertShader->SetShaderText(vertexsource, ShaderType::GLST_VERTEX_SHADER);
			vertShader->Compile();

			std::unique_ptr<Shader> fragShader(new Shader());
			fragShader->SetShaderText(fragmentsource, ShaderType::GLST_FRAGMENT_SHADER);
			fragShader->Compile();

			std::unique_ptr<Shader> shaderProgram(new Shader);
			shaderProgram->m_type = ShaderType::GLST_PROGRAM_SHADER;
			shaderProgram->AddShader(vertShader, ShaderType::GLST_VERTEX_SHADER);
			shaderProgram->AddShader(fragShader, ShaderType::GLST_FRAGMENT_SHADER);
			
			shaderProgram->BindAttribLocation(0, "in_Position");
			shaderProgram->BindAttribLocation(1, "in_Texcoord");//"in_Color");
			shaderProgram->BindAttribLocation(2, "in_Normals");
			
			shaderProgram->Link();
			free(vertexsource);
			free(fragmentsource);
			//shaderProgram.ActivateShader();
			//shaderProgram.BindUniform1Int(0, "colorTexture");
			return shaderProgram;
		}
	}
}
