#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define COR_DO_PLANO 0.52,0.52,0.78,1.0

float angle=0.0;

// direcao da camera
float lx=0.0f,lz=-1.0f;

// posicao da camera
float x=0.0f,z=5.0f;

// medidas 
float paredeX = 17.0, paredeZ = 7.0, paredeY = 0.2,
	medidaMesaX = 3.5, medidaMesaZ = 0.1, medidaMesaY = 2.0,
	escaninhoX = paredeX - paredeX/3, escaninhoZ = paredeZ/5, escaninhoY = escaninhoZ;

// angulo da abertura da porta
GLfloat anguloPorta = 0.0, 
	posicaoPortaX = 6.0, posicaoPortaZ = 1.0, posicaoPortaY = 9.0,
	posicaoPortaXOriginal = 6.0, posicaoPortaZOriginal = 1.0, posicaoPortaYOriginal = 9.0,
	medidaPortaX = paredeX/7, medidaPortaZ = paredeZ - 1.0, medidaPortaY = 0.1;
bool portaAberta = false;

// iluminao de cada objeto
// Plano
GLfloat plano_difusa[]    = { 1.5, 1.5, 1.0, 1.0 };
GLfloat plano_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat plano_brilho[]    = { 50.0 };

//Posicao da luz0 (ambiente)
GLfloat luz0_posicao[] = { 0.0, 5.0, 1.0, 1.0};
GLfloat luz0_cor[] = {1.0,1.0,1.0, 1.0 };
GLfloat luz0_cor_ambiente[] = {0.3, 0.3, 0.3, 1.0};

void init(void){

 	glClearColor (0.0, 0.0, 0.0, 0.0);

	glShadeModel (GL_SMOOTH);
	
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luz0_cor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luz0_cor);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luz0_cor_ambiente);
	glLightfv(GL_LIGHT0, GL_POSITION, luz0_posicao);	

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	
	//Iluminacao padrao dos objetos
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, plano_difusa);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, plano_especular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, plano_brilho);
	
	//Habilitacao de iluminacao
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
}

