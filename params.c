#include "main.h"
/**
 * init_params - reset buffer
 * @params: the struct for parameters
 * @ap: pointer
*/
void init_params(params_t *params, va_list ap)
{
	params->uni = 0;
	params->plus = 0;
	params->space = 0;
	params->hash = 0;
	params->zero = 0;
	params->min = 0;
	params->wid = 0;
	params->prec = UINT_MAX;
	params->h_mod = 0;
	params->l_mod = 0;
	(void)ap;
}
