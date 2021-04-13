#include"Aplication.h"
#include "ModuloRender.h"
#include "ModuleTextures.h"

#include "Map.h"

#include <math.h>

Map::Map(aplication* APP) : Module(APP)
{
	folder.Create("XML/");
}

// Destructor
Map::~Map() {}

// Ask for the value of a custom property
int Properties::GetProperty(const char* value, int defaultValue) const
{
	return defaultValue;
}

// Called before render is available
bool Map::Awake(pugi::xml_node& config)
{
	bool ret = true;


	return ret;
}

// Draw the map (all requried layers)
void Map::Draw()
{
	if (mapLoaded == false) return;
	bool exit = false;

	// Prepare the loop to draw all tilesets + DrawTexture()
	TileSet* tileset;
	ListItem<MapLayer*>* layer = data.layers.start;

	// Make sure we draw all the layers and not just the first one
	while (layer != NULL)
	{
		for (int y = 0; y < data.height; ++y)
		{
			for (int x = 0; x < data.width; ++x)
			{
				int tileId = layer->data->Get(x, y);

				tileset = GetTilesetFromTileId(tileId);

				SDL_Rect rect = tileset->GetTileRect(tileId);
				iPoint point = MapToWorld(x, y);
						
				app->render->Blit(tileset->textureTile, point.x, point.y, &rect);
	
			}
		
		}
		layer = layer->next;
	}
	/*SDL_RWops* io;
	io->read()*/
	
}

void Map::ChangeCollisionsDraw()
{
	ListItem<MapLayer*>* list1;
	list1 = data.layers.start;

	if (list1->data->properties.propety.propetyValue == 1)
	{
		list1->data->properties.propety.propetyValue = 0;
	}
	else
	{
		list1->data->properties.propety.propetyValue = 1;
	}
}

iPoint Map::MapToWorld(int x, int y) const
{
	iPoint ret(0, 0);

	// Add isometric map to world coordinates
	if (data.type == MAPTYPE_ORTHOGONAL)
	{
		ret.x = x * data.tileWidth;
		ret.y = y * data.tileHeight;
	}

	else if (data.type == MAPTYPE_ISOMETRIC)
	{
		ret.x = (x - y) * (data.tileWidth / 2);
		ret.y = (x + y) * (data.tileHeight / 2);
	}

	else
	{

		ret.x = x; ret.y = y;
	}

	return ret;
}

int Map::numberToMap(int number)
{
	return number / data.tileWidth;
}

// Add orthographic world to map coordinates
iPoint Map::WorldToMap(int x, int y) const
{
	iPoint ret(0, 0);

	// Add the case for isometric maps to WorldToMap
	if (data.type == MAPTYPE_ORTHOGONAL)
	{
		ret.x = x / data.tileWidth;
		ret.y = y / data.tileHeight;
	}

	else if (data.type == MAPTYPE_ISOMETRIC)
	{

		float halfWidth = data.tileWidth * 0.5f;
		float halfHeight = data.tileHeight * 0.5f;
		ret.x = int((x / halfWidth + y / halfHeight) / 2);
		ret.y = int((y / halfHeight - (x / halfWidth)) / 2);
	}

	else
	{
		
		ret.x = x; ret.y = y;
	}

	return ret;
}

int Map::GetTileIdFromPosition(int x, int y, const char* layername)
{
	ListItem<MapLayer*>* layer = data.layers.start;

	while (layer != nullptr)
	{
		if (layer->data->name == layername)
		{
			break;
		}
		layer = layer->next;
	}

	return layer->data->Get(x, y);
}

// Pick the right Tileset based on a tile id
TileSet* Map::GetTilesetFromTileId(int id) const
{
	ListItem<TileSet*>* lista = data.tilesets.start;
	TileSet* set = lista->data;
	while (lista->data != nullptr)
	{
		if (lista->next == nullptr)
		{
			set = lista->data;
			break;
		}
		if ((lista->data->firstgid <= id) && (lista->next->data->firstgid > id))
		{
			set = lista->data;
			break;
		}
		lista = lista->next;
	}

	return set;
}

// Called before quitting
bool Map::CleanUp()
{
	ListItem<TileSet*>* item;
	item = data.tilesets.start;
	app->Texture->Unload(item->data->textureTile);


	while (item != NULL)
	{
		delete item->data;
		item = item->next;
	}
	data.tilesets.Clear();

	ListItem<Property*>* lisItem;
	lisItem = data.layers.start->data->properties.list.start;
	while (lisItem != NULL)
	{
		lisItem->data->propetyName.Clear();
		delete lisItem->data;
		lisItem = lisItem->next;
	}


	// Clean up the pugui tree
	ListItem<MapLayer*>* ite;
	ite = data.layers.start;
	while (ite != NULL)
	{
		delete ite->data;
		ite = ite->next;
	}
	data.layers.Clear();
	mapFile.reset();


	return true;
}
States Map::Postupdate() 
{
	Draw();
	return States::Continue;
}
SDL_Rect TileSet::GetTileRect(int id) const
{
	SDL_Rect rect = { 0 };

	// Get relative Tile rectangle
	// ORTHOGONAL
	rect.w = tileWidth;
	rect.h = tileHeight;
	int num = texWidth / tileWidth;
	int usa = id - firstgid + 1;
	int res = usa / num;
	int hond = usa % num;
	if (hond == 0)
	{
		hond = num;
		res = res - 1;
	}
	hond = hond - 1;
	rect.x = hond * rect.w;
	rect.y = res * rect.h;

	

	return rect;
}

