#pragma once

#include <cstdint>

enum class ChunkType : int32_t {
	GLProject = 1,
    MaterialObj = 5,
    ModelGroup = 1000,
    BoneObj = 1001,
    SPMesh = 1002,
    Collision = 1003,
    AtomicMesh = 1004,
    SkinObj = 1005,
    GLCamera = 1006,
    LightObj = 1007,
    LevelObj = 1009,
    Materials = 1010,
    SectorOctree = 1011,
    World = 1012,
    AnimationKey = 1015,
    AnimLib = 1017,
    OcclusionMesh = 1018,
    Occlusion = 1019,
    WpPoints = 1020,
    NavigationMesh = 1021,
    Zones = 1023,
    Area = 1024,
    LinkEmm = 1026,
    Animation = 1027,
    SpLights = 1029,
    Entities = 20000,
    Entity = 20001,
    Textures = 20002
};
