#ifndef PLANET_HPP
#define PLANET_HPP

# include <cmath>

class Planet {
private:
    float *color, sph_radius, tr_radius, rt_speed, tr_speed, tr_angle, rt_angle;
    bool ring;

public:
    Planet (float *color, float sph_radius = 0, float tr_radius = 0, float rt_speed = 0, float tr_speed = 0, bool ring = false):
        color(color), sph_radius(sph_radius), tr_radius(tr_radius), rt_speed(rt_speed), tr_speed(tr_speed) {
            tr_angle = rt_angle = 0;
        }

    void draw() {
        glColor3f(color[0], color[1], color[2]);

        glPushMatrix();
            glRotatef(tr_angle, 0, 0, 1); // Translation
            glTranslatef(tr_radius, 0, 1);
            glRotatef(rt_angle, 0, 0, 1); // Rotation

            if (ring) {
                auto startList = glGenLists( 4 );
                auto qobj = gluNewQuadric();

                gluQuadricDrawStyle(qobj, GLU_LINE); /* all polygons wireframe */
                gluQuadricNormals(qobj, GLU_NONE);
                glNewList(startList+2, GL_COMPILE);
                    gluDisk(qobj, sph_radius + 0.2, sph_radius + 0.6, 20, 4);
                glEndList();
            }

            glutWireSphere(sph_radius, 20, 20);
        glPopMatrix();
    }

    void move(float elapsed_time) {
        tr_angle = tr_speed * elapsed_time;
        rt_angle = rt_speed * elapsed_time;
    }
};

#endif /* end of include guard: PLANET_HPP */
