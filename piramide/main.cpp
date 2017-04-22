/*
	Diego Armando Herrera FLores
*/

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

//Definimos variables

 GLfloat mat_ambient[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };
 GLfloat mat_diffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
 GLfloat mat_specular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
 GLfloat shine[] = {27.8974f};
    
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;

void init(void)
{
// Ubicamos la fuente de luz en el punto
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat luz_ambiental[] = { 0.2, 0.2, 0.2, 1.0 };


// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glDisable(GL_COLOR_MATERIAL);

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
// Queremos que se dibujen las caras frontales
// y con un color solido de relleno.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void display()
{
    //  Borrar pantalla y Z-buffer
     // "Limpiamos" el frame buffer con el color de "Clear"
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );

    // Resetear transformaciones
    glLoadIdentity();
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    // Primera cara, se identica por multiples colores

     //-----base de la piramide--varios colores
	//se usa GL_QUADS para crear un cuadrilátero
	
	// Propiedades del material
    
    glPushMatrix();
    //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    
	//glColorMaterial(GL_FRONT, GL_SPECULAR);
    //glEnable(GL_COLOR_MATERIAL);
    //cambiarColor(0.393548, 0.271906, 0.166721);
    	
	glBegin(GL_QUADS);
	//vértices en 3d
	//glColor3f(1,1,1);//rojo
	glNormal3f(-0.5,0.0,-0.5);//4
	glVertex3f(-0.5,0.0,-0.5);
	//glColor3f(1,1,1);//amarillo
	glNormal3f(-0.5,0.0,0.5);
	glVertex3f(-0.5,0.0,0.5);//3
	//glColor3f(1,1,1);//azul
	glNormal3f(0.5,0.0,0.5);//2
	glVertex3f(0.5,0.0,0.5);
	//glColor3f(1,1,1);//verde
	glNormal3f(0.5,0.0,-0.5);//1
	glVertex3f(0.5,0.0,-0.5);//1
	glEnd();
	
	//------------------caras de la pirámide
	//para las caras triangulares
	//se usará GL_TRIANGLES
	//--------Cara 4  amarillo con blanco
	
	glBegin(GL_TRIANGLES);
	//vértices en 3d
	//glColor3f(1,1,1);//blanco
	glNormal3f(0,0.5,0);
	glVertex3f(0,0.5,0);
	//glColor3f(1,1,0);
	glNormal3f(-0.5,0,-0.5);
	glVertex3f(-0.5,0,-0.5);//1
	glNormal3f(0.5,0,-0.5);
	glVertex3f(0.5,0,-0.5);//4
	glEnd();

	//--------Cara 1 rojo con blanco
	
	glBegin(GL_TRIANGLES);
	//vértices en 3d
	//glColor3f(1,1,1);//blanco
	glNormal3f(0,0.5,0);
	glVertex3f(0,0.5,0);
	//glColor3f(1,0,0);//rojo
	glNormal3f(0.5,0,-0.5);
	glVertex3f(0.5,0,-0.5);
	glNormal3f(0.5,0,0.5);
	glVertex3f(0.5,0,0.5);
	glEnd();
	//--------Cara 3 verde con blanco
	glBegin(GL_TRIANGLES);
	//vértices en 3d
	//glColor3f(1,1,1);//blanco
	glNormal3f(0,0.5,0);
	glVertex3f(0,0.5,0);
	//glColor3f(0,1,0);//verde
	glNormal3f(-0.5,0,0.5);
	glVertex3f(-0.5,0,0.5);
	glNormal3f(-0.5,0,-0.5);
	glVertex3f(-0.5,0,-0.5);
	glEnd();
	//-------Cara 2 azul con blanco

	glBegin(GL_TRIANGLES);
	//vértices en 3d
	//glColor3f(1,1,1);//blanco
	glNormal3f(0,0.5,0);
	glVertex3f(0,0.5,0);
	//glColor3f(0,0,1);//azul
	glNormal3f(0.5,0,0.5);
	glVertex3f(0.5,0,0.5);
	glNormal3f(-0.5,0,0.5);
	glVertex3f(-0.5,0,0.5);
	glEnd();
	
    glFlush();
    glutSwapBuffers();

}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-1, 1, -1, 1, -1, 1);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;

    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;

    //  Solicitar actualización de visualización
    glutPostRedisplay();

}

// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
	case '1':
		mat_ambient[0] = 0.49412f;
		mat_ambient[1] = 2.123529f;
		mat_ambient[2] = 0.327451f;
		mat_ambient[3] = 1.0f;	
		
		mat_diffuse[0] = 2.78412f;
		mat_diffuse[1] = 0.343529f;
		mat_diffuse[2] = 0.997451f;
		mat_diffuse[3] = 1.0f;
		
		mat_specular[0] = 2.29412f;
		mat_specular[1] = 0.223529f;
		mat_specular[2] = 0.924451f;
		mat_specular[3] = 1.0f;
		
		shine[0] = 27.75;
				
		break;
	case '2':
		mat_ambient[0] = 0.47612f;
		mat_ambient[1] = 0.124129f;
		mat_ambient[2] = 0.476251f;
		mat_ambient[3] = 1.0f;	
		
		mat_diffuse[0] = 0.47812f;
		mat_diffuse[1] = 0.349529f;
		mat_diffuse[2] = 0.937451f;
		mat_diffuse[3] = 1.0f;
		
		mat_specular[0] = 0.78412f;
		mat_specular[1] = 0.247129f;
		mat_specular[2] = 0.124451f;
		mat_specular[3] = 1.0f;
		
		shine[0] = 28.75;
		break;
	case '3':
		mat_ambient[0] = 0.88612f;
		mat_ambient[1] = 1.664129f;
		mat_ambient[2] = 0.976751f;
		mat_ambient[3] = 1.0f;	
		
		mat_diffuse[0] = 5.11812f;
		mat_diffuse[1] = 0.8799529f;
		mat_diffuse[2] = 0.5227451f;
		mat_diffuse[3] = 1.0f;
		
		mat_specular[0] = 5.188412f;
		mat_specular[1] = 0.6647129f;
		mat_specular[2] = 0.424451f;
		mat_specular[3] = 1.0f;
		
		shine[0] = 25.75;
		break;
	case '4':
		mat_ambient[0] = 1.184722454f;
		mat_ambient[1] = 2.264129577f;
		mat_ambient[2] = 0.874635133f;
		mat_ambient[3] = 1.0f;	
		
		mat_diffuse[0] = 0.71812146f;
		mat_diffuse[1] = 3.34589529f;
		mat_diffuse[2] = 0.6444451f;
		mat_diffuse[3] = 1.0f;
		
		mat_specular[0] = 0.388412f;
		mat_specular[1] = 4.1647129f;
		mat_specular[2] = 0.424451f;
		mat_specular[3] = 1.0f;
		
		shine[0] = 27.75;
		break;
		
	case '5':
		mat_ambient[0] = 3.184722454f;
		mat_ambient[1] = 0.264129577f;
		mat_ambient[2] = 0.874635133f;
		mat_ambient[3] = 1.0f;	
		
		mat_diffuse[0] = 5.71812146f;
		mat_diffuse[1] = 0.34589529f;
		mat_diffuse[2] = 0.6444451f;
		mat_diffuse[3] = 1.0f;
		
		mat_specular[0] = 3.388412f;
		mat_specular[1] = 0.1647129f;
		mat_specular[2] = 1.424451f;
		mat_specular[3] = 1.0f;
		
		shine[0] = 27.75;
		break;
    case 's':
        scale=0.5;
        break;
    case 'd':
        scale=1.5;
        break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;
    case 'q':
        exit(0);			// exit
    }
    glutPostRedisplay();
}



int main(int argc, char* argv[])
{

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);

    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("Cubo controlado por teclas");
	
	init();
    // Habilitar la prueba de profundidad de Z-buffer
    //glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_NORMALIZE);
	glDisable(GL_COLOR_MATERIAL);
    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}
