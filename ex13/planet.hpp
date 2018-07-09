#ifndef PLANET_HPP
#define PLANET_HPP

# include <cmath>

class Planet {
private:
    GLuint texture;
    float sph_radius, tr_radius, rt_speed, tr_speed, tr_angle, rt_angle;
    bool ring;

public:
    Planet (GLuint texture = 0, float sph_radius = 0, float tr_radius = 0,
        float rt_speed = 0, float tr_speed = 0, bool ring = false):
        texture(texture), sph_radius(sph_radius), tr_radius(tr_radius),
        rt_speed(rt_speed), tr_speed(tr_speed), ring(ring) {
            tr_angle = rt_angle = 0;
        }

    void draw() {
        glBindTexture(GL_TEXTURE_2D, texture);

        GLUquadricObj *quadratic = gluNewQuadric();
        gluQuadricTexture(quadratic, GL_TRUE);
        gluQuadricNormals(quadratic, GLU_SMOOTH);

        glPushMatrix();
            glRotatef(tr_angle, 0, 0, 1); // Translation
            glTranslatef(tr_radius, 0, 1);

            if (ring) {
                glPushMatrix();
                    glScalef(1, 1, 0.05);
                    glutWireTorus(sph_radius + 0.2, sph_radius + 0.4, 10, 20);
                glPopMatrix();
            }

            glRotatef(rt_angle, 0, 0, 1); // Rotation
            gluSphere(quadratic, sph_radius, 20, 20);
        glPopMatrix();
    }

    void move(float elapsed_time) {
        tr_angle = tr_speed * elapsed_time;
        rt_angle = rt_speed * elapsed_time;
    }
};

#endif /* end of include guard: PLANET_HPP */
