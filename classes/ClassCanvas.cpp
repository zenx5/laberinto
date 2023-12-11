class Canvas {
    public:
        void drawRect(int x, int y, int width, int height, int color[]) {
            glColor3ub(color[0], color[1], color[2]);
            glBegin(GL_QUADS);
                glVertex2f(x, y + height);
                glVertex2f(x, y);
                glVertex2f(x + width, y);
                glVertex2f(x + width, y + height);
            glEnd();

        }

        void drawCircle(int cx, int cy, float radius, int color[], bool fill) {
            glColor3ub(color[0], color[1], color[2]);
            int num_segments = 100;
            float k = radius;
            while(k>0){
                glBegin(GL_LINE_LOOP);
                for(int ii = 0; ii < num_segments; ii++) {
                    float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

                    float x = k * cosf(theta);
                    float y = k * sinf(theta);
                    glVertex2f(x + cx, y + cy);
                }
                glEnd();
                k = k - 0.5;
                if( !fill ){
                    k=0;
                }
            }
        }

        void clear() {
            glClearColor(BGRED, BGGREEN, BGBLUE, 1);
            glClear(GL_COLOR_BUFFER_BIT);
        }
};