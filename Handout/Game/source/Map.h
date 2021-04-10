#ifndef __MAP_H__
#define __MAP_H__

#include "SString.h"
#include "List.h"
#include "Point.h"
#include"External/SDL_image/include/SDL_image.h"
#include "PugiXml\src\pugixml.hpp"

struct TileSet
{
	SString	name;
	int	firstgid;
	int margin;
	int	spacing;
	int tileWidth;
	int tileHeight;
	SDL_Texture* textureTile;
	int	texWidth;
	int	texHeight;
	int	numTilesWidth;
	int	numTilesHeight;
	int	offsetX;
	int	offsetY;
	SDL_Rect GetTileRect(int id) const;
};

// We create an enum for map type, just for convenience,
// NOTE: Platformer game will be of type ORTHOGONAL
enum MapTypes
{
	MAPTYPE_UNKNOWN = 0,
	MAPTYPE_ORTHOGONAL,
	MAPTYPE_ISOMETRIC,
	MAPTYPE_STAGGERED
};

// Create a generic structure to hold properties
struct Property
{
	SString propetyName;
	int propetyValue;
};

// Create a generic structure to hold properties
struct Properties
{

	Property propety;
	~Properties() {}

	// Method to ask for the value of a custom property
	int GetProperty(const char* name, int default_value = 0) const;

	List<Property*> list;
};

struct MapLayer
{
	SString	name;
	int width;
	int height;
	int* data;

	// Support custom properties
	Properties properties;

	MapLayer() : data(NULL) {}

	~MapLayer()
	{
		delete data;
	}

	// Short function to get the value of x,y
	inline int Get(int x, int y) const
	{
		return data[(y * width) + x];
	}
};

// Create a struct needed to hold the information to Map node
struct MapData
{
	int width;
	int	height;
	int	tileWidth;
	int	tileHeight;
	SDL_Color backgroundColor;
	MapTypes type;
	List<TileSet*> tilesets;
	List<MapLayer*> layers;
};

class Map : public Module
{
public:

	Map(aplication* APP);

	// Destructor
	virtual ~Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();
	States Postupdate()override;
	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);
	iPoint MapToWorld(int x, int y) const;
	iPoint WorldToMap(int x, int y) const;
	int numberToMap(int number);

private:

	// Methods to load all required map data
	bool LoadMap();
	bool LoadTilesetDetails(pugi::xml_node& tileset_node, TileSet* set);
	bool LoadTilesetImage(pugi::xml_node& tileset_node, TileSet* set);
	bool LoadLayer(pugi::xml_node& node, MapLayer* layer);

	// Load a group of properties 
	bool LoadProperties(pugi::xml_node& node, Properties& properties);

public:

	int GetTileIdFromPosition(int x, int y, const char* layername);
	TileSet* GetTilesetFromTileId(int id) const;
	void ChangeCollisionsDraw();

	// Add your struct for map info
	MapData data;

private:

	pugi::xml_document mapFile;
	SString folder;
	bool mapLoaded;
};
#endif // __MAP_H__