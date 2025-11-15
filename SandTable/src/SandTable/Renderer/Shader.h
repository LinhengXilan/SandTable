/**
 * @file SandTable/Renderer/Shader.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 * 
 * @brief 着色器类
 */

#ifndef SANDTABLE_RENDERER_SHADER_H
#define SANDTABLE_RENDERER_SHADER_H

#include <SandTable/Core.h>
#include <glm/glm.hpp>

namespace SandTable
{
	/**
	 * @brief 创建一个着色器
	 */
	class Shader
	{
	public:
		Shader() = default;
		virtual ~Shader() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual const std::string& GetName() const = 0;

		static ObjectRef<Shader> Create(const std::string& name, const std::string& vertexSource, std::string& fragmentSource);
		static ObjectRef<Shader> Create(const std::string& path);
	};

	/**
	 * @brief 管理对象的着色器
	 */
	class ShaderLibrary
	{
	public:
		ShaderLibrary() = default;
		~ShaderLibrary() = default;

	public:
		ObjectRef<Shader> GetShader(const std::string& name);
		void Add(const ObjectRef<Shader>& shader);
		void Add(const std::string& name, const ObjectRef<Shader>& shader);
		ObjectRef<Shader> Load(const std::string& path);
		ObjectRef<Shader> Load(const std::string& name, const std::string& path);

	private:
		std::unordered_map<std::string, ObjectRef<Shader>> m_Shaders;
	};
}

#endif