//
//  hitable_list.hpp
//  Raytracing in a weekend
//
//  Created by Dubito on 2019/11/17.
//  Copyright © 2019 Dubito. All rights reserved.
//

#ifndef hitable_list_hpp
#define hitable_list_hpp

#include "hitable.hpp"

class hitable_list: public hitable{
public:
    hitable_list() {}
    hitable_list(hitable **L, int n) {list = L; list_size = n;}
    virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
    hitable **list;
    int list_size;
};

bool hitable_list::hit(const ray& r, float t_min, float t_max, hit_record& rec) const{
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;
    for (int i = 0; i < list_size; i++) {
        if (list[i]->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

#endif /* hitable_list_hpp */
