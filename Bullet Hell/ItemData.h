#pragma once

struct ItemType
{
	ItemType& operator=(const ItemType& other)
	{
		name = other.name;
		description = other.description;
		return *this;
	}

	bool operator==(const ItemType other)
	{
		if (name != other.name)
			return false;
		if (description != other.description)
			return false;
		return true;
	}

	char* name;
	char* description;
};

const ItemType ITEM_NOTHING = { "", "" };
const ItemType ITEM_TEST = { "name", "testing description" };