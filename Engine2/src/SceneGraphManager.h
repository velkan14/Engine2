#pragma once

#ifndef _SCENE_MANAGER_
#define _SCENE_MANAGER_

#include <string>
#include <map>

namespace Engine2{

	class SceneGraph;

	class SceneGraphManager
	{
	private:
		static SceneGraphManager* m_instance;

		std::map<std::string, SceneGraph*> scenes;

		SceneGraphManager();
		~SceneGraphManager();

	public:
		static SceneGraphManager* instance();
		void add(const std::string& name, SceneGraph* shader);
		SceneGraph* get(const std::string& name);

		void destroy();
	};

}
#endif