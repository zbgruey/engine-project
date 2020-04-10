typedef unsigned char byte;
typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef long long int64;
typedef float float32;
typedef double float64;

#define SUCCESS 1
#define FAIL 0

static bool global_run_program = true;

struct window_state
{
  int width;
  int height;
};

void
platform_kill_window()
{
  global_run_program = false;
}

#include <windows.h>
#include <gl/gl.h>
#include "opengl.h"
#include "game.cpp"

// Accepted values for attribute names for the OpenGL Context(WGL)
#define WGL_CONTEXT_MAJOR_VERSION_ARB			    0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB			    0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB			    0x2093
#define WGL_CONTEXT_FLAGS_ARB				    0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB			    0x9126

// Accepted values for flag bits for the OpenGL Context(WGL)
#define WGL_CONTEXT_DEBUG_BIT_ARB			    0x0001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB		    0x0002

// Accepted values for attribute bits for the OpenGL Context(WLG)
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB		    0X00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB	    0X00000002

typedef HGLRC __stdcall
wgl_create_context_attribs_arb(HDC hDC, HGLRC hShareContext, const int *attribList);

void
opengl_link_functions()
{
  // OpenGL 2
  glCreateShader = (gl_create_shader *)wglGetProcAddress("glCreateShader");
  glShaderSource = (gl_shader_source *)wglGetProcAddress("glShaderSource");
  glCompileShader = (gl_compile_shader *)wglGetProcAddress("glCompileShader");
  glGetShaderiv = (gl_get_shader_iv *)wglGetProcAddress("glGetShaderiv");
  glCreateProgram = (gl_create_program *)wglGetProcAddress("glCreateProgram");
  glAttachShader = (gl_attach_shader *)wglGetProcAddress("glAttachShader");
  glLinkProgram = (gl_link_program *)wglGetProcAddress("glLinkProgram");
  glDetachShader = (gl_detach_shader *)wglGetProcAddress("glDetachShader");
  glDeleteShader = (gl_delete_shader *)wglGetProcAddress("glDeleteShader");
  glGetShaderInfoLog = (gl_get_shader_info_log *)wglGetProcAddress("glGetShaderInfoLog");
  glGetProgramiv = (gl_get_program_iv *)wglGetProcAddress("glGetProgramiv");
  glUseProgram = (gl_use_program *)wglGetProcAddress("glUseProgram");
  glGetUniformLocation = (gl_get_uniform_location *)wglGetProcAddress("glGetUniformLocation");
  glDeleteProgram = (gl_delete_program *)wglGetProcAddress("glDeleteProgram");
  glUniform1i = (gl_uniform_1i *)wglGetProcAddress("glUniform1i");
  glUniform2i = (gl_uniform_2i *)wglGetProcAddress("glUniform2i");
  glUniform3i = (gl_uniform_3i *)wglGetProcAddress("glUniform3i");
  glUniform4i = (gl_uniform_4i *)wglGetProcAddress("glUniform4i");
  glUniform1iv = (gl_uniform_1iv *)wglGetProcAddress("glUniform1iv");
  glUniform2iv = (gl_uniform_2iv *)wglGetProcAddress("glUniform2iv");
  glUniform3iv = (gl_uniform_3iv *)wglGetProcAddress("glUniform3iv");
  glUniform4iv = (gl_uniform_4iv *)wglGetProcAddress("glUniform4iv");
  glUniform1ui = (gl_uniform_1ui *)wglGetProcAddress("glUniform1ui");
  glUniform2ui = (gl_uniform_2ui *)wglGetProcAddress("glUniform2ui");
  glUniform3ui = (gl_uniform_3ui *)wglGetProcAddress("glUniform3ui");
  glUniform4ui = (gl_uniform_4ui *)wglGetProcAddress("glUniform4ui");
  glUniform1uiv = (gl_uniform_1uiv *)wglGetProcAddress("glUniform1uiv");
  glUniform2uiv = (gl_uniform_2uiv *)wglGetProcAddress("glUniform2uiv");
  glUniform3uiv = (gl_uniform_3uiv *)wglGetProcAddress("glUniform3uiv");
  glUniform4uiv = (gl_uniform_4uiv *)wglGetProcAddress("glUniform4uiv");
  glUniform1f = (gl_uniform_1f *)wglGetProcAddress("glUniform1f");
  glUniform2f = (gl_uniform_2f *)wglGetProcAddress("glUniform2f");
  glUniform3f = (gl_uniform_3f *)wglGetProcAddress("glUniform3f");
  glUniform4f = (gl_uniform_4f *)wglGetProcAddress("glUniform4f");
  glUniform1fv = (gl_uniform_1fv *)wglGetProcAddress("glUniform1fv");
  glUniform2fv = (gl_uniform_2fv *)wglGetProcAddress("glUniform2fv");
  glUniform3fv = (gl_uniform_3fv *)wglGetProcAddress("glUniform3fv");
  glUniform4fv = (gl_uniform_4fv *)wglGetProcAddress("glUniform4fv");
  glUniformMatrix2fv = (gl_uniform_matrix_2fv *)wglGetProcAddress("glUniformMatrix2fv");
  glUniformMatrix3fv = (gl_uniform_matrix_3fv *)wglGetProcAddress("glUniformMatrix3fv");
  glUniformMatrix4fv = (gl_uniform_matrix_4fv *)wglGetProcAddress("glUniformMatrix4fv");
  glUniformMatrix2x3fv = (gl_uniform_matrix_2x3fv *)wglGetProcAddress("glUniformMatrix2x3fv");
  glUniformMatrix3x2fv = (gl_uniform_matrix_3x2fv *)wglGetProcAddress("glUniformMatrix3x2fv");
  glUniformMatrix2x4fv = (gl_uniform_matrix_2x4fv *)wglGetProcAddress("glUniformMatrix2x4fv");
  glUniformMatrix4x2fv = (gl_uniform_matrix_4x2fv *)wglGetProcAddress("glUniformMatrix4x2fv");
  glUniformMatrix3x4fv = (gl_uniform_matrix_3x4fv *)wglGetProcAddress("glUniformMatrix3x4fv");
  glUniformMatrix4x3fv = (gl_uniform_matrix_4x3fv *)wglGetProcAddress("glUniformMatrix4x3fv");
  glGenBuffers = (gl_gen_buffers *)wglGetProcAddress("glGenBuffers");

  glBindBuffer = (gl_bind_buffer *)wglGetProcAddress("glBindBuffer");
  glBufferData = (gl_buffer_data *)wglGetProcAddress("glBufferData");
  glEnableVertexAttribArray = (gl_enable_vertex_attrib_array *)wglGetProcAddress("glEnableVertexAttribArray");
  glDisableVertexAttribArray = (gl_disable_vertex_attrib_array *)wglGetProcAddress("glDisableVertexAttribArray");
  glDeleteBuffers = (gl_delete_buffers *)wglGetProcAddress("glDeleteBuffers");
  glUnmapBuffer = (gl_unmap_buffer*)wglGetProcAddress("glUnmapBuffer");
  glBufferSubData = (gl_buffer_sub_data*)wglGetProcAddress("glBufferSubData");
  glVertexAttribPointer = (gl_vertex_attrib_pointer*)wglGetProcAddress("glVertexAttribPointer");
  glActiveTexture = (gl_active_texture*)wglGetProcAddress("glActiveTexture");
  
  // OpenGL 3
  glGenVertexArrays = (gl_gen_vertex_arrays *)wglGetProcAddress("glGenVertexArrays");
  glBindVertexArray = (gl_bind_vertex_array *)wglGetProcAddress("glBindVertexArray");
  glDeleteVertexArrays = (gl_delete_vertex_arrays *)wglGetProcAddress("glDeleteVertexArrays");
  glMapBufferRange = (gl_map_buffer_range *)wglGetProcAddress("glMapBufferRange");
  glClearBufferfv = (gl_clear_buffer_fv *)wglGetProcAddress("glClearBufferfv");
  
  // OpenGL 4.2
  glTexStorage2D = (gl_tex_storage_2d *)wglGetProcAddress("glTexStorage2D");
  
  // OpenGL 4.3
  glBindVertexBuffer = (gl_bind_vertex_buffer *)wglGetProcAddress("glBindVertexBuffer");
  glVertexAttribFormat = (gl_vertex_attrib_format *)wglGetProcAddress("glVertexAttribFormat");
  glVertexAttribBinding = (gl_vertex_attrib_binding *)wglGetProcAddress("glVertexAttribBinding");
  
}

