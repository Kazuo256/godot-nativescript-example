
#include "generated_tilemap.hpp"

#include <chrono>
#include <random>
#include <vector>

namespace godot {

using std::vector;
using grid = vector<vector<bool>>;

void GeneratedTileMap::_register_methods() {
  register_method("generate", &GeneratedTileMap::generate);
  register_property<GeneratedTileMap, int64_t>("map_size",
                                               &GeneratedTileMap::_map_size, 100);
  register_property<GeneratedTileMap, int64_t>("min_room_size",
                                               &GeneratedTileMap::_min_room_size, 5);
  register_property<GeneratedTileMap, int64_t>("max_room_size",
                                               &GeneratedTileMap::_max_room_size, 20);
  register_property<GeneratedTileMap, int64_t>("room_amount",
                                               &GeneratedTileMap::_room_amount, 30);
}

bool fits(const grid& map, int64_t x, int64_t y, int64_t width, int64_t height);

void GeneratedTileMap::generate() {
  using uniform = std::uniform_int_distribution<int>;

  unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 rng (seed1);
  grid map(_map_size, vector<bool>(_map_size, false));
  uniform room_size(_min_room_size, _max_room_size);

	for (int64_t i = 0; i < _room_amount; i++) {
		int64_t width = room_size(rng);
		int64_t height = room_size(rng);
    uniform max_x(0, _map_size - width);
    uniform max_y(0, _map_size - height);
    int64_t x = max_x(rng);
    int64_t y = max_y(rng);
		if (fits(map, x, y, width, height))
			for (int64_t dy = 0; dy < height; dy++)
				for (int64_t dx = 0; dx < width; dx++)
					map[y+dy][x+dx] = true;
  }
  for (int64_t y = 0; y < _map_size; y++)
    for (int64_t x = 0; x < _map_size; x++)
      set_cell(x, y, map[y][x] ? 1 : 0);
}

bool fits(const grid& map, int64_t x, int64_t y, int64_t width, int64_t height) {
	for (int64_t dy = 0; dy < height; dy++)
		for (int64_t dx = 0; dx < width; dx++)
			if (map[y+dy][x+dx])
				return false;
	return true;
}

} // namespace godot

