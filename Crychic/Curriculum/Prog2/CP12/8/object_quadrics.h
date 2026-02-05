#ifndef OBJECT_QUADRICS_H
#define OBJECT_QUADRICS_H

#include "object_plane.h"
#include <vector>

class CObjectQuadrics : public CObjectBase
{
public:
    CObjectQuadrics(vec3d pos,
        double ppa,       // X coefficient denominator
        double ppb,       // Y coefficient denominator
        double ppc,       // Z coefficient denominator
        int pinoutflag,   // inside/outside flag (1 or -1)
        COLORREF color, double transparency, double reflection,
        double refraction, int highlightdiaphragm, double highlight
    );
    ~CObjectQuadrics();

    vec3d GetVecNormal(vec3d pos);
    bool CheckInside(vec3d pos);
    double RayCast(vec3d viewpoint, vec3d ray, int inout, double lt);

private:
    double pa;
    double pb;
    double pc;
    int inoutflag;
    std::vector<CObjectPlane> block_plane_list;

    bool BlockPlane_CheckInside(vec3d pos)
    {
        for (int i = 0; i < block_plane_list.size(); i++)
        {
            if (block_plane_list[i].CheckInside(pos) == false)
            {
                return false;
            }
        }
        return true;
    }

public:
    void BlockPlaneList_Ins(vec3d pos, vec3d n)
    {
        block_plane_list.push_back(CObjectPlane(pos, n));
    }

    void BlockPlaneList_Release()
    {
        block_plane_list.clear();
    }
};

#endif
