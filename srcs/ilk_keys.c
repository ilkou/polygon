
#include <graphic.h>

int		ilk_keys(int key, t_graphic *p)
{
	if (key == ILK_KEY_ESC)
		ilk_close(p);
	return (1);
}
