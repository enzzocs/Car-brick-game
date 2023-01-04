/***************************************************************************************
*
*		BORGES INVADERS - Game com o LCD5110 e um pequeno Joystick (uso do FreeRTOS)
*
*		Autor: Charles B. L.
*		28/06/2016	v. 1.0
*
***************************************************************************************/

#include "defPrincipais.h"
#include "figuras.h"
#include "sons.h"
#include "ASF/sam/drivers/tc/tc.h"

static struct pontos_t carro_player;

static uint32_t media_eixoX, media_eixoY;
static uint32_t venceu = 0;
static uint32_t perdeu = 0;
static uint32_t inicio = 0;
static int32_t numero_carros = 0;
int32_t lvl = 1;
struct pontos_t carros[4];


//---------------------------------------------------------------------------------------------------
// Função para atualizar periodicamente o LCD
//---------------------------------------------------------------------------------------------------
void vTask_LCD_Print(void *pvParameters)
{
	while(1) {
		escreve2fb(tela_jogo);
		vTaskDelay(ms(30));
		imprime_LCD();
	}
}

void vTask_tela_inicial(void *pvParameters)
{
	// inicializa tela do jogo
	while(1) {
		if(inicio == 1) {
			escreve2fb(tela_inicial);
			while((PIOA->PIO_PDSR & PIO_PA23)) { // quando pressionar a tecla começa o jogo
				imprime_LCD();
				atraso_ms(1000);
				inverte_pixels();
				atraso_ms(1000);
				normaliza_pixels();
			}

			limpa_LCD();
			inicio = 0;
			escreve2fb(tela_jogo);
		}
		vTaskDelay(ms(1000));

	}
}
void vTask_musica(void *pvParameters)
{
	while(1) {
		atualiza_nota_TC0_0(554);
		vTaskDelay(105);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(11);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(466);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(554);
		vTaskDelay(674);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(74);
		atualiza_nota_TC0_0(523);
		vTaskDelay(674);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(74);
		atualiza_nota_TC0_0(659);
		vTaskDelay(674);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(74);
		atualiza_nota_TC0_0(622);
		vTaskDelay(674);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(74);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(554);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(554);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(659);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(659);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(554);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(554);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(659);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(659);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(554);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(554);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(659);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(659);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(622);
		vTaskDelay(674);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(74);
		atualiza_nota_TC0_0(466);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(554);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(783);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(932);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1108);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1108);
		vTaskDelay(82);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(9);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(82);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(9);
		atualiza_nota_TC0_0(932);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(830);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(830);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(554);
		vTaskDelay(674);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(74);
		atualiza_nota_TC0_0(466);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(554);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(783);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(932);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1108);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1108);
		vTaskDelay(82);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(9);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(82);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(9);
		atualiza_nota_TC0_0(932);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(830);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(932);
		vTaskDelay(1349);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(149);
		atualiza_nota_TC0_0(466);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(554);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(783);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(932);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1108);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1108);
		vTaskDelay(82);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(9);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(82);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(9);
		atualiza_nota_TC0_0(932);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(830);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(830);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(554);
		vTaskDelay(674);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(74);
		atualiza_nota_TC0_0(466);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(523);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(554);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(622);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(783);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(188);
		atualiza_nota_TC0_0(932);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(698);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1108);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1108);
		vTaskDelay(82);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(9);
		atualiza_nota_TC0_0(1046);
		vTaskDelay(82);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(9);
		atualiza_nota_TC0_0(932);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(830);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(932);
		vTaskDelay(1349);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(149);
		atualiza_nota_TC0_0(932);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(932);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(932);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(932);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(932);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(932);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(932);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(932);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(622);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(783);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(783);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(783);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(336);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(37);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(125);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(391);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(391);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(783);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(674);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(74);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(880);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(783);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(783);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(698);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(783);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(336);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(37);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(125);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(587);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(349);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(391);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(523);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(391);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(554);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(440);
		vTaskDelay(111);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(12);
		atualiza_nota_TC0_0(659);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(659);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(94);
		atualiza_nota_TC0_0(659);
		vTaskDelay(167);
		atualiza_nota_TC0_0(1.0);
		vTaskDelay(18);

	}

}

