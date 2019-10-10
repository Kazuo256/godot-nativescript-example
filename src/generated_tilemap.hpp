
#include <Godot.hpp>
#include <TileMap.hpp>

namespace godot {

class GeneratedTileMap : public TileMap {
    GODOT_CLASS(GeneratedTileMap, TileMap);
  public:
    GeneratedTileMap() { }

    /* _init must exist as it is called by Godot */
    void _init() { }

    void generate();

    static void _register_methods();
    
    int64_t _map_size{100};
    int64_t _min_room_size{5};
    int64_t _max_room_size{20};
    int64_t _room_amount{30};
};

} // namespace godot


