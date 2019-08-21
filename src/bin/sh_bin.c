#include "libft.h"
#include "ftsh.h"
#include "sh_bin.h"

/*
t_hset	*sh_bin(void)
{
	return (g_htbin);
}
*/
t_dastr	*sh_bin_names(void)
{
	return (sh_sh()->bin_nl);
}

/*
t_hset	**sh_bin_ptr(void)
{
	return (&g_htbin);
}
*/

int 	sh_bin_init(t_hset **phtbin, t_dastr **bin_names)
{
	*phtbin = ft_hset_init(SH_BIN_HTSIZE,
		ft_htab_hcode_str, ft_htab_equals_str, ft_htab_free_ent_str);
	*bin_names = ft_dastrnew_max(2);
	return (OK);
}

int		sh_bin_filter(const struct dirent *dent)
{
	return  (BIT_IS(dent->d_type, DT_REG));
}