static window_state
win32_get_window_dimension(HWND window)
{
  window_state result;

  RECT client_rect;
  GetClientRect(window, &client_rect);
  result.width = client_rect.right - client_rect.left;
  result.height = client_rect.bottom - client_rect.top;
  return(result);
}

void
win32_process_pending_messages()
{
  MSG message;
  while(PeekMessageA(&message, 0, 0, 0, PM_REMOVE))
  {
    
    switch (message.message)
    {
    case WM_QUIT:
      {
	global_run_program = false;
      } break;
    case WM_SYSKEYDOWN:{} break;
    case WM_SYSKEYUP:{} break;
    case WM_KEYDOWN:
      {
	uint32 vk_code = (uint32)message.wParam;	  
      } break;
    case WM_KEYUP:
      {
	uint32 vk_code = (uint32)message.wParam;
      } break;
    case WM_LBUTTONDOWN:{} break;
    case WM_LBUTTONUP:{} break;
    default:
      {
	TranslateMessage(&message);
	DispatchMessageA(&message);
      } break;
    }
  }
}

LRESULT CALLBACK
win32_msg_callback(HWND window_handle, UINT msg, WPARAM w_param, LPARAM l_param)
{
  LRESULT result = 0;
  switch (msg)
  {
  case WM_CREATE:{}break;
  case WM_CLOSE:
    {
    global_run_program = false;
    PostQuitMessage(0);
    }break;
  case WM_DESTROY:
    {
    global_run_program = false;
    PostQuitMessage(0);
    }break;
  case WM_PAINT:
    {
      PAINTSTRUCT paint;
      HDC device_context = BeginPaint(window_handle, &paint);
      EndPaint(window_handle, &paint);
    } break;
  case WM_SIZE:{} break;
  default:
    return DefWindowProc(window_handle, msg, w_param, l_param);
  }
  
  return result;
}

