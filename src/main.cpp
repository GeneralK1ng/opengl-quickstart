#include <GL/freeglut.h>  // FreeGLUT头文件

// 初始化OpenGL状态
void init() {
    glEnable(GL_DEPTH_TEST);  // 启用深度测试
}

// 绘制一个旋转的立方体
void display() {
    static float angle = 0.0f;  // 旋转角度

    // 清空颜色和深度缓存
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 重置模型视图矩阵
    glLoadIdentity();

    // 设置相机位置
    gluLookAt(0.0, 0.0, 5.0,  // 摄像机位置
              0.0, 0.0, 0.0,  // 观察目标
              0.0, 1.0, 0.0); // 头顶向上方向

    // 旋转立方体
    glRotatef(angle, 1.0, 1.0, 0.0);  // 根据x和y轴旋转

    // 绘制彩色立方体
    glBegin(GL_QUADS);

    // 前面
    glColor3f(1.0f, 0.0f, 0.0f); // 红色
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    // 后面
    glColor3f(0.0f, 1.0f, 0.0f); // 绿色
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    // 上面
    glColor3f(0.0f, 0.0f, 1.0f); // 蓝色
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    // 下面
    glColor3f(1.0f, 1.0f, 0.0f); // 黄色
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    // 左面
    glColor3f(1.0f, 0.0f, 1.0f); // 紫色
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    // 右面
    glColor3f(0.0f, 1.0f, 1.0f); // 青色
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    glEnd();

    // 刷新缓冲区
    glutSwapBuffers();

    // 增加旋转角度
    angle += 0.1f;
}

// 调整窗口大小时调用
void reshape(int width, int height) {
    glViewport(0, 0, width, height);  // 设置视口

    // 设置投影矩阵
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / height, 1.0, 100.0);

    // 回到模型视图矩阵
    glMatrixMode(GL_MODELVIEW);
}

// 主函数，设置窗口和循环
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // 双缓冲和深度测试
    glutInitWindowSize(800, 600);  // 窗口大小
    glutCreateWindow("Rotating Cube");  // 窗口标题

    init();  // 初始化OpenGL设置

    glutDisplayFunc(display);  // 注册显示回调函数
    glutIdleFunc(display);     // 空闲时更新
    glutReshapeFunc(reshape);  // 注册窗口大小改变回调函数

    glutMainLoop();  // 进入GLUT主循环
    return 0;
}
