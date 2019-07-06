GLuint texture [35] ;
GLvoid ReSizeGLScene (GLsizei width,  GLsizei height)		// Resize And Initialize The GL Window
{
	if  (height == 0)										// Prevent A Divide By Zero By
	{
		height =1;										// Making Height Equal One
	}
	glViewport (0, 0, width, height);						// Reset The Current Viewport
	glMatrixMode (GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity ( );									// Reset The Projection Matrix
	// Calculate The Aspect Ratio Of The Window
	gluPerspective (70.0f,  (GLfloat)width/ (GLfloat)height, 0.1f, 100.0f);
	glMatrixMode (GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity ( );									// Reset The Modelview Matrix
}

AUX_RGBImageRec *LoadBMP (char *Filename)
{
FILE *File  = NULL ;
if  (!Filename )
{
	return NULL ;
}
File  = fopen (Filename ,  "r" ) ;
if  (File )
{
	fclose  (File ) ;
	return auxDIBImageLoadA  (Filename ) ;
}
	return NULL ;
}

AUX_RGBImageRec *LoadBMPA (char *Filename)
{
	FILE *File  = NULL ;
	if  (!Filename )
	{
		return NULL ;
	}
	File  = fopen (Filename ,  "r" ) ;
	if  (File )
	{
		fclose  (File ) ;
		return auxDIBImageLoadA  (Filename ) ;
	}
	return NULL ;
}
int LoadGLTextures()                                    // Load Bitmaps And Convert To Textures
{
    int Status=FALSE;                                   // Status Indicator
	int texsiz=27;
    AUX_RGBImageRec** TextureImage = new AUX_RGBImageRec*[texsiz];
 
    memset(TextureImage,0,sizeof(void *)*texsiz);
 
    // Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
    if (  (TextureImage[0]=LoadBMP("Data/Pictures/Others/ping2.bmp")) //add directories here
        &&(TextureImage[1]=LoadBMP("Data/Pictures/Gameboard/p2.bmp"))
		&&(TextureImage[2]=LoadBMP("Data/Pictures/Gameboard/p3.bmp"))
		&&(TextureImage[3]=LoadBMP("Data/Pictures/Gameboard/p4.bmp"))
		&&(TextureImage[4]=LoadBMP("Data/Pictures/Gameboard/p5.bmp"))
        &&(TextureImage[5]=LoadBMP("Data/Pictures/Ads/s1.bmp"))
		&&(TextureImage[6]=LoadBMP("Data/Pictures/Ads/s2.bmp"))
		&&(TextureImage[7]=LoadBMP("Data/Pictures/Ads/s4.bmp"))
		&&(TextureImage[8]=LoadBMP("Data/Pictures/Ads/s5.bmp"))
		&&(TextureImage[9]=LoadBMP("Data/Pictures/Others/b1.bmp"))
		&&(TextureImage[10]=LoadBMP("Data/Pictures/Scoreboard/r1.bmp"))
		&&(TextureImage[11]=LoadBMP("Data/Pictures/Scoreboard/r2.bmp"))
		&&(TextureImage[12]=LoadBMP("Data/Pictures/Scoreboard/r3.bmp"))
		&&(TextureImage[13]=LoadBMP("Data/Pictures/Scoreboard/r4.bmp"))
		&&(TextureImage[14]=LoadBMP("Data/Pictures/Scoreboard/r5.bmp"))
		&&(TextureImage[15]=LoadBMP("Data/Pictures/Scoreboard/r6.bmp"))
		&&(TextureImage[16]=LoadBMP("Data/Pictures/Scoreboard/r7.bmp"))
		&&(TextureImage[17]=LoadBMP("Data/Pictures/Scoreboard/r8.bmp"))
		&&(TextureImage[18]=LoadBMP("Data/Pictures/Scoreboard/r9.bmp"))
		&&(TextureImage[19]=LoadBMP("Data/Pictures/Scoreboard/r10.bmp"))
		&&(TextureImage[20]=LoadBMP("Data/Pictures/Scoreboard/r11.bmp"))
		&&(TextureImage[21]=LoadBMP("Data/Pictures/Scoreboard/r12.bmp"))
		&&(TextureImage[22]=LoadBMP("Data/Pictures/Win or Defeat/w1.bmp"))
		&&(TextureImage[23]=LoadBMP("Data/Pictures/Win or Defeat/w2.bmp"))
		&&(TextureImage[24]=LoadBMP("Data/Pictures/donic.bmp"))
		&&(TextureImage[25]=LoadBMP("Data/Pictures/paye.bmp"))
		&&(TextureImage[26]=LoadBMP("Data/Pictures/StartShow/back_white.bmp"))
		){

        Status=TRUE;// Set The Status To TRUE
        glGenTextures(texsiz, texture);         // Create The Texture
 
        for (int loop=0; loop<texsiz; loop++) // Loop Through All The Textures
        {
            glBindTexture(GL_TEXTURE_2D, texture[loop]);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
            glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[loop]->sizeX,TextureImage[loop]->sizeY,0,GL_RGB,GL_UNSIGNED_BYTE,TextureImage[loop]->data);
        }
    }
 
    for (int loop=0; loop<texsiz; loop++)
     {
        if (TextureImage[loop]) // If Texture Exists
        {
            if (TextureImage[loop]->data) // If Texture Image Exists
                free(TextureImage[loop]->data); // Free The Texture Image Memory
            free(TextureImage[loop]); // Free The Image Structure
        }
    }
    return Status;                 
}