void laboratorio(){	
	gluLookAt (0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);

	//glDepthMask(GL_TRUE);
	//glClearColor(1.0,1.0,1.0,1.0);
	//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


	//plano - propriedades do material

	glColor3ub(200,202,190);
	glNormal3f(0,1,0); 
	glBegin(GL_QUADS);
	glVertex3f(-50,-2.0,50);
	glVertex3f(50,-2.0,50);
	glVertex3f(50,-2.0,-50);
	glVertex3f(-50,-2.0,-50);
	glEnd();  
    
	//chao		
	/*glPushMatrix();
	glColor3f(178.0,168.0,108.0);
    glTranslatef (0.0, -2.0, 0.0);  
    glRotatef (90, 1.0, 0.0, 0.0);
    glTranslatef (0.0, 0.0, 0.0);       
    glPushMatrix();  
    glScalef (paredeX,paredeX+1.1,paredeY);
    glutSolidCube (1.0);
    glPopMatrix();
    glPopMatrix();*/

    //topo
	glColor3ub(232.0,232.0,232.0);  
	glPushMatrix();
    glTranslatef (0.0, 6, 0.0);  
    glRotatef (90, 1.0, 0.0, 0.0);    
    glTranslatef (0.0, 0.0, 0.0);       
    glPushMatrix();  
    glScalef (paredeX,paredeX+1.1,paredeY);
    glutSolidCube (1.0);
    glPopMatrix();
    glPopMatrix();
	

	//parede do fundo  
	glColor3ub(220.0,220.0,220.0); 
	glPushMatrix();
    glTranslatef (0.0, 2.0, -9.0);      
    glPushMatrix();  
    glScalef (paredeX,paredeZ+1.0,paredeY);
    glutSolidCube (1.0);
    glPopMatrix();
	glPopMatrix();

	//janela1 do fundo  
	glColor3ub(220.0,250.0,250.0); 
	glPushMatrix();
    glTranslatef (4.0, 2.0, -9.0);      
    glPushMatrix();  
    glScalef (paredeX/2 - 2,paredeZ/2,paredeY);
    glutSolidCube (1.0);
    glPopMatrix();
	glPopMatrix();

	//janela2 do fundo  
	glColor3ub(220.0,250.0,250.0); 
	glPushMatrix();
    glTranslatef (-4.0, 2.0, -9.0);      
    glPushMatrix();  
    glScalef (paredeX/2 - 2,paredeZ/2,paredeY);
    glutSolidCube (1.0);
    glPopMatrix();
	glPopMatrix();

	//mesa1 fundo  
  	glColor3ub(150.0,150.0,150.0); 
  	glPushMatrix();
    glTranslatef (0.0, -0.3, -8.5);
    glPushMatrix();  
    glScalef (medidaMesaX,medidaMesaZ,medidaMesaY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix();

	//parede lateral esquerda  
 	//glColor3ub(232.0,232.0,232.0);     	
 	glColor3ub(200.0,200.0,200.0); 
  	glPushMatrix();
    glTranslatef (-8.5, 2.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (0.0, 0.0, 0.0);
    glPushMatrix();  
    glScalef (paredeX+1.1,paredeZ+1.1,paredeY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix();

  	//Ar condicionado  
	glColor3ub(240.0,245.0,210.0); 
	glPushMatrix();
	    glTranslatef (-3.0, 5.0, -8.5);      
	    glPushMatrix();  
	    glScalef (paredeX/4,paredeZ/7,medidaMesaY-1.);
	    glutSolidCube (1.0);
	    glPopMatrix();
	glPopMatrix();	

  	//Escaninho esqueda
	glColor3ub(236.0,232.0,232.0);
  	glPushMatrix();
    glTranslatef (-8.5, 3.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (2.0, 0.0, 1.5);
    glPushMatrix();  
    glScalef (escaninhoX,escaninhoZ,escaninhoY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix(); 

	//Servidor
	glColor3ub(178.0,168.0,108.0);
  	glPushMatrix();
	    glTranslatef (-8.5, 3.0, 0.0);  
	    glRotatef (90, 0.0, 1.0, 0.0);    
	    glTranslatef (-7.0, 0.0, 1.5);
	    glPushMatrix();  
	    glScalef (paredeX/10,escaninhoZ-0.2,escaninhoY);
	    glutSolidCube (1.0);
	    glPopMatrix();
  	glPopMatrix();
  	
	//torre do computador1
	glColor3ub(30.0,30.0,120.0); 
	glPushMatrix();
	    glTranslatef (-8.5, 0.0, 0.0);  
	    glRotatef (90, 0.0, 1.0, 0.0);    
	    glTranslatef (7.0, -2.0, -0.0);
	    glPushMatrix();  
	    glScalef ((medidaMesaX/4)-0.3,2.0,medidaMesaY-0.3);
	    glutSolidCube (1.0);
	    glPopMatrix();
  	glPopMatrix();

  	//mesa1 esquerda  
  	glColor3ub(150.0,150.0,150.0); 
  	glPushMatrix();
	    glTranslatef (-8.5, 0.0, 0.0);  
	    glRotatef (90, 0.0, 1.0, 0.0);    
	    glTranslatef (5.0, -0.3, 1.5);
	    glPushMatrix();  
	    glScalef (medidaMesaX,medidaMesaZ,medidaMesaY);
	    glutSolidCube (1.0);
	    glPopMatrix();
  	glPopMatrix();

  	//monitor do computador1 esquerda
  	glColor3ub(30.0,30.0,120.0); 
  	glPushMatrix();
	    glTranslatef (-8.5, 0.0, 0.0);  
	    glRotatef (60, 0.0, 1.0, 0.0);    
	    glTranslatef (6.0, 0.5, -2.5);
	    glPushMatrix();  
	    glScalef ((medidaMesaX/2)-0.3,1.0,0.2);
	    glutSolidCube (1.0);
	    glPopMatrix();
  	glPopMatrix();
  	glPushMatrix();
	    glTranslatef (-8.5, 0.0, 0.0);  
	    glRotatef (60, 0.0, 1.0, 0.0);    
	    glTranslatef (6.0, -0.2, -2.5);
	    glPushMatrix();  
	    glScalef ((medidaMesaX/10)-0.3,0.5,0.2);
	    glutSolidCube (1.0);
	    glPopMatrix();
  	glPopMatrix();

  	//base
  	glPushMatrix();
	    glTranslatef (-8.5, 0.0, 0.0);  
	    glRotatef (60, 0.0, 1.0, 0.0);    
	    glTranslatef (6.0, -0.5, -2.5);
	    glPushMatrix();  
	    glScalef ((medidaMesaX/4),0.1,1.2);
	    glutSolidCube (1.0);
	    glPopMatrix();
  	glPopMatrix();
  	glPushMatrix();
	    glTranslatef (-8.5, 0.0, 0.0);  
	    glRotatef (90, 0.0, 1.0, 0.0);    
	    glTranslatef (5.0, -0.5, 1.0);
	    glPushMatrix();  
	    glScalef ((medidaMesaX/2)-0.3,0.1,0.5);
	    glutSolidCube (1.0);
	    glPopMatrix();
  	glPopMatrix();


  	//mesa2 esquerda
  	glColor3ub(150.0,150.0,150.0); 
  	glPushMatrix();
    glTranslatef (-8.5, 0.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (1.0, -0.3, 1.5);
    glPushMatrix();  
    glScalef (medidaMesaX,medidaMesaZ,medidaMesaY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix();

  	//Mesa3 esquerda
  	glPushMatrix();
    glTranslatef (-8.5, 0.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (-2.7, -0.3, 1.5);
    glPushMatrix();  
    glScalef (medidaMesaX,medidaMesaZ,medidaMesaY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix();

  	//Mesa4 esquerda   
  	glPushMatrix();
    glTranslatef (-8.5, 0.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (-6.5, -0.3, 1.5);
    glPushMatrix();  
    glScalef (medidaMesaX,medidaMesaZ,medidaMesaY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix();

  	//parede lateral direta     	
 	glColor3ub(200.0,200.0,200.0); 
  	glPushMatrix();
    glTranslatef (8.5, 2.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (0.0, 0.0, 0.0);
    glPushMatrix();  
    glScalef (paredeX+1.1,paredeZ+1.1,paredeY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix();

  	//Escaninho direita
	glColor3ub(236.0,232.0,232.0);
  	glPushMatrix();
    glTranslatef (8.5, 3.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (0.0, 0.0, -1.5);
    glPushMatrix();  
    glScalef (escaninhoX,escaninhoZ,escaninhoY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix(); 

  	//mesa1 direita  
  	glColor3ub(150.0,150.0,150.0); 
  	glPushMatrix();
    glTranslatef (8.5, 0.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (6.5, -0.3, -1.5);
    glPushMatrix();  
    glScalef (medidaMesaX,medidaMesaZ,medidaMesaY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix();

  	//mesa2 direita
  	glPushMatrix();
    glTranslatef (8.5, 0.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (2.7, -0.3, -1.5);
    glPushMatrix();  
    glScalef (medidaMesaX,medidaMesaZ,medidaMesaY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix();

  	//mesa3 direita
  	glPushMatrix();
    glTranslatef (8.5, 0.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (-1.0, -0.3, -1.5);
    glPushMatrix();  
    glScalef (medidaMesaX,medidaMesaZ,medidaMesaY);
    glutSolidCube (1.0);
    glPopMatrix();
  	glPopMatrix();

  	//mesa4 direita
  	glPushMatrix();
    glTranslatef (8.5, 0.0, 0.0);  
    glRotatef (90, 0.0, 1.0, 0.0);    
    glTranslatef (-4.7, -0.3, -1.5);
    //glPushMatrix();  
    glScalef (medidaMesaX,medidaMesaZ,medidaMesaY);
    glutSolidCube (1.0);
    //glPopMatrix();
  	glPopMatrix();
 
	//cilindro
	/*glPushMatrix();
    glTranslatef (0,0,0);         
	glRotatef(-90,1,0,0);
    glPushMatrix();  
    glScalef (4.0,4.0,4.0);
    GLUquadricObj *obj = gluNewQuadric();
	gluCylinder(obj,0.1f,0.2f,0.4f,32,32);
    glPopMatrix();
    glPopMatrix();*/
	
	//parede da frente parte I 
	glColor3ub(220.0,220.0,220.0); 
	glPushMatrix();
    glTranslatef (0.0, 2.0, 9.0);      
    //glPushMatrix();  
    glScalef (paredeX+0.5,paredeZ+1.2,paredeY);
    glutSolidCube (1.0);
    //glPopMatrix();
	glPopMatrix();

	//porta
  	glColor3ub(128.0,128.0,128.0);
	glPushMatrix();
		glTranslatef(posicaoPortaX,posicaoPortaZ,posicaoPortaY);
		glRotatef ((GLfloat) anguloPorta, 0, 1, 0);	
		glScalef(medidaPortaX,medidaPortaZ,medidaPortaY);
		glutSolidCube(1.0);
	glPopMatrix();

	glFlush();
}


void renderScene(void) {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	
	// Set the camera
	gluLookAt(x, 1.0f, z, x+lx, 1.0f,  z+lz, 0.0f, 1.0f,  0.0f);
	laboratorio();
	glutSwapBuffers();
}


void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	//glTranslatef (0.0, 0.0, -10.0);
}

void processoSetas(int key, int xx, int yy) {
	float fraction = 0.5f;
	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.3f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.3f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}

void processoTeclas(unsigned char key, int x, int y){
	switch(key){
		case 'e':
			if(portaAberta==true){
				anguloPorta -= 90.0;
				posicaoPortaX = posicaoPortaXOriginal;
				posicaoPortaY = posicaoPortaYOriginal;
				portaAberta = false;
			}
			else{
				anguloPorta += 90.0;
				posicaoPortaX += medidaPortaX/2;
				posicaoPortaY -= medidaPortaX/2;
				portaAberta = true;
			}
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(renderScene); 
	glutReshapeFunc(reshape);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processoSetas);
	glutKeyboardFunc(processoTeclas);
	glutMainLoop();
	return 0;
}
