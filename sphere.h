#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class sphere : public hittable {
    private:
        point3 center;
        double radius;

    public:
        sphere(const point3& center, double radius) : center(center), radius(fmax(0, radius)) {}

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            vec3 displacement = center - r.origin();

            double a = r.direction().length_squared();
            double h = dot(r.direction(), displacement);
            double c = displacement.length_squared() - radius*radius;
            double discriminant = (h*h - a*c);

            if (discriminant < 0) return false;

            auto sqrtd = sqrt(discriminant);

            // First root we check
            auto root = (h - sqrtd) / a;
            if (!ray_t.surrounds(root)) {
                // Second root we check (remember, +/- !)
                root = (h + sqrtd) / a;
                if (!ray_t.surrounds(root)) {
                    return false;  // can't say we didn't try
                }
            }

            // Update the record -- we passed it by reference
            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);

            return true;
        }
};

#endif 
