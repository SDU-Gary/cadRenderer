#pragma once

#include "CADMesh.h"
#include "MyMask.h"

class ModelInstance{
private:
    struct treeNodeV2
    {
        std::vector<uint32_t> children;
        vsg::mat4 originalMatrix;
        vsg::dbox bounds;
    };
    struct InstanceInfo
    {
        uint32_t fbIndex;
        uint32_t arrayIdx;
        uint32_t parentIdx;
        uint32_t protoIdx;
        std::string instanceId;
        std::string parentId;
        //treeNode nodePtr;
            treeNodeV2 node;
    };

public:
    std::vector<Line> lines;
    std::vector<vsg::vec3> positions;
    std::unordered_map<vsg::vec3, uint32_t> positionToIndex;
    std::vector<uint32_t> indices;
    std::vector<InstanceInfo> mInstances;
    std::unordered_map<std::string, treeNode> nodePtr;        //��¼ID��Ӧ�Ľڵ�
    std::unordered_map<std::string, int> instanceIndex;     

    void buildInstance(CADMesh* mesh, vsg::ref_ptr<vsg::Group> scene, vsg::ref_ptr<vsg::ShaderSet> shader, const vsg::dmat4& modelMatrix);
    void buildObjInstance(CADMesh* mesh, vsg::ref_ptr<vsg::Group> scene, vsg::ref_ptr<vsg::ShaderSet> shader, const vsg::dmat4& modelMatrix);
    void buildFbInstance(CADMesh* mesh, vsg::ref_ptr<vsg::Group> scene, vsg::ref_ptr<vsg::GraphicsPipelineConfigurator> gpc_ibl, vsg::ref_ptr<vsg::GraphicsPipelineConfigurator> gpc_shadow, const vsg::dmat4& modelMatrix, vsg::ref_ptr<vsg::Options> options);
    void buildObjInstanceIBL(CADMesh* mesh, vsg::ref_ptr<vsg::Group> scene, vsg::ref_ptr<vsg::GraphicsPipelineConfigurator> gpc_ibl, vsg::ref_ptr<vsg::GraphicsPipelineConfigurator> gpc_shadow, const vsg::dmat4& modelMatrix);
    void drawLine(vsg::vec3& begin, vsg::vec3& end, vsg::ref_ptr<vsg::Group> scene);
    void buildInstanceIBL(CADMesh* mesh, vsg::ref_ptr<vsg::Group> scene, vsg::ref_ptr<vsg::GraphicsPipelineConfigurator> gpc_ibl, vsg::ref_ptr<vsg::GraphicsPipelineConfigurator> gpc_shadow, const vsg::dmat4& modelMatrix);
};