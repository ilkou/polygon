
#include <graphic.h>

int				ilk_close(t_graphic *p)
{
	mlx_destroy_image(p->ilk_mlx, p->ilk_img);
	mlx_destroy_window(p->ilk_mlx, p->ilk_win);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static void		ilk_init(t_graphic *p, char *title)
{
	if ((p->list = read_file(title)) == NULL)
		exit(EXIT_FAILURE);
	p->ilk_mlx = mlx_init();
	p->ilk_win = mlx_new_window(p->ilk_mlx, WIDTH, HEIGHT, title);
	p->ilk_img = mlx_new_image(p->ilk_mlx, WIDTH, HEIGHT);
	p->pixels = (int *)mlx_get_data_addr(p->ilk_img, &p->bpp, &p->size_line, &p->endian);
	calcul_angle(p->list);
	sort_list(p->list);
}

int				main(int argc, char **argv)
{
	t_graphic p;

	if (argc != 2 && write(1, "usage: ./polygon file\n", 22))
		return (EXIT_FAILURE);
	ilk_init(&p, argv[1]);
	mlx_hook(p.ilk_win, 17, (1L << 17), ilk_close, &p);
	mlx_hook(p.ilk_win, 2, 0, ilk_keys, &p);
	mlx_loop_hook(p.ilk_mlx, ilk_draw, &p);
	mlx_loop(p.ilk_mlx);
	return (EXIT_SUCCESS);
}
