#pragma once

#ifndef _SCENE_GRAPH_
#define _SCENE_GRAPH_

namespace Engine2 {

	class SceneNode;
	class Camera;
	class DirectionalLight;

	class SceneGraph
	{
	public:
		SceneGraph();
		~SceneGraph();

		SceneNode * getRoot();
		SceneNode * createNode();
		Camera * getCamera();
		void setCamera(Camera* cam);
		void setLight(DirectionalLight * light);

		void draw();

		void destroy();

	private:
		SceneNode* root;
		Camera* camera;
		DirectionalLight * directionalLight;

	};
}


#endif