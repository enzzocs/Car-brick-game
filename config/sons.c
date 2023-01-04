#include <stdint.h>
#include "sons.h"
#include "ASF/sam/drivers/tc/tc.h"

void som_init()
{
	PIOB->PIO_PDR = PIO_PB25;
	PIOB->PIO_ABSR = PIO_PB25;
	PIOB->PIO_OER = PIO_PB25;       // Output Enable Register
	PIOB->PIO_PUDR = PIO_PB25;      // Pull-up Disable Register - desabilita pull-up do pino PB27

	PIOA->PIO_PDR =  PIO_PA2;
	PIOA->PIO_ABSR &= ~PIO_PA2;
	PIOA->PIO_OER =  PIO_PA2;       // Output Enable Register
	PIOA->PIO_PUDR = PIO_PA2;      // Pull-up Disable Register - desabilita pull-up do pino PB27

	PMC->PMC_PCER0 = (1 << ID_TC2) | (1 << ID_TC1) | (1 << ID_TC0);
	tc_init(TC0, 0, TC_CMR_WAVE | TC_CMR_TCCLKS_TIMER_CLOCK1 | TC_CMR_WAVSEL_UP_RC | TC_CMR_ACPA_TOGGLE);
	tc_init(TC0, 1, TC_CMR_WAVE | TC_CMR_TCCLKS_TIMER_CLOCK1 | TC_CMR_WAVSEL_UP_RC | TC_CMR_ACPA_TOGGLE);
}

void atualiza_nota_TC0_0(float f)
{
	f /= SOUND_CORRECTION;
	tc_write_ra(TC0, 0, (uint32_t)(10500000.0 / f));
	tc_write_rc(TC0, 0, (uint32_t)(21000000.0 / f));
	tc_start(TC0, 0);
}

void atualiza_nota_TC0_1(float f)
{
	f /= SOUND_CORRECTION;
	tc_write_ra(TC0, 1, (uint32_t)(10500000.0 / f));
	tc_write_rc(TC0, 1, (uint32_t)(21000000.0 / f));
	tc_start(TC0, 1);
}