// Load new map
bool Map::Load(const char* filename)
{
	bool ret = true;
	SString tmp("%s%s", folder.GetString(), filename);

	char* buffer = nullptr;
	int size=app->Assets->MakeLoad(&buffer, tmp.GetString());

	//TODO 6:load xml file through buffer (1 line)
	pugi::xml_parse_result result = mapFile.load_buffer(buffer, size);
	delete[] buffer;

	if (result == NULL)ret = false;

	// Load general info
	// Create and call a private function to load a tileset remember to support more any number of tilesets!
	pugi::xml_node tileset;
	for (tileset = mapFile.child("map").child("tileset"); tileset && ret; tileset = tileset.next_sibling("tileset"))
	{
		TileSet* set = new TileSet();

		if (ret == true) ret = LoadTilesetDetails(tileset, set);

		if (ret == true) ret = LoadTilesetImage(tileset, set);

		data.tilesets.Add(set);
	}

	if (ret == true)
	{
		// Create and call a private function to load and fill all your map data
		ret = LoadMap();
	}

	if (ret == true)
	{
		// LOG all the data loaded iterate all tilesets and LOG everything
		ListItem<TileSet*>* list1;
		list1 = data.tilesets.start;

		
	}

	pugi::xml_node layer;
	pugi::xml_node node2;
	ListItem<MapLayer*>* list2;

	for (layer = mapFile.child("map").child("layer"); layer && ret; layer = layer.next_sibling("layer"))
	{
		MapLayer* lay = new MapLayer();

		ret = LoadLayer(layer, lay);

		if (ret == true)
			data.layers.Add(lay);

		node2 = layer.child("properties");
		list2 = data.layers.start;
		for (node2 = node2.child("property"); node2; node2 = node2.next_sibling("property"))
		{
			LoadProperties(node2, list2->data->properties);
		}
	}
	mapLoaded = ret;

	return ret;
}

bool Map::LoadLayer(pugi::xml_node& node, MapLayer* layer)
{
	bool ret = true;

	layer->height = node.attribute("height").as_int();
	layer->name = node.attribute("name").as_string();
	layer->width = node.attribute("width").as_int();
	int cant = layer->height * layer->width;
	layer->data = new int[cant];
	memset(layer->data, 0, cant);
	pugi::xml_node node1 = node.child("data").child("tile");
	for (int i = 0; i < cant; i++)
	{
		int num=node1.attribute("gid").as_int();
		layer->data[i] = num;
		node1 = node1.next_sibling("tile");
	}

	return ret;
}

// Load map general properties
bool Map::LoadMap()
{
	bool ret = true;
	pugi::xml_node map = mapFile.child("map");

	if (map == NULL)
	{
		
		ret = false;
	}
	else
	{
		ListItem<TileSet*>* node;
		node = data.tilesets.start;
		// Load map general properties
		data.tileHeight = map.attribute("tileheight").as_int(32);
		data.tileWidth = map.attribute("tilewidth").as_int(32);
		node->data->numTilesHeight = map.attribute("height").as_int();
		node->data->numTilesWidth = map.attribute("width").as_int();
		data.height = map.attribute("height").as_int();
		data.width = map.attribute("width").as_int();
		SString tmp("%s", map.attribute("orientation").value());
		if (tmp == "orthogonal")
		{
			data.type = MapTypes::MAPTYPE_ORTHOGONAL;
		}
		else if (tmp == "isometric")
		{
			data.type = MapTypes::MAPTYPE_ISOMETRIC;
		}
		else if (tmp == "staggered")
		{
			data.type = MapTypes::MAPTYPE_STAGGERED;
		}
		else
		{
			data.type = MapTypes::MAPTYPE_UNKNOWN;
		}
	}

	return ret;
}

// Load Tileset attributes
bool Map::LoadTilesetDetails(pugi::xml_node& tilesetNode, TileSet* set)
{
	bool ret = true;

	if (tilesetNode == NULL)
	{
		
		ret = false;
	}
	else
	{
		set->firstgid = tilesetNode.attribute("firstgid").as_int();
		set->margin = tilesetNode.attribute("margin").as_int();
		set->name = tilesetNode.attribute("name").as_string();
		set->tileWidth = tilesetNode.attribute("tilewidth").as_int();
		set->tileHeight = tilesetNode.attribute("tileheight").as_int();
		set->tileHeight = tilesetNode.attribute("tileheight").as_int();
		set->tileWidth = tilesetNode.attribute("tilewidth").as_int();
		set->spacing = tilesetNode.attribute("spacing").as_int();
	}

	return ret;
}

// Load Tileset image
bool Map::LoadTilesetImage(pugi::xml_node& tileset_node, TileSet* set)
{
	bool ret = true;
	pugi::xml_node image = tileset_node.child("image");

	if (image == NULL)
	{
		
	}
	else
	{
		
		SString tmp("%s%s", folder.GetString(), image.attribute("source").as_string());
		set->textureTile = app->Texture->Load(tmp.GetString());
		set->texHeight = image.attribute("height").as_int();
		set->texWidth = image.attribute("width").as_int();
		set->numTilesWidth = tileset_node.attribute("tilewidth").as_int();
		set->numTilesHeight = tileset_node.attribute("tileheight").as_int();
	}

	return ret;
}

// Load a group of properties from a node and fill a list with it
bool Map::LoadProperties(pugi::xml_node& node, Properties& properties)
{
	bool ret = true;

	properties.propety.propetyName = node.attribute("name").as_string();
	properties.propety.propetyValue = node.attribute("value").as_int();

	return ret;

}

