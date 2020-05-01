// Modified from:
// http://www.codeproject.com/Articles/16051/Creating-an-OpenGL-view-on-a-Windows-Form

#pragma once
#include <math.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>


using namespace System::Windows::Forms;
using namespace System;


namespace OpenGLForm 
{

    public ref class COpenGL: public System::Windows::Forms::NativeWindow
    {
    public:
        COpenGL(System::Windows::Forms::Form ^ parentForm,
                GLsizei iWidth, GLsizei iHeight)
        {
            CreateParams^ cp = gcnew CreateParams;

            // Set the position on the form
            cp->X = 10;
            cp->Y = 10;
            cp->Height = iHeight;
            cp->Width = iWidth;

            // Specify the form as the parent.
            cp->Parent = parentForm->Handle;

            // Create as a child of the specified parent and make
            // OpenGL compliant (no clipping)
            cp->Style = WS_CHILD | WS_VISIBLE |
                WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

            // Create the actual window
            this->CreateHandle(cp);

            m_hDC = GetDC((HWND)this->Handle.ToPointer());

            if(m_hDC)
            {
                MySetPixelFormat(m_hDC);
                ReSizeGLScene(iWidth, iHeight);
                InitGL();
            }

            rtri = 0.0f;
            rquad = 0.0f;
        }


        System::Void Render(float *quat)
        {
            // Clear screen and depth buffer
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            // Reset the current modelview matrix
            glLoadIdentity();
            // Move into the screen 7.0
            glTranslatef(0.0f,0.0f,-15.0f);
            // Pre-Rotate for PC viewing
            glRotatef(120.0, 0.5f, -0.5f, 0.5f);
            if (quat[0] > 1.0) quat[0] = 1.0;
            if (quat[0] < -1.0) quat[0] = -1.0;
            glRotatef((float)(-2.0f * Math::Acos(quat[0])* 180.0f / Math::PI),quat[1],quat[2],quat[3]);
            // Draw a quad
            glBegin(GL_QUADS);
            // Set The color to green
            glColor3f(0.0f,1.0f,0.0f);
            // Top Right of the quad (top)
            glVertex3f( 1.0f, 1.0f,-1.0f);
            // Top Left of the quad (top)
            glVertex3f(-1.0f, 1.0f,-1.0f);
            // Bottom left of the quad (top)
            glVertex3f(-1.0f, 1.0f, 1.0f);
            // Bottom right of the quad (top)
            glVertex3f( 1.0f, 1.0f, 1.0f);
            // Set The color to orange
            glColor3f(1.0f,0.5f,0.0f);
            // Top Right of the quad (bottom)
            glVertex3f( 1.0f,-1.0f, 1.0f);
            // Top Left of the quad (bottom)
            glVertex3f(-1.0f,-1.0f, 1.0f);
            // Bottom left of the quad (bottom)
            glVertex3f(-1.0f,-1.0f,-1.0f);
            // Bottom right of the quad (bottom)
            glVertex3f( 1.0f,-1.0f,-1.0f);
            // Set The color to red
            glColor3f(1.0f,0.0f,0.0f);
            // Top Right of the quad (front)
            glVertex3f( 1.0f, 1.0f, 1.0f);
            // Top Left of the quad (front)
            glVertex3f(-1.0f, 1.0f, 1.0f);
            // Bottom left of the quad (front)
            glVertex3f(-1.0f,-1.0f, 1.0f);
            // Bottom right of the quad (front)
            glVertex3f( 1.0f,-1.0f, 1.0f);
            // Set The color to yellow
            glColor3f(1.0f,1.0f,0.0f);
            // Top Right of the quad (back)
            glVertex3f( 1.0f,-1.0f,-1.0f);
            // Top Left of the quad (back)
            glVertex3f(-1.0f,-1.0f,-1.0f);
            // Bottom left of the quad (back)
            glVertex3f(-1.0f, 1.0f,-1.0f);
            // Bottom right of the quad (back)
            glVertex3f( 1.0f, 1.0f,-1.0f);
            // Set The color to blue
            glColor3f(0.0f,0.0f,1.0f);
            // Top Right of the quad (left)
            glVertex3f(-1.0f, 1.0f, 1.0f);
            // Top Left of the quad (left)
            glVertex3f(-1.0f, 1.0f,-1.0f);
            // Bottom left of the quad (left)
            glVertex3f(-1.0f,-1.0f,-1.0f);
            // Bottom right of the quad (left)
            glVertex3f(-1.0f,-1.0f, 1.0f);
            // Set The color to violet
            glColor3f(1.0f,0.0f,1.0f);
            // Top Right of the quad (right)
            glVertex3f( 1.0f, 1.0f,-1.0f);
            // Top Left of the quad (right)
            glVertex3f( 1.0f, 1.0f, 1.0f);
            // Bottom left of the quad (right)
            glVertex3f( 1.0f,-1.0f, 1.0f);
            // Bottom right of the quad (right)
            glVertex3f( 1.0f,-1.0f,-1.0f);
            // Done drawing the quad
            glEnd();
			glBegin(GL_POLYGON);
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(-3.0f, -1.0f, 3.0f);
			glVertex3f(-3.0f, 1.0f, 3.0f);
			glVertex3f(-1.0f, 3.0f, 3.0f);
			glVertex3f(1.0f, 3.0f, 3.0f);
			glVertex3f(3.0f, 1.0f, 3.0f);
			glVertex3f(3.0f, -1.0f, 3.0f);
			glVertex3f(1.0f, -3.0f, 3.0f);
			glVertex3f(-1.0f, -3.0f, 3.0f);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-3.0f, -1.0f, -3.0f);
			glVertex3f(-3.0f, 1.0f, -3.0f);
			glVertex3f(-1.0f, 3.0f, -3.0f);
			glVertex3f(1.0f, 3.0f, -3.0f);
			glVertex3f(3.0f, 1.0f, -3.0f);
			glVertex3f(3.0f, -1.0f, -3.0f);
			glVertex3f(1.0f, -3.0f, -3.0f);
			glVertex3f(-1.0f, -3.0f, -3.0f);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(3.0, -3.0f, -1.0f);
			glVertex3f(3.0, -3.0f, 1.0f);
			glVertex3f(3.0, -1.0f, 3.0f);
			glVertex3f(3.0, 1.0f, 3.0f);
			glVertex3f(3.0, 3.0f, 1.0f);
			glVertex3f(3.0, 3.0f, -1.0f);
			glVertex3f(3.0, 1.0f, -3.0f);
			glVertex3f(3.0, -1.0f, -3.0f);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(-3.0, -3.0f, -1.0f);
			glVertex3f(-3.0, -3.0f, 1.0f);
			glVertex3f(-3.0, -1.0f, 3.0f);
			glVertex3f(-3.0, 1.0f, 3.0f);
			glVertex3f(-3.0, 3.0f, 1.0f);
			glVertex3f(-3.0, 3.0f, -1.0f);
			glVertex3f(-3.0, 1.0f, -3.0f);
			glVertex3f(-3.0, -1.0f, -3.0f);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-3.0f, -3.0f, -1.0f);
			glVertex3f(-3.0f, -3.0f, 1.0f);
			glVertex3f(-1.0f, -3.0f, 3.0f);
			glVertex3f(1.0f, -3.0f, 3.0f);
			glVertex3f(3.0f, -3.0f, 1.0f);
			glVertex3f(3.0f, -3.0f, -1.0f);
			glVertex3f(1.0f, -3.0f, -3.0f);
			glVertex3f(-1.0f, -3.0f, -3.0f);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(1.0f, 0.5f, 0.0f);
			glVertex3f(-3.0f, 3.0f, -1.0f);
			glVertex3f(-3.0f, 3.0f, 1.0f);
			glVertex3f(-1.0f, 3.0f, 3.0f);
			glVertex3f(1.0f, 3.0f, 3.0f);
			glVertex3f(3.0f, 3.0f, 1.0f);
			glVertex3f(3.0f, 3.0f, -1.0f);
			glVertex3f(1.0f, 3.0f, -3.0f);
			glVertex3f(-1.0f, 3.0f, -3.0f);
			glEnd();
        }

        System::Void SwapOpenGLBuffers(System::Void)
        {
            SwapBuffers(m_hDC);
        }

    private:
        HDC m_hDC;
        HGLRC m_hglrc;
        GLfloat    rtri;                // Angle for the triangle
        GLfloat    rquad;                // Angle for the quad

    protected:
        ~COpenGL(System::Void)
        {
            this->DestroyHandle();
        }

        GLint MySetPixelFormat(HDC hdc)
        {
            static    PIXELFORMATDESCRIPTOR pfd= // pfd Tells Windows How We Want Things To Be
                {
                    sizeof(PIXELFORMATDESCRIPTOR),// Size Of This Pixel Format Descriptor
                    1,                          // Version Number
                    PFD_DRAW_TO_WINDOW |        // Format Must Support Window
                    PFD_SUPPORT_OPENGL |        // Format Must Support OpenGL
                    PFD_DOUBLEBUFFER,           // Must Support Double Buffering
                    PFD_TYPE_RGBA,              // Request An RGBA Format
                    16,                         // Select Our Color Depth
                    0, 0, 0, 0, 0, 0,           // Color Bits Ignored
                    0,                          // No Alpha Buffer
                    0,                          // Shift Bit Ignored
                    0,                          // No Accumulation Buffer
                    0, 0, 0, 0,                 // Accumulation Bits Ignored
                    16,                         // 16Bit Z-Buffer (Depth Buffer)
                    0,                          // No Stencil Buffer
                    0,                          // No Auxiliary Buffer
                    PFD_MAIN_PLANE,             // Main Drawing Layer
                    0,                          // Reserved
                    0, 0, 0                     // Layer Masks Ignored
                };
            
            GLint  iPixelFormat; 
         
            // get the device context's best, available pixel format match 
            if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
            {
                MessageBox::Show("ChoosePixelFormat Failed");
                return 0;
            }
             
            // make that match the device context's current pixel format 
            if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
            {
                MessageBox::Show("SetPixelFormat Failed");
                return 0;
            }

            if((m_hglrc = wglCreateContext(hdc)) == NULL)
            {
                // try try again: Driver bug:
                // http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&Number=250130
                // make that match the device context's current pixel format 
                if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
                {
                    MessageBox::Show("SetPixelFormat Failed");
                    return 0;
                }
                if((m_hglrc = wglCreateContext(hdc)) == NULL)
                {
                    MessageBox::Show(System::String::Format("wglCreateContext Failed {0}", GetLastError()));
                    return 0;
                }
            }

            if((wglMakeCurrent(hdc, m_hglrc)) == NULL)
            {
                MessageBox::Show("wglMakeCurrent Failed");
                return 0;
            }

            return 1;
        }

        bool InitGL(GLvoid)                   // All setup for opengl goes here
        {
            glShadeModel(GL_SMOOTH);             // Enable smooth shading

            glClearColor(0.0f, 0.0f, 0.0f, 0.5f);// Black background
            glClearDepth(1.0f);                  // Depth buffer setup
            glEnable(GL_DEPTH_TEST);             // Enables depth testing
            glDepthFunc(GL_LEQUAL);              // The type of depth testing to do
            // Really nice perspective calculations
            glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
            return TRUE;  // Initialisation went ok
        }
        // https://code.google.com/p/talktom-aicro/source/browse/trunk/TalkTom/TalkTom/ReSizeGLScene.cpp?spec=svn3&r=3
        // Resize and initialise the gl window
        GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
        {
            if (height==0)                 // Prevent A Divide By Zero By
            {
                height=1;                 // Making Height Equal One
            }

            glViewport(0,0,width,height);   // Reset The Current Viewport

            glMatrixMode(GL_PROJECTION);    // Select The Projection Matrix
            glLoadIdentity();               // Reset The Projection Matrix

            // Calculate The Aspect Ratio Of The Window
            gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

            glMatrixMode(GL_MODELVIEW);     // Select The Modelview Matrix
            glLoadIdentity();               // Reset The Modelview Matrix
        }
    };
}
