#include "ftsh.h"

int			sh_p_subsh(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_SUBSH)
	if (sh_p_match(p, NULL, TSPL) // TODO: Recheck NULL
		&& sh_p_comp_list(p, SHP_CAST_L)
		&& sh_p_match(p, NULL, TSPR)) // TODO: Recheck NULL
		PRET(1);
	PRET(0);
}
