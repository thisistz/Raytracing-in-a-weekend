//
//  camera.hpp
//  Raytracing in a weekend
//
//  Created by Dubito on 2019/11/23.
//  Copyright © 2019 Dubito. All rights reserved.
//

#ifndef camera_hpp
#define camera_hpp

#include "ray.hpp"

class camera{
public:
    vec3 origin;
    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
    
    camera(){
        lower_left_corner = vec3(-2.0, -1.0,  -1.0);
        horizontal = vec3(4.0, 0.0, 0.0);
        vertical = vec3(0.0, 2.0, 0.0);
        origin = vec3(0.0, 0.0, 0.0);
    }
    
    ray get_ray(float u, float v){
        return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
    }
};

#endif /* camera_hpp */