void vTask_Carro_Player(void *pvParameters)
{
	static uint32_t x = 69, y = 25;
	static int32_t dif_eixoX, dif_eixoY;

	carro_player.x2 = 0;
	carro_player.y2 = 0;
	carro_player.x3 = 0;
	carro_player.y3 = 0;

	while(1) {
		dif_eixoX = 512 - media_eixoX;
		dif_eixoY = 512 - media_eixoY;

		if(dif_eixoX < -50) {
			if(x > 0) {
				x--;
			}
		} else if(dif_eixoX > 50) { // 50 = Delta de tolerancia no deslocamento do eixo
			if(x < 75) {
				x++;
			}
		}
		// ------------------------------------------------------------------------
		if(dif_eixoY < -50) {
			if(y < 40) {
				y++;
			}
		}

		else if(dif_eixoY > 50) {
			if(y > 0) {
				y--;
			}
		}
		// ------------------------------------------------------------------------
		carro_player.x1 = x;
		carro_player.y1 = y;

		if(carro_player.y1 < 11) {	//ifs para definir limites do carro nas bordas
			carro_player.y1 = 11;
		}
		if(carro_player.y1 == 40) {
			carro_player.y1 = 39;
		}
		if(carro_player.x1 > 70) {
			carro_player.x1 = 69;
		}

		desenha_fig(&carro_player, &carro_jogador);
		vTaskDelay(ms(20));					// atraso para o carro não se movimentar muito rápido.
		desenha_fig(&carro_player, &apaga_carro_jogador);
	}
}

void vTask_Carro_npc(void *pvParameters)
{
	uint32_t i, k , posic_inic, velocidade;
	velocidade = 35;
	k = 1;
	i = 0;

	escreve_Nr_Peq(8, 4, lvl, 1);
	//vTaskDelay(ms(10));
	for(i = 0; i < 4; i++) {
		carros[i].x1 = 0;
	}
	carros[0].x1 = 1;
	posic_inic = (TRNG->TRNG_ODATA % 3) + 1;

	if(posic_inic == 1) {
		carros[0].y1 = 13;
	}

	if(posic_inic == 2) {
		carros[0].y1 = 25;
	}

	if(posic_inic == 3) {
		carros[0].y1 = 37;
	}

	vTaskDelay(ms(50));
	while(1) {

		for(i = 0; i < 4; i++) {
			if(carros[i].x1 == 84) {
				carros[i].x1 = 0;
				numero_carros++;
				k--;
			}
		}

		if(numero_carros >= 20 && velocidade != 10) {
			velocidade = velocidade - 5;
			lvl++;
			numero_carros = 0;
		}
		if(numero_carros >= 20 && velocidade <= 10) {
			venceu = 1;
		}

		for(i = 1; i < 4; i++) {
			if(carros[i - 1].x1 == 50) {
				carros[i].x1 = 1;
				posic_inic = (TRNG->TRNG_ODATA % 3) + 1;
				if(posic_inic == 1) {
					carros[i].y1 = 13;
				}

				if(posic_inic == 2) {
					carros[i].y1 = 25;
				}

				if(posic_inic == 3) {
					carros[i].y1 = 37;
				}
				k++;
			}
			if(carros[3].x1 == 50) {
				carros[0].x1 = 1;
				posic_inic = (TRNG->TRNG_ODATA % 3) + 1;
				if(posic_inic == 1) {
					carros[0].y1 = 13;
				}

				if(posic_inic == 2) {
					carros[0].y1 = 25;
				}

				if(posic_inic == 3) {
					carros[0].y1 = 37;
				}
				k++;
			}
		}

		for(i = 0; i < 4; i++) {
			if(carros[i].x1 > 0) {
				desenha_fig(&carros[i], &carro_npc);
				carros[i].x1 ++;
			}
		}
		vTaskDelay(ms(velocidade));
		for(i = 0; i < 4; i++) {
			if(carros[i].x1 > 0) {
				desenha_fig(&carros[i], &apaga_carro_npc);
			}
		}
	}
}

void vTask_colisao(void *pvParameters)
{
	uint32_t i;
	vTaskDelay(ms(100));
	while(1) {
		for(i = 0; i < 4; i++) {	//Varre os 4 carros do npc
			if(carros[i].x1 > 0) {
				if((carro_player.x1 + 2 <= carros[i].x1 + 13) && (carro_player.x1 + 14 >= carros[i].x1)) {
					if((carro_player.y1 <= carros[i].y1 + 7) && (carro_player.y1 + 4 >= carros[i].y1)) {
						vTaskDelay(ms(10));
						perdeu = 1;
					}

				}
			}
		}
		vTaskDelay(ms(10));

	}
}

void vtask_score(void *pvParameters)
{
	while(1) {
		escreve_Nr_Peq(8, 4, lvl, 1);
		vTaskDelay(ms(5));
		escreve_Nr_Peq(17, 6, numero_carros, 2);
		vTaskDelay(ms(10));
	}
}

