#include "src/window/Window.h"

void draw(Canvas *canv){
    Context c = canv->getContext();
    //glClearColor(c.c.getRf(),c.c.getGf(),c.c.getBf(),c.c.getAf());
    float vertices[] = {
            -0.5f, -0.5f, 1.0f,0.0f,0.0f, 0.0f,0.0f,
             0.5f, -0.5f, 0.0f,1.0f,0.0f, 0.0f,0.0f,
             0.0f,  0.5f, 0.0f,0.0f,1.0f, 0.0f,0.0f,
           //   x,     y,    r,   g,   b,    s,   t,
    };

    glBindVertexArray(c.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, c.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    c.s.use();
    c.s.setBool("tex",false);
    c.s.setMat4("mat",c.proj);
    glBindVertexArray(c.VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

}

int main(){
    Window w(640,480,"App");
    w.setBG(new Color("#fff"));
    w.draw(draw);
    return 0;
}
