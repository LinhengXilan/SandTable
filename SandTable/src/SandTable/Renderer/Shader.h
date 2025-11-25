/**
 * @file SandTable/Renderer/Shader.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief 着色器类
 */

#ifndef SANDTABLE_RENDERER_SHADER_H
#define SANDTABLE_RENDERER_SHADER_H

#include <SandTable/Core/Core.h>
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

		virtual void SetData(const std::string& name, int32_t value) = 0;
		virtual void SetData(const std::string& name, uint32_t value) = 0;
		virtual void SetData(const std::string& name, float value) = 0;
		virtual void SetData(const std::string& name, double value) = 0;
		virtual void SetData(const std::string& name, const glm::vec2& value) = 0;
		virtual void SetData(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetData(const std::string& name, const glm::vec4& value) = 0;
		virtual void SetData(const std::string& name, const glm::mat3& value) = 0;
		virtual void SetData(const std::string& name, const glm::mat4& value) = 0;

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
		/**
		 * @brief 添加现有着色器
		 * @param shader 着色器对象
		 */
		void Add(const ObjectRef<Shader>& shader);
		void Add(const std::string& name, const ObjectRef<Shader>& shader);
		/**
		 * @brief 从文件加载着色器
		 * @param path 文件路径
		 * @return 着色器对象
		 */
		ObjectRef<Shader> Load(const std::string& path);
		ObjectRef<Shader> Load(const std::string& name, const std::string& path);

	private:
		std::unordered_map<std::string, ObjectRef<Shader>> m_Shaders;
	};
}

#endif