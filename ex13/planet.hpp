#ifndef PLANET_HPP
#define PLANET_HPP

# include <cmath>

class Planet {
private:
    GLuint texture, ring_texture;
    float sph_radius, tr_radius, rt_speed, tr_speed, tr_angle, rt_angle;
    bool ring;

public:
    Planet (GLuint texture = 0, float sph_radius = 0, float tr_radius = 0,
        float rt_speed = 0, float tr_speed = 0, bool ring = false, GLuint ring_texture = 0):
        texture(texture), sph_radius(sph_radius), tr_radius(tr_radius),
        rt_speed(rt_speed), tr_speed(tr_speed), ring(ring), ring_texture(ring_texture) {
            tr_angle = rt_angle = 0;
        }

    void draw() {
        GLUquadricObj *sphere = gluNewQuadric();
        gluQuadricTexture(sphere, GL_TRUE);
        gluQuadricNormals(sphere, GLU_SMOOTH);

        glPushMatrix();
            glRotatef(tr_angle, 0, 0, 1); // Translation
            glTranslatef(tr_radius, 0, 1);

            if (ring) {
                GLUquadricObj *ring = gluNewQuadric();
                gluQuadricTexture(ring, GL_TRUE);
                gluQuadricNormals(ring, GLU_SMOOTH);
                glBindTexture(GL_TEXTURE_2D, ring_texture);
                gluDisk(ring, sph_radius + 0.2, sph_radius + 0.9, 20, 20);
                gluDeleteQuadric(ring);
            }

            glRotatef(rt_angle, 0, 0, 1); // Rotation
            glBindTexture(GL_TEXTURE_2D, texture);
            gluSphere(sphere, sph_radius, 20, 20);
        glPopMatrix();
        gluDeleteQuadric(sphere);
    }

    void move(float elapsed_time) {
        tr_angle = tr_speed * elapsed_time;
        rt_angle = rt_speed * elapsed_time;
    }
};

#endif /* end of include guard: PLANET_HPP */