int WINAPI
WinMain(_In_ HINSTANCE dll_name, _In_opt_ HINSTANCE unused, _In_ LPSTR cmd_line_str,
	_In_ int display_flags)
{
  HWND window_handle;
  window_state window;
  window.width = 800;
  window.height = 600;
  
  WNDCLASSEXA win_class_info = {};
  win_class_info.cbSize = sizeof(WNDCLASSEX);
  win_class_info.lpszMenuName = 0;
  win_class_info.lpszClassName = "SIDESCROLL";
  win_class_info.style = CS_HREDRAW | CS_VREDRAW; 
  win_class_info.lpfnWndProc = win32_msg_callback;
  win_class_info.cbClsExtra = 0;
  win_class_info.cbWndExtra = 0;
  win_class_info.hInstance = dll_name;
  win_class_info.hIcon = LoadIcon(0, IDI_APPLICATION);
  win_class_info.hCursor = LoadCursorA(0, (LPCSTR)IDC_ARROW);
  win_class_info.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  win_class_info.hIconSm = LoadIcon(0, IDI_APPLICATION);
  
  if (!RegisterClassExA(&win_class_info))
    OutputDebugStringA("Window Registration Failed!");
  
  RECT window_rect = { 0, 0, window.width, window.height };
  AdjustWindowRectEx(&window_rect, WS_OVERLAPPEDWINDOW, false, WS_EX_CLIENTEDGE);
  
  window_handle =
    CreateWindowExA(WS_EX_CLIENTEDGE, "SIDESCROLL", "Side Scroller Game",
		    WS_OVERLAPPEDWINDOW | WS_THICKFRAME | WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT,
		    window_rect.right - window_rect.left, window_rect.bottom - window_rect.top, 0, 0,
		    dll_name, 0);
  
  if (window_handle == 0)
    OutputDebugStringA("Window Creation Failed!");
  
  HDC window_device_context = GetDC(window_handle);
  if (window_device_context == 0)
    OutputDebugStringA("Obtaining Device Context Failed!");

  PIXELFORMATDESCRIPTOR desired_pixel_format = {}, suggested_pixel_format = {};
  desired_pixel_format.nSize = sizeof(desired_pixel_format);
  desired_pixel_format.nVersion = 1;
  desired_pixel_format.dwFlags = PFD_SUPPORT_OPENGL |PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
  desired_pixel_format.iPixelType = PFD_TYPE_RGBA;
  desired_pixel_format.cColorBits = 32;
  desired_pixel_format.cAlphaBits = 8;
  desired_pixel_format.cDepthBits = 16;
  desired_pixel_format.iLayerType = PFD_MAIN_PLANE;
  
  int suggested_pixel_format_index = ChoosePixelFormat(window_device_context, &desired_pixel_format);
  
  if (!suggested_pixel_format_index)
    MessageBoxA(0, "Obtaining Suggested Pixel Format Index Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
  
  if (!DescribePixelFormat(window_device_context, suggested_pixel_format_index,
			   sizeof(suggested_pixel_format), &suggested_pixel_format))
    MessageBoxA(0,"Obtaining Description of a Pixel Format Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
  
  
  if (!SetPixelFormat(window_device_context, suggested_pixel_format_index, &suggested_pixel_format))
    MessageBoxA(0, "Setting Pixel Format Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
  
  DescribePixelFormat(window_device_context, suggested_pixel_format_index,
		      sizeof(suggested_pixel_format), &suggested_pixel_format);
  SetPixelFormat(window_device_context, suggested_pixel_format_index, &suggested_pixel_format);

  HGLRC opengl_context = wglCreateContext(window_device_context);
  
  if (!opengl_context)
    MessageBoxA(0, "Obtaining OpenGL Render Context Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
 
  if (wglMakeCurrent(window_device_context, opengl_context))
  {
    wgl_create_context_attribs_arb *wglCreateContextAttribsARB =
      (wgl_create_context_attribs_arb *)wglGetProcAddress("wglCreateContextAttribsARB");
    
    if (wglCreateContextAttribsARB)
    {
      int opengl_description[] =
	{
	 WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
	 WGL_CONTEXT_MINOR_VERSION_ARB, 3,
	 WGL_CONTEXT_FLAGS_ARB, 
	 // TODO: Remove Debug for final
	 WGL_CONTEXT_DEBUG_BIT_ARB, 
	 WGL_CONTEXT_PROFILE_MASK_ARB,
	 WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
	 0
	};

      HGLRC modern_context = wglCreateContextAttribsARB(window_device_context, 0, opengl_description);
      
      if (modern_context)
      {
	if (wglMakeCurrent(window_device_context, modern_context))
	{
	  wglDeleteContext(opengl_context);
	  opengl_context = modern_context;
	}
      }
    }
    else
    {
      MessageBoxA(0, "Failed to link wglCreateContextAttribsARB!", "Error!", MB_ICONEXCLAMATION | MB_OK);
    }
  }
  else
  {
    MessageBoxA(0, "wglMakeCurrent Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
  }
  
  opengl_link_functions();
  
  ShowWindow(window_handle, display_flags);
  
  MSG msg = {};

  LARGE_INTEGER cpu_freq_result, last_counter, end_counter;
  float64 ms_per_frame, fps;
  QueryPerformanceFrequency(&cpu_freq_result);
  int64 counter_elapsed, cpu_freq = cpu_freq_result.QuadPart;
  QueryPerformanceCounter(&last_counter);

  global_run_program = game_initialize(window);

  while (global_run_program)
  {
    win32_process_pending_messages();

    game_loop();
    
    if (!SwapBuffers(window_device_context))
      OutputDebugStringA("Swapping Buffers Failed!");
    
    QueryPerformanceCounter(&end_counter);
    counter_elapsed = end_counter.QuadPart - last_counter.QuadPart;
    ms_per_frame = (1000.0f *(float64)counter_elapsed) / (float64)cpu_freq;
    fps = (float64)cpu_freq / (float64)counter_elapsed;
  }
  
  return msg.message;
}