void vTask_fim(void *pvParameters)
{

	while(1) {
		while(venceu == 1) {
			atraso_ms(100);
			limpa_LCD();
			atraso_ms(200);
			escreve2fb(vitoria);
			imprime_LCD();
			atraso_ms(1000);
			inverte_pixels();
			atraso_ms(1000);
			normaliza_pixels();
		}

		while(perdeu == 1) {
			atraso_ms(100);
			inic_LCD();
			limpa_LCD();
			escreve2fb(game_over);
			imprime_LCD();
			atraso_ms(1000);
			inverte_pixels();
			atraso_ms(1000);
			normaliza_pixels();
		}

		vTaskDelay(ms(10));
	}
}
//---------------------------------------------------------------------------------------------------
// Função para ler o ADC e realizar um filtro de média móvel de 32 amostras
//---------------------------------------------------------------------------------------------------
void vTask_Le_Joystik(void *pvParameters)
{
	static uint32_t ADC_x[32], ADC_y[32], k = 0;
	uint32_t j;

	while(1) {
		ADC_Handler();		// le o ADC, atualiza x e y

		ADC_x[k] = get_ADC_VRx();  //valor do ADC entra no filtro, na amostra mais antiga
		ADC_y[k] = get_ADC_VRy();

		k++;
		if(k == 32) {
			k = 0;
		}

		media_eixoX = 0;
		media_eixoY = 0;

		for(j = 0; j < 32; j++) {
			media_eixoX += ADC_x[j];  //somatório das amostras e média
			media_eixoY += ADC_y[j];
		}
		media_eixoX /= 32;
		media_eixoY /= 32;
	}
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
int main(void)
{
	sysclk_init();

	WDT->WDT_MR = WDT_MR_WDDIS;		//desabilitar o watchdog!

	// --------------------------------------------------------------------------------------
	// Botao Joystik  pino PA23 - A2 (Arduino)
	PIOA->PIO_PER =  PIO_PA23;			// PIO Enable Register
	PIOA->PIO_PUER = PIO_PA23;			// Pull-up Enable Register (DEFAULT É HABILITADO)
	PIOA->PIO_ODR =  PIO_PA23;			// Output Disable Register (DEFAULT É DESABILITADO)

	// Habilita o Debouncing por hardware
	PIOA->PIO_DIFSR = PIO_PA23;	// Debouncing Input Filter Select Register
	PIOA->PIO_IFER = PIO_PA23;	// Glitch Input Filter Enable Register
	PIOA->PIO_SCDR = 163;		/* ajuste do divisor de clock para o debouncing filter
									DIV = (T/(2.Tslow)) - 1
									[Slow Clock = 32768 Hz] clock para o sistema
									[T = 10 ms] período do debauncing - validade garantida para pulso > T
								*/
	//Reading the I/O line levels requires the clock of the PIO controller to be enabled
	PMC->PMC_PCER0 = 0x01 << ID_PIOA;

	// Gerador de Números Aleatórios do ATSAM
	pmc_enable_periph_clk(ID_TRNG);	// liga o ckl para o TRNG
	TRNG->TRNG_CR = 0x524E4701;		// habilita o TRNG

	//TIMER
	PIOB->PIO_PDR = PIO_PB25;
	PIOB->PIO_ABSR = PIO_PB25;
	PIOB->PIO_OER = PIO_PB25;
	PIOB->PIO_PUDR = PIO_PB25;

	PMC->PMC_PCER0 = (1 << ID_TC0);
	tc_init(TC0, 0, TC_CMR_WAVE | TC_CMR_TCCLKS_TIMER_CLOCK1 | TC_CMR_WAVSEL_UP_RC | TC_CMR_ACPA_TOGGLE);

	// --------------------------------------------------------------------------------------
	inic_ADC();
	//inic_Interrupt_ADC_EOC();
	// --------------------------------------------------------------------------------------
	// inicializa LCD 5110
	inic_IO_LCD();					// CLK (13 - PB27), DIN (12 - PD8), DC (11 - PD7), CE (10 - PC29), RST (9 - PC21)
	inic_LCD();
	limpa_LCD();
	// --------------------------------------------------------------------------------------
	inicio = 1;
	// ---------------------------------------------------------------------------------------

	// cria as tarefas
	xTaskCreate(vTask_LCD_Print, "Task 1", 100, NULL, 1, NULL);
	xTaskCreate(vTask_Le_Joystik, "Task 2", 100, NULL, 1, NULL);
	xTaskCreate(vTask_Carro_Player, "Task 3", 100, NULL, 1, NULL);
	xTaskCreate(vTask_Carro_npc, "Task 4", 100, NULL, 1, NULL);
	xTaskCreate(vTask_fim, "Task 5", 100, NULL, 3, NULL);
	xTaskCreate(vtask_score, "Task 6", 100, NULL, 1, NULL);
	xTaskCreate(vTask_colisao, "Task 7", 100, NULL, 2, NULL);
	xTaskCreate(vTask_musica, "Task 8", 100, NULL, 3, NULL);
	xTaskCreate(vTask_tela_inicial, "Task 9", 100, NULL, 2, NULL);
	vTaskStartScheduler();	// apos este comando o RTOS passa a executar as tarefas

	while(1);
}
//---------------------------------------------------------------------------------------------------

