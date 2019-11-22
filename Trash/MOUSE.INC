#define MV_LBUTTON 1
#define MV_RBUTTON 2
#define MV_BBUTTON 3

int NUMBER_BUTTONS = 2;
int MOUSE_SIZE = 16;

unsigned char MOUSE_THERE;
unsigned char MOUSE_VISIBLE;

unsigned char LBUTTON_DOWN,
			  RBUTTON_DOWN,
			  BBUTTON_DOWN,
			  LBUTTON_UP,
			  RBUTTON_UP,
			  BBUTTON_UP,
			  CURSOR_MOVED;

int CMX = 0,
    CMY = 0;
int BSTATE = 0;

union REGS mregs;
struct SREGS msegregs;

unsigned char EGA_REG_READ = 1;
unsigned char lbutton, rbutton;
int xmouse, ymouse;

void reset_mouse()
{
  MOUSE_THERE = 0;
  MOUSE_SIZE = 16;
  MOUSE_VISIBLE = 0;
  if (getvect(0x33) != 0L)
  {
	mregs.x.ax = 0;
	int86(0x33, &mregs, &mregs);
	if (mregs.x.ax != 0)
	{
	  MOUSE_THERE = 1;
	  NUMBER_BUTTONS = mregs.x.bx;
	  LBUTTON_DOWN = 0;
	  RBUTTON_DOWN = 0;
	  BBUTTON_DOWN = 0;
	}
  }
}

void show_mouse()
{
  if (MOUSE_THERE)
  {
	mregs.x.ax = 1;
	int86(0x33, &mregs, &mregs);
	MOUSE_VISIBLE = 1;
  }
}

void hide_mouse()
{
  if (MOUSE_THERE && MOUSE_VISIBLE)
  {
	mregs.x.ax = 2;
	int86(0x33, &mregs, &mregs);
	MOUSE_VISIBLE = 0;
  }
}

void get_mouse_button(unsigned char *lbutton, unsigned char *rbutton, int *x, int *y)
{
  if (MOUSE_THERE)
  {
	mregs.x.ax = 3;
	int86(0x33, &mregs, &mregs);
	*lbutton = (mregs.x.bx == 1) ? 1 : 0;
	*rbutton = (mregs.x.bx == 2) ? 1 : 0;
	if (mregs.x.bx == 3)
	  *rbutton = *lbutton = 1;
	*x = mregs.x.cx;
	*y = mregs.x.dx;
  }
}

unsigned char get_button_rls_info(int butt_no, int *count, int *x, int *y)
{
  if (MOUSE_THERE)
  {
	  mregs.x.ax = 6;
	  mregs.x.bx = butt_no;
	  int86(0x33, &mregs, &mregs);
	  *count = mregs.x.bx;
	  *x = mregs.x.cx;
	  *y = mregs.x.dx;
    if (butt_no == 0)
      return (!(mregs.x.ax & 1));
    else
      return (!((mregs.x.ax & 2) >> 1));
  }
  return 0;
}

void set_event_handler(int call_mask, void (far *location)(void))
{
  if (MOUSE_THERE)
  {
	  mregs.x.ax = 12;
	  mregs.x.cx = call_mask;
	  mregs.x.dx = FP_OFF(location);
	  msegregs.es = FP_SEG(location);
	  int86(0x33, &mregs, &mregs);
  }
}

void set_hide_bound(int x1, int y1, int x2, int y2)
{
  if (MOUSE_THERE)
  {
	  mregs.x.ax = 16;
	  mregs.x.cx = x1;
	  mregs.x.dx = y1;
	  mregs.x.si = x2;
	  mregs.x.di = y2;
	  int86(0x33, &mregs, &mregs);
  }
}

void set_mouse_position(int x,int y)
{
  if (MOUSE_THERE)
  {
	  mregs.x.ax = 4;
	  mregs.x.cx = x;
	  mregs.x.dx = y;
	  int86(0x33, &mregs, &mregs);
  }
}

void set_mouse_hlimits(int x1,int x2)
{
  if (MOUSE_THERE)
  {
	  mregs.x.ax = 7;
	  mregs.x.cx = x1;
	  mregs.x.dx = x2;
	  int86(0x33, &mregs, &mregs);
  }
}

void set_mouse_vlimits(int y1,int y2)
{
  if (MOUSE_THERE)
  {
	  mregs.x.ax = 8;
	  mregs.x.cx = y1;
	  mregs.x.dx = y2;
	  int86(0x33, &mregs, &mregs);
  }
}

/*void far event_handler(void);

void near event_processor(int event_status, int button_status, int x, int y)
{
  if ((CMX != x) || (CMY != y))
  {
    CURSOR_MOVED = 1;
    CMX = x;
    CMY = y;
  }

  BSTATE = button_status;

  if (event_status & 2)
    LBUTTON_DOWN = 1;
  if (event_status & 8)
    RBUTTON_DOWN = 1;
  if (((event_status & 2) || (event_status & 8)) && (button_status == 3))
    BBUTTON_DOWN = 1;
  if ((NUMBER_BUTTONS == 3) && (event_status & 32))
    BBUTTON_DOWN = 1;
  if (event_status & 4)
    LBUTTON_UP = 1;
  if (event_status & 16)
    RBUTTON_UP = 1;
  if (LBUTTON_UP & RBUTTON_UP)
    BBUTTON_UP = 1;
  if ((NUMBER_BUTTONS == 3) && (event_status & 64))
    BBUTTON_UP = 1;
}

void reset_event_handler(void)
{
  CURSOR_MOVED = 0;
  LBUTTON_DOWN = LBUTTON_UP = 0;
  RBUTTON_DOWN = RBUTTON_UP = 0;
  BBUTTON_DOWN = BBUTTON_UP = 0;
}

void install_event_handler(void)
{
  if (NUMBER_BUTTONS == 3)
    set_event_handler(127, event_handler);
  else
    set_event_handler(31, event_handler);
}*/