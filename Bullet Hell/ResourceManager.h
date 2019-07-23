#pragma once
#include <vector>
#include "Resource.h"

class ResourceManager
{
private:
	ResourceManager() {}
	ResourceManager(const ResourceManager&) {}
	ResourceManager& operator=(const ResourceManager&) {}

public:
	enum ResourceType
	{
		FONT,
		TEXTURE,
	};

	static ResourceManager& getInstance()
	{
		static ResourceManager instance;
		return instance;
	}

	~ResourceManager() {}

	template<typename... Args>
	std::shared_ptr<ResourceBase> get(ResourceType type, const std::string filename, Args... args)
	{
		std::vector<std::shared_ptr<ResourceBase>>::iterator it;

		//check if resource is already loaded
		for (it = m_resources.begin(); it != m_resources.end(); ++it)
		{
			if (filename.compare((*it)->getFilename()) == 0)
				return *it;
		}

		//if not, load it as the correct type
		switch (type)
		{
		case ResourceType::FONT:
		{
			std::shared_ptr<ResourceBase> resource(new Resource<aie::Font>(filename, 32)); //to do: fix
			m_resources.push_back(resource);
			return resource;
		}
		case ResourceType::TEXTURE:
		{
			std::shared_ptr<ResourceBase> resource(new Resource<aie::Texture>(filename));
			m_resources.push_back(resource);
			return resource;
		}
		default:
			return nullptr;
		}
	}

	int getCount() const { return m_resources.size(); }

	/*Iterates through resource vector and erases any resources
	that are currently only being referenced by the manager.*/
	void collectGarbage()
	{
		for (std::vector<std::shared_ptr<ResourceBase>>::iterator it =
			m_resources.begin(); it != m_resources.end();)
		{
			if ((*it).use_count() == 1)
				it = m_resources.erase(it);
			else
				++it;
		}
	}

private:
	std::vector<std::shared_ptr<ResourceBase>> m_resources;
};